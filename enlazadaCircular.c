#include "enlazadaCircular.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void inicializar(calendario *cal){
  cal = (calendario *)malloc(sizeof(calendario));
  cal->inicio = (dia *)malloc(sizeof(dia));
  cal->inicio->anterior = cal->inicio;
  cal -> inicio ->siguiente = cal->inicio;
  cal->tam = 0;
}

int insertarOrdenado(calendario *cal,int ano, int mes, int day){
  dia *node;
  if((node = reservarMemo(node)) == NULL)
    return -1;
  if(cal->tam ==1)
    {
      if(ano > cal->inicio->year)
	insertarDespues(cal,1, ano, mes, day);
      else if(ano == cal->inicio->year)
	{
	  if(mes > cal->inicio->month)
	    insertarDespues(cal,1, ano, mes, day);
	  else if( mes == cal->inicio->month)
	    {
	      if(day > cal->inicio->day)
		insertarDespues(cal,1, ano, mes, day);
	      else
		insertarInicio(cal,ano,mes,day);
	    }
	  else{
	    insertarInicio(cal,ano,mes,day);
	  }
	}
      else
	insertarInicio(cal,ano,mes,day);
    }
  else
    {
      dia *current = cal->inicio;
      int i =1;
      while(buscarNodo(cal, ano, mes, day) != current)
	{
	  i = i+1;
	  current= current->siguiente;
	}
      if(i == cal->tam)
	{
	  insertarInicio(cal, ano, mes, day);
	}
      else{
      printf(" En teoría la posición es: %d", i);
      insertarDespues(cal, i, ano, mes,day);
      }
    }

  
}

int insertarVacia(calendario *cal, int ano, int mes, int day){
  dia *nuevoVa;
  if((nuevoVa = (dia *) malloc(sizeof(dia))) == NULL)
    return -1;
  nuevoVa->year = ano;
  nuevoVa->month = mes;
  nuevoVa->day = day;
  nuevoVa->siguiente = nuevoVa;
  nuevoVa->anterior = nuevoVa;
  cal->inicio = nuevoVa;
  cal->tam++;
  return 0;
}
int insertarInicioModi(calendario *cal, int ano, int mes, int day, dia *n){

  dia *nuevoInicio;
  printf("\n Antes de asignar memoria: Anterior: %p - Actual: %p - Siguiente: %p \n", n->anterior, n, n->siguiente);
  if((nuevoInicio = reservarMemo(nuevoInicio)) == NULL)
    return -1;
  printf("\n La dirección de memoria del nodo inicio es: %p \n", nuevoInicio);
  printf("\n Después de asignar memoria: Anterior: %p - Actual: %p - Siguiente: %p \n", n->anterior, n, n->siguiente);
  printf("\n **************Antes de la insercion**********\n");
  imprimirNodos(cal);
    printf("\n **************Fin listado**********\n");
  nuevoInicio->year = ano;
  nuevoInicio->month = mes;
  nuevoInicio->day = day;
  nuevoInicio->anterior = cal->inicio->anterior;
  nuevoInicio->siguiente = cal->inicio;
  cal->inicio->anterior = nuevoInicio;
  cal->inicio = nuevoInicio;
  cal->inicio->anterior->siguiente = nuevoInicio;
  cal->tam++;

}

dia *reservarMemo(dia *nodo){
  if((nodo = (dia *)malloc(sizeof(dia))) == NULL)
    return NULL;
  else
    return 
      nodo;
}

int insertarInicio(calendario *cal, int ano, int mes, int day){
  dia *nuevoInicio;
  if((nuevoInicio = (dia *)malloc(sizeof(dia))) == NULL)
    return -1;
  printf("\n La dirección de memoria del nodo inicio es: %p \n", nuevoInicio);
  printf("\n **************Antes de la insercion**********\n");
  imprimirNodos(cal);
    printf("\n **************Fin listado**********\n");
  nuevoInicio->year = ano;
  nuevoInicio->month = mes;
  nuevoInicio->day = day;
  nuevoInicio->anterior = cal->inicio->anterior;
  nuevoInicio->siguiente = cal->inicio;
  cal->inicio->anterior = nuevoInicio;
  cal->inicio = nuevoInicio;
  cal->inicio->anterior->siguiente = nuevoInicio;
  cal->tam++;

}
 

