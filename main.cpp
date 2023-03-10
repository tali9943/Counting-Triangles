#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <omp.h>
#include <thread>
#include <filesystem>
#include "readFile.cpp"
#include "countingTriangles.cpp"


using namespace std;


auto executionSequence(int** adjacency_matrix, int num_nodes){

   cout << "SEQUENCE ALGORITHM" << '\n' << endl;

   auto start = chrono::high_resolution_clock::now();
   
   int numbers_triangles = countTrianglesSequence(adjacency_matrix, num_nodes);

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
    createResults(results);
}



int main(){

    int num_nodes = MaxNode();
    cout <<"NODES: " << num_nodes << endl;
    
    int** adjacency_matrix = creaMatrix(num_nodes);

    edges(adjacency_matrix,num_nodes);  


    auto sequence_time = executionSequence(adjacency_matrix,num_nodes);
    cout << '\n';

    int num_threads;
    cout << "Insert the numbers of threads: ";
    cin >> num_threads;
    executionParallel(adjacency_matrix, num_nodes, sequence_time,num_threads);

    return 0;
}