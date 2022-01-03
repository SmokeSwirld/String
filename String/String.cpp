#include "String.h"
int main()
{
	String a;
	String b("hello world1");
	String c("hello world2");

	b.PrintLn();
	a = b + c;
	a.PrintLn();
	a.ToUpper();
	a.PrintLn();
	a.ToLower();
	a.PrintLn();
	a.Shuffle();
	a.PrintLn();

	a.PrintLn();
	a.SortAZ();
	a.PrintLn();
	a.Reverse();
	a.PrintLn();
	c.SortZA();
	c.PrintLn();
	String d("      ertrert     ");
	d.Trim();
	d.PrintLn();
	b.Replace('l', 'p');
	b.PrintLn();


	//  memchr — Просматривает массив чтобы отыскать первое вхождение символа
	//	memcmp — Сравнивает определённое количество символов в двух массивах
	//  memcpy — Копирует символы из одного массива в другой
	//  memmove — Копирует символы из одного массива в другой с учётом перекрытия массивов
	//  memset — Заполняет определённое количество символов массива заданным
	system("pause");
}