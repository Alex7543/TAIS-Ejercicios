// Nombre del alumno: Alejandro Castillo Jiménez

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

long long int resolver(long long int n_datos) {
    long long int dato;
    priority_queue<long long int, vector<long long int>, greater<long long int>> list;
    for (long long int i = 0; i < n_datos; i++) {
        cin >> dato;
        list.push(dato);
    }
    long long int valor_acumulado = 0, num1, num2, numres;
    while (list.size() > 1) {
        num1 = list.top();
        list.pop();
        num2 = list.top();
        list.pop();
        numres = num1 + num2;
        valor_acumulado += numres;
        list.push(numres);
    }
    return valor_acumulado;
}


bool resuelveCaso() {
    long long int num_datos;
    cin >> num_datos;
    if (num_datos == 0)
        return false;

    cout << resolver(num_datos) << '\n';
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
