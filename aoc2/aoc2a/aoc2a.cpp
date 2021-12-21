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
    int x = 0;
    int y = 0;
    string line;
    vector<string> s1;
    ifstream file("day2.txt");
    if (file.is_open()){
        while (getline(file, line))
            s1.push_back(line);
    file.close();
    }
    else
        cout << "No file read" << endl;
    
    for (int i=0; i < s1.size(); i++){
        string direction;
        for (int j=0; j < s1[i].size(); j++){
            if (s1[i][j] != ' ' && !isdigit(s1[i][j]))
                direction += s1[i][j];
            if (s1[i][j] != ' ' && isdigit(s1[i][j])){
                if (direction == "forward")
                    x += (s1[i][j] - '0');
                else if (direction == "down")
                    y += (s1[i][j] - '0');
                else if (direction == "up")
                    y -= (s1[i][j] - '0');
            }
        }
    }
    
    cout << "The product of the depth and horizontal position is: " << x * y << endl;
    return 0;
}
