/*
Классы
Вариант 17
Описать класс, реализующий стек и работу с ним.
1.)	Класс должен содержать следующие сведения о книгах в библиотеке:
•	фамилию автора;
•	название;
•	год издания;
•	количество экземпляров данной книги в библиотеке.
2.)	В классе должны быть реализованы следующие операции над стеком:
•	добавление данных о книгах, вновь поступивших в библиотеку;
•	удаление данных о списываемой книге, название которой введено с клавиатуры;
•	вывод информации обо всех книгах в библиотеке;
•	по запросу выводится информация о книгах, изданных после года, введенного с клавиатуры.
3.)	Программа должна обеспечивать диалог с помощью меню.
4.)	В программе должны быть созданы два экземпляра класса: книги в библиотеке и выданные читателям.
Когда читатель берет книгу в библиотеке, информация о ней (по введенному названию книги) должна быть
автоматически удалена из списка книг в библиотеке и переведена в список книг у читателей.
Когда читатель сдает книгу в библиотеку, информация о ней должна быть автоматически удалена из
списка книг у читателей и перенесена в список книг в библиотеке. При выводе информации о книгах,
пользователь должен выбрать какой список выводить (книги в библиотеке или у читателей), либо
вывести все книги из обоих списков.

Разработал студент группы ИКТб-1301 Перминов Данил
Версия: 2.0
Год разработки 2020
*/

#include <iostream>
#include <string>
#include <conio.h> 
#include <locale.h>
#include <Windows.h>

using namespace std;

struct Book
{
	string name;
	string autor;
	int year;
	string booknumber;
};

struct ListElement
{
	ListElement* Next;
	Book book;
};

class Stack
{
private:

