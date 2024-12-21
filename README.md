
# Programming Assignment: Heap-Sort and Kruskal's Algorithm

## Overview

This repository contains the implementations of two algorithms:

1. **Heap-Sort Algorithm**: A sorting algorithm that uses a binary heap to sort a sequence of numbers.
2. **Kruskal's Algorithm**: A graph algorithm used to find the Minimum Spanning Tree (MST) of a network.

## Table of Contents

- [Heap-Sort Algorithm](#heap-sort-algorithm)
  - [Algorithm Description](#algorithm-description)
  - [Time Complexity Analysis](#time-complexity-analysis)
  - [Example](#example)
- [Kruskal's Algorithm](#kruskals-algorithm)
  - [Algorithm Description](#algorithm-description-1)
  - [Time Complexity Analysis](#time-complexity-analysis-1)
  - [Example](#example-1)

## Heap-Sort Algorithm

### Algorithm Description

Heap-Sort is a comparison-based sorting algorithm that works by converting an array into a binary heap and then repeatedly extracting the minimum element from the heap to build a sorted array. The algorithm consists of two main phases:

1. **Heap Construction**: Building a binary heap from the input array.
2. **Sorting**: Repeatedly extracting the minimum element from the heap and placing it in the sorted array.

### Time Complexity Analysis

- **Building the Heap**: `O(n)`, where `n` is the number of elements in the array.
- **Sorting**: Extracting the minimum element and reheapifying takes `O(log n)` time, and this is done `n` times, resulting in a time complexity of `O(n log n)`.
- **Overall Time Complexity**: `O(n log n)`.

### Example

Sample Input:
```
Enter the number of elements in the array: 5
Enter the elements of the array:
Element 1: 10
Element 2: 4
Element 3: 6
Element 4: 3
Element 5: 8
```

Sample Output:
```
Sorted array: 3 4 6 8 10
```

## Kruskal's Algorithm

### Algorithm Description

Kruskal’s algorithm finds the Minimum Spanning Tree (MST) of a graph by:

1. Sorting all edges of the graph in non-decreasing order of their weight.
2. Iterating through the sorted edges and adding them to the MST if they don’t form a cycle (using a union-find data structure to check for cycles).

### Time Complexity Analysis

1.  **Sorting:**
    *   **Description:** The algorithm begins by sorting the edges of the graph by their weights in ascending order.
    *   **Complexity:** The time complexity for sorting the edges is given as  `E log(E)`, where `E` is the number of edges. this is equal to `E log(V^2)` which simplifies to  `Θ(E log(V))` where `V` is the number of vertices.
2.  **Make-Set:**
    *   **Description:** For each vertex, a separate set is created.
    *  **Complexity:** When using a "normal array" data structure for the set, this takes `Θ(V)`. When using a disjoint set forest, it takes time of `V * Make-Set Time`.
3.  **Find-Set:**
    *   **Description:**  For each edge, we need to determine which set its vertices belong to.
    *   **Complexity:** When using a "normal array" data structure for the set, this takes `Θ(E)`. When using a disjoint set forest, it takes time of `E * Find-Set Time`.
4.  **Union:**
    *   **Description:** If the two vertices from an edge are in different sets, these two sets are combined to represent connected components of the spanning tree.
    *  **Complexity:** When using a "normal array" data structure for the set, this takes `Θ(V^2)`. When using a disjoint set forest, it takes time of `V * Union Time`.

**Total Complexity (with Normal Array):**

*   The sum of the complexities is: `Θ(E log(V)) +  Θ(V) + Θ(E) +  Θ(V^2)`.
*   Simplifying (assuming E can be as large as V^2, the dominant terms are the `E log(V)` and `V^2`), the total complexity is  `Θ(E log(V) + V^2)`.

### Example

Sample Input:
```
Enter the number of vertices: 4
Enter the number of edges: 5
Enter the vertices (e.g., A, B, C, ...):
Vertex 1: A
Vertex 2: B
Vertex 3: C
Vertex 4: D
Enter the edges (source, destination, weight):
Edge 1: A B 10
Edge 2: A C 20
Edge 3: B C 5
Edge 4: B D 2
Edge 5: C D 1
```

Sample Output:
```
Edges in the MST:
D -- C == 1
B -- D == 2
B -- A == 10
Total weight of MST: 13
```