dia *insertarDespues(calendario *cal, int pos, int  ano, int mes, int day){
  dia *nuevoNodo, *current, *prevNode, *nextNode;
  if((nuevoNodo = reservarMemo(nuevoNodo))==NULL)
    return nuevoNodo;
  else{
    nuevoNodo->year = ano;
    nuevoNodo->month = mes;
    nuevoNodo->day = day;
    current = cal->inicio;
    for(int i = 1; i<pos; i=i+1){
      printf("\n El nodo es: %p - %d\n", current, current->year);
      current = current->siguiente;
    }
    prevNode = current;
    nextNode = current->siguiente;
    nuevoNodo->siguiente = nextNode;
    nuevoNodo->anterior = prevNode;
    current->siguiente->anterior = nuevoNodo;
    current->siguiente = nuevoNodo;
    cal->tam++;
    return nuevoNodo;
  }

}

dia *buscarNodo(calendario *cal, int  ano, int mes, int day){
  dia *current;
  current = cal->inicio;
  printf("El tamano del calendario es: %d", cal->tam);
  for(int  i = 1; i<= cal->tam; i = i +1)
    {
      printf("\n La entrada al ciclo es:  %d \n ", i);
      if(ano > current->year){
	printf("\n Si soy mayor!!!\n");
	current = current->siguiente;
      }
      else if(ano == current->year)
	{
	  if(mes > current->month)
	    current = current->siguiente;
	  else if(mes == current->month)
	    {
	      if(day > current->day)
		current = current->siguiente;
	      else
		break;
	    }
	  else
	    break;
	}
      else{
	break;
      }
    }
  return current->anterior;;
}

dia *insertarAntes(dia *node, int ano, int mes, int day )
{
  dia *nuevo;
  dia *prevNode = node->anterior;

  nuevo = (dia *) malloc (sizeof(dia));
  nuevo->year = ano;
  nuevo-> month = mes;
  nuevo->day = day;
  nuevo->siguiente = node;
  nuevo->anterior = prevNode;
  node->anterior = nuevo;
  prevNode->siguiente = node;

  return nuevo;
}

void imprimirCal(calendario *cal){
  dia *current;
  current = cal->inicio;
  printf("\n************IMPRESION DE LISTA DOBLEMENTE ENLAZADA CIRCULAR ********************* \n");
  do{
    printf("%d %d %d \n",current->year, current->month,current->day);
    current = current->siguiente;
  }while(current!= cal->inicio);
}

void imprimirNodos(calendario *cal){
 dia *current;
  current = cal->inicio;
  printf("\n************IMPRESION DE LISTA DE NODOS ********************* \n");
  do{
    printf("Anterior %p - Actual %p -Siguiente %p- %d %d %d \n",current->anterior, current, current->siguiente,current->year, current->month,current->day);
    current = current->siguiente;
  }while(current != cal->inicio);
}

void imprimirVol(calendario *cal){
  dia *current;
  current = cal->inicio->anterior;
  printf("\n************IMPRESION DE LISTA DOBLEMENTE ENLAZADA CIRCULAR AL REVES ********************* \n");
  do{
    printf("%d %d %d \n",current->year, current->month,current->day);
    current = current->anterior;
  }while(current != cal->inicio-> anterior);
}

int existeNodo(calendario *cal, int ano, int mes, int day){
  dia *nod,*current;
  int pos=1;
  int encontrado = 0;
  if((nod = reservarMemo(nod)) == NULL)
    {
      return -1;
    }
  current = cal->inicio;
  for(pos; pos<cal->tam; pos=pos+1){
    if(ano != current->year)
      current = current->siguiente;
    else
      if(mes != current->month)
	continue;
      else
	if(day != current->day)
	  continue;
	else
	  encontrado = 1;
	  break;
  }
  if(encontrado == 1)
    return pos;
  else
    return -1;
  
}



