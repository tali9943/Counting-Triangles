#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "readFile.cpp"

using namespace std;


int** creaMatrix(int n){
   int **matrix = new int *[n];

   for (int i = 0; i < n; i++){
      matrix[i] = new int[n];
   }

   // Initialize the adjacency matrix to 0
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
            matrix[i][j] = 0;
      }
   }
   return matrix;
}


//print matrix function
void prinMatrix(int** matrix, int n){
      for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){
               cout << matrix[i][j] << " ";
         }
         cout << endl;
      }
}




//Function to count the numbers of triangles in adjacency matrix
int countTriangles(int** matrix, int n){
   auto start = std::chrono::high_resolution_clock::now();
   int numbers_triangles = 0;

   for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
         if(matrix[i][j] == 1){
            for(int z = j+1; z < n; z++){
               if(matrix[j][z] == 1 && matrix[z][i] == 1){
                  numbers_triangles++;
               }
            }
         }
      }
   }

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> total_time = end - start;

   cout <<'\n';
   cout << "Time of execution countingTriangles: " << total_time.count()<< "seconds" << std::endl;
   return numbers_triangles;
}



void esecution(){
   auto start = std::chrono::high_resolution_clock::now();
   int n = MaxNode()+1;

   cout <<"NODES: " << n <<'\n';
   auto matrix = creaMatrix(n);

   edges(matrix,n);  

   int numbers = countTriangles(matrix, n);

   cout << "Numbers of triangles is: " << numbers << endl;

   auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> total_time = end - start;
   cout << "Total time of execution: " << total_time.count() << "seconds" << std::endl;

}



int main(){
   esecution();

   return 0;
}