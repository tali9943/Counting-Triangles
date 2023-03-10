#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits> // per numeric_limits
#include <chrono>
#include <filesystem>
#include <vector>

using namespace std;


auto path_name = "./Databases/Email-Enron.txt";

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

void edges(int** matrix, int n){
    string line;
    ifstream myfile(path_name);
    if (myfile.is_open()){

        while (getline(myfile, line)){   

            istringstream ss(line);
            string firstword, secondword;

            ss >> firstword >> secondword;

            int node = stoi(firstword);
            int edge = stoi(secondword);

            matrix[node][edge] = 1; 
            matrix[edge][node] = 1; 

        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
}


int MaxNode(){
    string line;
    ifstream myfile(path_name);

    int maxNode = 0;

    if (myfile.is_open()){

        while (getline(myfile, line)){  
            istringstream ss(line);
            string firstword, secondword;

            ss >> firstword >> secondword;

            int node = stoi(firstword);
            int edge = stoi(secondword);

            if(node > maxNode){
                maxNode = node;
            }

            if(edge > maxNode){
                maxNode = edge;
            }
 
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    return maxNode+1;
}



void createResults(vector<pair<int, double>> data){

    // Impostiamo la directory di output
    filesystem::path output_dir("./outputResults");

    // Verifichiamo se la directory esiste, altrimenti la creiamo
    if (!filesystem::exists(output_dir)) {
        filesystem::create_directory(output_dir);
    }

    // Creiamo il file di testo nella directory di output
    ofstream outfile(output_dir / "results.txt"); // apriamo il file in scrittura
    outfile <<"Numbers of threads" << "   " << "speedup" << endl;
    for (const auto& p : data) {
        outfile << p.first << " " << p.second << endl;
    }

    outfile.close(); // chiudiamo il file
}










