
/*@ <authors>
 *
 *	Alejandro Castillo Jiménez TAIS019
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "bintree.h"

using namespace std;

const char CASO_ENTEROS = 'N';
const char CASO_PALABRAS = 'P';

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct res {
	bool is_AVL;
	int deepth;
	res() {
		is_AVL = true;
		deepth = 0;
	}
	res(bool _is_AVL, int _deepth) {
		is_AVL = _is_AVL;
		deepth = _deepth;
	}
};

res is_AVL_palabras(BinTree <string> const& tree) {

	// If the tree is empty, it is AVL and it's depth 0
	if (tree.empty())
		return { true, 0 };

	// If any of the branches is not AVL, neither is the root
	res left = is_AVL_palabras(tree);
	if (!left.is_AVL)
		return { false, 0 };
	res right = is_AVL_palabras(tree);
	if (!right.is_AVL)
		return { false, 0 };

	// If the diference between branches is more than 1, the tree is not AVL
	if (abs(left.deepth - right.deepth) > 1)
		return { false, 0 };

	// If the right branch is lesser than the root of the left is more than the root, the tree is not AVL
	if (!tree.left().empty() && tree.left().root() > tree.root())
		return { false, 0 };
	if (!tree.right().empty() && tree.right().root() < tree.root())
		return { false, 0 };

	// If the tree fulfills all the requirements, it is AVL
	return { true, max(left.deepth, right.deepth) + 1 };
}

bool arbol_palabras() {
	BinTree <string> tree;
	string line;
	getline(cin, line);
	tree.preorder(line);
	return is_AVL_palabras(tree).is_AVL;
}

res is_AVL_enteros(BinTree <int> const & tree){

	// If the tree is empty, it is AVL and it's depth 0
	if (tree.empty())
		return { true, 0 };

	// If any of the branches is not AVL, neither is the root
	res left = is_AVL_enteros(tree);
	if (!left.is_AVL)
		return { false, 0 };
	res right = is_AVL_enteros(tree);
	if (!right.is_AVL)
		return { false, 0 };

	// If the diference between branches is more than 1, the tree is not AVL
	if (abs(left.deepth - right.deepth) > 1)
		return { false, 0 };

	// If the right branch is lesser than the root of the left is more than the root, the tree is not AVL
	if(!tree.left().empty() && tree.left().root() > tree.root())
		return { false, 0 };
	if (!tree.right().empty() && tree.right().root() < tree.root())
		return { false, 0 };

	// If the tree fulfills all the requirements, it is AVL
	return { true, max(left.deepth, right.deepth) + 1 };
}

bool arbol_enteros() {
	BinTree <int> tree;
	string line;
	getline(cin, line);
	tree.preorder(line);
	return is_AVL_enteros(tree).is_AVL;
}

bool resuelveCaso() {
	char type;
	cin >> type;
	
	if (!std::cin)  // fin de la entrada
		return false;

	bool solution = false;

	if (type == CASO_ENTEROS)
		solution = arbol_enteros();

	else if (type == CASO_PALABRAS)
		solution = arbol_palabras();

	if (solution)
		cout << "SI" << '\n';
	else
		cout << "NO" << '\n';

	return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	if (!in.is_open())
		std::cout << "Error: no se ha podido abrir el archivo de entrada." << std::endl;
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	std::cout << "Pulsa Intro para salir..." << std::flush;
	std::cin.get();
#endif
	return 0;
}
