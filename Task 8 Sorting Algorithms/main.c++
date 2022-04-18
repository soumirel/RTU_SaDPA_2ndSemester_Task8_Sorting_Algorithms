
#include <iostream>
#include <locale>


using namespace std;


void printMenu();


template<typename T>
void printArray();


int main()
{
	setlocale(LC_ALL, "ru");

	// Главные переменные
	

	//Переменные для пользовательского ввода.
	int userMenuChoice = -1;

	// Главный меню-цикл.
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
			cout << "До свидания!\n";
			userMenuChoice = 0;
			system("pause");
			break;

		case 2022:
			cout << "Пасхалочка :D\n";
			system("pause");
			break;

		default:
			cout << "Я не понимаю вас, повторите ввод\n";
			cin.clear();
			system("pause");
			break;
		}
	}

	return 0;
}


void printMenu()
{
	cout << "Практическая работа #7 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 2 - Обработка выражений в разных нотациях.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";
	cout << "Введите [1], чтобы ...\n"
		"Введите [2], чтобы ...\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}