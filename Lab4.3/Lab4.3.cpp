﻿// Lab4.3.cpp :
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#pragma warning (disable : 4996)

using namespace std;

struct Note {
	string fullName;
	string phoneNum;
	int birthDate[3];
};

void AddTXT(char* fname);
void PrintTXT(char* fname);
int SearchTXT(char* fname, char phone[]);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[100];

	int menuItem;
	do {
		cout << "Оберіть дію: " << endl;
		cout << "[1]  Cтворити файл." << endl;
		cout << "[2]  Додати елементи до списку." << endl;
		cout << "[3]  Переглянути нотатку." << endl;
		cout << "[4]  Пошук за номером телефону." << endl;
		cout << "[5]  Відкрити файл." << endl;
		cout << "[0]  вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			AddTXT(fname);
			break;
		case 2:
			AddTXT(fname);
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 4:
			char m[100];
			cout << "Введіть номер телефона: "; cin >> m;
			SearchTXT(fname,m);
			break;
		case 5:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}

void AddTXT(char* fname) {
	ofstream fout;
	fout.open(fname, ios::app);
	string s;
	int k;
	cout << "Кількість елементів: "; cin >> k;
	Note* b = new Note[k];
	for (int i = 0; i < k; i++) {
		cin.get();
		cin.sync();
		cout << "Повне ім'я: "; getline(cin, b[i].fullName);
		fout << b[i].fullName << ' ';
		cout << "Номер телефону: "; getline(cin, b[i].phoneNum);
		fout << b[i].phoneNum << ' ';
		cout << "День народження: "; cin >> b[i].birthDate[0];
		cout << "Місця народження: "; cin >> b[i].birthDate[1];
		cout << "Рік народження: "; cin >> b[i].birthDate[2];
		fout << b[i].birthDate[0] << '.' << b[i].birthDate[1] << '.' << b[i].birthDate[2] << endl;
	}
}

void PrintTXT(char* fname) {
	ifstream fin(fname);
	string s;
	while (getline(fin, s)) {
		cout << s << endl;
	}
	cout << endl;
}

int  SearchTXT(char* fname, char phone[]) {
	ifstream fin(fname);
	char s[400];
	char* w;
	//char m[100];
	bool find = false;
	cin.ignore();
	
	while (fin.getline(s, sizeof(s))) {
		char tmp[400];
		strcpy(tmp, s);
		w = strtok(tmp, " ");
		while (w != NULL) {
			if (strcmp(w, phone) == 0) {
				cout << "Дані про людину із вказаним номером: " << s << endl;
				find = true;
			}
			w = strtok(NULL, " ");
		}
	}
	if (find == false) {
		cout << "За введеними параметрами не знайдено ні одного співпадіння." << endl;
		return -1;
	}
	else {
		return 1;
	}
}
