#pragma once
#include <iostream>
#include <string>

using namespace std;

// Узел поискового дерева
template<class T>
class Node
{
private:
	T _value;        // Значение узла
	Node* left;      // Указатель на левого потомка
	Node* right;     // Указатель на правого потомка

public:
	// Конструктор по умолчанию
	Node() : _value(T()), left(nullptr), right(nullptr) {}

	// Конструктор с параметрами
	Node(T value){
		_value = value;
		left = nullptr;
		right = nullptr;
	}

	// Методы для установки потомков и значения узла
	void SetLeft(Node* t) { left = t; }
	void SetRight(Node* t) { right = t; }
	void SetValue(T value) { _value = value; }

	// Методы для получения значения узла и указателей на потомков
	T GetValue() { return _value; }
	Node* GetLeft() { return left; }
	Node* GetRight() { return right; }
};

// Представление бинарного поискового дерева
template<class T>
class Tree
{
private:
	Node<T>* head;  // Указатель на корень дерева

private:
	bool search(T value, Node<T>* node);  // Поиск значения в дереве
	void add(Node<T>* node, T value);      // Добавление значения в дерево
	void delete_tree(Node<T>* t);          // Рекурсивное удаление дерева

	void print_unordered(Node<T>* t, ostream& out, int& c);  // Вывод дерева в неупорядоченном порядке
	ostream& print_ordered(Node<T>* t, ostream& out);         // Вывод дерева в упорядоченном порядке
	void print_koncevoe(Node<T>* t, ostream& out);            // Вывод кронцевого обхода дерева
	Node<T>* RemoveNode(Node<T>* root, T x);                  // Удаление узла с заданным значением
	void copyTree(Node<T>* newNode, Node<T>* otherNode);     // Копирование дерева
	bool compareNodes(Node<T>* node1, Node<T>* node2);       // Сравнение узлов деревьев

	// Определение среднего арифметического элементов самой длинной ветви
	int leng(Node<T>* node, T& maxSum, int& maxLength);

public:
	Tree();                                   // Конструктор по умолчанию
	Tree(T value);                            // Конструктор с корневым значением
	Tree(Node<T>* node);                      // Конструктор с заданным корневым узлом
	Tree(const Tree& other);                  // Конструктор копирования
	~Tree();                                  // Деструктор

	void Lenght(ostream& out);                // Вывод среднего арифметического самой длинной ветви
	Node<T>* GetHead() { return head; }       // Получение указателя на корень дерева
	void SetHead(Node<T>* head_) { head = head_; }  // Установка нового корня дерева
	void print_unordered(ostream& out);       // Вывод дерева в неупорядоченном порядке
	ostream& print_ordered(ostream& out);     // Вывод дерева в упорядоченном порядке
	void print_koncevoe(ostream& out);        // Вывод кронцевого обхода дерева
	Tree* scan_file(string path);             // Создание дерева из файла

	Node<T>* RemoveNode(T x);                 // Удаление узла с заданным значением
	void add(T value);                        // Добавление значения в дерево
	bool search(T value);                     // Поиск значения в дереве
	Tree<T>& operator = (const Tree<T>& other);  // Перегрузка оператора присваивания
	bool operator == (const Tree<T>& other);      // Перегрузка оператора сравнения
};


//Вызов рекурсии поиска суммы самой длинной ветки
template<class T>
void Tree<T>::Lenght(ostream& out) {
	
	int c = 0;
	T maxS = 0;
	int maxL = 0;
	leng(head, maxS, maxL);
	double avg = (maxS * 1.0) / maxL;
	if (&out == &cout)
		cout << "Среднее самой длинной ветки: ";
	cout << avg << "\n";
}
//Рекурсия поиска суммы
template<class T>
int Tree<T>::leng(Node<T>* node, T& maxSum, int& maxLength){
	if (node == nullptr) {
		maxSum = 0;
		maxLength = 0;
		return 0;
	}

	//Рекурсивно ищем в левом и правом поддеревьях
	T leftSum, leftLength, rightSum, rightLength;
	leftSum = leng(node->GetLeft(), maxLength, leftLength);
	rightSum = leng(node->GetRight(), maxLength, rightLength);

	//Максимальная сумма между левым и правым поддеревьями плюс текущий узел
	maxLength = std::max(leftLength, rightLength) + 1;

	if (leftLength >= rightLength) {
		maxSum = leftSum + node->GetValue();
	}
	else {
		maxSum = rightSum + node->GetValue();
	}

	return maxSum;
}

