#include "listaEnlazada.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/********** Implementación de código ***************/
void inicializarLista(lista *lis, char* type){
  lis ->inicio = NULL;
  lis ->fin = NULL;
  lis ->size = 0;
  strcpy(lis->tipo,type);
}

int insertEmptyList(lista *lis, char* nombre, char* des, int inicio, int fin){
  int retorno = 0;
  actividad *nuevo;
  if((nuevo = reservarMemoria(nuevo)) == NULL)
    retorno = -1;
  else{
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo-> descripcion, des);
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    lis ->inicio = nuevo;
    lis ->fin = nuevo;
    lis ->size++;
    retorno =0;
  }
  return retorno;  
}

int insertBegining(lista *lis, char* nombre, char* des, int inicio, int fin){
  actividad *nuevo;
  int retorno = 0;
  if((nuevo = reservarMemoria(nuevo)) == NULL)
    retorno = -1;
  else{
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo-> descripcion, des);
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    nuevo->anterior = NULL;
    nuevo->siguiente = lis->inicio;
    lis->inicio->anterior= nuevo;
    lis->inicio = nuevo;
    lis-> size++;
    retorno = 0;
  }
  return retorno;
}

int insertEnd(lista *lis, char* nombre, char* des, int inicio, int fin){
  actividad *nuevo;
  int retorno =0;
  if((nuevo = reservarMemoria(nuevo))== NULL)
    retorno = -1;
  else{
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo-> descripcion, des);
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    nuevo->siguiente = NULL;
    nuevo->anterior = lis->fin;
    lis->fin->siguiente = nuevo;
    lis->fin = nuevo;
    lis->size++;
    retorno = 0;
  }
  return retorno;
}

int insertBefore(lista *lis, int pos, char* nombre, char* des, int inicio, int fin){
  actividad *nuevo, *current;
  int retorno = 0;
  if((nuevo = reservarMemoria(nuevo))==NULL)
    retorno = -1;
  else{
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo-> descripcion, des);
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    current = lis->inicio;
    for(int i = 1; i<pos; i=i+1){
      current = current->siguiente;
    }
    nuevo->siguiente = current;
    nuevo->anterior = current->anterior;
    if(current->anterior == NULL)
      lis->inicio = nuevo;
    else
      current->anterior->siguiente=nuevo;
    current->anterior =  nuevo;
    lis-> size++;
    retorno = 0;
  }
  return retorno;
}


int insertAfter(lista *lis, int pos, char* nombre, char* des, int inicio, int fin){
  actividad *nuevo, *current;
  int retorno = 0;
  if((nuevo = reservarMemoria(nuevo))==NULL)
    retorno = -1;
  else{
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo-> descripcion, des);
    nuevo->horaInicio = inicio;
    nuevo->horaFin = fin;
    current = lis->inicio;
    for(int i = 1; i<pos; i=i+1){
      current = current->siguiente;
    }
    nuevo->siguiente = current->siguiente;
    nuevo->anterior = current;
    if(current->siguiente == NULL)
      lis->fin = nuevo;
    else
      current->siguiente->anterior = nuevo;
    current->siguiente = nuevo;
    lis->size++;
    retorno = 0 ;
  }
  return retorno;
}

void imprimir(lista *lis){
  actividad *current;
  current = lis->inicio;
  printf("\n************IMPRESION DE LISTA DOBLEMENTE ENLAZADA ********************* \n");
  while(current != NULL){
    printf("%s",strcat(current->nombre,"\n"));
    current = current->siguiente;
  }
}

actividad *reservarMemoria(actividad *nuevo){
  if((nuevo = (actividad *)malloc(sizeof(actividad)))== NULL){
    return NULL;
  }
  if((nuevo->nombre = (char *)malloc(80*sizeof(char)))== NULL){
    return NULL;
  }
  if((nuevo->descripcion = (char *)malloc(120*sizeof(char)))==NULL)
    {
      return NULL;
    }
  nuevo->horaInicio = 0;
  nuevo->horaFin = 0;    
  return nuevo;
}

int delete(lista *lis, int pos){
  int i;
  actividad *candidato, *current;
  if(lis->size ==0){
    return -1;
  }
  if(pos ==1){
    candidato = lis->inicio;
    lis->inicio = lis->inicio->siguiente;
    if(lis->inicio == NULL)
      lis->fin = NULL;
    else
      lis->inicio->anterior = NULL;
  }else if(pos == lis->size){
    candidato = lis->fin;
    lis->fin->anterior->siguiente = NULL;
    lis->fin = lis->fin->anterior;
  }else{
    current = lis->inicio;
    for(i=1;i<pos;i=i+1){
      current = current->siguiente;
    }
    candidato = current;
    current->anterior->siguiente = current->siguiente;
    current->siguiente->anterior = current->anterior;
  }
  free(candidato->nombre);
  free(candidato->descripcion);
  free(candidato);
}

int sortedInsert(lista *lis,char* nombre, char* des, int inicio, int fin){
  int posi = findPosition(lis, inicio);
  printf("%d",posi);
  if(posi == 0)
    insertBegining(lis, nombre, des, inicio, fin);
  else
    insertAfter(lis, posi, nombre, des, inicio, fin);
}

int findPosition(lista *lis, int hora)
{
  int pos = 1;
  actividad *current, *nuevo;
  if((nuevo = reservarMemoria(nuevo)) == NULL)
    return -1;
  current = lis->inicio;
  if(lis->size ==1){
    printf("Entré acá viteh");
    if(hora> current->horaInicio){
      printf("Si es mayor");
      pos = pos +1;
    }else{
      pos = 0;
    }
  }else{
    while(hora > current->horaInicio && current->siguiente != NULL)
      {
	current = current->siguiente;      
	pos = pos +1;
      }
  }
  if(pos == 1)
    pos = 0;
    return pos;
}
