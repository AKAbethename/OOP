#include "stdafx.h"
#include "MyString.h"

#include <stdio.h>

void MyString::Copy (const char* s)
{
	delete [] m_pStr;
	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
//		strcpy (m_pStr, s);
		memcpy(m_pStr, s, len);
}

// Определение конструктора.
MyString::MyString (const char* s)
{
	m_pStr = 0;
	Copy(s);
}

// Определение деструктора.
MyString::~MyString()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	if(m_pStr) delete[] m_pStr;
}

// Метод класса
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength() const
{
	return strlen(m_pStr) + 1;
}

MyString& MyString::operator=(const MyString& M){
	if(this == &M) return *this;

	if(m_pStr) delete[] m_pStr;
	int len = M.GetLength() + 1;
	m_pStr = new char[len];

	memcpy(m_pStr, M.m_pStr, len-1);
	m_pStr[len-1] = '\0';

	return *this;
}

MyString::MyString(){
	m_pStr = new char[1];
	m_pStr[0] = '\0';
}

MyString::MyString(const MyString& M){
	m_pStr = nullptr;
	/* int len = M.GetLength();
	m_pStr = new char[len+1];
	memcpy(m_pStr, M.m_pStr, len);
	m_pStr[len] = '\0'; */
	Copy(M.m_pStr);

}