//Конструктор по умолчанию
template<class T>
Tree<T>::Tree(){
	head = nullptr;
}
//Конструктор с заданием значения
template<class T>
Tree<T>::Tree(T value){
	Node<T>* node = new Node<T>(value);
	head = node;
}
//Конструктор с заданием узла
template<class T>
Tree<T>::Tree(Node<T>* node) { head = node; }
//Конструктор копирования
template<class T>
Tree<T>::Tree(const Tree& other){
	if (other.head == nullptr){
		head = nullptr;
	}
	else{
		head = new Node<T>(other.head->GetValue());
		copyTree(head, other.head);
	}
}
//Вызов рекурсивного удаления
template<class T>
Tree<T>::~Tree()
{
	delete_tree(head);
	head = nullptr;
}

//МЕТОДЫ ОБХОДА - вызов рекурсий
//Обратный (лево-корень-право)
template<class T>
void Tree<T>::print_unordered(ostream& out)
{
	if (&out == &cout)
		cout << "Обратный обход:\n"
			<< "Формат: |шаг рекурсии|узел (Главный узел)\n";

	int c = 0;
	print_unordered(head, out, c);
}
//Прямой (корень-лево-право)
template<class T>
ostream& Tree<T>::print_ordered(ostream& out)
{
	if (&out == &cout)
		cout << "Прямой обход:\n";
	return print_ordered(head, out);
}
//Концевой (лево-право-корень)
template<class T>
void Tree<T>::print_koncevoe(ostream& out)
{
	if (&out == &cout)
		cout << "Концевой обход: " << endl;
	print_koncevoe(head, out);

	if (&out == &cout)
		cout << endl;
}

//Чтение из файла
template<class T>
Tree<T>* Tree<T>::scan_file(string path)
{
	ifstream fin(path);
	T value;
	while (fin >> value)
	{
		this->add(value);
	}
	fin.close();
	return this;
}

//Рекурсия удаления дерева
template<class T>
void Tree<T>::delete_tree(Node<T>* t)
{
	if (t != NULL)
	{
		delete_tree(t->GetLeft());
		delete_tree(t->GetRight());
		delete t;
	}
}

//Рекурсии обходов:
//Рекурсия вывода обратным обходом
template<class T>
void Tree<T>::print_unordered(Node<T>* t, ostream& out, int &c)
{
	if (t != nullptr)
	{
		if (&out == &cout) {
			//Форматированный вывод с обозначением корня и глубины рекурсии
			int floor = c;
			c++;
			print_unordered(t->GetLeft(),out, c);
			if (floor == 0)
				cout << "(" << t->GetValue() << ") ";
			else
				cout << "|" << floor << "|" << t->GetValue() << " ";
			print_unordered(t->GetRight(), out, c);
		}
		else {
			print_unordered(t->GetLeft(), out, c);
			out << t->GetValue() << " ";
			print_unordered(t->GetRight(), out, c);
		}
	}
}
//Рекурсия вывода прямым обходом
template<class T>
ostream& Tree<T>::print_ordered(Node<T>* t, ostream& out)
{
	if (t != nullptr)
	{
		out << t->GetValue() << " ";
		print_ordered(t->GetLeft(), out);
		print_ordered(t->GetRight(), out);
	}
	return out;
}
//Рекурсия вывода концевым обходом
template<class T>
void Tree<T>::print_koncevoe(Node<T>* t, ostream& out)
{
	if (t != nullptr)
	{
		print_koncevoe(t->GetLeft(), out);
		print_koncevoe(t->GetRight(), out);
		out << t->GetValue() << " ";
	}
}

