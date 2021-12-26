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
#include <cmath>
using namespace std;

int convert(string val);

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

    string gamma = "";
    string epsilon = "";

    for (int i=0; i < s1[0].size(); i++){
        int zero = 0;
        int one = 0;
        for (int j=0; j < s1.size(); j++){
            if ((s1[j][i] - '0') == 0)
                zero++;
            if ((s1[j][i] - '0') == 1)
                one++;
        }
        if (zero > one){
            gamma += '0';
            epsilon += '1';
        }
        else if (one > zero){
            gamma += '1';
            epsilon += '0'; 
        }
    }

    int gammalvl = convert(gamma);
    int epslvl = convert(epsilon);

    cout << "The power consumption of the submarine is " << gammalvl * epslvl << endl;
    return 0;
}

int convert(string val){
    int decimal = 0;
    for (int i = 0; i < val.size(); i++){
        if ((val[i] - '0') == 1)
            decimal += pow(2, val.size()-1-i);
    }
    return decimal;
}