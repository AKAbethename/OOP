//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "MyVector.h"
#include "MyString.h"

#include "MyRect.hpp"

#include "Circle.hpp"

#include "Shape.hpp"

#include <vector>
#include <iostream>
#include <list>
#include <algorithm> // для std::reverse

#include <stdexcept>

#include <new>      // для std::bad_alloc

#include <cstring>



#define stop __asm("nop")// Эта макроподстановка упрощает установку точек останова

//============= Шаблон функции для вывода с помощью итератора
template <class T> void pr(T& v, string s)
{
	cout<<"\n\n\t"<<s<<"  # Sequence:\n";
	
	// Итератор любого контейнера
	typename T::iterator p;
	int i;

	for (p = v.begin(), i=0;  p != v.end();  p++, i++)
		cout << endl << i+1 <<". "<< *p;
	cout << '\n';
}

template <typename T>
void Swap(T& value1, T& value2){
//    T tmp = value1;
//    value1 = value2;
//    value2 = tmp;

/* move семантика*/
	T tmp = std::move(value1);
	value1 = std::move(value2);
	value2 = std::move(tmp);

}

class StackOverflow {};         
class StackUnderflow {};       

class StackOutOfRange {
public:
    void Out() const {
        std::cout << "\nStack index out of range!\n\n";
    }
};

template <class T, int count>
class MyStack{
	int sz;
	int cap;
	T* array;

  public:
	MyStack() : sz(0), cap(count), array(new T[cap]) {}

//	MyStack(int co) : sz(sz), cap(sz*2), array(new T[cap]) {} 

	int GetSize() {return sz;}

	int Capacity() {return cap;}

	void bigger() {
		T* array_copy = new T[cap * 2];
		memcpy(array_copy, array, sizeof(T)*sz);
		delete[] array;
		array = array_copy; 
	}

	void Push(T obj) {
		if(sz == cap) bigger();

		sz++;

		array[sz-1] = obj;
	}


	T Pop() {
        if (sz == 0) {
            throw StackUnderflow();  // Защита от пустого стека
        }
        sz--;                       // Сначала уменьшаем размер
        return array[sz];           // Затем возвращаем элемент
    }


	~MyStack() {delete[] array;}

	T& operator[](int index) {
        if (index < 0 || index >= sz) {
            throw StackOutOfRange();
        }
        return array[index];
    }
};


bool cond(Vector& v){
	if(!(v) > 3.5) return true;
	return false;
}

bool cond_1(Vector* v){
	if(!(*v) > 3.5) return true;
	return false;
}

bool first_letter_b(string s){
	if(s[0] == 'b') return true;
	return false;
}

bool comp(string s, string ss){
	if(s == ss) return true;
	return false;
}


class object_func{
	string cur_s;
  public:
	object_func(string s): cur_s(s) {}
	bool operator()(string s){
		if(cur_s == s) return true;
		return false;
	}	
};


