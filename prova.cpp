#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int** createAdjMatrix(){
    string line;
    ifstream myfile("email-Eu-core.txt");

    if (myfile.is_open()){
        cout <<"prova";
        // Read the first line to determine the number of vertices
        getline(myfile, line);
        int node = 1005 ; //stoi(line);

        // Allocate 2D array for the adjacency matrix
        int **adjMatrix = new int *[node];
        for (int i = 0; i < node; i++){
            adjMatrix[i] = new int[node];
        }

        // Initialize the adjacency matrix to 0
        for (int i = 0; i < node; i++){
            for (int j = 0; j < node; j++){
                adjMatrix[i][j] = 0;
            }
        }

        // Read the rest of the lines and update the adjacency matrix
        int i, j;
        while (getline(myfile, line)){
            i = stoi(line.substr(0, line.find(" ")));
            j = stoi(line.substr(line.find(" ") + 1));
            if(i!=j){
                adjMatrix[i][j] = 1;
                adjMatrix[i][j] = 1;
            }

        }

        // Print the adjacency matrix
        for (int i = 0; i < node; i++){
            for (int j = 0; j < node; j++){
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }

        return adjMatrix;


        // Close the file
        myfile.close();
    }

    else{
        cout << "Unable to open file";
    }

    return 0;
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


    auto matrix = createAdjMatrix();
    //cout <<matrix;

    int numbers = countTriangles(matrix, 1005);
    cout << "Numbers of triangles is: " << numbers << endl;


}
