#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
#include <omp.h>
#include <thread>
#include "readFile.cpp"
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


