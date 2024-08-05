---
date:   2024-06-18
---

# Leetcode 208. Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

## prefix tree
Create a new class Node to represent prefix tree Node. It contains a letter, whether this is a word, and children nodes.

The root node contains no letter. And during insert, start from root, insert the first letter to root, and do it recursively. Until it hits the last letter.
During search, start from root, check if the node's children contains the desired letter. If not, return false; if yes, continue search recursively.

For implementation, when checking a node for letter ch. Because things start at root, the implementation is assume the parameter node as parent, and check if parent has a child with letter ch.

## Java Code
<pre>
<code>
class Trie {
    class Node {
        private char letter = ' ';
        private boolean isWord = false;
        HashMap<Character, Node> children;
        Node() {
            children = new HashMap<Character, Node>();
        }
    }

    private Node root;

    public Trie() {
        root = new Node();
    }
    
    private void insertNode(String word, int pos, Node parent) {
        if (pos >= word.length()) {
            return;
        }
        char c = word.charAt(pos);
        if (!parent.children.containsKey(c)) {
            parent.children.put(c, new Node());
        }
        Node child = parent.children.get(c);
        child.letter = c;
        if (pos == word.length()-1) {
            child.isWord = true;
        } else {
            insertNode(word, pos+1, child);
        }
        return;
    }
    public void insert(String word) {
        insertNode(word, 0, root);
        return;
    }
    
    private boolean searchNode(String word, int pos, Node parent) {
        if (pos >= word.length()) {
            return false;
        }
        char ch = word.charAt(pos);
        if (!parent.children.containsKey(ch)) {
            return false;
        }
        Node node = parent.children.get(ch);
        if (pos == word.length() - 1) {
            return node.isWord;
        }
        
        return searchNode(word, pos+1, node);
    }
    public boolean search(String word) {
        return searchNode(word, 0, root);
    }
    
    private boolean startsWithNode(String prefix, int pos, Node parent) {
        if (pos >= prefix.length()) {
            return false;
        }
        char ch = prefix.charAt(pos);
        if (!parent.children.containsKey(ch)) {
            return false;
        }
        Node node = parent.children.get(ch);
        if (pos == prefix.length() - 1) {
            return true;
        }
        return startsWithNode(prefix, pos+1, node);
    }
    public boolean startsWith(String prefix) {
        return startsWithNode(prefix, 0, root);
    }
}
</code>
</pre>

<h2> Implementation with for loop </h2>
The recursive implementation is costly. The other way to handle it is using a for loop for all the chars in the words. And update Node pointer after each iteration.


<h2> Java Code </h2>
<pre>
<code>
class Trie {
    class Node {
        private char letter = ' ';
        private boolean isWord = false;
        HashMap<Character, Node> children = null;
        Node() {
            children = new HashMap<Character, Node>();
        }
    }
    private Node root = null;

    public Trie() {
        root = new Node();        
    }
    
    public void insert(String word) {
        Node p = root;
        for (char ch : word.toCharArray()) {
            if (!p.children.containsKey(ch)) {
                p.children.put(ch, new Node());
            }
            Node node = p.children.get(ch);
            node.letter = ch;
            p = node;
        }
        p.isWord = true;
    }
    
    public boolean search(String word) {
        Node p = root;
        for (char ch : word.toCharArray()) {
            if (!p.children.containsKey(ch)) {
                return false;
            }
            p = p.children.get(ch);
        }
        return p.isWord;
    }
    
    public boolean startsWith(String prefix) {
        Node p = root;
        for (char ch : prefix.toCharArray()) {
            if (!p.children.containsKey(ch)) {
                return false;
            }
            p = p.children.get(ch);
        }
        return true;
    }
}
</code>
</pre>