int main()
{

	//===========================================================
	// Шаблоны функций
	//===========================================================
	// Создайте шаблон функции перестановки двух параметров - Swap().
	// Проверьте работоспособность созданного шаблона с помощью
	// приведенного ниже фрагмента.
	{
		int i = 1, j = -1;
		Swap (i, j);

		std::cout << i << "\t" << j << "\n";

		double a = 0.5, b = -5.5;
		Swap (a, b);

		std::cout << a << "\t" << b << "\n";

		Vector u(1,2), w(-3,-4);
		Swap(u, w);

		std::cout << u.get_x() << "\t" << w.get_x() << "\n";

		// Если вы достаточно развили класс MyString в предыдущей работе,
		// то следующий фрагмент тоже должен работать корректно.
		
		MyString s1 ("Your fault"), s2 ("My forgiveness");
		Swap (s1, s2);

		std::cout << s1.GetString() << "\n";

		std::cout << s2.GetString() << "\n";

		MyStack <int, 3> stack;
	}




	//===========================================================
	// Шаблоны классов
	//===========================================================
	// Создайте шаблон класса MyStack для хранения элементов любого типа T.
	// В качестве основы для стека может быть выбран массив.
	// Для задания максимального размера стека может быть использован
	// параметр-константа шаблона
	// Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
	// Необязательной - может быть выбор по индексу (operator[]).
	// Для того, чтобы гарантировать корректное выполнение этих операций 
	// следует генерировать исключительные ситуации.
	
	// С помощью шаблона MyStack создайте стек переменных типа int, затем
	// стек переменных типа double и, наконец, стек из переменных типа Vector 
	// Если вы подготовите три класса для обработки исключений,
	// то следующий фрагмент должен работать
	int p = 0;
	try
	{
		cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

//		stack.Push(4);	// Здесь должно быть "выброшено" исключение

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements\n";
		
		p++;
		stack.Pop();
		stack.Pop();		// Здесь должно быть "выброшено" исключение
		stack.Push(2);




//		int i = stack[3];	// Здесь должно быть "выброшено" исключение


		MyStack<Vector, 5> ptStack;

		cout << "\nVector Stack capacity: " << ptStack.Capacity() << "\n";

		ptStack.Push(Vector(1,1));
		ptStack.Push(Vector(2,2));

		cout << "\nVector Stack pops: ";
//		// Используйте метод класса Vector для вывода элемента
		ptStack.Pop().Out();

		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements\n";


	}
	catch (StackOverflow)
	{
		cout << "\nStack overflow\n";
	}
	catch (StackUnderflow)
	{
		cout << "\nStack underflow\n";
	}
	catch (StackOutOfRange o)
	{
		o.Out();
	}

	stop;
	p;



	std::cout << "\n\n Контейнеры стандартной библиотеки\n\n";
	//=======================================================================
	// Контейнеры стандартной библиотеки. Последовательности типа vector
	//=======================================================================
	
	// Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
	// С помощью метода push_back() заполните вектор какими-либо значениями.
	// Получите новый размер вектора и выведите значения его элементов.
	// В процессе работы с вектором вы можете кроме количества реально заполненных
	// элементов (size()) узнать максимально возможное количество элементов (max_size()),
	// а также зарезервированную память (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	std::cout << "size is " << n << endl;
	n = v.capacity();
	std::cout << "capacity is " << n << endl;
	n = v.max_size();
	std::cout << hex << "max_size is " << n;
		
	// Так как мы часто будем выводить последовательности, то целесообразно
	// создать шаблон функции для вывода любого контейнера.
	// Проанализируйте коды такого шабдлона (pr), который приведен выше
	// Используйте его для вывода вашего вектора

	pr (v, "Vector of ints");
	
	// Используем другой конструктор для создания вектора вещественных
	// с начальным размером в 2 элемента и заполнением (222.).
	// Проверим параметры вектора. Затем изменим размер вектора и его заполнение
	// (метод - resize()) и вновь проверим параметры.
	


	vector<double> vd{222., 222.};

	pr (vd, "Vector of doubles");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	vd.resize(5, 10);

	pr (vd, "After resize");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	// Используя метод at(), а также операцию выбора [], измените значения
	// некоторых элементов вектора и проверьте результат.

	vd.at(0) = 220;

	pr (vd, "After at");
	

	// Создайте вектор вещественных, который является копией существующего.

	vector<double> wd(vd);

	pr (wd, "Copy");
	

	// Создайте вектор, который копирует часть существующей последовательности
	vector<double> ud(wd.begin()+1, wd.begin() + 4);
	pr (ud, "Copy part");



	// Создайте вектор вещественных, который является копией части обычного массива.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar+2, ar+5);

	//vector<double> va 
	pr (va, "Copy part of array");
	

	// Создайте вектор символов, который является копией части обычной строки
	char s[] = "Array is a succession of chars";
	
	vector<char> vc(s+11, s+17);
	pr (vc, "Copy part of c-style string");



	// Создайте вектор элементов типа Vector и инициализируйте
	// его вектором с координатами (1,1).

	Vector v1(1, 1);
	Vector v2(2, 2);



	vector<Vector> vv{v1, v2};
	
	cout << "\n\nvector of Vectors\n";
	for (int i=0;  i < vv.size();  i++)
		vv[i].Out();



	// Создайте вектор указателей на Vector и инициализируйте его адресами
	// объектов класса Vector
	
	vector<Vector*> vp{&v1, &v2};
	
	cout << "\n\nvector of pointers to Vector\n";
	
	for (int i=0;  i < vp.size();  i++)
		vp[i]->Out();

	

	// Научитесь пользоваться методом assign и операцией
	// присваивания = для контейнеров типа vector.

	vp.assign({&v2, &v1}); 

	cout << "\n\nAfter assign\n";
	for (int i=0;  i < vp.size();  i++)
		vp[i]->Out();
	
	// Декларируйте новый вектор указателей на Vector и инициализируйте его 
	// с помощью второй версии assign

	vector <Vector*> vpNew;
	vpNew.assign(vp.begin(), vp.end());
	
	cout << "\n\nNew vector after assign\n";
	for (int i=0;  i < vpNew.size();  i++)
		vpNew[i]->Out();


	// На базе шаблона vector создание двухмерный массив и
	// заполните его значениями разными способами.
	// Первый вариант - прямоугольная матрица
	// Второй вариант - ступенчатая матрица

	
	//========= Ступенчатая матрица

	// прямоугольная матрица

{
	int i = 0;

	int M = 5;
	int N = 3;

	vector <vector<double>> vdd(M);

	for (i=0;  i < vdd.size();  i++)
		vdd[i] = vector<double>(N, double(i));



	cout << "\n\n\tTest vector of vector<double>\n";
	for (i=0;  i < vdd.size();  i++)
	{
		cout << endl;
		for (int j=0;  j < vdd[i].size();  j++)
			cout << vdd[i][j] << "  ";
	}

	std::cout << endl;

	stop;

}

{
	// ступенчатая матрица

	int M = 7;
	int N = 9;

	vector<vector<double>> mat(M);

	vector<double> str{1, 2, 3};
	str.resize(M, 0);
	std::reverse(str.begin(), str.end());

	for(int i = 0; i < mat.size(); ++i){
		vector <double> vcp(i+1, 0);
		vcp.resize(N, i+1);
		mat[i] = vector <double>(vcp);
	}

	for (int i=0;  i < mat.size();  i++)
	{
		cout << endl;
		for (int j=0;  j < mat[i].size();  j++)
			cout << mat[i][j] << "  ";
	}

	std::cout << endl;
}


std::cout << "\nVector, base\n\n";

	//===================================
	// Простейшие действия с контейнерами
	//===================================
	//3б. Получение значения первого и последнего элементов последовательности.
	//Получение размера последовательности. Присваивание значений
	//элементов одной последовательности элементам другой - assign().

	vector <double> vec{1, 2, 6, 3, 7, 1, 10, 19, 16};

	std::cout << *vec.begin() << "\n";

//	std::cout << *(vec.end()-1) << "\n";

	std::cout << *vec.rbegin() << "\n";

	std::cout << "size equals " << vec.size() << "\n";

	vector <double> vec1;
	vec1.assign(vec.begin(), vec.end());

	pr(vec1, "eli");



	//Создайте и проинициализируйте вектор из элементов char. Размер -
	//по желанию.

	vector <char> symbs{'A', 'F', 'K', 'O', 'S', 'z', 'd'};

	std::cout << symbs[3] << "\n";


	//Создайте и проинициализируйте массив из элементов char. Размер -
	//по желанию.


	//Получите значение первого элемента вектора ( front() )

	std::cout << "first element is " << symbs.front() << "\n";


	//Получите значение последнего элемента вектора ( back() )

	std::cout << "last element is " << symbs.back() << "\n";


	//Получите размер вектора

	std::cout << "size equals " << symbs.size() << "\n";


	//Присвойте вектору любой диапазон из значений массива cMas.

	char Cmas[] = {'R', 'U', 'S', 'S', 'I', 'A'};

	symbs.assign(Cmas, Cmas + 5);


	//Проверьте размер вектора, первый и последний элементы.

	std::cout << "after Cmas size equals " << symbs.size() << "\n";

	std::cout << "first element is " << *symbs.begin() << "\n";

	std::cout << "last element is " << *(symbs.rbegin()) << "\n";

  
	stop;


	//3в. Доступ к произвольным элементам вектора с проверкой - at()
	//и без проверки - []
	//Создайте неинициализированный вектор из 8 элементов char - vChar2.
	//С помощью at() присвойте четным элементам вектора значения
	//элементов vChar1 из предыдущего задания,
	//а с помощью [] присвойте нечетным элементам вектора vChar2 значения
	//массива {'K','U','K','U'}.

	vector <char> vChar2(8);
	int k = 0;
	char array[] = {'K', 'U', 'K', 'U'};

	for(int i = 0; i < 8; i += 2){
		vChar2.at(i) = symbs[k++];
	}
	k = 0;
	for(int i = 1; i < 8; i += 2){
		vChar2[i] = array[k++];
	}

	pr(vChar2, "hah");



	
	  stop;
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. Обратите внимание: что происходит при
	//попытке обращения к несуществующему элементу в обоих случаях

//	std::cout << symbs.at(20) << "\n";

	std::cout << symbs[20] << "\n";

  
	stop;

	//3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
	//расширения кругозора можете ее сразу же и выкинуть (pop_back())

	vChar2.push_back('Z');
	vChar2.pop_back();

  
	stop;

	//3д. Вставка-удаление элемента последовательности insert() - erase()
	//Очистка последовательности - clear()

	vChar2.insert(vChar2.begin() + 5, 'W');

	pr(vChar2, "after insert");

	vChar2.erase(vChar2.begin() + 5);

	pr(vChar2, "after erase");



	//Вставьте перед каждым элементом вектора vChar2 букву 'W'

	int l = 0;
	int size_vChar2 = vChar2.size();

	while(true){
		vChar2.insert(vChar2.begin()+l, 'W');
		l += 2;
		if(l >= size_vChar2*2) break;
	}

	pr(vChar2, "Now");
	

	//Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'

	vChar2.insert(vChar2.begin() + 4, {'X', 'X', 'X'});

	pr(vChar2, "after xxx");


	//Вставьте перед 2-ым элементом вектора vChar2 с третьего по
	//шестой элементы массива "aaabbbccc"

	char arrray[] = "aaabbbccc";

	vChar2.insert(vChar2.begin()+1, arrray+3, arrray+6);

	pr(vChar2, "after arrray");

  
	//Сотрите c первого по десятый элементы vChar2

	vChar2.erase(vChar2.begin(), vChar2.begin()+10);

	pr(vChar2, "after delete");

  
	stop;

	//Уничтожьте все элементы последовательности - clear()

	vChar2.clear();

	pr(vChar2, "after clear");

	stop;

	//Создание двухмерного массива

	vector <vector<double>> mass(7);
	for(int i = 0; i < 7; ++i){
		mass[i] = vector<double>(8, i);
	}

	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 8; ++j){
			std::cout << mass[i][j] << " ";
		}
		cout << endl;
	}

	stop;



