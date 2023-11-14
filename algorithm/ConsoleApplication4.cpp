#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;
#include <chrono>

class File {
private:
	const char* Name;

	void directMerge(string in1, string in2, string out, int step, int& mergesCount) {					//������ �������
		//������ 2 ������� �����
		ifstream inFile1(in1), inFile2(in2);
		ofstream outFile(out);
		int a, b, i, j;
		inFile1 >> a;
		inFile2 >> b;
		while (!inFile1.eof() && !inFile2.eof()) {
			//���� � ��� ���� ��������
			i = 0;
			j = 0;
			while (i < step && j < step && !inFile1.eof() && !inFile2.eof()) {
				//������� ������ � ���� �� �������
				if (a < b) {
					outFile << a << " ";
					inFile1 >> a;
					i++;
				}
				else {
					outFile << b << " ";
					inFile2 >> b;
					j++;
				}
			}
			while (i < step && !inFile1.eof()) {
				outFile << a << " ";
				inFile1 >> a;
				i++;
			}
			while (j < step && !inFile2.eof()) {
				outFile << b << " ";
				inFile2 >> b;
				j++;
			}
		}
		while (!inFile1.eof()) {
			outFile << a << " ";
			inFile1 >> a;
		}
		while (!inFile2.eof()) {
			outFile << b << " ";
			inFile2 >> b;
		}
		inFile1.close();
		inFile2.close();
		outFile.close();
		mergesCount++;
	};

	void multiphaseMerge(const char* inName1, const char* inName2, const char* outName, int& compareCount) {			//������������ �������
		FILE* in1, * in2, * out, * temp;
		fopen_s(&in1, inName1, "r");
		fopen_s(&in2, inName2, "r");
		fopen_s(&out, outName, "w");
		int elem1, elem2, prev1, prev2;
		fscanf_s(in1, "%d", &elem1);
		fscanf_s(in2, "%d", &elem2);
		while (!feof(in1)) {
			bool isSeries1 = true, isSeries2 = true;
			while (isSeries1 && isSeries2) {
				compareCount++;
				if (elem1 < elem2) {
					fprintf_s(out, "%d ", elem1);
					prev1 = elem1;
					fscanf_s(in1, "%d", &elem1);
					if (elem1 < prev1 || feof(in1))
						isSeries1 = false;
				}
				else {
					fprintf_s(out, "%d ", elem2);
					prev2 = elem2;
					fscanf_s(in2, "%d", &elem2);
					if (elem2 < prev2 || feof(in2))
						isSeries2 = false;
				}
			}
			while (isSeries1 && !feof(in1)) {
				fprintf_s(out, "%d ", elem1);
				prev1 = elem1;
				fscanf_s(in1, "%d", &elem1);
				compareCount++;
				if (elem1 < prev1)
					isSeries1 = false;
			}
			while (isSeries2 && !feof(in2)) {
				fprintf_s(out, "%d ", elem2);
				prev2 = elem2;
				fscanf_s(in2, "%d", &elem2);
				compareCount++;
				if (elem2 < prev2)
					isSeries2 = false;
			}
		}
		fopen_s(&temp, "temp_.txt", "w");
		while (!feof(in2)) {
			fprintf_s(temp, "%d ", elem2);
			fscanf_s(in2, "%d", &elem2);
		}
		fclose(in1);
		fclose(in2);
		fclose(out);
		fclose(temp);
		fopen_s(&temp, "temp_.txt", "r");
		fopen_s(&in2, inName2, "w");
		while (fscanf_s(temp, "%d", &elem1) != EOF)
			fprintf_s(in2, "%d ", elem1);
		fclose(in2);
		fclose(temp);
		remove("temp_.txt");
	};

	int* findMultiphaseParams() {					//����� ��� � ���� ����� ����� � ������� ������������������ ���������
		FILE* source;
		fopen_s(&source, Name, "r");
		int current, prev, countSeries = 1;
		fscanf_s(source, "%d", &current);
		while (!feof(source)) {
			prev = current;
			fscanf_s(source, "%d", &current);
			if (current < prev)
				countSeries++;
		}
		fclose(source);
		int minSeries = 0, maxSeries = 1, nextFibonachiNum = 1, deep = 0;
		while (nextFibonachiNum < countSeries) {
			minSeries = maxSeries;
			maxSeries = nextFibonachiNum;
			nextFibonachiNum = minSeries + maxSeries;
			deep++;
		}
		return new int[3] {minSeries, (minSeries + maxSeries) - countSeries, deep};
	};

public:

