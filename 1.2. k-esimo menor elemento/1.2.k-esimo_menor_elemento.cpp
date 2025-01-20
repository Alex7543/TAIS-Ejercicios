/* @ <authors>
 * TAIS019 Alejandro Castillo Jiménez
 * @ </authors>
 */

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include "TreeSet_AVL.h"


bool resuelveCaso() {
    int num_elems;
    cin >> num_elems;
    if (num_elems == 0)
        return false;
    Set<int> tree;
    int aux;
    for (int i = 0; i < num_elems; i++) {
        cin >> aux;
        tree.insert(aux);
    }
    int num_k, k, res;
    cin >> num_k;
    for (int i = 0; i < num_k; i++) {
        cin >> k;
        try {
            cout << tree.kesimo(k) << '\n';
        }
        catch (out_of_range e) {
            cout << e.what() << '\n';
        }
    }
    cout << "---" << '\n';
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
