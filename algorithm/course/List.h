#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//����� ����
template<class T>
class Node
{
        T value;
        Node<T>* next;
        Node<T>* prev;
    public:
        T Value() { return value; }
        void Set(T _value) {value = _value;}
        Node<T>* Next() { return next; }
        void SetNext(Node<T>* _next) {next = _next;}
        Node<T>* Prev() { return prev; }
        void SetPrev(Node<T>* _prev) {prev = _prev;}
};

//����� ������
template<class T>
class List
{
	Node<T>* begin_;
	Node<T>* end_;
	int size_;
public:
    //������������, ����������� � ���������
	List():begin_(nullptr), end_(nullptr), size_(0){}
    List(int S):size_(S){}
	List(const List& obj) { Copy(obj); }
	List<T>& operator = (const List& obj) { Copy(obj); return *this; }
	~List() { Clear(); }

    //������ � ���� �������
    int size() { return size_; }

    //��������� ����
    void set(istream& input, int size){
        int value;
        if (&input == &cin){
            cout<<"������� �������� ����� ������:\n";
        }
        for (int i = 0; i < size; i++){
            input >> value;
            setEnd(value);
        }
    }

    int search(T value, bool echo){
        int c = 0;
        for (int i = 0; i < size_; i++){
            if (GetValue(i) == value){
                if(!echo)
                    cout<<"������ ������� �"<<i<<":"<<" "<<value<<"\n";
                c++;
            }
        }
        if (!echo){
            if (c)
                cout<<"����� ����� ��������� "<<c<<".\n";
            else
                cout<<"�� ������� �� ������ ������ ��������.\n";
        }
        return c;
        
    }
    //��������� �����
    void get(ostream& out){
        if (size_ == 0 && &out == &cout){
            cout<<"������ ������.\n";
        }
        else{
            if (&out == &cout)
                cout<<"������ ������� " <<size_<<":\n";
            Node<T>* t = begin_;
            for (int i = 0; i < size_; i++){
                out << t->Value() << " ";
                t = t->Next();
            }
            out << "\n";
        }
	}

    //�������� � ������ ������
	void setBegin(T _value){
        Node<T>* t = new Node<T>;
        t->Set(_value);
        t->SetPrev(nullptr);
        t->SetNext(begin_);

        if (size_ > 0){
            begin_->SetPrev(t);
            begin_ = t;
        }
        else{
            begin_ = end_ = t;
        }
        size_++;
	}

    //�������� � ����� ������
	void setEnd(T _value){
        Node<T>* t = new Node<T>;
        t->Set(_value);
        t->SetPrev(end_);
        t->SetNext(nullptr);
        if (end_ != nullptr)
            end_->SetNext(t);
        if (size_ == 0)
            begin_ = end_ = t;
        else{
            end_ = t;
        }
        size_++;
	}

    //�������� �� �������
	void setIndex(int index, T _value){
		if (index == size_){
			setEnd(_value);
			return;
		}
		if (index == 0){
			setBegin(_value);
			return;
		}
        Node<T>* itemPrev = getIndex(index - 1);
        Node<T>* item = getIndex(index);
        Node<T>* t = new Node<T>;
        t->Set(_value);
        t->SetNext(item);
        t->SetPrev(itemPrev);
        itemPrev->SetNext(t);
        item->SetPrev(t);
        size_++;
	}

    //������ � �������� �� �������
	Node<T>* getIndex(int index){
		Node<T>* t = begin_;
		for (int i = 0; i < index; i++)
			t = t->Next();
		return t;
	}

    //������ � �������� �������� �� �������
	T GetValue(int index){
		Node<T>* t = getIndex(index);
		return t->Value();
	}

    //������� ������� �� �������
	void DelIndex(int index){
		Node<T>* item = getIndex(index);
		Node<T>* itemPrev = item->Prev();
		Node<T>* itemNext = item->Next();
		if ((size_ > 1) && (itemPrev != nullptr))
			itemPrev->SetNext(itemNext);
		if ((itemNext != nullptr) && (size_ > 1))
			itemNext->SetPrev(itemPrev);
		if (index == 0)
			begin_ = itemNext;
		if (index == size_ - 1)
			end_ = itemPrev;
		delete item;
		size_--;
	}
	
    //������� ��������� �������
	void Delete_start() { return DelIndex(0); }

    //������� �������� �������
	void Delete_end() { return DelIndex(size_ - 1); }

    //������� ������
	void Clear(){
		int n = size_;
		for (int i = 0; i < n; i++)
			DelIndex(0);
	}

    //����� ����������� �������
	void Copy(const List<T>& obj){
		Clear();
		Node<T>* t = obj.begin;
		while (t != nullptr){
			setBegin(t->Value());
			t = t->Next();
		}
	}

    

	
};

#endif