#pragma once

class car{
    private:
        string brand;
        string model;
        int speed;
        char GearBox;
    public:
        void set(istream& in);
        void get(ostream& out);
        char getT();
        int getS();
        void copy(const car& B);
        car& operator= (const car& B){copy(B);return *this;}
        bool operator<(const car& B);
        
        friend ostream& operator<<(ostream&, car&);
        friend istream& operator>>(istream&, car&);


};
class dealer{
    private:
        vector<car> catalogA;
        vector<car> catalogM;
    public:
        void Clear();
        void sortS();
        istream& set(istream& in);
        ostream& get(ostream& out);
        ostream& top5(ostream& out);
        
};


