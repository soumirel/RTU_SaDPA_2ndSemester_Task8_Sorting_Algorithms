
#include <iostream>
#include <locale>


using namespace std;


void printMenu();


template<typename T>
void printArray();


int main()
{
	setlocale(LC_ALL, "ru");

	// ������� ����������
	

	//���������� ��� ����������������� �����.
	int userMenuChoice = -1;

	// ������� ����-����.
	while (userMenuChoice != 0)
	{
		system("cls");
		printMenu();

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


void printMenu()
{
	cout << "������������ ������ #7 ����-03-21 ������� �.�. ������� 17\n\n"
		"������� 2 - ��������� ��������� � ������ ��������.\n"
		"~~~~~~~~~~~~~~~~~����~~~~~~~~~~~~~~~\n";
	cout << "������� [1], ����� ...\n"
		"������� [2], ����� ...\n"
		"������� [0], ����� ��������� ������ ���������.\n";
	cout << "��� �����: ";
}