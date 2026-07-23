# Lab 7: Implementation of Graphs

This lab focuses on **Graphs** andhow they can be implemented in C++.

You will practice the following concepts:

* Adjacency Matrix
* Adjacency List


All the following sections of this lab are based on the following levels of dificulty:

🟢 __Simple__: A simple coding task that usually guides you step by step through the process and focuses on learning the basics. It should not take more than 15min to finish it. 

🟡 __Moderate__: A coding task that usually states a moderate problem to test your understanding and transfer skills from syntax to real-world applications. These tasks can be solved in about 30mins depending on your knowledge.

🔴 __Complex__: Quite a difficult or lengthy coding task that requires you to use the acquired knowledge of the previous tasks in a broader context or project. Such tasks might take up to a few hours to solve them.

---

## 🟢 Section I: Graph Basics

A graph is a mathematical structure used to describe pairwise relationships between objects. These objects are called nodes (vertices).
If two nodes are related to each other, this relationship is represented by connecting the two nodes with an edge.

---

### Task Description

Given is the following graph:

![A simple Graph](simpleGraphA.svg)

Write down (e.g. as comments in a .cpp file):
* The set of nodes/vertices **V**
* The set of edges **E**
* The characteristics of the graph (weighted, directed, connected, degree of each node)

---

## 🟡 Section II: Adjacency Matrix Representation

An adjacency matrix is a square _n x n_ matrix that models a finite graph.
It offers a simple and intuitive way to represent the connections between the graph’s nodes.

The adhacency matrix at element ```[i,j]``` is zero or non-zero depending on if there is an edge between vertex _i_ and _j_.

## Task Description

Create an adjacency matrix for the graph. Interpret the characters A, B, C as 0, 1, 2.

- Use boolean values for each element of the matrix and a fixed sized 2d array.
- The matrix should be contained in a class called ```AdjacencyMatrix```.
- Set all values of the matrix in the constructor to zero.
- Create a method to set the element ```[i,j]``` of the matrix to either 1 or 0.
- Create a method to print the matrix in a matrix-shaped format.

In main, create a matrix representing the graph of the exercise.

Answer as comment in the code:
* What are the current downsides of the implementation of the matrix? 

---

## 🟡 Section III: Improved Adjacency Matrix Representation

In this section, we want to improve the existing class by getting rid of the fixed-sized 2d array.

## Task Description

- Replace the 2d array by a 2d vector container
- use integers instead of bools to be able to represent weigthed edges
- Adapt your existing class and main function
- Add an additional method to get the weight of an edge

Answer as comment in the code:
* What is (still) the downside of this implementation of the matrix?

## 🟡 Section IV: Adjacency List Representation

An adjacency list is a way to represent a graph by storing, for each vertex (node), a list of all the vertices connected to it.

An adjacency list stores each vertex together with a list of all vertices directly connected to it. Internally, this is usually implemented as an array/vector where each index represents a vertex and contains a linked list or vector of its neighbors.

![Graph example with list](adjacencyList.svg)

## Task Description

Based on the image in this section IV, create a class called ```AdjacencyList```.

Interpret the characters A, B, C as 0, 1, 2.

The class should contain:
- a vector container representing the adjacency list
- a constructor to initialize the list
- a method to add new vertices
- a method to add edges between vertices
- a method to print the adjacency list to the console

Create an object in main representing the graph shown in the image above in section IV.

---

## 🔴 Section V: Shortest Path with Dijkstra

In this section, you will extend your adjacency list implementation and use it to find the shortest path between two vertices.

Dijkstra's algorithm is used to find the shortest path from one start vertex to all other vertices in a weighted graph. The algorithm works step by step by always selecting the currently unvisited vertex with the smallest known distance.

Learn more about it [in this video](https://youtu.be/bZkzH5x0SKU?si=2SHKmCb2u9zQYWyR).

## Task Description

Extend your existing class `AdjacencyList` from Section IV.

Use the following graph:

![Graph example with weights](graphWeighted.svg)

Interpret the characters A, B, C, D as 0, 1, 2, 3.

The class should contain:
- a vector container representing a weighted adjacency list
- a method to add weighted edges between vertices
- a method `findShortestPath(int start, int destination)`
- a method to print the shortest path and its total distance

The method `findShortestPath` should:
- take a starting vertex and a destination vertex
- calculate the shortest path using Dijkstra's algorithm
- return the vertices of the shortest path including start and destination
- also calculate the total distance of the shortest path

Use the following simplifications:
- assume that all edge weights are positive
- assume that the graph is undirected

Create an object in `main` representing the graph shown in the image above.

Test your implementation with at least two different start and destination vertices.

Answer as comment in the code:
* Why is Dijkstra more efficient than calculating all possible paths?
* Why does Dijkstra require non-negative edge weights?
