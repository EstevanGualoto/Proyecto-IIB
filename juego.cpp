#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib> 

using namespace std;
struct Jugador {
    string nombre;
    int puntaje;
};
void mostrarMenu() {
    cout << "Preguntas y respuestas\n";
    cout << "Menu:\n";
    cout << "1. Jugar\n";
    cout << "2. Puntajes\n";
    cout << "3. Créditos\n";
    cout << "4. Salir\n";
}
void jugar(vector<Jugador>& jugadores) {
    string nombre;
    int puntaje = 0;
    cout << "Ingrese su nombre: ";
    getline(cin, nombre);
    cout << "Hola " << nombre << ", vamos a empezar el juego de preguntas y respuestas!\n";
    cout << "Responde las siguientes preguntas escribiendo la opción correcta (a, b o c).\n";
    cout << "\nPregunta 1: ¿Qué es C++?\n";
    cout << "a) Un lenguaje de programación.\n";
    cout << "b) Una fruta.\n";
    cout << "c) Un país.\n";
    char respuesta1;
    cin >> respuesta1;
    if (respuesta1 == 'a' || respuesta1 == 'A') {
        cout << "¡Respuesta correcta!\n";
        puntaje++;
    } else {
        cout << "Respuesta incorrecta.\n";
    }

    cout << "\nPregunta 2: ¿Qué es una clase en C++?\n";
    cout << "a) Un tipo de dato.\n";
    cout << "b) Una función.\n";
    cout << "c) Un vehículo.\n";
    char respuesta2;
    cin >> respuesta2;
    if (respuesta2 == 'a' || respuesta2 == 'A') {
        cout << "¡Respuesta correcta!\n";
        puntaje++;
    } else {
        cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 3: ¿Qué es 'cout' en C++?\n";
    cout << "a) Una palabra reservada.\n";
    cout << "b) Una operación aritmética.\n";
    cout << "c) Para mostrar salida en la consola.\n";
    char respuesta3;
    cin >> respuesta3;
    if (respuesta3 == 'c' || respuesta3 == 'C') {
        cout << "¡Respuesta correcta!\n";
        puntaje++;
    } else {
        cout << "Respuesta incorrecta.\n";
    }
    Jugador jugador = {nombre, puntaje};
    jugadores.push_back(jugador);
}
void mostrarPuntajes(const vector<Jugador>& jugadores) {
    cout << "Puntajes:\n";
    vector<Jugador> sortedJugadores = jugadores;
    sort(sortedJugadores.begin(), sortedJugadores.end(), [](const Jugador& a, const Jugador& b) {
        return a.puntaje > b.puntaje;
    });

    for (int i = 0; i < min(static_cast<int>(sortedJugadores.size()), 3); i++) {
        cout << i + 1 << ". " << sortedJugadores[i].nombre << ": " << sortedJugadores[i].puntaje << "\n";
    }
}
void mostrarCreditos() {
    cout << "Desarrollado por:\n";
    cout << "- Integrante 1\n";
    cout << "- Integrante 2\n";
    cout << "- Integrante 3\n";
}
int main() {
    vector<Jugador> jugadores;
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                jugar(jugadores);
                break;
            case 2:
                mostrarPuntajes(jugadores);
                break;
            case 3:
                mostrarCreditos();
                break;
            case 4:
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
    return 0;
}