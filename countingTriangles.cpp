#include <iostream>
#include <vector>
#include <omp.h>
#include <thread>
#include <chrono>


using namespace std;


int countTrianglesSequence(int** matrix, int num_nodes){
   auto start = chrono::high_resolution_clock::now();
   int numbers_triangles = 0;

   for(int i = 0; i < num_nodes; i++){
      for(int j = i+1; j < num_nodes; j++){
         if(matrix[i][j] == 1){
            for(int z = j+1; z < num_nodes; z++){
               if(matrix[j][z] == 1 && matrix[z][i] == 1){
                  numbers_triangles++;
               }
            }
         }
      }
   }

   auto end = chrono::high_resolution_clock::now();
   chrono::duration<double> total_time = end - start;

   cout <<'\n';
   cout << "Time of execution countingTriangles: " << total_time.count()<< "seconds" << endl;
   return numbers_triangles;
}



vector<pair<int, double>> countTrianglesParallel(int** adjacency_matrix, int num_nodes, double time_sequence, int threads){
    int num_triangles = 0;

    vector<pair<int, double>> data;

    for(int num_threads = 1; num_threads < threads; num_threads++){

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
        auto time_parallel = total_time.count();
        auto speedup = time_sequence / time_parallel;

        cout << "Numbers of thread: " << num_threads << endl;
        cout << "Numbers of triangles is: " << num_triangles << endl;
        cout << "Time execution countTriangles: " << time_parallel << " seconds" << std::endl;
        cout << "Speedup: " << speedup << std::endl;
        cout << '\n';
        
        data.push_back(make_pair(num_threads, speedup));

        num_triangles = 0;
    }
    return data;
}