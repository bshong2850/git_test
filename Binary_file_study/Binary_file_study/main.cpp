#include <iostream>
#include <fstream>

using namespace std;

bool ReadFile(string filePath, unsigned char **_data, int *datalen)
{
	ifstream is(filePath, ifstream::binary);

	if (is)
	{
		is.seekg(0, is.end);
		int length = (int)is.tellg();
		is.seekg(0, is.beg);

		unsigned char * buffer = (unsigned char*)malloc(length);

		is.read((char*)buffer, length);
		is.close();
		*_data = buffer;
		*datalen = length;
		return true;
	}
	else
		return false;
}

int WriteToFile(string filePath, unsigned char* data, int data_len)
{
	ofstream fout;
	fout.open(filePath, ios::out | ios::binary);

	if (fout.is_open())
	{
		fout.write((const char*)data, data_len);
		fout.close();
	}
	return 0;
}

int main()
{
	/*string filepath = "cube_binary.stl";
	unsigned char ** data;
	int *data_len = 0;
	cout << "test" << endl;
	if (ReadFile(filepath, data, data_len))
	{
		cout << "Read Success" << endl;
	}
	else
	{
		cout << "Read Failed" << endl;
	}

	cout << data << endl;*/

	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (auto & a : array)
	{
		cout << a << endl;
	}
}