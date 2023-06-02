#include <gtest/gtest.h>

#include "lista_enlazada.h"

using namespace std;


TEST(ListaEnlazadaGenerica, 01_lista_enlazada_vacia) {
    ListaEnlazada<int> lista_enlazada;
    
    EXPECT_EQ(0, lista_enlazada.longitud());
}

TEST(ListaEnlazadaGenerica, 02_agregar_elementos_incrementa_la_longitud) {
    ListaEnlazada<int> lista_enlazada;
    lista_enlazada.agregarAtras(2);
    
    EXPECT_EQ(1, lista_enlazada.longitud());

    lista_enlazada.agregarAtras(10);
    
    EXPECT_EQ(2, lista_enlazada.longitud());
}

TEST(ListaEnlazadaGenerica, 03_puedo_acceder_a_los_elementos) {
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    
    ListaEnlazada<int> lista_enlazada;
    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    
    EXPECT_EQ(primer_elemento, lista_enlazada.iesimo(0));
    EXPECT_EQ(segundo_elemento, lista_enlazada.iesimo(1));
}


TEST(ListaEnlazadaGenerica, 04_tipo_de_datos_complejo) {
    struct punto2d {
        int x;
        int y;

        punto2d(int a, int b) : x(a), y(b) {}
        bool operator==(const punto2d b) const {return this->x == b.x && this->y == b.y;}
    };

    ListaEnlazada<punto2d> l;
    punto2d p(0,1);
    l.agregarAtras(p);
    l.agregarAtras(punto2d(1,1));

    EXPECT_EQ(p, l.iesimo(0));
}