///////////////////////////////////////////////////////////////////

	//Задание 4. Списки. Операции, характерные для списков.
	//Создайте два пустых списка из элементов Vector - ptList1 и
	//ptList2

	list <Vector> ptList1;
	list <Vector> ptList2;

	

	//Наполните оба списка значениями с помощью методов push_back(),
	//push_front, insrert()

	ptList1.push_back(v1);
	ptList1.push_front(v2);

	Vector v3(3, 3);
	Vector v4(4, 4);

	ptList1.insert(++ptList1.begin(), v3);

	ptList2.push_front(v4);
	ptList2.push_back(v1);
	ptList2.insert(--ptList2.end(), v3);

	pr(ptList1, "list_1");

	pr(ptList2, "list_2");




	//Отсортируйте списки - sort().
	//Подсказка: для того, чтобы работала сортировка, в классе Vector
	//должен быть переопределен оператор "<"

	ptList1.sort();

	pr(ptList1, "list_1 after sort");

	ptList2.sort();

	pr(ptList2, "list_2 after sort");

  
	stop;

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит со вторым списком.

	ptList1.merge(ptList2);

	pr(ptList1, "list_1 after merge");

	pr(ptList2, "list_2 after merge");


	stop;

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подсказка: для этого необходимо также переопределить
	//в классе Vector оператор "=="

	ptList1.remove({3, 3});

	pr(ptList1, "list_1 after remove");


	stop;

