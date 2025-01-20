// Nombre del alumno: Alejandro Castillo y Diego Montero Blanco

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

struct music_group {
    int num_comp;
    int num_part;

    bool operator<(const music_group& other) const {
        return float(this->num_comp) / float(this->num_part) < float(other.num_comp) / float(other.num_part);
    }
};

int resolver(int n_part, int n_inst) {
    float res = 0;
    int num_musicos;
    priority_queue<music_group> musicos;
    music_group aux;
    for (int i = 0; i < n_inst; i++) {
        cin >> num_musicos;
        musicos.push({ num_musicos, 1 });
        n_part--;
    }
    while (n_part > 0) {
        aux = musicos.top();
        musicos.pop();
        aux.num_part++;
        n_part--;
        musicos.push(aux);
    }
    res = musicos.top().num_comp / musicos.top().num_part;
    if (musicos.top().num_comp % musicos.top().num_part == 0)
        return res;
    return res + 1;
}


bool resuelveCaso() {
    int num_partituras;
    cin >> num_partituras;
    if (!cin)
        return false;
    int num_instrumentos;
    cin >> num_instrumentos;

    int sol = resolver(num_partituras, num_instrumentos);
    cout << sol << '\n';
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