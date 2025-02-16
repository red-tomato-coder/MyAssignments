#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("data.txt");
    file << "Hello, file!";
    file.close();

    std::ifstream infile("data.txt");
    std::string content;
    infile >> content;
    std::cout << content;
    return 0;
}
