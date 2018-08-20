#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() 
{
	//vector<int> numVector;
	int myArray[10000];
	const int SKIP_NUM = 6000;//number in file to skip to
	int numBytes = 5;//bytes to be read in(4byte num + newline)
	int product = (numBytes * SKIP_NUM);//to be used with seekg()
	fstream file("file1.txt");


	if (!file)
	{
		cout << "Cannot open file.\n";
		exit(1); //exit program if file isnt open
	}
	//cout << "check";
	/*file.seekg(product);//skipping to the pointer to start adding new nums

	while (file.is_open())//read in the numbers of the file
	{
		int nextNum;
		file >> nextNum;
		if (file.fail())
		{
			break;
		}
		numVector.push_back(nextNum);//subscript out of range
	}

	file.clear();//clear the file handles

	file.seekp(product);

	for (int i = 7777; i <= 7781; i++) //inserting 5 new numbers starting at pos. 6001
	{
		file << i << endl;
	}

	for (int i = 6006; i <= 9999; i++) //continuing to add the rest of the numbers from the file
	{
		file << numVector[i] << endl;
	}*/
	
	//===================================different logic testing========================================
	
	
	int count = 0;

	while (!file.fail())
	{
		int num;
		file >> num;
		if (num == SKIP_NUM)
		{
			break;
		}
	}
	int numLoc = file.tellg();
	//cout << "CHECK";
	file >> myArray[count];//subscript out of range
	//cout << "CHECK1";
	while(!file.fail())
	{
		count++;
		file >> myArray[count];
	}
	//cout << "CHECK2";
	file.clear();
	file.seekp(product);

	for (int i = 7777; i <= 7781; i++)
	{
		file << i << endl;
	}
	//cout << "CHECK3";
	for (int i = 0; i < count; i++)
	{
		file << myArray[i] << endl;
	}
	//cout << "CHECK 4";

	cout << "Numbers being placed.............";
	cout << " Complete. ";
	
	file.close();

	return 0;
}
