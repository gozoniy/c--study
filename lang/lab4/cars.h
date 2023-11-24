#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class car{
    private:
        string brand;
        string model;
        int speed;
        char GearBox;
    public:
        int set(ifstream& in){
            if (!in.eof()){
                in>>brand;
                in>>model;
                in>>speed;
                in>>GearBox;
                return 1;
            }
            else{
                return 0;
            }
        }
        void get(ofstream& out){
            out<<brand<<" ";
            out<<model<<" ";
            out<<speed<<" ";
            out<<GearBox<<" ";
        }
        void copy(const car& B){
            brand = B.brand;
            model = B.model;
            speed = B.speed;
            GearBox = B.GearBox;
        }
        car& operator= (const car& B){
            copy(B);
            return *this;
        }

};
class cars{
    private:
        vector<car> catalog;
    public:
        void set(string filename,int size){
            ifstream fin(filename);
            car temp;
            for (int i = 0; i < size; i++){
                temp.set(fin);
                catalog.push_back(temp);
            }
        }
        void get(string filename){
            
            ofstream fout(filename);
            car temp;
            while (!catalog.empty()){
                temp = catalog.back();
                catalog.pop_back();
                temp.get(fout);
                fout<<"\n";
            }
        }

};