	ListElement* Top;
	int Size;

public:
	Stack() { Top = NULL; Size = 0; }
	~Stack() { Clear(); }
	void Clear();
	void Push(Book o);
	Book Pop();
	int GetSize() { return Size; }
	void remove();
};
//--------------
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char menu;
	int tmpyear;

	string tmpStr;
	Book tmpbook;
	Stack tmpStack;
	Stack InLibrary;
	Stack InReader;

	while (true) {
		system("cls");
		cout << " 1 - Добавить данные о новой книге. \n";
		cout << " 2 - Удалить данные о книге.\n";
		cout << " 3 - Выдать книгу читателю. \n";
		cout << " 4 - Вернуть книгу в библиотеку. \n";
		cout << " 5 - Книги в библиотеке.\n";
		cout << " 6 - Книги у читателей.\n";
		cout << " 7 - Информация о книгах изданных после введённого года. \n";
		cout << " 8 - Информация обо всех книгах.\n";
		cout << " 0 - Выход. \n";
		menu = _getch();
		switch (menu)
		{
		case '1':
			system("cls");
			cout << "Введите название книги: "; cin >> tmpbook.name;
			cin.sync();
			cout << "Введите фамилию автора: "; cin >> tmpbook.autor;
			cout << "Введите год издания: "; cin >> tmpbook.year;
			cout << "Введите кол-во экземпляров: "; cin >> tmpbook.booknumber;
			InLibrary.Push(tmpbook);
			break;
		case '2':
			system("cls");
			cout << "Введите название удаляемой книги : "; cin >> tmpStr;
			while (InLibrary.GetSize() > 0)
			{
				tmpbook = InLibrary.Pop();
				if (tmpbook.name != tmpStr)tmpStack.Push(tmpbook);
				else
				{
					tmpStack.remove();
					cout << "Книга удалена.\n";
					system("pause");
					break;
				}
			}
			while (tmpStack.GetSize() > 0) InLibrary.Push(tmpStack.Pop());

			while (InReader.GetSize() > 0)
			{
				tmpbook = InReader.Pop();
				if (tmpbook.name != tmpStr)tmpStack.Push(tmpbook);
				else
				{
					tmpStack.remove();
					cout << "Книга удалена.\n";
					system("pause");
					break;
				}
			}
			while (tmpStack.GetSize() > 0) InReader.Push(tmpStack.Pop());
			break;
		case '3':
			system("cls");
			cout << "Введите название выдаваемой книги : "; cin >> tmpStr;
			while (InLibrary.GetSize() > 0)
			{
				tmpbook = InLibrary.Pop();
				if (tmpbook.name != tmpStr)tmpStack.Push(tmpbook);
				else
				{
					InReader.Push(tmpbook);
					cout << "Книга переведенна в список книг у читателей.\n";
					system("pause");
					break;
				}
			}

			while (tmpStack.GetSize() > 0)InLibrary.Push(tmpStack.Pop());
			break;
		case '4':
			system("cls");
			cout << "Введите название сдаваемой книги : "; cin >> tmpStr;
			while (InReader.GetSize() > 0)
			{
				tmpbook = InReader.Pop();
				if (tmpbook.name != tmpStr)tmpStack.Push(tmpbook);
				else
				{
					InLibrary.Push(tmpbook);
					cout << "Книга переведенна в список книг в библиотеке.\n";
					system("pause");
					break;
				}
			}

			while (tmpStack.GetSize() > 0) InReader.Push(tmpStack.Pop());
			break;
		case '5':
			system("cls");
			cout << " Список книг в библиотеке: \n";
			while (InLibrary.GetSize() > 0)
			{
				tmpbook = InLibrary.Pop();
				tmpStack.Push(tmpbook);
				cout << "\n Название: " << tmpbook.name;
				cout << "\n Автор: " << tmpbook.autor;
				cout << "\n Год издания: " << tmpbook.year;
				cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
				cout << "\n";
			}

			while (tmpStack.GetSize() > 0) InLibrary.Push(tmpStack.Pop());
			system("pause");
			break;

		case '6':
			system("cls");
			cout << "Список книг у читателей: \n";
			while (InReader.GetSize() > 0)
			{
				tmpbook = InReader.Pop();
				tmpStack.Push(tmpbook);
				cout << "\n Название: " << tmpbook.name;
				cout << "\n Автор: " << tmpbook.autor;
				cout << "\n Год издания: " << tmpbook.year;
				cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
				cout << "\n";
			}
			while (tmpStack.GetSize() > 0) InReader.Push(tmpStack.Pop());
			system("pause");
			break;
		case '7':
			system("cls");
			cout << "Введите год :\n";
			cin >> tmpyear;
			while (InReader.GetSize() > 0)
			{
				tmpbook = InReader.Pop();
				tmpStack.Push(tmpbook);
				if (tmpbook.year > tmpyear)
				{
					cout << "\n У читателя : ";
					cout << "\n Название: " << tmpbook.name;
					cout << "\n Автор: " << tmpbook.autor;
					cout << "\n Год издания: " << tmpbook.year;
					cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
					cout << "\n";
				}
			}
			while (tmpStack.GetSize() > 0) InReader.Push(tmpStack.Pop());

			while (InLibrary.GetSize() > 0)
			{
				tmpbook = InLibrary.Pop();
				tmpStack.Push(tmpbook);
				if (tmpbook.year > tmpyear)
				{
					cout << "\n В библиотеке : ";
					cout << "\n Название: " << tmpbook.name;
					cout << "\n Автор: " << tmpbook.autor;
					cout << "\n Год издания: " << tmpbook.year;
					cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
					cout << "\n";
				}
			}
			while (tmpStack.GetSize() > 0) InLibrary.Push(tmpStack.Pop());
			system("pause");
			break;
		case '8':
			system("cls");
			cout << "Список всех книг: \n";

			while (InReader.GetSize() > 0)
			{
				tmpbook = InReader.Pop();
				tmpStack.Push(tmpbook);
				cout << "У читателя : ";
				cout << "\n Название: " << tmpbook.name;
				cout << "\n Автор: " << tmpbook.autor;
				cout << "\n Год издания: " << tmpbook.year;
				cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
				cout << "\n";
			}
			while (tmpStack.GetSize() > 0) InReader.Push(tmpStack.Pop());


			while (InLibrary.GetSize() > 0)
			{
				tmpbook = InLibrary.Pop();
				tmpStack.Push(tmpbook);
				cout << "В библиотеке: ";
				cout << "\n Название: " << tmpbook.name;
				cout << "\n Автор: " << tmpbook.autor;
				cout << "\n Год издания: " << tmpbook.year;
				cout << "\n Кол-во экземпляров: " << tmpbook.booknumber;
				cout << "\n";
			}
			while (tmpStack.GetSize() > 0)InLibrary.Push(tmpStack.Pop());
			system("pause");
			break;
		case '0':
			return 0;
			break;
		}
	}
	return 0;
}
//--------------
void Stack::Clear()
{
	while (GetSize() != 0)
		Pop();
}

void Stack::Push(Book o)
{
	ListElement* tmpPtrNew = new ListElement;
	tmpPtrNew->Next = Top;
	tmpPtrNew->book = o;
	Top = tmpPtrNew;
	Size++;
}


Book Stack::Pop()
{
	ListElement* tmpPtr = Top;
	Book tmpbook;
	if (GetSize() > 0) {
		Top = tmpPtr->Next;
		tmpbook = tmpPtr->book;
		free(tmpPtr);
		Size--;
	}
	return tmpbook;
}

void Stack::remove()
{
	ListElement* tmpPtr = Top;
	Book tmpbook;
	if (GetSize() > 0) {
		Top = tmpPtr->Next;
		free(tmpPtr);
		Size--;
	}
}
