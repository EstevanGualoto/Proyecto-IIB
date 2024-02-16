#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Jugador {
    string nombre;
    int puntaje;
};

void mostrarMenu() {
    cout << "Menu:\n";
    cout << "1. Jugar\n";
    cout << "2. Puntajes\n";
    cout << "3. Créditos\n";
    cout << "4. Salir\n";
}

void jugar(std::vector<Jugador>& jugadores) {
    string nombre;
    int puntaje;

    cout << "Ingrese su nombre: ";
    getline(std::cin, nombre);

    cout << "Ingrese su puntaje: ";
    cin >> puntaje;
    cin.ignore();
    Jugador jugador = {nombre, puntaje};
    jugadores.push_back(jugador);
}
void mostrarPuntajes(const std::vector<Jugador>& jugadores) {
    cout << "Puntajes:\n";
    vector<Jugador> sortedJugadores = jugadores;
    sort(sortedJugadores.begin(), sortedJugadores.end(), [](const Jugador& a, const Jugador& b) {
        return a.puntaje > b.puntaje;
    });

    for (int i = 0; i < std::min((int)sortedJugadores.size(), 3); i++) {
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