#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <vector>

using namespace std;



int** creaMatrix(int n){
   int **adjacency_matrix = new int *[n];

   for (int i = 0; i < n; i++){
      adjacency_matrix[i] = new int[n];
   }
   
   // Initialize the adjacency matrix
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
            adjacency_matrix[i][j] = 1;
      }
   }
   return adjacency_matrix;
}




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
        cout << "Speedup: " << speedup << endl;
        cout << '\n';
        
        data.push_back(make_pair(num_threads, speedup));

        num_triangles = 0;
    }
    return data;
}


auto executionSequence(int** adjacency_matrix, int num_nodes){

   cout << "SEQUENCE ALGORITHM" << '\n' << endl;

   auto start = chrono::high_resolution_clock::now();
   
   long long numbers_triangles = countTrianglesSequence(adjacency_matrix, num_nodes);

   cout << "Numbers of triangles is: " << numbers_triangles << endl;

   auto end = chrono::high_resolution_clock::now();
   chrono::duration<double> total_time = end - start;
   cout << "Total time of execution of sequence algorithm: " << total_time.count() << "seconds" << endl;

   return total_time.count();
}



void executionParallel(int** adjacency_matrix, int num_nodes, double time, int num_threads){
    cout << "PARALLEL ALGORITHM" << '\n' << endl;

    auto start = chrono::high_resolution_clock::now();

    vector<pair<int, double>> results = countTrianglesParallel(adjacency_matrix,num_nodes,time, num_threads );

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> total_time = end - start;
    cout << "Total time of parallel algorithm: " << total_time.count() << "seconds" << std::endl;
    //createResults(results);
}



int main(){

    int num_nodes;
    cout << "Insert the number of nodes: ";
    cin >> num_nodes;

    int** adjacency_matrix = creaMatrix(num_nodes);

    auto sequence_time = executionSequence(adjacency_matrix,num_nodes);
    cout << '\n';

    int num_threads;
    cout << "Insert the number of threads: ";
    cin >> num_threads;
    executionParallel(adjacency_matrix, num_nodes, sequence_time,num_threads);





    return 0;
}