	void random(int l, int r, int size) {				//���������
		FILE* out;
		fopen_s(&out, Name, "w");
		srand(time(0));
		for (int i = 0; i < size; i++) {
			int random = rand() % (r - l + 1) + l;
			fprintf_s(out, "%d ", random);
		}
		fclose(out);
	};

	void posledovat(int size) {							//����������������
		FILE* out;
		fopen_s(&out, Name, "w");
		for (int i = 0; i < size; i++) {
			fprintf_s(out, "%d ", i);
		}
		fclose(out);
	};

	void obrat(int size) {								//�������� �������
		FILE* out;
		fopen_s(&out, Name, "w");
		for (int i = size; i > 0; i--) {
			fprintf_s(out, "%d ", i);
		}
		fclose(out);
	};

	File(const char* _Name) : Name(_Name) {};	//�����������

	void directMergeSort(int& compareCount, int& mergesCount) {					//���������� ������ ��������
		int elem, size = 0;
		ifstream out(Name);
		while (out >> elem) {
			size++;
		}
		cout<<size<<" N\n";
		out.close();
		for (int step = 1; step < size; step *= 2) {
			//������� ������� ������ ��� ������� �������
			ifstream out(Name);
			ofstream temp1("temp1.txt"), temp2("temp2.txt");
			out >> elem;
			while (!out.eof()) {
				for (int i = 0; i < step && !out.eof(); i++) {
					temp1 << elem << " ";
					out >> elem;
				}
				for (int j = 0; j < step && !out.eof(); j++) {
					temp2 << elem << " ";
					out >> elem;
				}
			}
			if (step == 1)
				temp2 << elem << " ";
			out.close();
			temp1.close();
			temp2.close();
			directMerge("temp1.txt", "temp2.txt", Name, step, mergesCount);
		}
		remove("temp1.txt");
		remove("temp2.txt");
	};
	void multiphaseSort(int& compareCount, int& mergesCount) {						//������������ ����������
		const int* sortParams = findMultiphaseParams();
		mergesCount = sortParams[2] - 1;
		FILE* source, * firstPart, * secondPart;
		fopen_s(&source, Name, "r");
		fopen_s(&firstPart, "temp0.txt", "w");
		const char* tempFileNames[][3] = { {"temp0.txt", "temp1.txt", "temp2.txt"}, {"temp1.txt", "temp2.txt", "temp0.txt"}, {"temp2.txt", "temp0.txt", "temp1.txt"} };
		int elem, prev, seriesIndex = 0, mergeCount;
		fscanf_s(source, "%d", &elem);
		while (seriesIndex != sortParams[0]) {
			prev = elem;
			fprintf_s(firstPart, "%d ", elem);
			fscanf_s(source, "%d", &elem);
			if (elem < prev)
				seriesIndex++;
		}
		fclose(firstPart);
		fopen_s(&secondPart, "temp1.txt", "w");
		while (!feof(source)) {
			fprintf_s(secondPart, "%d ", elem);
			fscanf_s(source, "%d", &elem);
		}
		fprintf_s(secondPart, "%d ", elem);
		fclose(source);
		for (int i = sortParams[1]; i > 0; i--) {
			fprintf_s(secondPart, "%d ", 0);
			fprintf_s(secondPart, "%d ", 1);
		}
		fclose(secondPart);
		for (mergeCount = 0; mergeCount < sortParams[2]; mergeCount++) {
			multiphaseMerge(tempFileNames[mergeCount % 3][0], tempFileNames[mergeCount % 3][1], tempFileNames[mergeCount % 3][2], compareCount);
		}
		int null = sortParams[1];
		int one = null;
		if ((mergeCount - 1) % 3 == 0)
			fopen_s(&firstPart, "temp2.txt", "r");
		else if ((mergeCount - 1) % 3 == 1)
			fopen_s(&firstPart, "temp0.txt", "r");
		else
			fopen_s(&firstPart, "temp1.txt", "r");
		fopen_s(&source, Name, "w");
		while (fscanf_s(firstPart, "%d", &elem) != EOF) {
			if (elem == 0 && null > 0) {
				continue;
				null--;
			}
			if (elem == 1 && one > 0) {
				one--;
				continue;
			}
			fprintf_s(source, "%d ", elem);
		}
		fclose(firstPart);
		fclose(source);
		remove("temp0.txt");
		remove("temp1.txt");
		remove("temp2.txt");
		delete[] sortParams;
	};
};


