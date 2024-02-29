#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "graph.c"

// Calculate the Minimun distance 
int minDistance(int dist[], bool sptSet[]) 
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Print the solution function 
void printSolution(int dist[], char* nodeNames[]) 
{
    printf("Bellman Fords Algorithm\n");
    printf("%-25s %s\n", "Vertex", "Distance from Source");
    for (int i = 0; i < V; i++)
        printf("%-25s %d\n", nodeNames[i], dist[i]);
}

// BellmandFord  Algorithm Function
void bellmanFord(int src, char* nodeNames[]) 
{
    // The Final array with the shortest distances 
    int dist[V]; 

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relax edges
    for (int i = 1; i <= V - 1; i++) 
    {
        for (int u = 0; u < V; u++) 
        {
            for (int v = 0; v < V; v++) 
            {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }

    // Negative Weight Check
    for (int u = 0; u < V; u++) 
    {
        for (int v = 0; v < V; v++) 
        {
            if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }

    // Print function call with shortest paths
    printSolution(dist, nodeNames);
}

// Main Function
int main() 
{
    // Store all the names of the graph
    char* nodeNames[V] = {"College Square", "Lewis Science Center", "Prince Center", "Computer Science", "Speach Language Hearing", "Torreyson Library", "Burdick", "Police Department", "Old Main", "Fine Art", "McAlister", "Maintenance College", "Student Center", "Student Health Center", "Wingo", "New Business Buiding", "Oak Tree", "Brewer-Hegema", "Bear Village Apt"};
    
    // Bellman Ford Function call 
    bellmanFord(0, nodeNames);

    return 0;
}
