/* HEADER
 * Este programa regresa el arreglo de substring alfabeticamente dado un string.
 * Complejidad computacional:
 * 1. Generar sufijos: O(n^2) - Se crean n sufijos y cada uno puede tener hasta n caracteres.
 * 2. Ordenar sufijos: O(n Log n) - Se ordenan n sufijos alfabeticamente
 * 3. Extraer índices: O(n) - Se recorre el vector ordenado para extraer sus índices.
 * Total: O(n^2) (de acuerdo con la generación de sufijos)
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
  vector<pair<string, int>> sa; // Vector para almacenar los sufijos y sus índices
  vector<int> A;
  S = S + "$";
  // Se generan los sufijos y almacenan sus índices 
  // Complejidad: O(n^2)
  for (int i = 0; i < n; i++){
    sa.push_back({S.substr(i), i + 1}); 
  }

  // Se ordenan los sufijos alfabeticamente
  // Complejidad: O(n Log n)
  sort(sa.begin(), sa.end());

  // Se extrae el indice de los sufijos ya ordenados
  // Complejidad: O(n)
  for (auto &p : sa){
    A.push_back(p.second); // Se agrega el indice inicial, es decir 1
  }
  return A;

}

int main(){
  string s;
  cout << "Dame tu input por favor: ";
  getline(cin, s); // Se lee el input dado por el usuario
  vector<int> suffixArray = suffix_array_maive(s);
  // Se imprime el indice de los sufijos, uno por linea
  for (int index : suffixArray){
    cout << index << endl;
  }
}