int main() {
	system("chcp 1251");

	auto start = chrono::steady_clock::now(), end = chrono::steady_clock::now();
	int sortMode, Mode, Size1, Size2, step, mode, size, l, r;
	cout << "�������� ����� ������:\n";
	cout << "1) ���������� ����� ������, �������������� ��������� �������" << endl << "2) ����� ���������� �������������� ������" << endl;
	cin >> mode;
	switch (mode) {
	case 1: {
		int compareCount = 0, mergesCount = 0;
		File single("sorted.txt");
		cout << "������� ���-�� ��������� � �����: " << endl;
		cin >> size;
		cout << "������� ������� ��������� ��������� (�����_������): " << endl;
		cin >> l >> r;
		single.random(l, r, size);
		cout << "�������� ����� ����������: \n";
		cout << "1) ������ �������" << endl;
		cout << "2) ������������ ����������" << endl;
		cin >> sortMode;
		if (sortMode == 1) {
			start = chrono::steady_clock::now();
			single.directMergeSort(compareCount, mergesCount);
			end = chrono::steady_clock::now();
		}
		else if (sortMode == 2) {
			compareCount = 2 * size;
			start = chrono::steady_clock::now();
			single.multiphaseSort(compareCount, mergesCount);
			end = chrono::steady_clock::now();
		}
		cout << "���������� ���������: " << compareCount << endl;
		cout << "���������� �������: " << mergesCount << endl;
		cout << "����� ����������: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
		break;
	}
	case 2: {
		File testFile("test.txt");
		int null1 = 0, null2 = 0;
		cout << "C������� ������������ �����: " << endl;
		cout << "1) ���������" << endl;
		cout << "2) ������������� ��������" << endl;
		cout << "3) �������� �������" << endl;
		cin >> Mode;
		cout << "������� ���������,�������� ������, ���" << endl;
		cin >> Size1 >> Size2 >> step;
		cout << "�������� ����� ����������: \n";
		cout << "1) ������ �������" << endl;
		cout << "2) ������������ ����������" << endl;
		cin >> sortMode;
		ofstream stat("stat.txt");
		if (sortMode == 1) {
			if (Mode == 1) {
				cout << "������� ������� ��������� ��������� (�����_������): " << endl;
				cin >> l >> r;
				for (int i = Size1; i < Size2; i += step) {
					testFile.random(l, r, i);
					start = chrono::steady_clock::now();
					testFile.directMergeSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
			else if (Mode == 2) {
				for (int i = Size1; i < Size2; i += step) {
					testFile.posledovat(i);
					start = chrono::steady_clock::now();
					testFile.directMergeSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
			else if (Mode == 3) {
				for (int i = Size1; i < Size2; i += step) {
					testFile.obrat(i);
					start = chrono::steady_clock::now();
					testFile.directMergeSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
		}
		else if (sortMode == 2) {
			if (Mode == 1) {
				cout << "������� ������� ��������� ��������� (�����_������): " << endl;
				cin >> l >> r;
				for (int i = Size1; i < Size2; i += step) {
					testFile.random(l, r, i);
					start = chrono::steady_clock::now();
					testFile.multiphaseSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
			else if (Mode == 2) {
				for (int i = Size1; i < Size2; i += step) {
					testFile.posledovat(i);
					start = chrono::steady_clock::now();
					testFile.multiphaseSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
			else if (Mode == 3) {
				for (int i = Size1; i < Size2; i += step) {
					testFile.obrat(i);
					start = chrono::steady_clock::now();
					testFile.multiphaseSort(null1, null2);
					end = chrono::steady_clock::now();
					if (stat.good())
						stat << "������: " << i << " �����: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " mcs" << endl;
				}
			}
		}
		stat.close();
		break;
	}
	}
	return 0;
}
