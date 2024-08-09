---
date:   2024-08-09
---

# Get Number of Teams

A product manager at Amazon wants to choose a two-member team for a project.

There are n employees to choose from where the i-th employee has a skill, skill[i]. The project needs a total skill between min_skill and max_skill, both inclusive.

Given the array skill and two integers min_skill and max_skill, find the number of pairs of employees whose sum of skills is between min_skill and max_skill, both inclusive.

Function Description

Complete the function getNumTeams in the editor below.

getNumTeams takes the following arguments:

int skill[n]: the skills of the employees
int min_skill: the minimum total skill
int max_skill: the maximum total skill
Returns

long int: the number of pairs of employees with the sum of skills in the given range

## Two rounds iteration
Sort employees by skill value. First choose first candidate, then choose the second.

## Java Code
<pre>
<code>
public long getNumTeams(int[] skill, int min_skill, int max_skill) {
  Arrays.sort(skill);
  int output = 0;
  for (int i = 0; i < skill.length; ++i) {
    for (int j = i+1; j < skill.length; ++j) {
      int total = skill[i] + skill[j];
      if (min_skill <= total && total <= max_skill) {
        ++output;
      }
    }
  }
  return output;
}
</code>
</pre>
