
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

	// Главные переменные
	int* array;
	size_t size;

	//Переменные для пользовательского ввода.
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


template<typename T>
void printMenu(T* p_array, size_t size)
{
	cout << "Практическая работа #7 ИКБО-03-21 Мазанов А.Е. Вариант 17\n\n"
		"Задание 2 - Обработка выражений в разных нотациях.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";
	cout << "Массив: ";
	printArray(p_array, size);
	cout << "Введите [1], чтобы ...\n"
		"Введите [2], чтобы ...\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
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
		cout << "Не заполнен.";
	}
}