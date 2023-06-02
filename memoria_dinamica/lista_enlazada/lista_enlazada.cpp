#include "lista_enlazada.h"

ListaEnlazada::ListaEnlazada() : _primero(nullptr), _actual(nullptr), _longitud(0), _ultimo(nullptr) {}

int ListaEnlazada::longitud() {
    return this->_longitud;
}

void ListaEnlazada::agregarAtras(const int elemento) {
    if (this->_primero == nullptr){
        this->_primero = new nodo {elemento, nullptr, nullptr};
        _actual = _primero;}
    else {
        nodo* actual = this->_primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = new nodo {elemento, nullptr, actual};
        _ultimo = actual -> siguiente;
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

int ListaEnlazada::suma() {
    int res = 0;
    for(int posicion = 0; posicion < this->longitud(); posicion++){
        res = res + this->iesimo(posicion);
    }
    return res;
}

void ListaEnlazada::borrarUltimo() {
    // Pre: 0 < *this.longitud()
    borrarIesimo(this->_longitud-1);
}

void ListaEnlazada::borrarIesimo(const int posicion) {
    // Pre: 0 <= pos < *this.longitud()
    struct nodo * actual = this->_primero;
    struct nodo * prev;
    struct nodo * next;
    //Recorro los nodos hasta llegar al iesimo
    for(int i = 0; i < posicion; i++){
        prev = actual;
        actual = actual -> siguiente;
        next = actual -> siguiente;
    }
    
    if(actual != _primero){
        prev -> siguiente = actual -> siguiente;

        if(actual -> siguiente != nullptr){
            next -> anterior = actual -> anterior;}
        else{
            _ultimo = prev;
        }}
    else{
        this->_primero = actual->siguiente;
        next -> anterior = nullptr;
    }

    //Actualizo _actual
    if(actual == this->_actual){
        _actual = _actual -> siguiente;
    }

    // Borro el Iesimo Nodo
    delete actual;
    actual->siguiente = nullptr;
    this->_longitud--;
}

int ListaEnlazada::actual() { 
    return _actual->elemento;
}

void ListaEnlazada::avanzar() {
    if(_actual -> siguiente == nullptr){
        _actual = _primero;
    }
    else {
        _actual = _actual -> siguiente;}
    
}

void ListaEnlazada::retroceder() {
    if(_actual -> anterior == nullptr){
        _actual = _ultimo;
    }
    else{
        _actual = _actual -> anterior;
    }
}