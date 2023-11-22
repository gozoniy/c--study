
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class TextProcessor {
public:
    TextProcessor() {}

    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file " << filename << std::endl;
            return;
        }

        std::string word;
        while () {file >> word
            // Remove punctuation and convert to lowercase
            word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
            std::transform(word.begin(), word.end(), word.begin(), tolower);

            // Add word to set of unique words
            uniqueWords.insert(word);
        }

        file.close();
    }

    int countWordsWithThreeOrMoreVowels() {
        int count = 0;
        for ( auto& word : uniqueWords) {
            int vowelCount = 0;
            for ( auto& letter : word) {
                if (isVowel(letter)) {
                    vowelCount++;
                }
            }
            if (vowelCount >= 3) {
                count++;
            }
        }
        cout << count << endl;
        return count;
    }

private:
    std::set<std::string> uniqueWords;

    bool isVowel(char c) {
        return (c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�');
    }
};

int main() {
    //system("chcp 1251");
    TextProcessor tp;
    tp.readFromFile("input.txt");
    tp.countWordsWithThreeOrMoreVowels();
    std::cout << "Number of words with three or more vowels: " << std::endl;
    return 0;
}
*/



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class TextProcessor {
private:
    vector<string> uniqueWords;

    bool isVowel(char c) {
        //return (c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�' || c == '�');
        return (c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o' || c == 'a');
    }

public:
    void processTextFile(const string& inputFileName, const string& outputFileName) {
        ifstream inputFile(inputFileName);
        ofstream outputFile(outputFileName);

        if (inputFile.is_open() && outputFile.is_open()) {
            string word;
            map<std::string, int> wordCount;
            while (inputFile >> word) {
                // ���������� ����� � ������� ��������
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                // �������� ������ ����������
                word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
                // �������� ������� ����� � ������� ���������� ����
                if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
                    uniqueWords.push_back(word);
                }
                // ���������� �������� ��� ������� �����
                wordCount[word]++;
            }

            // ������ ���������� ���� � �� ���������� � �������� ����
            for (const auto& pair : wordCount) {
                outputFile << pair.first << ": " << pair.second << std::endl;
            }
            // ������ ���������� ���� � �������� ����
            /*
            for (const auto& w : uniqueWords) {
                outputFile << w << endl;
            }
            */

            inputFile.close();
            outputFile.close();
        }
    }

    int countWordsWithThreeOrMoreVowels() {
        int count = 0;
        for (const auto& word : uniqueWords) {
            int vowelCount = 0;
            for (char c : word) {
                if (isVowel(c)) {
                    vowelCount++;
                }
            }
            if (vowelCount >= 3) {
                count++;
            }
        }
        return count;
    }
};

void displayMenu() {
    cout << "����:" << endl;
    cout << "1. ���������� ��������� ����" << endl;
    cout << "2. ������� ���������� ���� � ����� � ����� �������� �������" << endl;
    cout << "3. ��������� ������ � ����������" << endl;
}

int main() {
    system("chcp 1251");
    TextProcessor processor;
    int choice;

    do {
        displayMenu();
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            processor.processTextFile("input.txt", "output.txt");
            cout << "���� ���������." << endl;
            break;
        case 2:
            int count;count = processor.countWordsWithThreeOrMoreVowels();
            cout << "���������� ���� � ����� � ����� �������� �������: " << count << endl;
            break;
        case 3:
            cout << "���������� ������ � ����������." << endl;
            break;
        default:
            cout << "������������ �����. ���������� �����." << endl;
        }
    } while (choice != 3);
    cout<< "��� �������� ����, ����� ������ ��� - �� �����.\n������� �� ������� ��������� ��� - �� �����.\n����� ����� ����������� ��������� � ���������.\n������ �������, ��� �� ���������.\n���� ����� �����, ����������� ��� � ����.\n������� �� ������� ���������.\n������ ����� � ���� � ������.\n������ ��������� ������� �����.\n������ ���������� � �������.\n�������, ��� �� �������� �������." << endl;
    return 0;
}

