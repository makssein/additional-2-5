
#include <iostream>
class Foo{
public:
    Foo(int j) {
        l = j;
        i = new int[j];

        for(int k = 0; k < l; k++){
            i[k] = k;
        }
    }

    void write(){
        for(int k = 0; k < l; k++){
            std::cout << i[k] << std::endl;
        }
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

    int l;
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
    Foo* f = new Foo(2);
    Foo* b = new Bar(4);

    f->write();
    std::cout << std::endl;
    b->write();
    std::cout << std::endl;

    *f = *b;

    f->write();
    std::cout << std::endl;
    b->write();

    delete f;
    delete b;
}

