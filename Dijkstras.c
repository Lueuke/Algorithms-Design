#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "graph.c"

// Find the minimum distance
int minDistance(int dist[], bool sptSet[]) 
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Print function to print results 
void printSolution(int dist[], char* nodeNames[]) 
{
    printf("Diijkstras Algorithm\n");
    printf("%-25s %s\n", "Vertex", "Distance from Source");
    for (int i = 0; i < V; i++)
        printf("%-25s %d\n", nodeNames[i], dist[i]);
}


// Function that implements Dijkstras algorithm
void dijkstra(int graph[V][V], int src, char* nodeNames[]) 
{
    int dist[V]; 

    bool sptSet[V]; 
    
    
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

   
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) 
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        
        for (int v = 0; v < V; v++)
           
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print function call
    printSolution(dist, nodeNames);
}


int main() 
{
    
    // Have all the names of each node 
    char* nodeNames[V] = {"College Square", "Lewis Science Center", "Prince Center", "Computer Science", "Speach Language Hearing", "Torreyson Library", "Burdick", "Police Department", "Old Main", "Fine Art", "McAlister", "Maintenance College", "Student Center", "Student Health Center", "Wingo", "New Business Buiding", "Oak Tree", "Brewer-Hegema", "Bear Village Apt"};

    // Dijkstras Function call
    dijkstra(graph, 0, nodeNames);

    return 0;
}
