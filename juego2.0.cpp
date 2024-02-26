#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Jugador {
    string nombre;
    int puntaje;
};
void cargarPuntajes(vector<Jugador>& jugadores);
void guardarPuntajes(const vector<Jugador>& jugadores);
void mostrarMenu();
void jugar(vector<Jugador>& jugadores);
void mostrarPuntajes(const vector<Jugador>& jugadores);
void mostrarCreditos();
int main() {
    vector<Jugador> jugadores;
    cargarPuntajes(jugadores);

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
    guardarPuntajes(jugadores);
    return 0;
}
void cargarPuntajes(vector<Jugador>& jugadores) {
    ifstream archivo("puntajes.txt");
    if (archivo.is_open()) {
        Jugador jugador;
        while (archivo >> jugador.nombre >> jugador.puntaje) {
            jugadores.push_back(jugador);
        }
        archivo.close();
    }
}
void guardarPuntajes(const vector<Jugador>& jugadores) {
    ofstream archivo("puntajes.txt");
    if (archivo.is_open()) {
        for (const auto& jugador : jugadores) {
            archivo << jugador.nombre << " " << jugador.puntaje << endl;
        }
        archivo.close();
    }
}
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
    for (int i = 0; i < min(static_cast<int>(jugadores.size()), 3); i++) {
        cout << i + 1 << ". " << jugadores[i].nombre << ": " << jugadores[i].puntaje << "\n";
    }
}
void mostrarCreditos() {
    cout << "Desarrollado por:\n";
    cout << "- Estevan Gualoto\n";
    cout << "- Juan Castañeda\n";
}
