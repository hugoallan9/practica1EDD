#include "listaEnlazada.h"


typedef struct nodoDia{
  int year;
  int month;
  int day;
  struct nodoDia *anterior;
  struct nodoDia *siguiente;
  lista *listaActividades;
}dia;

typedef struct listaDia{
  dia *inicio;
   int tam;
}calendario;


void imprimirNodos(calendario *cal);
void inicializar(calendario *cal);
dia *buscarNodo(calendario *cal, int  ano, int mes, int day);
int buscarPos(calendario *cal, int ano, int mes, int day);
int insertarVacia(calendario *cal, int ano, int mes, int day);
int insertarInicio(calendario *cal, int ano, int mes, int day);
int insertarInicioModi(calendario *cal, int ano, int mes, int day, dia *n);
int insertarFinal(calendario *cal, int ano, int mes, int day);
dia *insertarAntes(dia *nodo, int ano, int mes, int day);
dia *insertarDespues(calendario *cal, int pos, int  ano, int mes, int day);
int insertarOrdenado(calendario *cal, int ano, int mes, int day);

int borrarNodo(calendario *cal, int pos); void inicializar(calendario *cal);
dia *reservarMemo(dia *nodo);
void graficar(calendario *cal);
int existeNodo(calendario *cal, int ano, int mes, int day);

  
