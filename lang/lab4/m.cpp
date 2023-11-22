
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
        return (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
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
        //return (c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' || c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я');
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
                // Приведение слова к нижнему регистру
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                // Удаление знаков препинания
                word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
                // Проверка наличия слова в массиве уникальных слов
                if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
                    uniqueWords.push_back(word);
                }
                // Увеличение счетчика для данного слова
                wordCount[word]++;
            }

            // Запись уникальных слов и их количества в выходной файл
            for (const auto& pair : wordCount) {
                outputFile << pair.first << ": " << pair.second << std::endl;
            }
            // Запись уникальных слов в выходной файл
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
    cout << "Меню:" << endl;
    cout << "1. Обработать текстовый файл" << endl;
    cout << "2. Вывести количество слов с тремя и более гласными буквами" << endl;
    cout << "3. Закончить работу с программой" << endl;
}

int main() {
    system("chcp 1251");
    TextProcessor processor;
    int choice;

    do {
        displayMenu();
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            processor.processTextFile("input.txt", "output.txt");
            cout << "Файл обработан." << endl;
            break;
        case 2:
            int count;count = processor.countWordsWithThreeOrMoreVowels();
            cout << "Количество слов с тремя и более гласными буквами: " << count << endl;
            break;
        case 3:
            cout << "Завершение работы с программой." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 3);
    cout<< "Это отличный день, чтобы начать что - то новое.\nНикогда не бойтесь пробовать что - то новое.\nЖизнь полна неожиданных поворотов и сюрпризов.\nВсегда помните, что вы уникальны.\nВаше время ценно, используйте его с умом.\nНикогда не забывай улыбаться.\nБудьте добры к себе и другим.\nЦените маленькие радости жизни.\nВсегда стремитесь к лучшему.\nПомните, что вы достойны счастья." << endl;
    return 0;
}

