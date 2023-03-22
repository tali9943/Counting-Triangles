#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <filesystem>
#include <vector>

using namespace std;

//string path_name = "./Databases/CA-GrQc.txt";           
//string path_name = "./Databases/Email-Enron.txt"; 
//string path_name = "./Databases/facebook_combined.txt";    
string path_name = "./Databases/denseGraph4039.txt";      

//function used to inizialize the adjacenty matrix
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




//print adjacenty matrix
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


//function used to search the maximum node of the graph
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



//function used to create a txt file with the results of the parallel execution
void createResults(vector<pair<int, double>> data){

    //directory of output
    filesystem::path output_dir("./outputResults");

    //checks of the directory for the output
    if (!filesystem::exists(output_dir)){
        filesystem::create_directory(output_dir);
    }

    // generates output file
    ofstream outfile(output_dir / "results.txt"); 
    outfile <<"Numbers of threads" << "   " << "Speedup" << endl;
    outfile << path_name << endl;

    for (const auto& p : data){
        outfile << p.first << " " << p.second << endl;
    }

    outfile.close(); 
}










