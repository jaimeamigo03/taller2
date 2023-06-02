#ifndef __LISTA_ENLAZADA_H__
#define __LISTA_ENLAZADA_H__

class ListaEnlazada {

    public:
    ListaEnlazada();
    ~ListaEnlazada();

    int longitud();

    void agregarAtras(const int elemento);
    
    int iesimo(const int posicion);
    
    private:
        struct nodo {
            nodo(int un_elemento) : elemento(un_elemento), siguiente(nullptr) {}
            int elemento;
            nodo* siguiente;
        };
        nodo* _primero;
        int _longitud;
};

ListaEnlazada::ListaEnlazada() : _primero(nullptr), _longitud(0) {}

int ListaEnlazada::longitud() {
    return this->_longitud;
}

void ListaEnlazada::agregarAtras(const int elemento) {
    if (this->_primero == nullptr)
        this->_primero = new nodo(elemento);
    else {
        nodo* actual = this->_primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = new nodo(elemento);
    }
    this->_longitud++;
}

int ListaEnlazada::iesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()

    nodo* actual = _primero;
    int i = 0;
    while (i < posicion){
        actual = actual->siguiente;
        i++;
    }
    return actual->elemento;
}

ListaEnlazada::~ListaEnlazada() {
    nodo * actual = this->_primero;
    while (actual != nullptr) {
        nodo* sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    this->_primero = nullptr;
}

#endif