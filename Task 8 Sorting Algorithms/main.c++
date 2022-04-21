
#include <iostream>
#include <locale>
#include <random>
#include <algorithm>

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

void testAlgsRandomArray();

void testAlgsSortedArray();


int main()
{
	setlocale(LC_ALL, "ru");

	// Главные переменные
	int* array = nullptr;
	size_t size = 0;

	//Переменные для пользовательского выбора.
	int userMenuChoice = -1;

	// Главный меню-цикл.
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
				cout << "Ошибка! Сформируйте массив.\n";
			}
			

			cout << '\n';
			system("pause");
			break;

		case 3:
			testAlgsRandomArray();
			system("pause");
			break;

		case 4:
			testAlgsSortedArray();
			system("pause");
			break;

		case 0:
			cout << "\nДо свидания!\n";
			userMenuChoice = 0;

			cout << '\n';
			system("pause");
			break;

		case 2022:
			cout << "\nПасхалочка :D\n";

			system("pause");
			break;

		default:
			cout << "\nЯ не понимаю вас.\n";
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
	cout << "Практическая работа #8 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание - Алгоритмы сортировки.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";

	cout << "Массив: ";
	if (size > maxSizeToPrint)
	{
		cout << "Массив сформирован и хранится в памяти.\n";
	}
	else 
	{
		printArray(p_array, size);
	}
	
	cout << "Введите [1], чтобы определить массив.\n"
		"Введите [2], чтобы произвести сортировку над введённым массивом\n"
		"Введите [3], чтобы выполнить контрольные прогоны алгоритма для различных размеров массива.\n"
		"Введите [4], чтобы выполнить прогоны алгоритма на отсортированных массивах различного размера.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "\nВаш выбор: ";
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
		cout << "Не заполнен.\n";
	}
}


void menuInputArray(int*& p_array, size_t& size)
{
	cout << "\nВведите размер массива: ";
	cin >> size;
	delete[] p_array;
	p_array = new int[size];

	int generateType;
	cout << "\nКак сформировать массив?\n"
		"Введите [1], чтобы заполнить массив вручную.\n"
		"Введите [2], чтобы заполнить массив случ.числами.\n"
		"\nВаш выбор: ";
	cin >> generateType;
	switch (generateType)
	{
	case 1:
		cout << "\nВведите " << size << " значений: ";
		inputArray(p_array, size);
		
		break;

	case 2:
		randomFillArray(p_array, size);
		break;

	default:
		cout << "\nЯ не понимаю вас.\n";
	}

	cout << "\nМассив сформирован.\n";
}


void menuSort(int*& p_array, const size_t& size)
{
	cout << "\nС помощью какого алгоритма отсортировать массив?\n"
		"Введите [1], чтобы выбрать сортировку пузырьком с условием Айверсона.\n"
		"Введите [2], чтобы выбрать сортировку Шелла с убывающим вдвое шагом.\n"
		"Введите [3], чтобы выбрать сортировку слиянием\n"
		"\nВаш выбор: ";

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
		cout << "\nЯ не понимаю вас.\n";
	}

	if (size > maxSizeToPrint)
	{
		cout << "Массив отсортирован.\n";
	}
	else 
	{
		cout << "Отсортированный массив: ";
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


void testAlgsRandomArray()
{
	cout << "\nКакой алгоритм вы хотите протестировать?\n"
		"Введите [1], чтобы выбрать сортировку пузырьком с условием Айверсона.\n"
		"Введите [2], чтобы выбрать сортировку Шелла с убывающим вдвое шагом.\n"
		"Введите [3], чтобы выбрать сортировку слиянием\n"
		"\nВаш выбор: ";

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

		cout << "Массив из " << testSize << " чисел был отсортирован.\n\n";
		
		testSize *= 10;

		delete[] testArray;
	}
}


int compAscending(const int* i, const int* j)
{
	return *i - *j;
}


int compDescending(const int* i, const int* j)
{
	return *j - *i;
}


void testAlgsSortedArray()
{
	cout << "\nКакой алгоритм вы хотите протестировать?\n"
		"Введите [1], чтобы выбрать сортировку пузырьком с условием Айверсона.\n"
		"Введите [2], чтобы выбрать сортировку Шелла с убывающим вдвое шагом.\n"
		"Введите [3], чтобы выбрать сортировку слиянием\n"
		"\nВаш выбор: ";

	int userChoiceAlgorithm;
	cin >> userChoiceAlgorithm;

	int* testArray;
	size_t testSize = 100;
	while (testSize <= 1000000)
	{
		testArray = new int[testSize];
		randomFillArray(testArray, testSize);

		cout << '\n';

		qsort(testArray, testSize, sizeof(int), (int(*) (const void*, const void*)) compAscending);
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

		cout << "Массив строго в возрастающем порядке из " << testSize << " чисел был отсортирован.\n";


		qsort(testArray, testSize, sizeof(int), (int(*) (const void*, const void*)) compDescending);
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

		cout << "Массив строго в убывающем порядке из " << testSize << " чисел был отсортирован.\n\n";

		testSize *= 10;

		delete[] testArray;
	}
}
