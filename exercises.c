#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
//#include "exercises.h"

/* 
Ejercicio 1.
Función que recibe 3 parámetros (a, b y c), 
y en c almacena el valor de la suma de a más b.
*/

void suma(int a, int b, int * c) {
  *c = a + b;
}

/*
Esta función suma los N primeros números del arreglo a
*/
int sumaN(int a[], int N) {
    int i;
    int tot = 0;
  
    for(i = 0; i < N; i++) {
      tot += a[i];
    }

    return tot;
}

/*
Ejercicio 2.
Esta función debe sumar los últimos m números del 
arreglo a y almacena el resultado en *suma.
Utilice la función sumaN.
*/

void sumaNultimos(int a[], int n, int m, int * suma) {

*suma = sumaN(a, n) - sumaN(a, n-m); //para obtener lo que nos piden, restamos n-m del total para obtener lo que nos piden.
}

/*
Ejercicio 3.
Considerando la estructura Persona, programe la función
crearPersona(...), la cual crea una nueva persona con 
los datos correspondientes y retorna un puntero al dato 
recién creado.
*/
typedef struct {
  char nombre[30];
  char rut[11];
  int edad;
} Persona;


Persona* crearPersona(char nombre[], char rut[], int edad) {
  Persona* p=(Persona*)malloc(sizeof(Persona));
  strcpy(p->nombre,nombre); // como ambos son de tipo char, lo almacenamos en la función strcpy
  strcpy(p->rut,rut);
  p->edad = edad;
  
   return p;
}

/*
Ejercicio 4.
SSConsiderando la estructura "Vector", escriba 
la función Vector* crearVector(int n), la cual crea 
un vector con capacidad `n`, reserva la memoria 
correspondiente para el arreglo con `n` datos 
inicializados en 0 y luego retorna el vector creado.
*/
typedef struct {
   int * datos; // arreglo dinámico
   int capacidad; // capacidad del arreglo
} Vector;

Vector* crearVector(int n) {
  Vector *array = NULL;
  
  array = (Vector *) malloc(sizeof(Vector)); //primero reservamos memoria
  
  array -> datos = (int *)calloc(n,(sizeof(int))); // con la función calloc inicializamos los valores en cero.
  array-> capacidad = n;
  return array;
  
}

/*
Ejercicio 5a.
Programe la función void asignarValor(Vector * v, int i, int valor), 
la cual asigna el valor a la posición i del vector v.
*/
void asignarValor(Vector * v, int i, int valor) {
  v->datos[i] = valor; // de esta manera en cada posición de los datos, se le asignará un valor.
}

/*
Ejercicio 6.
Programe la función int obtenerValor(Vector * v, int i), 
la cual retorna el valor en la posición i del vector v.
*/
int obtenerValor(Vector * v, int i) {
  
   return v->datos[i]; // como anteriormente esto era lo que nos pedían, de esta misma manera lo retornamos.
}

/*
Ejercicio 7.
Función que suma los vectores `a` y `b` y 
actualiza el vector `c` con el resultado de la suma.
*/
void sumaV(Vector * a, Vector * b, Vector * c) {
  for (int i= 0 ; i < 3 ; i++){ //hacemos un for hasta 3, eran 3 elementos.
    
    c->datos[i] = a ->datos[i] + b->datos[i]; // sumamos los datos y los almacenamos en c.
    
  }

}

/*
Ejercicio 8.
Use las operaciones implementadas de vectores para 
sumar (a1,a2)+(b1+b2). Almacene el resultado en el vector c.
*/
void sumaV2(int a1, int a2, int b1, int b2, Vector *c){
  int i = 0;  //inicializamos el contador
  
  c-> datos[i] = ( a1 + b1 ); //como anteriormente, sumamos los valores y lo almacenamos en c.
  
  i++ ;
  
  c->datos[i] = ( a2 + b2 );

}
