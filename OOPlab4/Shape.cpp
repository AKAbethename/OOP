#include "Shape.hpp"

int Shape::Count = 0;

int Shape::cap = 1;

Shape** Shape::shapes = new Shape*[10];

#if 0

Shape::Shape(){
    ++Count;

    if(Count == 1){
        shapes = new Shape*[10];
        cap = 10;
    }

    if(cap == Count){
        shapes = new Shape*[cap*3];
        cap *= 3;
    }

}

#endif

Shape::Shape(){
    // Увеличиваем счетчик ДО работы с массивом

//    std::cout << "Shape ctor called, Count before: " << Count << std::endl;
    
    int newCount = Count + 1;
    
    // Проверяем нужно ли увеличивать массив
    if (newCount > cap) {
        int newCap = (cap == 0) ? 10 : cap * 2;
        Shape** newShapes = new Shape*[newCap];
        
        // Копируем существующие элементы
        for (int i = 0; i < Count; ++i) {
            newShapes[i] = shapes[i];
        }
        
        // Удаляем старый массив
        delete[] shapes;
        shapes = newShapes;
        cap = newCap;
    }
    
    // Добавляем текущий объект в массив
    shapes[Count] = this;
    Count = newCount;  // Обновляем счетчик

 //   std::cout << "Shape ctor finished, Count after: " << Count << std::endl;
}

Shape::~Shape(){
//    std::cout << "Shape dtor called, Count before: " << Count << std::endl;
    
    if (shapes != nullptr && Count > 0) {
        // Находим текущий объект в массиве
        for (int i = 0; i < Count; ++i) {
            if (shapes[i] == this) {
                // Сдвигаем остальные элементы
                for (int j = i; j < Count - 1; ++j) {
                    shapes[j] = shapes[j + 1];
                }
                shapes[Count - 1] = nullptr;
                break;
            }
        }
        --Count;
        
        // Освобождаем память если объектов не осталось
        if (Count == 0) {
            delete[] shapes;
            shapes = nullptr;
            cap = 0;
        }
    }
    
//    std::cout << "Shape dtor finished, Count after: " << Count << std::endl;
}