// Nombre del alumno: Alejandro Castillo Jiménez


using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>

struct client {
    int time;
    int box;

    bool operator>(const client& other) const {
        if (this->time == other.time)
            return this->box > other.box;
        return this->time > other.time;
    }
};

bool resuelveCaso() {
    int num_boxes, num_clients;
    cin >> num_boxes >> num_clients;
    if (num_boxes == 0 && num_clients == 0)
        return false;
    client new_cl;
    vector<client> list;
    list.resize(num_clients);
    for (int i = num_clients - 1; i >= 0; i--) {
        cin >> new_cl.time;
        list[i] = new_cl;
    }

    // Si hay mas cajas libres que clientes, devolvemos la caja libre mas cercana
    if (num_boxes > num_clients)
        cout << num_clients + 1 << '\n';
    else {
        // En caso contrario asignamos a los primeros [num_boxes] clientes a las cajas en orden
        int res = 0;
        priority_queue<client, vector<client>, greater<client>> box_queue;
        for (int i = 0; i < num_boxes; i++) {
            new_cl = list[list.size() - 1];
            list.pop_back();
            new_cl.box = i + 1;
            box_queue.push(new_cl);
        }
        // Si no quedan mas clientes en la cola, devolvemos la primera caja en quedar libre
        if (list.empty())
            cout << box_queue.top().box << '\n';
        // una vez las cajas han sido rellenadas, vamos removiendo los clientes según terminen y añadiendo nuevos a dichas cajas hasta que vaciemos "list"
        else {
            while (list.size() > 0) {
                new_cl = box_queue.top();
                box_queue.pop();
                list[list.size() - 1].box = new_cl.box;
                list[list.size() - 1].time += new_cl.time;
                box_queue.push(list[list.size() - 1]);
                list.pop_back();
            }
            cout << box_queue.top().box << '\n';
        }
    }
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
