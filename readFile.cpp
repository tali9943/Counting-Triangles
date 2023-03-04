#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int MaxNodeFound(){
    string line;
    ifstream myfile("email-Eu-core.txt");
    int maxNode = 0;

    if (myfile.is_open()){

        while (getline(myfile, line)){  
            int elem = stoi(line); 
            if(elem > maxNode){
                maxNode = elem;
            }
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    return maxNode;
}



void edges(int** matrix, int n){
    string line;
    ifstream myfile("email-Eu-core.txt");
    if (myfile.is_open()){

        while (getline(myfile, line)){   
            int node = line[0];
            int edge = line[1];
            cout<<"node: "<< node <<'\n';
            cout<<"edge: "<< edge <<'\n';

            matrix[node][edge] = 1; 
        }
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
}



