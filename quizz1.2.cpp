#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Jugador {
    string nombre;
    int puntaje;
};
vector<Jugador> jugadores;
void jugar() {
    cout << "\nPregunta 1: ¿Qué es C++?\n";
    cout << "a) Un lenguaje de programación\n";
    cout << "b) Una bebida\n";
    cout << "c) Un sistema operativo\n";
    char respuesta1;
    cin >> respuesta1;
    if (respuesta1 == 'a' || respuesta1 == 'A') {
        cout << "¡Respuesta correcta!\n";
        jugadores.back().puntaje++;
    }else {
        cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 2: ¿Que es una clase en C++?\n";
    cout << "a) Un tipo de dato.\n";
    cout << "b) Una función.\n";
    cout << "c) Un vehículo.\n";
    char respuesta2;
    cin >> respuesta2;
    if (respuesta2 == 'a' || respuesta1 == 'A') {
        cout << "¡Respuesta correcta!\n";
        jugadores.back().puntaje++;
    }else {
        cout << "Respuesta incorrecta.\n";
    }
}
void mostrarPuntajes() {
    sort(jugadores.begin(), jugadores.end(), [](const Jugador &a, const Jugador &b) {
        return a.puntaje > b.puntaje;
    });

    cout << "\nPuntajes de los jugadores:\n";
    for (int i = 0; i < min(3, (int)jugadores.size()); i++) {
        cout << i + 1 << ". Nombre: " << jugadores[i].nombre << ", Puntaje: " << jugadores[i].puntaje << endl;
    }
}
void mostrarCreditos() {
    cout << "\nCréditos:\n";
    cout << "Este juego fue desarrollado por: \n";
}
int main() {
    char opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Jugar\n";
        cout << "2. Puntajes\n";
        cout << "3. Créditos\n";
        cout << "4. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcion;
        switch(opcion) {
            case '1':
                {
                    Jugador jugador;
                    cout << "Ingrese su nombre: ";
                    cin >> jugador.nombre;
                    jugador.puntaje = 0;
                    jugadores.push_back(jugador);
                    jugar();
                }
                break;
            case '2':
                mostrarPuntajes();
                break;
            case '3':
                mostrarCreditos();
                break;
            case '4':
                cout << "Saliendo del juego...\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elija de nuevo.\n";
        }
    } while(opcion != 'd');
    return 0;
}
