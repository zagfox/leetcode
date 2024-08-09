---
date:   2024-08-09
---

# Leetcode 1105. Filling Bookcase Shelves

You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.

## Enumerate
Try all ways to place books. When a book can be placed in the same level, without increasing this level's height, place. Otherwise, try both ways, one is to place it at this level and increase height, the other is to place at the next level.

It works but TLE.

## Java Code
<pre>
<code>
class Solution {
    // level Height is the height of this single level
    // height is the current height of the books. 
    // col is the current position to place books, 0, 1, 2,3 with width = 4.
    int minHeight = 9999;
    public void enumerate(int levelHeight, int height, int col, int bookId, int[][] books, int shelfWidth) {
        if (bookId == books.length) {
            if (height < minHeight) {
                minHeight = height;
            }
            return;
        }
        // if book can place in same level, without extra height
        if (books[bookId][0] <= shelfWidth-col && books[bookId][1] <= levelHeight) {
            enumerate(levelHeight, height, col+books[bookId][0], bookId+1, books, shelfWidth);
            return;
        }
        // if book can place in the same level, with extra height
        if (books[bookId][0] <= shelfWidth-col && books[bookId][1] > levelHeight) {
            enumerate(books[bookId][1], height + books[bookId][1]-levelHeight, col+books[bookId][0],
                      bookId+1, books, shelfWidth);
        }
        // try placing books on the next level
        enumerate(books[bookId][1], height + books[bookId][1], books[bookId][0],
                  bookId+1, books, shelfWidth);
    }
    public int minHeightShelves(int[][] books, int shelfWidth) {
        enumerate(0, 0, 0, 0, books, shelfWidth);
        return minHeight;
    }
}
</code>
</pre>

## Dynamic programming
dp[i] to denote the minHeight if using books [0...i]. 
for dp[i+1], it's the min of multiple cases
   1. placing i+1 in a new layer
   2. [0...i-1] in same layer, i and i+1 in new layer
   3. [0...i-2] in the same layer, i-1, i, i+1 in same layer
   4. until exceeding width

## Java Code
<pre>
<code>

</code>
</pre>