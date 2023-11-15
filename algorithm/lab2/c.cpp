void directMergeSort(string filename, int size) {					//сортировка прямым слиянием
		int elem;
		for (int i = 1; i < size; i *= 2) {
			//делим файлы для слияния
			ifstream out(filename);
			ofstream temp1("buffer1.txt"), temp2("buffer2.txt");
			out >> elem;
			while (!out.eof()) {
				for (int I = 0; I < i && !out.eof(); I++) {
					temp1 << elem << " ";
					out >> elem;
				}
				for (int j = 0; j < i && !out.eof(); j++) {
					temp2 << elem << " ";
					out >> elem;
				}
			}
			if (i == 1)
				temp2 << elem << " ";
			out.close();
			temp1.close();
			temp2.close();
            //Слияние
			ifstream inFile1("buffer1.txt"), inFile2("buffer2.txt");
            ofstream outFile(filename);
            int a, b, I, j;
            inFile1 >> a;
            inFile2 >> b;
            while (!inFile1.eof() && !inFile2.eof()) {
                //Сливаем пока в файлах есть элементы
                I = 0;
                j = 0;
                while (I < i && j < i && !inFile1.eof() && !inFile2.eof()) {
                    //слияние файлов в один по размеру
                    if (a < b) {
                        outFile << a << " ";
                        inFile1 >> a;
                        I++;
                    }
                    else {
                        outFile << b << " ";
                        inFile2 >> b;
                        j++;
                    }
                }
                while (I < i && !inFile1.eof()) {
                    outFile << a << " ";
                    inFile1 >> a;
                    I++;
                }
                while (j < i && !inFile2.eof()) {
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

            }
		remove("buffer1.txt");
		remove("buffer2.txt");
}