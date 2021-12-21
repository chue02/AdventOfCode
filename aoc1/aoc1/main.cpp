//
//  main.cpp
//  aoc1
//
//  Created by Eric Chu on 12/18/21.
//

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
    
    int numInc = 0;
    for (int i=1; i < s1.size(); i++){
        if (stoi(s1[i]) > stoi(s1[i-1])){
            numInc++;
        }
    }
    cout << "The number of increasing depths is: " << numInc << endl;
    return 0;
}
