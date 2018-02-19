#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class FileOperation
{
public:
	void ReadFromFile();
	void PutTheLineIntoTheArray(char* pointer, int size, string line);
	void WriteToFile(char* pointer, int size, int sentenceLength[]);
};

int main()
{
	setlocale(LC_ALL, "hun");
	FileOperation instance;
	instance.ReadFromFile();
	system("PAUSE");
	return 0;
}


void FileOperation::ReadFromFile()
{
	ifstream source;
	string target;
	string concatenatedTarget;
	source.open("source.txt");
	int sentenceLength[100];
	int size = 0;
	int numberOfLinesInFile = 0;
	
	while (!source.eof())
	{
		getline(source, target);
		sentenceLength[numberOfLinesInFile] = target.length();
		numberOfLinesInFile++;
		cout << target << endl;
		size = size + target.length();
		concatenatedTarget = concatenatedTarget + target; //Concatenating
	}
	
	int z = 0;
	while (z<numberOfLinesInFile)
	{
		cout << "length of "<<z+1<<". sentence: "<<sentenceLength[z] << endl;
		z++;

	}
	char* pointer = new char[size];
	PutTheLineIntoTheArray(pointer, size, concatenatedTarget);
	WriteToFile(pointer, size, sentenceLength);
	delete[] pointer;
	source.close();
}

void FileOperation::PutTheLineIntoTheArray(char* pointer, int size, string concatenatedTarget)
{
	for (int i = 0; i < size; i++)
	{
		pointer[i] = concatenatedTarget[i];//Convert string to char
	}
	int j = 0;
	while (j < size)
	{
		cout << pointer[j] << endl;
		j++;
	}
}


void FileOperation::WriteToFile(char* pointer, int size, int sentenceLength[])
{
	ofstream outPutFile;
	outPutFile.open("target.txt");

	int i = 0;
	int k = 1;
	int sentenceLengthVariable = 0;

	cout <<"Total number of caharacters: "<< size << endl;



	while (i < size)
	{

		outPutFile << pointer[i];
		if (sentenceLength[sentenceLengthVariable] == k)
		{
			outPutFile << endl;
			sentenceLengthVariable++;
			i++;
			k = 1;
			outPutFile << pointer[i];
		}
		i++;
		k++;

	}
	outPutFile.close();
}