//Копирование
template<class T>
void Tree<T>::copyTree(Node<T>* newNode, Node<T>* otherNode){
	if (otherNode->GetLeft() != nullptr){
		newNode->SetLeft(new Node<T>(otherNode->GetLeft()->GetValue()));
		copyTree(newNode->GetLeft(), otherNode->GetLeft());
	}
	if (otherNode->GetRight() != nullptr){
		newNode->SetRight(new Node<T>(otherNode->GetRight()->GetValue()));
		copyTree(newNode->GetRight(), otherNode->GetRight());
	}
}

//Рекурсивное сравнение узлов
template<class T>
bool Tree<T>::compareNodes(Node<T>* node1, Node<T>* node2){
	if (node1 == nullptr && node2 == nullptr)
		return true;
	else if (node1 == nullptr || node2 == nullptr)
		return false;
	else if (node1->GetValue() != node2->GetValue())
		return false;
	else
		return ((compareNodes(node1->GetLeft(), node2->GetLeft())) && (compareNodes(node1->GetRight(), node2->GetRight())));
}
//Вызов рекурсии удаления узла
template<class T>
Node<T>* Tree<T>::RemoveNode(T x){
	head = RemoveNode(head, x);
	return head;
}
//Рекурсивный поиск ноды и последующим её удалением
template<class T>
Node<T>* Tree<T>::RemoveNode(Node<T>* root, T x)
{
	if (root == NULL)
		return NULL;
	if (x == root->GetValue()){
		Node<T>* t;
		if (root->GetLeft() == NULL){
			t = root->GetRight();
			delete root;
			return t;
		}
		t = root->GetLeft();
		while (t->GetRight()){
			t = t->GetRight();
		}
		t->SetRight(root->GetRight());
		t = root;
		root = root->GetLeft();
		delete t;
		return root;
	}
	if (x < root->GetValue())
		root->SetLeft(RemoveNode(root->GetLeft(), x));
	else
		root->SetRight(RemoveNode(root->GetRight(), x));
	return root;
}

//Вызов добавления узла
template<class T>
void Tree<T>::add(T value){
	if (head == nullptr){
		Node<T>* newNode = new Node<T>(value);
		head = newNode;
	}
	else if (value >= head->GetValue()){
		if (head->GetRight() != nullptr)
			add(head->GetRight(), value);
		else{
			Node<T>* newNode = new Node<T>(value);
			head->SetRight(newNode);
		}
	}
	else{
		if (head->GetLeft() != nullptr)
			add(head->GetLeft(), value);
		else{
			Node<T>* newNode = new Node<T>(value);
			head->SetLeft(newNode);
		}
	}
}
//Добавление узла
template<class T>
void Tree<T>::add(Node<T>* node, T value){
	if (head == nullptr){
		Node<T>* newNode = new Node<T>(value);
		head = newNode;
	}
	else if (value >= node->GetValue()){
		if (node->GetRight() != nullptr)
			add(node->GetRight(), value);
		else{
			Node<T>* newNode = new Node<T>(value);
			node->SetRight(newNode);
		}
	}
	else{
		if (node->GetLeft() != nullptr)
			add(node->GetLeft(), value);
		else{
			Node<T>* newNode = new Node<T>(value);
			node->SetLeft(newNode);
		}
	}
}


//Вызов рекурсивного поиска
template<class T>
bool Tree<T>::search(T value){
	while (head != NULL){
		if (value == head->GetValue())
			return true;
		else{
			if (value <= head->GetValue())
				return search(value, head->GetLeft());
			else
				return search(value, head->GetRight());
		}
	}
	return false;
}
//Рекурсивный поиск 
template<class T>
bool Tree<T>::search(T value, Node<T>* node){
	while (node != NULL){
		if (value == node->GetValue())
			return true;
		else{
			if (value <= node->GetValue())
				return search(value, node->GetLeft());
			else
				return search(value, node->GetRight());

		}
	}
	return false;
}

//Перегрузка оператора присваивания
template<class T>
Tree<T>& Tree<T>::operator=(const Tree<T>& other){
	if (this != &other){
		delete_tree(head);
		if (other.head == nullptr)
			head = nullptr;
		else
		{
			head = new Node<T>(other.head->GetValue());
			copyTree(head, other.head);
		}
	}
	return *this;
}
//Перегрузка оператора равенства
template<class T>
bool Tree<T>::operator==(const Tree<T>& other)
{
	return compareNodes(head, other.head);
}

