#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <omp.h>
#include <thread>
#include <pthread.h>
#include "readFile.cpp"
using namespace std;


int countTrianglesSeq(int** matrix, int num_nodes){
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



auto executionSequence(){
   cout << "Sequence algorithm" << '\n' << endl;

   auto start = chrono::high_resolution_clock::now();
   int num_nodes = MaxNode()+1;

   cout <<"NODES: " << num_nodes << endl;
   int** matrix = creaMatrix(num_nodes);

   edges(matrix,num_nodes);  

   int numbers = countTrianglesSeq(matrix, num_nodes);

   cout << "Numbers of triangles is: " << numbers << endl;

   auto end = chrono::high_resolution_clock::now();
   chrono::duration<double> total_time = end - start;
   cout << "Total time of execution: " << total_time.count() << "seconds" << endl;

   return total_time.count();
}



