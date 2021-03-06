/* Cabecera para lista enlazada */

/***** Definición de variables a usar */
typedef struct nodoActividad{
  char* nombre;
  char* descripcion;
  int horaInicio, horaFin;
  struct nodoActividad *anterior;
  struct nodoActividad *siguiente;
}actividad;

typedef struct caracteristicaLista{
  actividad *inicio;
  actividad *fin;
  int size;
  char* tipo;
}lista;

/*Metodo que inicializa la lista */
void inicializarLista(lista * lis, char* type);


/********************Metodos para insercion***************/
int insertEmptyList(lista *lis, char* nombre, char* des, int inicio, int fin);
int insertBegining(lista *lis, char* nombre, char* des, int inicio, int fin);
int insertEnd(lista *lis, char* nombre, char* des, int inicio, int fin);
int insertAfter(lista *lis, int pos, char* nombre, char* des, int inicio, int fin);
int insertBefore(lista *lis, int pos, char* nombre, char* des, int inicio, int fin);
int findPosition(lista *lis, int hora);
int sortedInsert(lista *lis, char* nombre, char* des, int inicio, int fin);
/*******************Metodo para eliminacion****************/
int delete(lista *lis, int );

/******************Metodo para reservar memoria***********/
actividad *reservarMemoria(actividad *nuevo);

/*******************Impresión de la lista******************/
void imprimir(lista *lis);

/******************Método para graficar lista ************/
void graficarLista(lista *lis);

