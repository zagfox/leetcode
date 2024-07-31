---
date:   2024-07-31
---

# Leetcode 973. K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

<h2>Priority Queue</h2>
Use a max heap, to store topK. If number of items exceeds K, remove max ones. In java implementation, it needs to define a customized comparater.


<h2> Java Code </h2>
<pre>
<code>
class Solution {
    class Point {
        private int x, y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public int zeroSquare() {
            return x*x + y*y;
        }
    }
    class PointComparator implements Comparator<Point> {
        // makes the heap root, to be max zeroSquare.
        public int compare(Point a, Point b) {
            return -1 * Integer.compare(a.zeroSquare(), b.zeroSquare());
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> topK = new PriorityQueue<>(k, new PointComparator());
        for (int[] point : points) {
            topK.add(new Point(point[0], point[1]));
            if (topK.size() > k) {
                topK.poll();
            }
        }
        Point[] pointOutput = topK.toArray(new Point[topK.size()]);
        int[][] output = new int[k][2];
        for (int i = 0; i < k; ++i) {
            output[i][0] = pointOutput[i].x;
            output[i][1] = pointOutput[i].y;
        }
        return output;
    }
}
</code>
</pre>