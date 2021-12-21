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
    // insert code here...
    string line;
    vector<string> s1;
    ifstream file("example.txt");
    if (file.is_open()){
        while (getline(file, line))
            s1.push_back(line);
    file.close();
    }
    else
        cout << "No file read" << endl;
    vector<int> s2;
    for (int i=0; i < s1.size()-2; i++){
        int temp = 0;
        for (int j=0; j < 3; j++){
            temp += stoi(s1[i+j]);
        }
        s2.push_back(temp);
    }
    int numInc = 0;
    for (int i=1; i < s2.size(); i++){
        if (s2[i] > s2[i-1]){
            numInc++;
        }
    }
    cout << "The number of increasing depths is: " << numInc << endl;
    return 0;
}
