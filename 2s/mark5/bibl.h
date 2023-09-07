using namespace std;

struct student
{
	char Fio[80];
	char grade[10];
};
struct Node
{
	student S;
	Node *Next;
	Node *Prev;
};
void setStudent(student &student)
{
	cin.ignore();
	cout<<"Введите ФИО ученика:\n";
	cin.getline(student.Fio,80);
	cout<<"Введите класс ученика:\n";
	cin>>student.grade;
	return;
}
void readStudent(student &student)
{
	cout<<"ФИО ученика: "<<student.Fio<<endl;
	cout<<"Класс ученика: "<<student.grade<<endl;
	return;
}
Node* first(void)
{
	Node* pv=new Node;
	cout<<"Введите данные первого ученика\n";
	setStudent(pv->S);
	pv->Next=0;
	pv->Prev=0;
	return pv;
}
Node* add(Node* pEnd)
{
	Node* pv=new Node;
	if (pEnd!=NULL)
	{
		cout << "Введите данные нового ученика\n";
		setStudent(pv->S);
		pv->Next = 0;
		pv->Prev = pEnd;
		pEnd->Next = pv;
	}
		return pv;
}
void del(Node* &pBegin)
{
	Node* pv=pBegin;
	if(pv==NULL)
		return;
	while(pv!=NULL)
	{
		pBegin = pBegin->Next;
		delete(pv);
		pv = pBegin;
	}
	
}
void search(Node* pBegin)
{
	char word[80];
	cout << "Введите ключевое поле элемента списка: ";
	cin.ignore();
	cin.getline(word, 80);
	Node* pv;
	for (pv = pBegin; pv != 0; pv = pv->Next)
		if (!(strcmp(pv->S.Fio, word)) || !(strcmp(pv->S.grade, word)))
			cout <<  &pv << endl;
}
void print(Node* pBegin)
{
	Node* pv;
	for(pv=pBegin;pv!=0;pv=pv->Next)
		readStudent(pv->S);
}
void print_back(Node* pEnd)
{
	Node* pv;
	for(pv=pEnd;pv!=0;pv=pv->Prev)
		readStudent(pv->S);
}
void setArr(student *students, int N)
{
	for (int i=0; i<N;i++)
	{
		cout<<"Введите данные об ученике №"<<i+1<<endl;
		setStudent(students[i]);
	}
}
void readArr(student *students, int N)
{
	for(int i=0;i<N;i++)
	{
	cout<<"Ученик №"<<i+1<<endl;
	readStudent(students[i]);
	}
}
bool same_grade(student *students,int N,int *mount,char grade_num[10] )
{
	bool prov=false;
	int count = 0; 
	for(int i=0;i<N;i++)
	{
		if (!(strcmp(students[i].grade,grade_num)))
			{
				cout<<students[i].Fio<<endl;
				prov=true;
				count++;
			}
	}
	*mount=count;
	return prov;
}