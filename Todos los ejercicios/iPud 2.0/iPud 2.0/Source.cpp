//Grupo E29, Laura Jiménez Fernández y E63, Pablo de Torre Barrio
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <string>
#include <exception>
#include "hashmap_eda.h"
#include "Header.h"



/* Describir lo que hace la función */


/* Coste de la función */


bool resuelveCaso() {
	std::string comando;
	std::cin >> comando;

	if (!std::cin) return false;

	std::string cancion, autor, nombre;
	int duracion, n;
	canciones can;
	if (comando != "FIN") {
		while (comando != "FIN") {
			try {
				if (comando == "addSong") {
					std::cin >> cancion >> autor >> duracion;
					can.addSong(cancion, autor, duracion);
				}
				//Ponía addToPlayList y no addToPlaylist
				else if (comando == "addToPlaylist") {
					std::cin >> cancion;
					can.addToPlayList(cancion);
				}
				else if (comando == "current") {
					std::string actual = can.current();
				}
				else if (comando == "play") {
					std::string sonando = can.play();
					if (sonando.length() > 0) std::cout << "Sonando " << sonando << '\n';
				}
				else if (comando == "totalTime") {
					int tiempo = can.totalTime();
					std::cout << "Tiempo total " << tiempo << '\n';
				}
				else if (comando == "recent") {
					std::cin >> n;
					std::string recientes = can.recent(n);
					std::cout << recientes;
				}
				else if (comando == "deleteSong") {
					std::cin >> cancion;
					can.deleteSong(cancion);
				}
				else if (comando == "saveCurrentList") {
					std::cin >> nombre;
					can.saveCurrentList(nombre);
				}
				else if (comando == "generateArtistList") {
					std::cin >> autor;
					can.generateArtistList(autor);
				}
				else if (comando == "setPlaylist") {

				}
				else if (comando == "allLists") {

				}

				}
			catch (std::domain_error e) {
				std::cout << e.what();
			}
			std::cin >> comando;
		}
			
	}
	
	std::cout << "----" << '\n';

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	while (resuelveCaso())
		;

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}