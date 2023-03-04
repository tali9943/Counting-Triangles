#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits> // per numeric_limits

using namespace std;


void edges(int** matrix, int n){
    string line;
    ifstream myfile("CA-GrQc.txt");
    if (myfile.is_open()){

        while (getline(myfile, line)){   

            istringstream ss(line);
            string firstword, secondword;

            ss >> firstword >> secondword;

            int node = stoi(firstword);
            int edge = stoi(secondword);

            matrix[node][edge] = 1; 
            matrix[edge][node] = 1; 
            //cout << "matrix: " << matrix[node][edge]  <<'\n';
            
            
            //cout << matrix[node][edge] <<'\0';
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
}



int MaxMinNode(){
    string line;
    ifstream myfile("CA-GrQc.txt");
    int maxNode = 0;
    double minNode = numeric_limits<double>::infinity();
    cout << minNode << '\n';

    if (myfile.is_open()){

        while (getline(myfile, line)){  
            istringstream ss(line);
            string firstword, secondword;

            ss >> firstword >> secondword;

            int node = stoi(firstword);
            int edge = stoi(secondword);

            if(node > maxNode)
                maxNode = node;
            if(edge > maxNode)
                maxNode = edge;

            if(node < minNode)
                minNode = node;
            if(edge < minNode)
                minNode = edge;
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    return maxNode,minNode;
}




int MaxNodeFound(){
    string line;
    ifstream myfile("email-Eu-core.txt");
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

