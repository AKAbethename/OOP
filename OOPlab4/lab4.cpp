// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cfloat>

#include <iterator>

#include "MyVector.h"

#include "MyString.h"

#include "Shape.hpp"

#include "Circle.hpp"

#include "Point.hpp"

#include "MyRect.hpp"

#include <deque>

#include <stack>

#include <queue>

using namespace std;	
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


template <class T> void prr(std::stack<T>& v)
{

	cout << "\n\tstack is here\n";
	std::stack<T> v_copy;
	int i = 1;
	while(v.size() != 0){
		cout << i++ << ": " << v.top() << endl;
		v_copy.push(v.top());
		v.pop();
	}
	v = v_copy;
	cout << "\n";
}

template <class T> void prr(std::queue<T>& v)
{
//	cout<<"\n\n\t"<<s<<"  # Without iterator((:\n";

	cout << "\n\tqueue is here\n";

	int i = 1;

	std::queue<T> v_copy;
	while(v.size() != 0){
		cout << i++ << ": " << v.front() << "\n";
		v_copy.push(v.front());
		v.pop();
	}
	v = v_copy;
	cout << endl;
}


template <class T> void prr(std::priority_queue<T>& v){
	std::priority_queue<T> v_copy;

	cout << "\n\tpriority_queue is here\n";
	int i = 1;

	while(v.size() != 0){
		cout << i++ << ": " << v.top() << "\n";
		v_copy.push(v.top());
		v.pop();
	}
	v = v_copy;
}


template <class T> MyString defin(T& v){
	cout << "\n\nCheck is here\n\n";

	Point p1(1, 1);
	Point p2(2, 2);
	Point p3(3, 3);
	MyString ans;

	v.push(p1);
	v.push(p2);

//	Point ppp = v.pop();

	return ans;
}

bool first_letter_Aa(MyString s){
	if(s[0] == 'A' || s[0] == 'a') return true;
	return false;
}


template <class T> void my_print(const T& n){
	cout << n << "\n";
}

template <class T> void set_point(T& p){
	++p;
}

template <typename T>
class Functor{
	T obj;
  public:
	Functor(const T& obj): obj(obj) {}; 
	bool operator()(const T& obj_1) const{
		if(obj == obj_1) return true;
		return false;
	}
};

int n = 100;
int m = 4;


bool Pred1_1(const Point& p){
	if(p.get_x() + n >= DBL_EPSILON && p.get_y() + n >= DBL_EPSILON &&
		m - p.get_x() >= DBL_EPSILON && m - p.get_y() >= DBL_EPSILON)
		return true;
	return false;
}

string Pred2_2(string& s){
	string res;
	for(int i = 0; i < s.size(); ++i){
		char symb = s[i];
		symb = (symb > 96 && symb < 123) ? symb : symb+32;
		res.push_back(symb);
	}
	s = res;
	return s;
}

