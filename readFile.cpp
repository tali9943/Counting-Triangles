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
        cout<< maxNode <<'\n';
        myfile.close();
    }
    else{
        cout << "Unable to open file";
    }
    return maxNode;
}


int main(){

int x = MaxNodeFound();

//cout <<x;
}

