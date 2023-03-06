#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include "readFile.cpp"



using namespace std;
using namespace chrono;


const int num_threads = 4;
int dimension = MaxNode()+1;
int** matrix = creaMatrix(dimension);
int count = 0;;

void count_triangles(int** matrix, int thread_id, int n){

    int local_count = 0;
    for (int i = thread_id; i < n; i += num_threads) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j]) {
                for (int k = j + 1; k < n; k++) {
                    if (matrix[j][k] && matrix[k][i]) {
                        local_count++;
                    }
                }
            }
        }
    }
    count += local_count;
}

int main(){
    
    cout <<"dimenion: " << dimension <<'\n';
   // int n = MaxNode()+1;

    //cout <<"NODES: " << n <<'\n';
    //auto matrix = creaMatrix(n);

    edges(matrix,dimension);  

    // Creazione dei thread e calcolo del numero di triangoli
    vector<thread> threads;

    for (int i = 0; i < num_threads; i++) {
        //threads.emplace_back(count_triangles, i , dimension);
    }
    for (auto& t : threads) {
        t.join();
    }

    // Stampa del risultato
    cout << "Il numero di triangoli nel grafo è: " << count << endl;

    return 0;
}


