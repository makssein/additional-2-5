
class Foo{
public:
    Foo(int j) {
        i = new int[j];
    }
    virtual ~Foo() { //добавлено virtual
        delete[] i; // delete -> delete[]
    }
private:
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
private:
    char* i;
};

int main(){ // void main() -> int main()
    Foo* f = new Foo(100);
    Foo* b = new Bar(200);
    *f = *b;

    delete f;
    delete b;
}

