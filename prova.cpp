#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int MaxNodeFound(){
    string line;
    ifstream myfile("testoprova.txt");
    int maxNode = 0;

    if (myfile.is_open()){

        while (getline(myfile, line)){  
            int elem = stoi(line); 
            if(elem > maxNode){
                maxNode = elem;
                //controllo maxnode
            }
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    return maxNode;
}

int** createAdjMatrix(int node){
    string line;
    ifstream myfile("testoprova.txt");
 
    if (myfile.is_open()){
        cout <<"prova";
        
        // Read the first line to determine the number of vertices
        getline(myfile, line);

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
            j = stoi(line.substr(1, line.find(" ")));
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

    int n = MaxNodeFound();
    cout << "number" << n <<'\n';
    auto matrix = createAdjMatrix(n);
    //cout <<matrix;

   // int numbers = countTriangles(matrix, 1005);
    //cout << "Numbers of triangles is: " << numbers << endl;


}
