#pragma once
#ifndef DEALER_H
#define DEALER_H

class car{
    private:
        string brand; // ����� ����������
        string model; // ������ ����������
        int speed; // �������� ����������
        char GearBox; // 1 ����� ������� ������� ����������
    public:
        // ���������� �������� �� �������� ������
        void set(istream& in);
        // �������� �������� � �������� �����
        void get(ostream& out) const;
        // �������� ��� ������� �������
        char getT() const { return GearBox; }
        // �������� ��������
        int getS() const { return speed; }
        // ����������� �������� �� ������� ������� car
        void copy(const car& B);
        // ���������� ��������� ������������
        car& operator= (const car& B){ copy(B); return *this; }
        // ���������� ��������� ������
        bool operator<(const car& B) const;
        // ���������� ��������� ������ � �����
        friend ostream& operator<<(ostream&, const car& B);
        // ���������� ��������� ����� �� ������
        friend istream& operator>>(istream&, car&);
};

class dealer{
    private:
        vector<car> catalogA; // ������� ����������� � ���������
        vector<car> catalogM; // ������� ����������� � ���������
    public:
        // �������� ��������
        void Clear();
        // ������������� ������� �� ��������
        void sortS();
        // ���������� �������� �� �������� ������
        istream& set(istream& in);
        // �������� �������� � �������� �����
        ostream& get(ostream& out) const;
        // ������� ��� 5 �����������
        ostream& top5(ostream& out);
};

#endif //DEALER_H
