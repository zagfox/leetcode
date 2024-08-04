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
    public class Point {
        public int x;
        public int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
        public double distance() {
            return Math.sqrt(x*x + y*y);
        }
    }
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Point> heap = new PriorityQueue<>(new Comparator<Point>() {
            public int compare(Point a, Point b) {
                // Default creates a min heap, it needs to create a maxheap
                return -Double.compare(a.distance(), b.distance());
            }
        });
        for (int[] point : points) {
            Point p = new Point(point[0], point[1]);
            heap.add(p);
            if (heap.size() > k) {
                heap.poll();
            }
        }
        int[][] outputs = new int[k][2];
        int id = 0;
        while (!heap.isEmpty()) {
            Point p = heap.poll();
            outputs[id][0] = p.x;
            outputs[id][1] = p.y;
            ++id;
        }
        return outputs;
    }
}
</code>
</pre>