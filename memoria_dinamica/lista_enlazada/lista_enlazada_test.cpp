#include <gtest/gtest.h>

#include "lista_enlazada.h"


TEST(ListaEnlazada, 01_lista_enlazada_vacia) {
    ListaEnlazada lista_enlazada;
    
    EXPECT_EQ(0, lista_enlazada.longitud());
}

TEST(ListaEnlazada, 02_agregar_elementos_incrementa_la_longitud) {
    ListaEnlazada lista_enlazada;
    lista_enlazada.agregarAtras(2);
    
    EXPECT_EQ(1, lista_enlazada.longitud());

    lista_enlazada.agregarAtras(10);
    
    EXPECT_EQ(2, lista_enlazada.longitud());
}

TEST(ListaEnlazada, 03_puedo_acceder_a_los_elementos) {
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    
    ListaEnlazada lista_enlazada;
    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    
    EXPECT_EQ(primer_elemento, lista_enlazada.iesimo(0));
    EXPECT_EQ(segundo_elemento, lista_enlazada.iesimo(1));
}

TEST(ListaEnlazada, 04_puedo_preguntar_por_la_suma_de_todos_los_elementos) {
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;
    const int suma = primer_elemento + segundo_elemento + tercer_elemento;
    
    ListaEnlazada lista_enlazada;
    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    EXPECT_EQ(suma, lista_enlazada.suma());
}

TEST(ListaEnlazada, 05_test_clase_teorica) {
    ListaEnlazada lista_enlazada;
    lista_enlazada.agregarAtras(1);
    lista_enlazada.agregarAtras(1);
    for (int i = 2; i < 10; i++){
        int nuevo = lista_enlazada.iesimo(i-1) + lista_enlazada.iesimo(i-2);
        lista_enlazada.agregarAtras(nuevo);
    }
    EXPECT_EQ(143, lista_enlazada.suma());
}

TEST(ListaEnlazada, 06_puedo_borrar_el_ultimo_elemento) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int ultimo_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(ultimo_elemento);
    
    lista_enlazada.borrarUltimo();

    EXPECT_EQ(2, lista_enlazada.longitud());
    EXPECT_EQ(primer_elemento, lista_enlazada.iesimo(0));
    EXPECT_EQ(segundo_elemento, lista_enlazada.iesimo(1));
}

TEST(ListaEnlazada, 07_puedo_borrar_cualquier_elemento) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.borrarIesimo(1);

    EXPECT_EQ(2, lista_enlazada.longitud());
    EXPECT_EQ(primer_elemento, lista_enlazada.iesimo(0));
    EXPECT_EQ(tercer_elemento, lista_enlazada.iesimo(1));
}

TEST(ListaEnlazada, 08_puedo_borrar_el_unico_elemento) {
    ListaEnlazada lista_enlazada;
    const int unico_elemento = 2;

    lista_enlazada.agregarAtras(unico_elemento);
    
    lista_enlazada.borrarUltimo();

    EXPECT_EQ(0, lista_enlazada.longitud());

    lista_enlazada.agregarAtras(unico_elemento);
    
    lista_enlazada.borrarIesimo(0);

    EXPECT_EQ(0, lista_enlazada.longitud());
}

TEST(ListaEnlazada, 09_puedo_borrar_el_primer_elemento) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.borrarIesimo(0);

    EXPECT_EQ(2, lista_enlazada.longitud());
    EXPECT_EQ(segundo_elemento, lista_enlazada.iesimo(0));
    EXPECT_EQ(tercer_elemento, lista_enlazada.iesimo(1));
}

TEST(ListaEnlazada, 10_actual_es_el_primer_elemento_agregado) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    

    EXPECT_EQ(primer_elemento, lista_enlazada.actual());
}

TEST(ListaEnlazada, 11_si_se_borra_el_actual_se_apunta_al_siguiente) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.borrarIesimo(0);

    EXPECT_EQ(segundo_elemento, lista_enlazada.actual());
}

TEST(ListaEnlazada, 12_puedo_avanzar_actual_al_siguiente_elemento_en_orden) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.avanzar();

    EXPECT_EQ(segundo_elemento, lista_enlazada.actual());
}

TEST(ListaEnlazada, 13_si_se_avanza_el_ultimo_elemento_se_vuelve_al_ppio) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.avanzar();
    lista_enlazada.avanzar();
    lista_enlazada.avanzar();

    EXPECT_EQ(primer_elemento, lista_enlazada.actual());
}

TEST(ListaEnlazada, 14_puedo_retroceder_al_anterior_elemento_en_orden) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.avanzar();
    lista_enlazada.avanzar();
    lista_enlazada.retroceder();

    EXPECT_EQ(segundo_elemento, lista_enlazada.actual());
}

TEST(ListaEnlazada, 15_si_retrocedo_el_primero_vuelvo_al_ultimo) {
    ListaEnlazada lista_enlazada;
    const int primer_elemento = 2;
    const int segundo_elemento = 10;
    const int tercer_elemento = 18;

    lista_enlazada.agregarAtras(primer_elemento);
    lista_enlazada.agregarAtras(segundo_elemento);
    lista_enlazada.agregarAtras(tercer_elemento);
    
    lista_enlazada.retroceder();

    EXPECT_EQ(tercer_elemento, lista_enlazada.actual());
}
