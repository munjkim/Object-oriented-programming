#include<iostream>
#include<string.h>
using namespace std;

char** copy_replace(const char* sentences[], const char original_char, const char new_char, int num_of_sentence)
{
	char* buffer;
	char** container = new char* [num_of_sentence];

	for (int i = 0; i < num_of_sentence; i++)
	{
		buffer = new char[strlen(sentences[i])];
		for (int j = 0; j < strlen(sentences[i]); j++)
		{
			if (*(sentences[i] + j) == original_char)
				buffer[j] = new_char;
			else
				buffer[j] = *(sentences[i] + j);
		}
		buffer[strlen(sentences[i])] = '\0';
		container[i] = buffer;
		
		cout << typeid(buffer).name() << endl;
		cout << typeid(container).name() << endl;
		//delete[] buffer;
	}

	return container;
}
int main()
{
	//double은 8byte

	double** p_arr = new double* [10];
	//double*는 4byte이고 10개이므로 40바이트

	for (int i = 0; i < 10; i++)
	{
		p_arr[i] = new double[5];
	}
	//double은 8byte이고 5개인데 10번 총 400byte
	//따라서 440바이트
	
	for (int i = 0; i < 5; i++)
		delete[] p_arr[i];
	delete[] p_arr;
	//-------------------------------

	const char* sentence[] = { "Hello World", "Hi World", "Heyo World" };
	int num_of_sentence = 3;

	char** p_result = copy_replace(sentence, 'o', 'x', num_of_sentence);

	cout << sentence[0] << endl;
	cout << sentence[1] << endl;
	cout << sentence[2] << endl;

	cout << p_result[0] << endl;
	cout << p_result[1] << endl;
	cout << p_result[2] << endl;

	return 0;
}