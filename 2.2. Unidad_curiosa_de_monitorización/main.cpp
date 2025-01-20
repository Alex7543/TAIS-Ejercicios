// Nombre del alumno: Alejandro Castillo Jiménez


using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

struct user {
    int id;
    int ping;
    int acum_time;

    bool operator>(const user& other) const {
        if (this->acum_time == other.acum_time)
            return this->id > other.id;
        return this->acum_time > other.acum_time;
    }
};

void resolver(priority_queue<user, vector<user>, greater<user>> list) {
    int num_res;
    cin >> num_res;
    user best;
    for (int i = 0; i < num_res; i++) {
        best = list.top();
        cout << best.id << '\n';
        best.acum_time += best.ping;
        list.pop();
        list.push(best);
    }
    cout << "---" << '\n';
}


bool resuelveCaso() {
    int num_datos;
    cin >> num_datos;
    if (num_datos == 0)
        return false;
    user new_us;
    priority_queue<user, vector<user>, greater<user>> list;
    for (int i = 0; i < num_datos; i++) {
        cin >> new_us.id >> new_us.ping;
        new_us.acum_time = new_us.ping;
        list.push(new_us);
    }

    resolver(list);

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
