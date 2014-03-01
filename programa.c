#include "enlazadaCircular.h"
#include "programa.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  lista *list;
  list = (lista *)malloc(sizeof(lista));
  insertEmptyList(list,"Actividad 1", "prueba", 1130, 1490);
  sortedInsert(list, "Actividad 2", "",900, 1320);
  sortedInsert(list, "Actividad 3", "hola", 1430, 1234);
  sortedInsert(list, "Actividad 4", "hola", 730, 1334);
  sortedInsert(list, "Actividad 5", "hola", 1730, 1334);
  sortedInsert(list, "Actividad 6", "hola", 430, 1334);
  imprimir(list);
  calendario *cal;
  cal = (calendario *)malloc(sizeof(calendario));
  inicializar(cal);
  insertarVacia(cal, 2011,10, 10);
  insertarOrdenado(cal, 2006, 8,9);
  insertarOrdenado(cal, 2000, 8,90);
  int pos = existeNodo(cal, 2007,8,9);
  printf("La posicion de existencia del nodo es: %d", pos);
  cal->inicio->listaActividades= list;
  imprimirNodos(cal);
  graficar(cal);

  menuPrincipal();
  

  return -1;
 }


void menuPrincipal()
{
  printf("\n****************************AGENDA ELECTRONICA************************\n");
  printf("POR FAVOR INGRESA EL AÑO\n");
  scanf("%d",&ano);
  printf("POR FAVOR INGRESA EL MES\n");
  scanf("%d",&mes);
  printf("POR FAVOR INGRESA EL DIA\n");
  scanf("%d",&day);



}
