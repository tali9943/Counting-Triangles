#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <vector>

using namespace std;

/*
CA-GrQc =  *SPARSO* NODES: 26197 EDGES:14496 TRIANGLES: 48260 
Email-Enron = *GRANDE* NODES: 36692 EDGES: 183831  TRIANGLES: 727044 
facebook_combined = *PICCOLO* - NODES: 4039 EDGE: 88234  TRIANGLES: 1612010 
denseGraph4039 = *DENSO* - NODES: 4039 EDGE: XXX  TRIANGLES: 1612010 
*/

//string path_name = "./Databases/CA-GrQc.txt"; 
//string path_name = "./Databases/email-Eu-core.txt";                 
//string path_name = "./Databases/Email-Enron.txt"; 
//string path_name = "./Databases/facebook_combined.txt";     //sparso 
string path_name = "./Databases/denseGraph4039.txt";      //denso

int** creaMatrix(int n){
   int **adjacency_matrix = new int *[n];

   for (int i = 0; i < n; i++){
      adjacency_matrix[i] = new int[n];
   }
   
   // Initialize the adjacency matrix
   for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
            adjacency_matrix[i][j] = 0;
      }
   }
   return adjacency_matrix;
}




//print matrix function
void prinMatrix(int** adjacency_matrix, int n){
      for (int i = 0; i < n; i++){
         for (int j = 0; j < n; j++){
               cout << adjacency_matrix[i][j] << " ";
         }
         cout << endl;
      }
}

//insert edges into the adjacency matrix
void edges(int** adjacency_matrix, int n){
    string line;
    ifstream myfile(path_name);
    if (myfile.is_open()){

        while (getline(myfile, line)){   

            istringstream ss(line);
            string first, second;

            ss >> first >> second;

            int node = stoi(first);
            int edge = stoi(second);

            adjacency_matrix[node][edge] = 1; 
            adjacency_matrix[edge][node] = 1; 

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
            string first, second;

            ss >> first >> second;

            int node = stoi(first);
            int edge = stoi(second);

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
    outfile <<"Numbers of threads" << "   " << "Speedup" << endl;
    outfile << path_name << endl;

    for (const auto& p : data) {
        outfile << p.first << " " << p.second << endl;
    }

    outfile.close(); 
}