void graficar(calendario *cal){
FILE *fichero;
 fichero=fopen("calendario.dot","w");
 fputs("digraph A{\n",fichero);
 fputs("rankdir=UD;",fichero);
 dia *aux = cal->inicio;
 do
   {
     fputs("\"",fichero);
     fprintf(fichero,"%d/%d/%d",aux->day,aux->month,aux->year);
     fputs("\"-> \"",fichero);
     fprintf(fichero,"%d/%d/%d",aux->siguiente->day,aux->siguiente->month,aux->siguiente->year);
     fputs("\"[rankdir=UD];\n",fichero);


     fputs("\"",fichero);
     fprintf(fichero,"%d/%d/%d",aux->day,aux->month,aux->year);
     fputs("\"-> \"",fichero);
     fprintf(fichero,"%d/%d/%d",aux->anterior->day,aux->anterior->month,aux->anterior->year);
     fputs("\"[rankdir=UD];\n",fichero);


     if(aux->listaActividades != NULL)
       {
	 fputs("\"",fichero);
	 fprintf(fichero,"%d/%d/%d",aux->day,aux->month,aux->year);
	 fputs("\"-> \"",fichero);
	 fprintf(fichero,"%s %s %d",aux->listaActividades->inicio->nombre,"Hora: ",aux->listaActividades->inicio->horaInicio);
	 fputs("\"-> \"",fichero);
	
	 lista *lis=aux->listaActividades;
	 actividad *auxact = lis->inicio->siguiente;
	 actividad *auxRetro = lis->fin;
	 do{
	   if(auxact != lis->inicio->siguiente){
	   fputs("\"",fichero);
	   fprintf(fichero,"%s %s %d",auxact->nombre,"Hora: ",auxact->horaInicio);
	   fputs("\"-> \"",fichero);
	   fprintf(fichero,"%s %s %d",auxact ->siguiente->nombre,"Hora: ",auxact->siguiente->horaInicio);
	   fputs("\"[rankdir=UD];\n",fichero);
	   
	   fputs("\"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro->nombre,"Hora: ",auxRetro->horaInicio);
	   fputs("\"-> \"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro ->anterior->nombre,"Hora: ",auxRetro->anterior->horaInicio);
	   fputs("\"[rankdir=UD];\n",fichero);
	   }
	   else{
	   fprintf(fichero,"%s %s %d",auxact->nombre,"Hora: ",auxact->horaInicio);
	   fputs("\"-> \"",fichero);
	   fprintf(fichero,"%s %s %d",auxact ->siguiente->nombre,"Hora: ",auxact->siguiente->horaInicio);
	   fputs("\"[rankdir=UD];\n",fichero);

	   fputs("\"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro->nombre,"Hora: ",auxRetro->horaInicio);
	   fputs("\"-> \"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro ->anterior->nombre,"Hora: ",auxRetro->anterior->horaInicio);
	   fputs("\"[rankdir=UD];\n",fichero);
	   
	   }
	   auxRetro = auxRetro->anterior;
	   auxact = auxact->siguiente;
	 }while(auxact != aux->listaActividades->fin );

	 	   
	   fputs("\"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro->nombre,"Hora: ",auxRetro->horaInicio);
	   fputs("\"-> \"",fichero);
	   fprintf(fichero,"%s %s %d",auxRetro ->anterior->nombre,"Hora: ",auxRetro->anterior->horaInicio);
	   fputs("\"[rankdir=UD];\n",fichero);

       }
     
     
         
     /*lista *auxact=aux->listaActividades;
     do
       {
	 if(auxact->siguiente!=NULL)
	   {
	     fputs("\"",fichero);
	     fprintf(fichero,"%d",auxact->horaInicio);
	     fputs("\"-> \"",fichero);
	     fprintf(fichero,"%d",auxact->siguiente->horaInicio);
	     fputs("\"[rankdir=UD];\n",fichero);
	   }
	 if(auxact->anterior!=NULL)
	   {
	     fputs("\"",fichero);
	     fprintf(fichero,"%d",auxact->anterior->horaInicio);
	     fputs("\"-> \"",fichero);
	     fprintf(fichero,"%d",auxact->horaInicio);
	     fputs("\"[rankdir=UD];\n",fichero);
	   }
	 auxact=auxact->siguiente;
       }
     while (auxact!=NULL);
            
     */       
            
     aux=aux->siguiente;
            
   }
 while (aux!=cal->inicio);
            
 fputs("}",fichero);
 fclose(fichero);
        
}
