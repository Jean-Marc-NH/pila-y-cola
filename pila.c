#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* next;

    Nodo(int x) : dato(x), next(nullptr) {}
};

struct  Pila {
    Nodo* top; 

    Pila() : top(nullptr) {}  

    void push(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);

        nuevoNodo->next = top;
        top = nuevoNodo;
    }

    void pop(int &v) {
        if (top != nullptr) {
            Nodo* temp = top;
            v = top->dato;
            top = top->next;
            delete temp;
        }
        else {
            cout << "La pila esta vacia" << endl;
        }
    }

    void print() {
        if (top == nullptr) {
            cout << "La pila esta vacia" << endl;
        }
        else {
            Nodo* temp = top;
            cout << "Pila: ";
            while (temp != nullptr) {
                cout << temp->dato << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Pila pila;
    int v;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    pila.print(); 

    pila.pop(v);
    cout << v << endl;
    pila.print();

    pila.push(40);
    pila.print();

    return 0;
}
