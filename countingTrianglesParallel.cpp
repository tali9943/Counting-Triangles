#include "readFile.cpp"
#include <iostream>
#include <vector>
#include <omp.h>
#include <thread>
#include <pthread.h>
#include <chrono>

using namespace std;



void countTrianglesPal(int** adjacency_matrix, int num_nodes){
    int num_triangles = 0;

    for(int num_threads = 1; num_threads < 21; num_threads++){

        auto start = chrono::high_resolution_clock::now();

        #pragma omp parallel for reduction(+:num_triangles) num_threads(num_threads)
        for (int i = 0; i < num_nodes; i++) {
            for (int j = i+1; j < num_nodes; j++) {
                if (adjacency_matrix[i][j] == 1) {
                    for (int k = j+1; k < num_nodes; k++) {
                        if (adjacency_matrix[i][k] == 1 && adjacency_matrix[j][k] == 1) {
                            num_triangles++; 
                        }
                    }
                }
            }
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> total_time = end - start;

        cout << "Numbers of thread: " << num_threads << endl;
        cout << "Numbers of triangles is: " << num_triangles << endl;
        cout << "Time execution countTriangles: " << total_time.count() << " seconds" << std::endl;
        cout << '\n';
        num_triangles = 0;
    }
}


auto executionParallel(){
    cout << "Parallel algorithm" << '\n' << endl;

    auto start = chrono::high_resolution_clock::now();
    int num_nodes = MaxNode()+1;

    cout << "NODES: " << num_nodes << endl;
    int** adjacency_matrix = creaMatrix(num_nodes);

    edges(adjacency_matrix,num_nodes);


    countTrianglesPal(adjacency_matrix,num_nodes);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> total_time = end - start;
    cout << "Total time of execution: " << total_time.count() << "seconds" << std::endl;

    return total_time.count();
}


/*
int main(){
    
    auto timee = executionParallel();
    cout << timee << '\n';
}
*/




