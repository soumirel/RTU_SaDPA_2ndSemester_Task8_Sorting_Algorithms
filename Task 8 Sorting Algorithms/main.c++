
#include <iostream>
#include <locale>
#include <random>

#include "BubbleIversonSort.h"
#include "ShellSort.h"
#include "MergeSort.h"


using namespace std;


const size_t maxSizeToPrint = 30;


void printMenu(int*& p_array, const size_t& size);

void printArray(int*& p_array, const size_t& size);

void inputArray(int*& p_array, const size_t& size);

void menuInputArray(int*& p_array, size_t& size);

void menuSort(int*& p_array, const size_t& size);

void randomFillArray(int*& p_array, const size_t& size);

int getRandomNumber(const int left, const int right);

void testAlgorithms();


int main()
{
	setlocale(LC_ALL, "ru");

	// ������� ����������
	int* array = nullptr;
	size_t size = 0;

	//���������� ��� ����������������� ������.
	int userMenuChoice = -1;

	// ������� ����-����.
	while (userMenuChoice != 0)
	{
		system("cls");
		printMenu(array, size);

		cin >> userMenuChoice;
		cin.ignore();

		switch (userMenuChoice)
		{
		case 1:
			menuInputArray(array, size);

			cout << '\n';
			system("pause");
			break;

		case 2:
			if (size)
			{
				menuSort(array, size);
			}
			else
			{
				cout << "������! ����������� ������.\n";
			}
			

			cout << '\n';
			system("pause");
			break;

		case 3:
			testAlgorithms();
			system("pause");
			break;

		case 0:
			cout << "\n�� ��������!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		case 2022:
			cout << "\n���������� :D\n";

			system("pause");
			break;

		default:
			cout << "\n� �� ������� ���.\n";
			cin.clear();

			cout << '\n';
			system("pause");
			break;
		}
	}

	return 0;
}


void printMenu(int*& p_array, const size_t& size)
{
	cout << "������������ ������ #8 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� - ��������� ����������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";

	cout << "������: ";
	if (size > maxSizeToPrint)
	{
		cout << "������ ����������� � �������� � ������.\n";
	}
	else 
	{
		printArray(p_array, size);
	}
	
	cout << "������� [1], ����� ���������� ������.\n"
		"������� [2], ����� ���������� ���������� ��� �������� ��������\n"
		"������� [3], ����� ��������� ����������� ������� ��������� ��� ��������� �������� �������.\n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "\n��� �����: ";
}


void inputArray(int*& p_array, const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> p_array[i];
	}
}


void printArray(int*& p_array, const size_t& size)
{
	if (size)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << p_array[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		cout << "�� ��������.\n";
	}
}


void menuInputArray(int*& p_array, size_t& size)
{
	cout << "\n������� ������ �������: ";
	cin >> size;
	delete[] p_array;
	p_array = new int[size];

	int generateType;
	cout << "\n��� ������������ ������?\n"
		"������� [1], ����� ��������� ������ �������.\n"
		"������� [2], ����� ��������� ������ ����.�������.\n"
		"\n��� �����: ";
	cin >> generateType;
	switch (generateType)
	{
	case 1:
		cout << "\n������� " << size << " ��������: ";
		inputArray(p_array, size);
		
		break;

	case 2:
		randomFillArray(p_array, size);
		break;

	default:
		cout << "\n� �� ������� ���.\n";
	}

	cout << "\n������ �����������.\n";
}


void menuSort(int*& p_array, const size_t& size)
{
	cout << "\n� ������� ������ ��������� ������������� ������?\n"
		"������� [1], ����� ������� ���������� ��������� � �������� ���������.\n"
		"������� [2], ����� ������� ���������� ����� � ��������� ����� �����.\n"
		"������� [3], ����� ������� ���������� ��������\n"
		"\n��� �����: ";

	int userChoiceAlgorithm;
	cin >> userChoiceAlgorithm;

	int* sortedArray = new int[size];
	
	memcpy(sortedArray, p_array, sizeof(int) * size);

	cout << '\n';
	switch (userChoiceAlgorithm)
	{
	case 1:
		bubbleIversonSort(sortedArray, size);
		break;

	case 2:
		shellSort(sortedArray, size);
		break;

	case 3:
		mergeSort(sortedArray, size);
		break;

	default:
		cout << "\n� �� ������� ���.\n";
	}

	if (size > maxSizeToPrint)
	{
		cout << "������ ������������.\n";
	}
	else 
	{
		cout << "��������������� ������: ";
		printArray(sortedArray, size);
	}
	
}


void randomFillArray(int*& p_array, const size_t& size)
{
	for (size_t i = 0; i < size; i++)
	{
		p_array[i] = getRandomNumber(-100, 100);
	}
}


int getRandomNumber(const int left, const int right)
{
	std::random_device r;
	std::default_random_engine e(r());
	std::uniform_int_distribution<int> dist(left, right);
	return dist(e);
}


void testAlgorithms()
{
	
	cout << "\n����� �������� �� ������ ��������������?\n"
		"������� [1], ����� ������� ���������� ��������� � �������� ���������.\n"
		"������� [2], ����� ������� ���������� ����� � ��������� ����� �����.\n"
		"������� [3], ����� ������� ���������� ��������\n"
		"\n��� �����: ";

	int userChoiceAlgorithm;
	cin >> userChoiceAlgorithm;

	int* testArray;
	size_t testSize = 100;
	while (testSize <= 1000000)
	{
		testArray = new int[testSize];
		randomFillArray(testArray, testSize);

		cout << '\n';
		switch (userChoiceAlgorithm)
		{
		case 1:
			bubbleIversonSort(testArray, testSize);
			break;
			
		case 2:
			shellSort(testArray, testSize);
			break;

		case 3:
			mergeSort(testArray, testSize);
			break;
		}

		cout << "������ �� " << testSize << " ����� ��� ������������.\n\n";
		
		testSize *= 10;

		delete[] testArray;
	}
}