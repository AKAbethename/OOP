class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (const char* s);	// Объявление конструктора
    ~MyString();		// Объявление деструктора

	MyString(const MyString&);

	void Copy (const char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength() const;	// Объявление метода (длина строки)

	MyString& operator=(const MyString&);

	const char& operator[](int i);

	friend ostream& operator<<(std::ostream& os, const MyString& p);
};