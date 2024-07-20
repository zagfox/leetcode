---
date:   2024-07-20
---

# Leetcode 721. Accounts Merge

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

## BFS
Create a map from email to accounts.

Iterate account, if account's one email are found in another account. Add the other account into the queue. Also needs to mark account as visited. Then one iteration can found all emails for an account.

It passed simple cases, but timeout for complicated cases.

## Java Code
<pre>
<code>
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        // Map from email to account ids.
        HashMap<String, HashSet<Integer>> emailToIds = new HashMap<>();
        for (int id = 0; id < accounts.size(); ++id) {
            List<String> account = accounts.get(id);
            for (int i = 1; i < account.size(); ++i) {
                String email = account.get(i);
                if (!emailToIds.containsKey(email)) {
                    emailToIds.put(email, new HashSet<>());
                }
                HashSet<Integer> ids = emailToIds.get(email);
                ids.add(id);
            }
        }
        List<List<String>> outputs = new LinkedList<>();
        HashSet<Integer> visited = new HashSet<>();
        // Visit all account, use BFS to find all related accounts.
        for (int id = 0; id < accounts.size(); ++id) {
            if (visited.contains(id)) {
                continue;
            }
            String name = accounts.get(id).get(0);
            TreeSet<String> allEmails = new TreeSet<>();
            Queue<Integer> queue = new LinkedList<>();
            queue.add(id);
            while (!queue.isEmpty()) {
                int frontId = queue.poll();
                visited.add(frontId);
                List<String> account = accounts.get(frontId);
                for (int i = 1; i < account.size(); ++i) {
                    allEmails.add(account.get(i));
                    HashSet<Integer> relatedIds = emailToIds.get(account.get(i));
                    for (int relatedId : relatedIds) {
                        if (visited.contains(relatedId)) {
                            continue;
                        }
                        queue.add(relatedId);
                    }
                }
            }
            List<String> output = new LinkedList<>();
            output.add(name);
            for (String email : allEmails) {
                output.add(email);
            }
            outputs.add(output);
        }
        return outputs;
    }
}
</code>
</pre>

## Union Find
Those emails forms a disjoint set. Suppose we define a leader for each email. And emails will form groups, each group has the same leader.

In this problem, we iterate all accounts.
  1. For an email, recursively find its leader, if none, set its leader to first email of the account
  2. If found an leader, set its leader to the found leader.

The, iterate all emails, find email's leader recursively, if belonging to the same leader, create a new account for this group.


## Java Code
<pre>
<code>
class Solution {
    // Create a new node, whose parent is itself.
    public void create(String node, HashMap<String, String> parentMap) {
        if (!parentMap.containsKey(node)) {
            parentMap.put(node, node);
        }
    }
    // find root of a node
    public String findRoot(String node, HashMap<String, String> parentMap) {
        if (!parentMap.containsKey(node)) {
            create(node, parentMap);
            return node;
        }
        while (node != parentMap.get(node)) {
            node = parentMap.get(node);
        }
        return node;
    }
    // Union, src node -> destination node
    public void union(String src, String dst, HashMap<String, String> parentMap) {
        String srcRoot = findRoot(src, parentMap);
        String dstRoot = findRoot(dst, parentMap);
        if (srcRoot.equals(dstRoot)) {
            return;
        }
        parentMap.put(srcRoot, dstRoot);
        return;
    }
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        HashMap<String, String> parentMap = new HashMap<>();
        HashMap<String, String> emailToName = new HashMap<>();
        for (List<String> account : accounts) {
            String name = account.get(0);
            for (int i = 1; i < account.size(); ++i) {
                String email = account.get(i);
                emailToName.put(email, name);
                create(email, parentMap);
                union(email, account.get(1), parentMap);
            }
        }
        HashMap<String, TreeSet<String>> rootToMembers = new HashMap<>();
        for (String email : parentMap.keySet()) {
            String root = findRoot(email, parentMap);
            if (!rootToMembers.containsKey(root)) {
                rootToMembers.put(root, new TreeSet<>());
            }
            rootToMembers.get(root).add(email);
        }
        List<List<String>> outputs = new LinkedList<>();
        rootToMembers.forEach((root, members) -> {
            List<String> output = new LinkedList<>();
            output.add(emailToName.get(root));
            for (String member : members) {
                output.add(member);
            }
            outputs.add(output);
        });
        return outputs;
    }
}
</code>
</pre>