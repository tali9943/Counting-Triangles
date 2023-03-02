#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// funzione per inizializzare la matrice di adiacenza con valori 0
void initializeAdjMatrix(int adj_matrix[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

// funzione per generare archi casuali
void generateRandomEdges(int adj_matrix[][100], int n) {
    srand(time(0)); // inizializza il generatore di numeri casuali
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int rand_num = rand() % 2; // genera un numero casuale tra 0 e 1
            if (rand_num == 1) {
                adj_matrix[i][j] = 1;
                adj_matrix[j][i] = 1;
            }
        }
    }
}

// funzione per calcolare il numero di triangoli nel grafo
int countTriangles(int adj_matrix[][100], int n) {
    int num_triangles = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                for (int k = j+1; k < n; k++) {
                    if (adj_matrix[j][k] == 1 && adj_matrix[k][i] == 1) {
                        num_triangles++;
                    }
                }
            }
        }
    }
    return num_triangles;
}

// funzione per stampare la matrice di adiacenza
void printAdjMatrix(int adj_matrix[][100], int n) {
    cout << "Matrice di adiacenza:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n; // numero di vertici
    cout << "Inserisci il numero di vertici: ";
    cin >> n;

    int adj_matrix[100][100]; // matrice di adiacenza

    initializeAdjMatrix(adj_matrix, n); // inizializza la matrice di adiacenza

    generateRandomEdges(adj_matrix, n); // genera archi casuali

    int num_triangles = countTriangles(adj_matrix, n); // calcola il numero di triangoli

    cout << "Il numero di triangoli nel grafo e': " << num_triangles << endl;

    printAdjMatrix(adj_matrix, n); // stampa la matrice di adiacenza

    return 0;
}
