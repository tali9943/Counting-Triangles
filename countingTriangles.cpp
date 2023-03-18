#include <iostream>
#include <vector>
#include <omp.h>
#include <thread>
#include <chrono>


using namespace std;


long long countTrianglesSequence(int** adjacency_matrix, int num_nodes){
   auto start = chrono::high_resolution_clock::now();
   long long numbers_triangles = 0;

   for(int i = 0; i < num_nodes; i++){
      for(int j = i+1; j < num_nodes; j++){
         if(adjacency_matrix[i][j] == 1){
            for(int z = j+1; z < num_nodes; z++){
               if(adjacency_matrix[j][z] == 1 && adjacency_matrix[z][i] == 1){
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
    long long num_triangles = 0;

    vector<pair<int, double>> data;

    for(int num_threads = 1; num_threads < threads; num_threads++){

        auto start = chrono::high_resolution_clock::now();

        #pragma omp parallel reduction(+:num_triangles) num_threads(num_threads)
        for (int i = 0; i < num_nodes; i++) {
            #pragma omp for schedule(static) nowait
            for (int j = i+1; j < num_nodes; j++) {
                if (adjacency_matrix[i][j] == 1) {
                    for (int z = j+1; z < num_nodes; z++) {
                        if (adjacency_matrix[i][z] == 1 && adjacency_matrix[j][z] == 1) {
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
        cout << "Speedup: " << speedup << endl;
        cout << '\n';
        
        data.push_back(make_pair(num_threads, speedup));

        num_triangles = 0;
    }
    return data;
}