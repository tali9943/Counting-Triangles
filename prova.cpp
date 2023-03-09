#include <iostream>
#include <fstream>
#include <filesystem>
#include <utility> // per std::pair
#include <vector>

int main()
{
    std::vector<std::pair<int, double>> data;

    // Aggiungiamo dinamicamente coppie al vettore
    data.push_back(std::make_pair(1, 5.5));
    data.push_back(std::make_pair(2, 3.3));
    data.push_back(std::make_pair(3, 2.2));
    data.push_back(std::make_pair(4, 1.1));

    // Impostiamo la directory di output
    std::filesystem::path output_dir("output_directory");

    // Verifichiamo se la directory esiste, altrimenti la creiamo
    if (!std::filesystem::exists(output_dir)) {
        std::filesystem::create_directory(output_dir);
    }

    // Creiamo il file di testo nella directory di output
    std::ofstream outfile(output_dir / "data.txt"); // apriamo il file in scrittura
    for (const auto& p : data) {
        outfile << p.first << " " << p.second << std::endl;
    }
    outfile.close(); // chiudiamo il file

    return 0;
}
