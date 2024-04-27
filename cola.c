#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* next;

    Nodo(int x) : dato(x), next(nullptr) {}
};

struct Cola {
    Nodo* head;
    Nodo* tail;

    Cola() : head(nullptr), tail(nullptr) {}

    void push(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);

        if (head == nullptr) {
            head = nuevoNodo;
            tail = nuevoNodo;
        }
        else {
            tail->next = nuevoNodo;
            tail = nuevoNodo;
        }
    }

    void pop() {
        if (head != nullptr) {
            Nodo* temp = head;
            head = head->next;
            delete temp;

            if (head == nullptr) {
                tail = nullptr;
            }
        }
        else {
            cout << "La cola esta vacia" << endl;
        }
    }

    void print() {
        if (head == nullptr) {
            cout << "La cola esta vacia" << endl;
        }
        else {
            Nodo* temp = head;
            cout << "Cola: ";
            while (temp != nullptr) {
                cout << temp->dato << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Cola cola;

    cola.push(10);
    cola.push(20);
    cola.push(30);

    cola.print();

    cola.pop();
    cola.print();

    cola.push(40);
    cola.print();

    return 0;
}
