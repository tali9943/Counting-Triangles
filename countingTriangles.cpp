#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int** creaMatrix(int n){

   int** matrix= 0;
   matrix = new int*[n];

   for(int i = 0; i < n; i++){
      matrix[i] = new int[n];
      for(int j = 0; j < n; j++){
         matrix[i][j] = 0;
      }
   }
   return matrix;
}

void prinMatrix(int** matrix, int n){
   cout << "Matrice di adiacenza:" << endl;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
}

void generateEdges(int** matrix,int n){
   srand(time(0));

   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         int random = rand() % 2;
         if(random == 1 && i != j){
            matrix[i][j] = 1;
            matrix[j][i] = 1;  
         }
      }
   }
}


int countTriangles(int** matrix, int n){
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
   return numbers_triangles;
}



int main(){
   int n; // numero di vertici
   cout << "Inserisci il numero di vertici: ";
   cin >> n;

   auto matrix = creaMatrix(n);

   generateEdges(matrix, n);

   cout << "Dopo: ";
   prinMatrix(matrix, n);

   int numbers = countTriangles(matrix, n);
   cout << "Numbers of triangles is: " << numbers << endl;

   return 0;
}