#include "Shape.hpp"

#include "MyVector.h"

int Shape::Count = 0;

int Shape::cap = 1;

int Shape::CountDel = 0;

int Shape::K = 0;

int Shape::array_of_indexes[999];

int Shape::r_cnt = 0;
int Shape::c_cnt = 0;
int Shape::v_cnt = 0;



Shape** Shape::shapes = new Shape*[10];


Shape::Shape(){

    std::cout << "Shape ctor called, Count before: " << Count << std::endl;

    K += 1;
    
    int newCount = Count + 1;
    
    if (newCount > cap) {
        int newCap = (cap == 0) ? 10 : cap * 2;
        Shape** newShapes = new Shape*[newCap];
        
        for (int i = 0; i < Count; ++i) {
            newShapes[i] = shapes[i];
        }
        
        delete[] shapes;
        shapes = newShapes;
        cap = newCap;
    }
    
    shapes[Count] = this;
    index = Count;
    Count = newCount; 

    std::cout << "Shape ctor finished, Count after: " << Count << std::endl;
}

#if 0  // O(n^2)

Shape::~Shape(){
    std::cout << "Shape dtor called, Count before: " << Count << std::endl;
    
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
    
    std::cout << "Shape dtor finished, Count after: " << Count << std::endl;
}

#endif

#if 1  // O(n)

Shape::~Shape(){
    std::cout << "Shape dtor called, Count before: " << Count << std::endl;

    if (shapes == nullptr || Count == 0) {
        return;
    }

    if(Count == 1){
        delete[] shapes;
        shapes = nullptr;
        cap = 0;
    }
    else{

    Shape** new_shapes = new Shape*[Count-1];
    int k = 0;

    
    if (shapes != nullptr && Count > 0) {
        for (int i = 0; i < Count; ++i) {
            if(shapes[i] != this){
                if (k < Count - 1) new_shapes[k++] = shapes[i];
            }
        }
        

        delete[] shapes;

        shapes = new_shapes;

        Count = k;

        cap = Count;

    }
    
    std::cout << "Shape dtor finished, Count after: " << Count << std::endl;

}
}

#endif


#if 0  // O(1)

Shape::~Shape(){
    std::cout << "Shape dtor called, Count before: " << Count << std::endl;

    Count--;
    if(Count == 0) delete[] shapes; 

    std::cout << "Shape dtor finished, Count after: " << Count << std::endl;
}




#endif
