// Вильковского О. С., 1 курс, ПИз-18
// Лабораторная 2, вариант 15
// Текст представляет собой программу на языке C. Подсчитать количество инструкций for вложенных одна в одну

#include "pch.h"
#include <iostream>
#include <locale>
#include <string>
const int N=1024;
const char WORD[4] = "for";

using namespace std;

int word_sum(char str[]) {
	int sum = 0;
	int word_len = strlen(WORD);
	for (int i = 0; i <= strlen(str) - word_len; i++) {
		for (int j = 0; j < word_len; j++) {
			if (str[i + j] != WORD[j]) {
				break;
			}
			else {
				if (j == word_len - 1) {
					sum++;
				}
			}
		}
	}

	if (sum > 0)
		sum -= 1;

	return sum;
}

int main()
{
	char str[N];
	setlocale(LC_ALL, "Russian");
	cout << "Подсчет вложенных инструкций for в тексте\n";
	do {
		cout << "Введите текст : ";
		cin.getline(str, sizeof(str));
	} while (strlen(str) < strlen(WORD));

	cout << "Вложенных инструкций for: " << word_sum(str) << "\n";
	system("pause");
}
