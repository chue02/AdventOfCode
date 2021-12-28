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
void findOxyLvl(vector<string>& oxy);
void findCO2Lvl(vector<string>&co2);

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

    vector<string> oxygen, carbondioxide;
    oxygen = s1;
    carbondioxide = s1;
    
    findOxyLvl(oxygen);
    findCO2Lvl(carbondioxide);

    string oxy = oxygen[0];
    string carbon = carbondioxide[0];

    cout << oxy << endl;
    cout << carbon << endl;

    int O2 = convert(oxy);
    int CO2 = convert(carbon);

    cout << "The power consumption of the submarine is " << O2 * CO2 << endl;
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

void findOxyLvl(vector<string>& oxy){
        for (int i=0; oxy.size() > 1 && i < oxy[0].size(); i++){
            vector<string> oxygen;
            int zero = 0;
            int one = 0;
            for (int j=0; j < oxy.size(); j++){
                if ((oxy[j][i] - '0') == 0)
                    zero++;
                if ((oxy[j][i] - '0') == 1)
                    one++;
            }
            if (zero > one){
                for (int j=0; j < oxy.size(); j++){
                    if ((oxy[j][i] - '0') == 0)
                        oxygen.push_back(oxy[j]);
                }
            }
            else if (one >= zero){
                for (int j=0; j < oxy.size(); j++){
                    if ((oxy[j][i] - '0') == 1)
                        oxygen.push_back(oxy[j]);
                }
            }
            oxy = oxygen;
        }
}

void findCO2Lvl(vector<string>& co2){
    for (int i=0; co2.size() > 1 && i < co2[0].size(); i++){
            vector<string> carbon;
            int zero = 0;
            int one = 0;
            for (int j=0; j < co2.size(); j++){
                if ((co2[j][i] - '0') == 0)
                    zero++;
                if ((co2[j][i] - '0') == 1)
                    one++;
            }
            if (one >= zero){
                for (int j=0; j < co2.size(); j++){
                    if ((co2[j][i] - '0') == 0)
                        carbon.push_back(co2[j]);
                }
            }
            else if (zero > one){
                for (int j=0; j < co2.size(); j++){
                    if ((co2[j][i] - '0') == 1)
                        carbon.push_back(co2[j]);
                }
            }
            co2 = carbon;
        }
}