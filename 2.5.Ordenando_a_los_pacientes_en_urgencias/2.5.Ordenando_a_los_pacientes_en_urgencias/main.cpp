// Nombre del alumno: Alejandro Castillo y Diego Montero Blanco

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

struct persona {
    int turno;
    int urgencia;
    string nombre;

    bool operator<(const persona &other) const {
        if (this->urgencia == other.urgencia)
            return this->turno > other.turno;
        return this->urgencia < other.urgencia;
    }
};

void resolver(int num_datos) {
    char accion;
    persona pers;
    priority_queue<persona> list;
    int turn = 0;
    for (int i = 0; i < num_datos; i++) {
        cin >> accion;
        if (accion == 'I') {
            cin >> pers.nombre >> pers.urgencia;
            pers.turno = turn;
            list.push(pers);
            turn++;
        }
        else { // accion == A
            cout << list.top().nombre << '\n';
            list.pop();
        }
    }
    cout << "---" << '\n';
}


bool resuelveCaso() {
    int num_casos;
    cin >> num_casos;
    if (num_casos == 0)
        return false;

    resolver(num_casos);

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