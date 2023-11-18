#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Класс узла
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

//Класс списка
template<class T>
class List
{
	Node<T>* begin_;
	Node<T>* end_;
	int size_;
public:
    //Конструкторы, деструкторы и операторы
	List():begin_(nullptr), end_(nullptr), size_(0){}
    List(int S):size_(S){}
	List(const List& obj) { Copy(obj); }
	List<T>& operator = (const List& obj) { Copy(obj); return *this; }
	~List() { Clear(); }

    //Доступ к полю размера
    int size() { return size_; }

    //Потоковый ввод
    void set(istream& input, int size){
        int value;
        if (&input == &cin){
            cout<<"Введите элементы через пробел:\n";
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
                    cout<<"Найден элемент №"<<i<<":"<<" "<<value<<"\n";
                c++;
            }
        }
        if (!echo){
            if (c)
                cout<<"Всего таких элементов "<<c<<".\n";
            else
                cout<<"Не найдено ни одного такого элемента.\n";
        }
        return c;
        
    }
    //Потоковый вывод
    void get(ostream& out){
        if (size_ == 0 && &out == &cout){
            cout<<"Пустой список.\n";
        }
        else{
            if (&out == &cout)
                cout<<"Список длинной " <<size_<<":\n";
            Node<T>* t = begin_;
            for (int i = 0; i < size_; i++){
                out << t->Value() << " ";
                t = t->Next();
            }
            out << "\n";
        }
	}

    //Добавить в начало списка
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

    //Добавить в конец списка
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

    //Добавить по индексу
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

    //Доступ к элементу по индексу
	Node<T>* getIndex(int index){
		Node<T>* t = begin_;
		for (int i = 0; i < index; i++)
			t = t->Next();
		return t;
	}

    //Доступ к значению элемента по индексу
	T GetValue(int index){
		Node<T>* t = getIndex(index);
		return t->Value();
	}

    //Удалить элемент по индексу
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
	
    //Удалить начальный элемент
	void Delete_start() { return DelIndex(0); }

    //Удалить конечный элемент
	void Delete_end() { return DelIndex(size_ - 1); }

    //Удалить список
	void Clear(){
		int n = size_;
		for (int i = 0; i < n; i++)
			DelIndex(0);
	}

    //Метод копирования списков
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