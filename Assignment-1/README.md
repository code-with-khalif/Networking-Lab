Dijkstra’s Algorithm – Single Source Shortest Path

Modern Operating Systems and Computer Network (Lab Assignment 1)
Date: Oct 14, 2025


Overview

This project implements Dijkstra’s Single Source Shortest Path Algorithm using C++. The goal is to find the shortest path from a given source vertex to all other vertices in a weighted graph. The graph is represented using an adjacency matrix and adjacency list for efficiency.

Problem Statement

Write a C++ program to implement Dijkstra’s algorithm for a graph represented using an adjacency matrix.

Given Data
	•	Number of vertices: 5
	•	Edges:

0 1 4  
0 2 8  
1 4 6  
2 3 2  
3 4 10


	•	Source vertex: 0

Implementation Details

The program performs the following steps:
	1.	Constructs an adjacency list from the given edge list.
	2.	Uses a priority queue (min-heap) to efficiently select the next vertex with the smallest distance.
	3.	Updates the shortest distance for each neighboring vertex iteratively.
	4.	Outputs the shortest distance from the source vertex to all other vertices.

Key Functions
	•	constructAdj() → Builds the adjacency list from the input edges.
	•	dijkstra() → Implements the core Dijkstra algorithm using a priority queue.
	•	main() → Defines the graph, initializes the source vertex, and prints the shortest distances.


Example Output

For the given graph, the program will print the shortest distance from vertex 0 to all other vertices.

Vertex    Distance from Source (0)
0         0
1         4
2         8
3         10
4         10

Concepts Used
	•	Graph representation using adjacency list
	•	Priority queue (Min-Heap)
	•	Greedy algorithm design
	•	Single-source shortest path

 commands) too?
