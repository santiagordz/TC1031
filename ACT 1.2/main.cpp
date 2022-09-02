// =================================================================
//
// File: main.cpp
// Author: Santiago Rodriguez Murialdo
// Date: 8/31/2022
//
// =================================================================

#include "arreglo.h"
#include "bubble.h"
#include "catch.h"
#include "header.h"
#include "search.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

int main(int argc, char* argv[]) {   
   Arreglo datos, valores;
   
   //====================================================================
   //Desplegar num de comparaciones que hace cada algoritmo de busqueda
   //
   //Orden: Bubble, Sort, Insertion
   //====================================================================
   datos.leerDatos("input4.txt");
   cout << bubbleSort(datos.getDatos(), datos.getSize()) << " ";
   datos.borrar();
   datos.leerDatos("input4.txt");
   cout << selectionSort(datos.getDatos(), datos.getSize()) << " ";
   datos.borrar();
   datos.leerDatos("input4.txt");
   cout << insertionSort(datos.getDatos(), datos.getSize());
   cout << endl;

   //=======================================================================
   //Desplegar las en cada linea:
   //posicion, num comparaciones secuencial, num comparaciones binarias
   //=======================================================================
   valores.leerValores("input4.txt");
   cout << endl;
   for(int i=0; i<valores.getSize(); i++){
      cout << sequentialSearch(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << " " 
      << cantSequential(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << " "
      << cantBinary(datos.getDatos(), datos.getSize(), valores.getDatos()[i]) << endl;
   }




   return 0;
}