std::cout << "\n\nЗадание 5. Стандартные алгоритмы\n\n";

///////////////////////////////////////////////////////////////////

	//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
	// <algorithm>
	//5а. Выведите на экран элементы ptList1 из предыдущего
	//задания с помощью алгоритма for_each()

	#if 0

	for(Vector v: ptList1){
		std::cout << v << "\n";
	}

	#endif

	for_each(ptList1.begin(), ptList1.end(), [](const Vector& v){std::cout << v << "\n";});


	stop;

	//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
	//определенным значением. С помощью алгоритма find_if() найдите
	//итератор на элемент, удовлетворяющий определенному условию, 
	//например, обе координаты точки должны быть больше 2.
	//Подсказка: напишите функцию-предикат, которая проверяет условие
	//и возвращает boolean-значение (предикат может быть как глобальной
	//функцией, так и методом класса)

	Vector vvv(2, 2);

	auto it = find(ptList1.begin(), ptList1.end(), vvv);

	auto it_1 = find_if(ptList1.begin(), ptList1.end(), cond);

	std::cout << "\n" << *it_1 << "\n";



	  stop;

	//Создайте список из указателей на элеметы Vector. С помощью 
	//алгоритма find_if() и предиката (можно использовать предикат - 
	//метод класса Vector, определенный в предыдущем задании) найдите в
	//последовательности элемент, удовлетворяющий условию

	std::cout << "\n";

	list <Vector*> ptrs;

	ptrs.push_back(&v1);
	ptrs.push_front(&v2);
	ptrs.push_back(&v3);
	ptrs.push_back(&v4);

	for_each(ptrs.begin(), ptrs.end(), [](const Vector* v){std::cout << *v << "\n";});
	std::cout << "\n\n";

	auto it_it = find_if(ptrs.begin(), ptrs.end(), cond_1);

	std::cout << **it_it << "\n";

  
	
	  stop;

	//5в. Создайте список элементов Vector. Наполните список
	//значениями. С помощью алгоритма replace() замените элемент
	//с определенным значением новым значением. С помощью алгоритма
	//replace_if() замените элемент, удовлетворяющий какому-либо
	//условию на определенное значение. Подсказка: условие
	//задается предикатом.

	list <Vector> List;

	List.push_back(v1);
	List.push_front(v2);
	List.push_back(v3);
	List.push_back(v4);

	Vector v5(5, 6);



	replace(List.begin(), List.end(), v3, v5);

	replace_if(List.begin(), List.end(), cond, v5);




  //Сформировали значения элементов списка

  std::cout << "\n\n";

  for_each(List.begin(), List.end(), [](const Vector& v){std::cout << v << "\n";});

  std::cout << "\n\n";

  
	stop;


	//5г. Создайте вектор строк (string). С помощью алгоритма count()
	//сосчитайте количество одинаковых строк. С помощью алгоритма
	//count_if() сосчитайте количество строк, начинающихся с заданной
	//буквы

	vector <string> vec_str{"banana", "chocolate", "banana", "kinza", "lemon", "kinza", "berry"};

	std::cout << "count of <<kinza>> equals " << count(vec_str.begin(), vec_str.end(), "kinza") << "\n";

	std::cout << "count of <<b...>> equals " << count_if(vec_str.begin(), vec_str.end(), first_letter_b);




	//5д. С помощью алгоритма count_if() сосчитайте количество строк,
	//которые совпадают с заданной строкой. Подсказка: смотри тему
	//объекты-функции
	
	static string s_input;

	std::cout << "Введите строку: \n";

	std::cin >> s_input;

	object_func sss(s_input);

	std::cout << "count of " << s_input << " equals " << count_if(vec_str.begin(), vec_str.end(), sss);
																								
//	s_cur = s_input;

	stop;

	cout <<"\n\n";

}
