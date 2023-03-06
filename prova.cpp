#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> createMatrix(){
    
    string filename = "./Databases/Brightkite_edges.txt"; 
    ifstream input_file(filename); 
    vector<vector<int>> adjacency_matrix; // matrice di adiacenza

    // legge il file di input riga per riga
    string line;
    while (getline(input_file, line)) {
        istringstream iss(line);
        int node1, node2;
        if (!(iss >> node1 >> node2)) { break; } // se la riga non contiene due numeri, esce dal ciclo
        int max_node = max(node1, node2);
        if (max_node >= adjacency_matrix.size()) { // se il massimo nodo trovato supera la dimensione della matrice, la espande
            adjacency_matrix.resize(max_node+1);
            for (auto& row : adjacency_matrix) {
                row.resize(max_node+1);
            }
        }
        adjacency_matrix[node1][node2] = 1; // imposta il valore della matrice di adiacenza a 1
        adjacency_matrix[node2][node1] = 1; // la matrice di adiacenza di un grafo non orientato è simmetrica
    }
    return adjacency_matrix;
}



int main() {
 
    auto matrix = createMatrix();
    cout << matrix.size();
}
