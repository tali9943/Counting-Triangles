#include "readFile.cpp"
#include <iostream>
#include <vector>
#include <omp.h>


int num_nodes = MaxNode()+1;
int** adjacency_matrix = creaMatrix(num_nodes);
int num_triangles = 0;;



void countTrianglesPal(){

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp paralle reduction(+:num_triangles) num_threads(5)
        for (int i = 0; i < num_nodes; i++) {
            #pragma omp for
            for (int j = i+1; j < num_nodes; j++) {
                if (adjacency_matrix[i][j] == 1) {
                    for (int k = j+1; k < num_nodes; k++) {
                        if (adjacency_matrix[i][k] == 1 && adjacency_matrix[j][k] == 1) {
                            num_triangles++; // incrementa il contatore per ogni triangolo trovato
                        }
                    }
                }
            }
        }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_time = end - start;
    cout << "Time execution countTriangles: " << total_time.count() << " seconds" << std::endl;
}





int main() {
    std::cout << "Parallel algorithm" << '\n' << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "NODES: " << num_nodes << std::endl;

    edges(adjacency_matrix,num_nodes);

    countTrianglesPal();

    std::cout << "Numbers of triangles is: " << num_triangles << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> total_time = end - start;
    cout << "Total time of execution: " << total_time.count() << "seconds" << std::endl;

    return 0;
}

