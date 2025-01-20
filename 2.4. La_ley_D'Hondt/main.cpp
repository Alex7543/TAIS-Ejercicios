// Nombre del alumno: Alejandro Castillo Jiménez

using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

struct candidatura {
    float escanos;
    float votos;
    float indice;

    bool operator<(const candidatura& other) const {
        if (this->votos / (this->escanos + 1) == other.votos / (other.escanos + 1)) {
            if (this->votos == other.votos)
                return this->indice > other.indice;
            else
                return this->votos < other.votos;
        }
        else
            return this->votos / (this->escanos + 1) < other.votos / (other.escanos + 1);
    }
};

void resolver(int cand, int esc) {
    candidatura candit;
    priority_queue<candidatura> list;
    int votos;
    vector<int> escanos_totales;
    for (int i = 0; i < cand; i++) {
        cin >> votos;
        escanos_totales.push_back(0);
        list.push({ 0, float(votos), float(i) });
    }
    for (int i = 0; i < esc; i++) {
        candit = list.top();
        list.pop();
        candit.escanos++;
        escanos_totales[candit.indice]++;
        list.push(candit);
    }
    for (int i = 0; i < escanos_totales.size(); i++)
        cout << escanos_totales[i] << " ";
    cout << '\n';
}


bool resuelveCaso() {
    int num_candidaturas, num_escanos;
    cin >> num_candidaturas >> num_escanos;
    if (num_candidaturas == 0 && num_escanos == 0)
        return false;

    resolver(num_candidaturas, num_escanos);

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