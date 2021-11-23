#include <iostream>
#include <vector>

using namespace std;

bool isSafeToDraw(int[] color, int node, bool graph[101][101], int N, int colo) {
    for (int i = 0; i < N; i++) {
        if (i != node && graph[i][node] == 1 && color[i] == colo) {
            return false;
        }
    }

    return true;
}

// Recursive Function
/**
 * @brief 
 * 
 * Vertex coloring is the most commonly encountered graph coloring problem.
 *  The problem states that given m colors, determine a way of coloring the vertices 
 * of a graph such that no two adjacent vertices are assigned same color.

 * @param node 
 * @param graph 
 * @param m 
 * @param N 
 * @param color 
 * @return true 
 * @return false 
 */
bool solve(int node, bool graph[101][101], int m, int N, int color[]) {
    
    if (node == N) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafeToDraw(color, node, graph, N, i)) {
            color[node] = i;
            if (solve(node+1, graph, m, N, color)) {
                return true;
            } else {
                color[node] = 0;
            }
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) {
    int color[N] = {0};
    if (solve(0,graph,m,N,color)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}