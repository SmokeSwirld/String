#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

#include <iostream>


class String
{
	char* text;
	unsigned int length;
	unsigned int capacity;

public:
	String(const char* text, unsigned int capacity = 80)
	{
		Initialize(text);
	}

	String()
	{
		Initialize("");
	}

	String(unsigned int capacity)
	{
		Initialize("", capacity);
	}

	String(const String& original)
	{
		Initialize(original.text, original.capacity);
	}

	~String()
	{
		delete[] text;
	}

	// דועעונû-סועעונû
	const char* GetString() const
	{
		return text;
	}

	void SetString(const char* text)
	{
		length = strlen(text);
		if (length >= capacity)
		{
			delete[] this->text;
			capacity = length + 20;
			this->text = new char[capacity];
		}
		strcpy_s(this->text, length + 1, text);
	}

	int GetLength() const
	{
		return length;
	}

	// לועמהא SetLength םו המכזםמ בûעü!

	int GetCapacity() const
	{
		return capacity;
	}

	void Clear()
	{
		text[0] = '\0';
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 == capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}
	const char  GetCharAt(unsigned int index) const
	{
		return text[index];
	}
	void Print()
	{
		cout << text;
	}
	void PrintLn()
	{
		cout << text << "\n";
	}
	void GetLine()
	{
		cin >> text;
		length = strlen(text);
	}
	
	///////////////////////////////////ÏÅÐÅÃÐÓÇÊÈ ÎÏÅÐÀÒÎÐÎÂ

	String operator = (const String& right) 
	{
		String result;

		result.capacity = right.capacity;
		result.length = right.length;
		this->text = new char[100];
		strcpy_s(this->text, 99, right.text);

		return result;
		
	}
	bool operator == (const String& right) 
	{
		if(length != right.length)
		{
			return false;
		}
		for (int i = 0 ; i < right.length; i++) {
			if (text[i] != right.text[i]) 
			{
				return false;
			}
		}
		return true;
	}
	bool operator != (const String& right)
	{
		return !(*this == right);
	}
	String  operator[] (int index) 
	{ 
		if (index < 0 || index >= length)
		{
			cout << "No char on this index" << endl;
			
		}
		return text[index];
	}
	
	friend String operator +(const String& left, const String& right)
	{
		String newstring;
	
		for (int i = 0; i < newstring.capacity; i++)
		{
			if (i < left.length)
			{
				newstring.text[i] = left.text[i];

			}
			else
			{
				newstring.text[i] = right.text[i - left.length];
			}		
		}
		return newstring;
	}
	 String operator +=( const String& right)
	{
		String newstring;
		length = strlen(text)+ strlen(right.text);
		for (int i = 0; i < capacity; i++)
		{
			if (i < strlen(text))
			{
				newstring.text[i] = text[i];
			}
			else
			{
				newstring.text[i] = right.text[i - strlen(text)];
			}
			
		}
		cout << newstring.text<<"\n";
		return newstring;
	}
	 friend String operator +(const String& left, const char right)
	 {
		 String newstring;

		 for (int i = 0; i < newstring.capacity; i++)
		 {
			 if (i < left.length)
			 {
				 newstring.text[i] = left.text[i];

			 }
			 else
			 {
				 newstring.text[i] = right;
			 }
		 }
		 return newstring;
	 }
	 friend String operator +(const char left, const String& right)
	 {
		 String newstring;

		 for (int i = 1; i <= newstring.capacity; i++)
		 {
			 if (i < right.length)
			 {
				 newstring.text[i] = right.text[i];

			 }
			 else
			 {
				 newstring.text[0] = left;
			 }
		 }
		 return newstring;
	 }
	 friend ostream& operator<< (ostream& output, const String& str)
	 {
		 output << str.text;
		 return output;
	 }
	 friend istream& operator>> (istream& input, String& str)
	 {
		 input >> str.text;
		
		 return input;
	 }

	void ToUpper()
	{
		_strupr_s(text, capacity);
	}
    void ToLower()
	{
		_strlwr_s(text, capacity);
	}
	void Shuffle() 
	{
		random_shuffle(text,text + strlen(text));
	}
	void RandomFill()
	{
		for (int i = 0; i < capacity; i++)
		{
			text[i] =char( rand() % 128+15);			
		}
	   
	}
	void Reverse()
	{
		reverse(text, text + strlen(text));
	}
	void SortAZ()
	{
		sort(text, text + strlen(text));
	}
	void SortZA()
	{
		sort(text, text + strlen(text));
		Reverse();
	}
	void TrimEnd()
	{
		for (int i = strlen(text) - 1; i >= 0 && strchr(" ", text[i]); i--)
		{
			text[i] = '\0';
		}
	}
	void TrimStart()
	{
		while (text[0] != '\0' && strchr(" ", text[0]))
		{
			memmove(&text[0], &text[1], strlen(text));
		}
	}
	void Trim()
	{
		TrimEnd();
		TrimStart();
	}
	void Replace(char ch1, char ch2)
	{
		for (int i = 0; i < length; i++)
		{
			if (text[i] == ch1) text[i] = ch2;
		}
	}
	void Replace(String str1, String str2)
	{

	}

private:
	void Initialize(const char* str, int capacity = 80) {
		length = strlen(str);
		this->capacity = (capacity > length) ? capacity : length + 20;
		this->text = new char[this->capacity];
		strcpy_s(this->text, length + 1, str);
	}
};




