#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

int countTrianglesParallel(int** matrix, int n, int num_threads){
    auto start = std::chrono::high_resolution_clock::now();
    int numbers_triangles = 0;

    std::vector<std::thread> threads;
    for(int t = 0; t < num_threads; t++){
        threads.emplace_back([&](){
            for(int i = t; i < n; i+=num_threads){
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
        });
    }

    for(auto& t : threads){
        t.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> total_time = end - start;

    cout << "Time of execution countingTriangles: " << total_time.count() << " seconds" << std::endl;
    return numbers_triangles;
}

