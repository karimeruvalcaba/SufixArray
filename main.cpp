/* HEADER
 * Este código resuelve un laberinto utilizando las técnicas "Backtracking" junto con "Ramificación y poda".
 * Primero se inicializan las 3 variables necesarias oara almacenar las matrices de los laberintos tanto de entrada
 * como de las 2 soluciones previamente mencionadas.
 *
 * Para la solución que utiliza backtracking, se hace uso de la recursividad para verificar si la celda actual es válida
 * utilizando la función isValidPlace (La cual verifica que la celda se encuentre dentro de los límites del laberinto y que sea 1),
 * para después movernos a otra celda y restroceder si es que no se encuentra un camino
 * válido. Ésta función tiene como caso base el que la celda actual sea la celda objetivo [M-1, N-1].
 *
 * Por otro lado, para la solución que utiliza Ramificación y poda se hace uso de un queue para explorar las celdas de forma eficiente
 * mientras se evita explorar celdas ya visitadas. De forma similar a la solución con backtracking, primero se verfifica si la celda
 * actual es la equivalente al final del laberinto para después explorar el resto de las celdas del laberinto, agregándolas al queue
 * si es que éstas son válidas.
 *
 * Al final se implementa la función findSolutions para gestionar ambas soluciones e imprimirlas en la función main.
 */

/* AUTORES
 * Carlos Ernesto Soto Alarcón A01747990
 * Sergio Alfonso Casillas Santoyo A01424863
 * Karime Itzel Ruvalcaba Pérez A01656188
 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> suffix_array_maive(string S){
  int n = S.length();
  vector<pair<string, int>> sa;
  vector<int> A;
  S = S + "$";
  for (int i = 0; i < n; i++){
    sa.push_back({S.substr(i), i + 1});
  }
  sort(sa.begin(), sa.end());

  for (auto &p : sa){
    A.push_back(p.second);
  }
  return A;

}

int main(){
  string s;
  cout << "Dame tu input por favor: ";
  getline(cin, s);
  vector<int> suffixArray = suffix_array_maive(s);
  for (int index : suffixArray){
    cout << index << endl;
  }
}
