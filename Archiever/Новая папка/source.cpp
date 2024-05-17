#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "zlib.h"

// Функция для сжатия данных с использованием zlib
std::vector<unsigned char> compressData(const std::vector<unsigned char>& data) {
    z_stream stream;
    memset(&stream, 0, sizeof(stream));
    deflateInit(&stream, Z_DEFAULT_COMPRESSION);

    std::vector<unsigned char> compressedData(1024, 0);
    stream.next_in = const_cast<unsigned char*>(data.data());
    stream.avail_in = static_cast<uInt>(data.size());
    stream.next_out = compressedData.data();
    stream.avail_out = static_cast<uInt>(compressedData.size());

    deflate(&stream, Z_FINISH);
    deflateEnd(&stream);

    compressedData.resize(stream.total_out);
    return compressedData;
}

// Функция для упаковки файлов в ZIP-архив
void packFiles(const std::vector<std::string>& filenames, const std::string& archiveName) {
    std::ofstream archive(archiveName, std::ios::binary);
    if (!archive.is_open()) {
        std::cerr << "Failed to create archive: " << archiveName << std::endl;
        return;
    }

    for (const auto& filename : filenames) {
        std::ifstream file(filename, std::ios::binary);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            continue;
        }

        // Читаем содержимое файла
        std::vector<unsigned char> fileData((std::istreambuf_iterator<char>(file)),
                                             std::istreambuf_iterator<char>());

        // Сжимаем содержимое файла
        std::vector<unsigned char> compressedData = compressData(fileData);

        // Записываем имя файла и сжатые данные в архив
        size_t nameLen = filename.size();
        archive.write(reinterpret_cast<const char*>(&nameLen), sizeof(size_t));
        archive.write(filename.c_str(), nameLen);
        size_t compressedSize = compressedData.size();
        archive.write(reinterpret_cast<const char*>(&compressedSize), sizeof(size_t));
        archive.write(reinterpret_cast<const char*>(compressedData.data()), compressedSize);

        file.close();
    }

    archive.close();
    std::cout << "Archive created successfully: " << archiveName << std::endl;
}

int main() {
    // Упаковываем файлы в ZIP-архив
    std::vector<std::string> filesToPack = {"file1.txt", "file2.txt", "file3.txt"};
    packFiles(filesToPack, "archive.zip");

    return 0;
}