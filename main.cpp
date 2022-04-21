
#include <iostream>
class Foo{
public:
    Foo(int j) {
        i = new int[j];
    }

    Foo(const Foo& object) : i(object.i){   //добавлен конструктор копирования
    }

    Foo& operator=(const Foo& object){  //добавлен оператор копирования
        return *this;
    }

    virtual ~Foo() { //добавлено virtual
        delete[] i;
    }
protected: // private -> protected
    int* i;
};

class Bar: public Foo{ // Foo -> public Foo
public:
    Bar(int j) : Foo(j) { // добавлено  : Foo(j)
        i = new char[j];
    }

    virtual ~Bar() { //добавлено virtual
        delete[] i; // delete -> delete[]
    }
protected: // private -> protected
    char* i;
};

int main(){ // void main() -> int main()
    Foo* f = new Foo(100);
    Foo* b = new Bar(100);
    *f = *b;

    delete f;
    delete b;
}