int main()
{

	#if 0

	//Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать


	deque <Point> dq;

	Point p1(1, 11);
	Point p2(2, 22);
	Point p3(3, 33);
	Point p4(4, 34);
	Point p5(5, 45);

	dq.assign({p1, p2, p3});

	pr(dq, "deque eli");



	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

	deque <MyString> st;

	MyString string1("My");
	MyString string2("Word");
	MyString string3("Comes");
	MyString string4("Easy");

	st.push_back(string1);

	st.push_front(string2);

	st.push_front(string3);

	st.insert(st.begin(), string4);

	st.erase(std::remove_if(st.begin(), st.end(), first_letter_Aa), st.end());

//	pr(st, "st eli");



	////////////////////////////////////////////////////////////////////////////////////


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?

	stack <Point> stak({p1, p3});

	queue <Point> que({p1, p2, p3});

	prr(stak);


	prr(stak);

	prr(que);

	priority_queue <Point> priora_que;
	priora_que.push(p2);
	priora_que.push(p1);
	priora_que.push(p3);

	prr(priora_que);
	


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 


	vector<Point> origins({p1, p5, p4});

	stack<Point> cop;
	for(auto it = --origins.end(); it != --origins.begin(); it--){
		cop.push(*it);
	}

	prr(cop);
	pr(origins, "vector origins is here");




	//Сравнение и копирование стеков
	//а) создайте стек и любым способом задайте значения элементов
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	//в) сравните стеки на равенство
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
	{

		stack<Point> st_1({p4, p1, p2, p5});
		stack<Point> cp_st_1(st_1);
		if(st_1 == cp_st_1) cout << "\nequal eli\n";
		cp_st_1.push(p3);
		prr(st_1);
		prr(cp_st_1);

		if(st_1 > cp_st_1) cout << "st_1 > cp_st_1 eli\n";
		if(st_1 < cp_st_1) cout << "st_1 < cp_st_1 eli\n";

	stop;

	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{
		Point* pp1 = new Point(p1);
		Point* pp2 = new Point(p2);
		Point* pp3 = new Point(p3);
		Point* pp4 = new Point(p4);
		Point* pp5 = new Point(p5);
		queue <Point*> ptrs({pp2, pp3, pp1, pp5, pp4}); 

		vector <Point*> vec;

		while(ptrs.size() != 0){
			vec.push_back(ptrs.back());
			ptrs.pop();
		}

		pr(vec, "vec is here eli");

	
	
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


	{
		char a = 'A';
		char b = 'B';
		char c = 'C';
		const char* pa = &a;
		const char* pb = &b;
		const char* pc = &c;
		const char* array[4] = {pa, pb, pc};
		
//		priority_queue <const char*> priora_3({array[0], array[1], array[2]});

		priority_queue <const char*> priora_3(array, array+3);

		std::cout << priora_3.top() << endl;

		prr(priora_3);

//		for(int i = 0; i < 3; ++i){
//			cout << array[i] << "\n";
//		}

		priora_3.pop();
		prr(priora_3);

		char q = 'B';
		const char* pq = &q;
		priora_3.push(pq);
		prr(priora_3);	

		stop;
	}

#endif	
	
	
	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)


	cout << "\n\tSET\n";

	Point pp1(2.6, 2.1);
	Point pp2(4.5, 6.3);

	std::set<Point> set_1{pp1, pp2};

	

	auto p(set_1.insert(pp1));

	

	std::cout << *p.first << endl;

	p = set_1.insert(pp2);

	std::cout << *p.first << endl;

	pr(set_1, "set_1 eli");

	auto var = set_1.find(pp1);

	std::cout << *var;

	if(var != set_1.end()) cout << "\nhey\n";



	set<int> set_2{4, 2, 1, 6};

	set<int> set_22{1, 2, 6, 4};

	int array_1[5] = {2, 5, 3, 2, 3};

	set_2.insert(array_1, array_1 + 5);

	pr(set_2, "set_2 eli");  // 1 2 3 4 5 6




	////////////////////////////////////////////////////////////////////////////////////
	//multiset

	cout << "\n\tMULTISET\n";

	multiset<Point> multi{pp1, pp2, pp1};

	auto multi_p = multi.find(pp1);

	std::cout << *multi_p << endl;

	pr(multi, "multiset eli");




	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//е) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	std::map<const char*, int> map_1; //{{"Иванова", 80000}, {"Ульянова", 90000}, 
									// {"Чавчавадзе", 75000}, {"Багдасарян", 70000}};


	map_1["Иванова"] = 80000;
	map_1["Ульянова"] = 90000;
	map_1["Чавчавадзе"] = 75000;
//	map_1["Багдасарян"] = 70000;
	map_1.insert({"Багдасарян", 70000});

	std::cout << map_1["Иванова"] << "\n";

	map_1["Иванова"] = 82000;

	std::cout << map_1["Иванова"] << "\n";

	std::cout << map_1["Багдасарян"] << "\n\n";

	for(auto it = map_1.begin(); it != map_1.cend(); ++it){
		cout << it->first << "\t" << it->second << "\n";
	}

	map_1.erase("Иванова");

	for(auto it = map_1.begin(); it != map_1.cend(); ++it){
		cout << it->first << "\t" << it->second << "\n";
	}

	map_1.insert({"Петрова", 82000});

	for(auto it = map_1.begin(); it != map_1.cend(); ++it){
		cout << it->first << "\t" << it->second << "\n";
	}


	stop;
	


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	cout << "\n\t MULTIMAP\n";

	multimap<string, string> dict;

	dict.insert(make_pair("fine", "Прекрасно"));

	dict.insert({"fine", "Штраф"});

	dict.insert({"Can", "Мочь"});

	dict.insert({"Can", "Жестяная банка"});

//	dict.insert({"fine", "Прекрасно"});

	

	for(auto it = dict.begin(); it != dict.cend(); ++it){
		cout << it->first << "\t" << it->second << "\n";
	}

	auto lower = dict.lower_bound("Can");
	auto upper = dict.upper_bound("Can");

	cout << "\nLet's see on words like Can ..\n";

	for(auto it = lower; it != upper; ++it){
		cout << it->first << "\t" << it->second << "\n";
	}


///////////////////////////////////////////////////////////////////

	//Итераторы

	cout << "\n\tИтераторы\n";

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	set<Point> set_3;

	set_3.insert({3, 5});
	set_3.insert({1.5, 2.6});
	set_3.insert({3.2, 7.4});
	set_3.insert({25.1, 12.5});

	pr(set_3, "set_3 eli");

	vector<Point> vec_1(set_3.rbegin(), set_3.rend());

//	pr(vec_1, "vec_1 eli");




	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

//	std::partial_sum(vec_1.cbegin(), vec_1.cend(), 
//                     std::ostream_iterator<Point>(std::cout, ", "));

	std::ostream_iterator<Point> print(std::cout, ", ");

	pr(vec_1, "vec_1 eli!");
	cout << "\n\nПотоковый итератор\n";


	for(auto it = vec_1.begin(); it != vec_1.end(); ++it){
		*print = *it;
		cout << "\t";
	}
	cout << "\n";

	for(auto it = set_3.begin(); it != set_3.end(); ++it){
		*print = *it;
		cout << "\t";
	}
	cout << "\n";
	




	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	Point back_eli = {3, 6};
	Point front_eli = {1, 11};

	Point array_3[2] = {back_eli, front_eli};


	std::fill_n(std::back_inserter(vec_1), 4, back_eli);

//	std::fill_n(std::front_inserter(vec_1), 4, front_eli); // vector не поддерживает front

	std::fill_n(std::inserter(set_3, set_3.end()), 4, front_eli);

	pr(vec_1, "vec_1 again eli!");

	cout << "set_3 eli!!\n\n";

	for(auto it = set_3.begin(); it != set_3.end(); ++it){
		std::cout << *it << "\n";
	}

	std::copy(array_3, array_3+2, std::inserter(vec_1, std::next(vec_1.begin())));

	pr(vec_1, "again vec_1 eli!");



///////////////////////////////////////////////////////////////////

	//Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	cout << "\n\nALGORITHMS\n\n";

	for_each(vec_1.begin(), vec_1.end(), my_print<Point>);

	cout << "set_3 eli\n";

	for_each(set_3.begin(), set_3.end(), my_print<Point>);



	stop;

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката


	for_each(vec_1.begin(), vec_1.end(), set_point<Point>);

//	for_each(set_3.begin(), set_3.end(), set_point<Point>);

	cout << "\nAfter set_point eli\n\n";

	for_each(vec_1.begin(), vec_1.end(), my_print<Point>);

	for_each(set_3.begin(), set_3.end(), my_print<Point>);





	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

//	find(vec_1.begin(), vec_1.end(), )
	cout << "\n\n\tAlgorithm find()\n";
	Point find_point(4, 7);
	Functor object_1(find_point);

	auto it = find_if(vec_1.begin(), vec_1.end(), object_1);

	if(it != vec_1.end()) cout << *it << endl;
	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!


	sort(vec_1.begin(), vec_1.end());

	pr(vec_1, "vec_1 after sort eli!");
	



	//Создайте глобальную функцию вида: bool Pred1_1(const Point& ), которая будет вызываться
	//алгоритмом find_if(), передавая в качестве параметра очередной элемент последовательности.
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

//	auto itt = find_if(vec_1.begin(), vec_1.end(), Pred1_1);

//	if(itt != vec_1.end()) cout << *itt << endl;

	auto itt = find_if(vec_1.begin(), vec_1.end(), Pred1_1);

	if(itt != vec_1.end()) cout << *itt << endl;



	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.

	Vector v1(vec_1[0].get_x(), vec_1[0].get_y());
	Vector v2(vec_1[1].get_x(), vec_1[1].get_y());
	Vector v3(vec_1[2].get_x(), vec_1[2].get_y());
	Vector v4(vec_1[3].get_x(), vec_1[3].get_y());
	Vector v5(vec_1[4].get_x(), vec_1[4].get_y());
	Vector v6(vec_1[5].get_x(), vec_1[5].get_y());
	Vector v7(vec_1[6].get_x(), vec_1[6].get_y());
	Vector v8(vec_1[7].get_x(), vec_1[7].get_y());

	Rect r1(v1, v2);
	Rect r2(v3, v4);
	Rect r3(v5, v6);
	Rect r4(v7, v8);

	vector<Rect> vec_rect({r1, r2, r3, r4});

	sort(vec_rect.begin(), vec_rect.end());

	pr(vec_rect, "vec_rect eli\n");
	



	{
		//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		string s = "StroOKa";

		std::cout << Pred2_2(s) << "\n";


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр

		list<string> list_1({"abA", "RAr", "aEg", "ht", "HT", "ABA"});

		set<string> set_end;

		transform(list_1.begin(), list_1.end(), inserter(set_end, set_end.end()), Pred2_2);

		for(auto it = set_end.begin(); it != set_end.end(); ++it){
			cout << *it << "\n";
		}
	



		stop;
	}

	{// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

		vector<string> vec_end({"aba", "aga", "ata", "aba", "ata", "aea", "aga", "ara", "aba", "apa", "ata"});
		map<string, int> dict_1;

		for(auto it = vec_end.begin(); it != vec_end.end(); ++it){
			dict_1[*it]++;
		}

		/* for(auto it = vec_end.begin(); it != vec_end.end(); ++it){
			Functor<string> obj(*it);
			for(auto itt = vec_end.begin()+k; itt != vec_end.end(); ++itt){
				if(*itt == *it) cnt++;
			}
			dict_1[*it] = cnt;
			cnt = 1;
			k++;

		} */

		std::cout << dict_1["ata"] << endl;
	


	}


	return 0;
}