//Перегрузка потоковых операторов:
template<class T>
ostream& operator << (ostream& out, Tree<T>& obj)
{
	int c = 0;
	obj.print_unordered(out);
	return out;
}
template<class T>
istream& operator >> (istream& in, Tree<T>& obj)
{
	T value;
	int n;
	cout << "Введите кол-во узлов: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		in >> value;
		obj.add(value);
	}
	return in;
}




//СБАЛАНСИРОВАННОЕ ДЕРЕВО

// Класс узла сбалансированного дерева
template<class T>
class BalancedNode : public Node<T>
{
private:
	int balance_factor; // Коэффициент балансировки
public:
	// Конструкторы
	BalancedNode() : Node<T>(), balance_factor(0) {}
	BalancedNode(T value) : Node<T>(value), balance_factor(0) {}

	// Методы для установки и получения коэффициента балансировки
	void SetBalanceFactor(int bf) { balance_factor = bf; }
	int GetBalanceFactor() { return balance_factor; }

	// Методы для установки потомков и значения узла
	void SetLeft(BalancedNode* t) { Node<T>::SetLeft(t); }
	void SetRight(BalancedNode* t) { Node<T>::SetRight(t); }
	void SetValue(T value) { Node<T>::SetValue(value); }

	// Методы для получения указателей на потомков
	BalancedNode* GetLeft() { return static_cast<BalancedNode*>(Node<T>::GetLeft()); }
	BalancedNode* GetRight() { return static_cast<BalancedNode*>(Node<T>::GetRight()); }
};

// Класс сбалансированного дерева
template<class T>
class BalancedTree : public Tree<BalancedNode<T>>
{
private:
	BalancedNode<T>* balancedHead; // Указатель на корень сбалансированного дерева

	// Приватные методы для балансировки дерева
	BalancedNode<T>* LeftRotation(BalancedNode<T>* node);
	BalancedNode<T>* RightRotation(BalancedNode<T>* node);
	BalancedNode<T>* LeftRightRotation(BalancedNode<T>* node);
	BalancedNode<T>* RightLeftRotation(BalancedNode<T>* node);
	void UpdateBalanceFactor(BalancedNode<T>* node);
	BalancedNode<T>* BalanceTree(BalancedNode<T>* node);

	// Приватные методы для добавления элемента, вывода дерева и вычисления высоты
	void Add(BalancedNode<T>* node, T value);
	void PrintTree(BalancedNode<T>* node, int& c);
	int GetHeight(BalancedNode<T>* node);

public:
	// Конструкторы и деструктор
	BalancedTree() : Tree<BalancedNode<T>>() {}
	BalancedTree(BalancedNode<T>* node) : Tree<BalancedNode<T>>(node) {}
	BalancedTree(const BalancedTree& other) : Tree<BalancedNode<T>>(other) {}
	~BalancedTree() {}

	// Методы для установки и получения указателя на корень дерева
	void SetHead(BalancedNode<T>* node) { balancedHead = node; }
	BalancedNode<T>* GetHead() { return balancedHead; }

	// Методы для добавления элемента и вывода дерева
	void Add(T value);
	void PrintTree();
};
//ПОВОРОТЫ
//Малый левый
template<class T>
BalancedNode<T>* BalancedTree<T>::LeftRotation(BalancedNode<T>* node)
{
	BalancedNode<T>* temp = node->GetRight();
	node->SetRight(temp->GetLeft());
	temp->SetLeft(node);
	return temp;
}
//Малый правый 
template<class T>
BalancedNode<T>* BalancedTree<T>::RightRotation(BalancedNode<T>* node)
{
	BalancedNode<T>* temp = node->GetLeft();
	node->SetLeft(temp->GetRight());
	temp->SetRight(node);
	return temp;
}
//Большой левый
template<class T>
BalancedNode<T>* BalancedTree<T>::LeftRightRotation(BalancedNode<T>* node){
	// Проверка наличия узла и его левого потомка
	if (node == nullptr || node->GetLeft() == nullptr){
		return node;
	}
	// Выполнение левого поворота для левого потомка
	node->SetLeft(LeftRotation(node->GetLeft()));
	// Выполнение правого поворота для исходного узла
	return RightRotation(node);
}
//Большой правый
template<class T>
BalancedNode<T>* BalancedTree<T>::RightLeftRotation(BalancedNode<T>* node){
	// Проверка наличия узла и его правого потомка
	if (node == nullptr || node->GetRight() == nullptr){
		return node;
	}
	// Выполнение правого поворота для правого потомка
	node->SetRight(RightRotation(node->GetRight()));
	// Выполнение левого поворота для исходного узла
	return LeftRotation(node);
}

