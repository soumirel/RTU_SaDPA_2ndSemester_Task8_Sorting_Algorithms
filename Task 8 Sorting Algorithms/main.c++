
#include <iostream>
#include <locale>


using namespace std;


template<typename T>
void printMenu(T* p_array, size_t size);

template<typename T>
void printArray(T* p_array, size_t size);

template<typename T>
void inputArray(T* p_array, size_t size);


int main()
{
	setlocale(LC_ALL, "ru");

	// ������� ����������
	int* array;
	size_t size;

	//���������� ��� ����������������� �����.
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
			
			system("pause");
			break;

		case 2:
			
			system("pause");
			break;

		case 0:
			cout << "�� ��������!\n";
			userMenuChoice = 0;
			system("pause");
			break;

		case 2022:
			cout << "���������� :D\n";
			system("pause");
			break;

		default:
			cout << "� �� ������� ���, ��������� ����\n";
			cin.clear();
			system("pause");
			break;
		}
	}

	return 0;
}


template<typename T>
void printMenu(T* p_array, size_t size)
{
	cout << "������������ ������ #7 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� 2 - ��������� ��������� � ������ ��������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";
	cout << "������: ";
	printArray(p_array, size);
	cout << "������� [1], ����� ...\n"
		"������� [2], ����� ...\n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "��� �����: ";
}


void inputArray(int* p_array, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		cin >> p_array[i];
	}
}


void printArray(int* p_array, size_t size)
{
	if (size)
	{
		for (size_t i = 0; i < size; i++)
		{
			cout << p_array[i] << " ";
		}
	}
	else
	{
		cout << "�� ��������.";
	}
}