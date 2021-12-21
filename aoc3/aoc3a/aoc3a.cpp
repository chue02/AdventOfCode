//
//  main.cpp
//  aoc1
//
//  Created by Eric Chu on 12/18/21.
//
//  g++ -std=c++11 -o main.out main.cpp && ./main.out

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string line;
    vector<string> s1;
    ifstream file("day3.txt");
    if (file.is_open()){
        while (getline(file, line))
            s1.push_back(line);
    file.close();
    }
    else
        cout << "No file read" << endl;

    cout << "The number of bits are: " << s1.size() << endl;
    return 0;
}