//Обновление коэффициента балансировки 
template<class T>
void BalancedTree<T>::UpdateBalanceFactor(BalancedNode<T>* node)
{
	// Вычисление высоты левого и правого поддеревьев узла
	int leftHeight = GetHeight(node->GetLeft());
	int rightHeight = GetHeight(node->GetRight());

	// Обновление коэффициента балансировки
	// (разница высот правого и левого поддеревьев)
	node->SetBalanceFactor(rightHeight - leftHeight);
}

//Конструктор копирования
template<class T>
BalancedNode<T>* BalancedTree<T>::BalanceTree(BalancedNode<T>* node){
	UpdateBalanceFactor(node);
	int balanceFactor = node->GetBalanceFactor();
	if (balanceFactor > 1){
		if (node->GetRight()->GetBalanceFactor() < 0){
			return RightLeftRotation(node);
		}
		else{
			return LeftRotation(node);
		}
	}
	else if (balanceFactor < -1){
		if (node->GetLeft()->GetBalanceFactor() > 0){
			return LeftRightRotation(node);
		}
		else{
			return RightRotation(node);
		}
	}
	return node;
}
//Вызов рекурсивного добавления
template<class T>
void BalancedTree<T>::Add(T value)
{
	if (balancedHead == nullptr)
	{
		balancedHead = new BalancedNode<T>(value);
	}
	else
	{
		Add(balancedHead, value);
		balancedHead = BalanceTree(balancedHead);
	}
}

//Добавление узла
template<class T>
void BalancedTree<T>::Add(BalancedNode<T>* node, T value){
	if (node == nullptr){
		BalancedNode<T>* t = new BalancedNode<T>(value);
		node = t;
	}
	if (value < node->GetValue()){
		if (node->GetLeft() == nullptr){
			node->SetLeft(new BalancedNode<T>(value));
		}
		else{
			Add(node->GetLeft(), value);
			node->SetLeft(BalanceTree(node->GetLeft()));
		}
	}
	else if (value > node->GetValue()){
		if (node->GetRight() == nullptr){
			node->SetRight(new BalancedNode<T>(value));
		}
		else{
			Add(node->GetRight(), value);
			node->SetRight(BalanceTree(node->GetRight()));
		}
	}
}
//Вызов рекурсии вывода
template<class T>
void BalancedTree<T>::PrintTree()
{
	cout << "Обратный обход:\n"
		<< "Формат: |шаг рекурсии|узел (Главный узел)\n";
	int c = 0;
	return PrintTree(balancedHead, c);
}

//Вывод с форматированием: |шаг рекурсии|узел (Главный узел) |шаг рекурсии|узел
template<class T>
void BalancedTree<T>::PrintTree(BalancedNode<T>* node,int& c){
	if (node != nullptr){	
		//Форматированный вывод с обозначением корня и глубины рекурсии
		int floor = c;
		c++;
		PrintTree(node->GetLeft(), c);
		if (floor == 0)
			cout << "(" << node->GetValue() << ") ";
		else
			cout <<"|" << floor << "|" <<node->GetValue() << " ";
		PrintTree(node->GetRight(),c);
	}
}
//определение высоты
template<class T>
int BalancedTree<T>::GetHeight(BalancedNode<T>* node)
{
	if (node == nullptr)
		return 0;

	int leftHeight = GetHeight(node->GetLeft());
	int rightHeight = GetHeight(node->GetRight());

	return max(leftHeight, rightHeight) + 1;
}
