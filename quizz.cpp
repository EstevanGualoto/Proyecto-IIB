#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unistd.h> 

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
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
    cout << "Hola " << nombre << ", vamos a empezar el juego de preguntas y respuestas!\n"<<RED;
    cout << "Responde las siguientes preguntas escribiendo la opción correcta (a, b o c).\n";
    sleep(2);
    system("clear");
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
    sleep(2);
    system("clear");
    cout << "\nPregunta 2: ¿Que es una clase en C++?\n";
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
    sleep(2);
    system("clear");
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
    sleep(2);
    system("clear");
    cout << "\nPregunta 4: ¿Qué es 'cin' en C++?\n";
    cout << "a) Un flujo de entrada.\n";
    cout << "b) Una struct.\n";
    cout << "c) Un artefacto.\n";
    char respuesta4;
    cin >> respuesta4;
    if (respuesta4 == 'a' || respuesta4 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    system("clear");
    cout << "\nPregunta 5: ¿Qué es una struct?\n";
    cout << "a) Un tipo de lenguaje.\n";
    cout << "b) Es una declaración de tipo de datos compuestos que define una lista de variables\n";
    cout << "c) Una ley del Ecuador.\n";
    char respuesta5;
    cin >> respuesta5;
    if (respuesta5 == 'b' || respuesta5 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 6: ¿Qué es una referencia en C++?\n";
    cout << "a) Un puntero constante.\n";
    cout << "b) Una variable que almacena la dirección de memoria de otra variable.\n";
    cout << "c) Un tipo de dato para representar números reales.\n";
    char respuesta6;
    cin >> respuesta6;
    if (respuesta6 == 'b' || respuesta6 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 7: ¿Cuál es el operador utilizado para la asignación en C++?\n";
    cout << "a) =\n";
    cout << "b) ==\n";
    cout << "c) :=\n";
    char respuesta7;
    cin >> respuesta7;
    if (respuesta7 == 'a' || respuesta7 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 8: ¿Cómo se declara una función en C++?\n";
    cout << "a) function myFunction() {}\n";
    cout << "b) void myFunction() {}\n";
    cout << "c) def myFunction() {}\n";
    char respuesta8;
    cin >> respuesta8;
    if (respuesta8 == 'b' || respuesta8 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 9: ¿Cuál es la diferencia entre '++i' y 'i++'?\n";
    cout << "a) No hay diferencia, ambas incrementan la variable en 1.\n";
    cout << "b) '++i' incrementa antes de la evaluación, 'i++' incrementa después.\n";
    cout << "c) 'i++' incrementa antes de la evaluación, '++i' incrementa después.\n";
    char respuesta9;
    cin >> respuesta9;
    if (respuesta9 == 'b' || respuesta9 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 10: ¿Qué es un puntero en C++?\n";
    cout << "a) Un tipo de dato para almacenar números reales.\n";
    cout << "b) Una variable que almacena la dirección de memoria de otra variable.\n";
    cout << "c) Una estructura de control de flujo.\n";
    char respuesta10;
    cin >> respuesta10;
    if (respuesta10 == 'b' || respuesta10 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 11: ¿Cómo se declara un vector en C++?\n";
    cout << "a) vector<int> vec;\n";
    cout << "b) int[] vec;\n";
    cout << "c) array vec;\n";
    char respuesta11;
    cin >> respuesta11;
    if (respuesta11 == 'a' || respuesta11 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 12: ¿Cómo se accede al elemento en la posición i de un vector 'v'?\n";
    cout << "a) v(i);\n";
    cout << "b) v[i];\n";
    cout << "c) v.at(i);\n";
    char respuesta12;
    cin >> respuesta12;
    if (respuesta12 == 'b' || respuesta12 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 13: ¿Cómo se obtiene el tamaño de un vector 'v' en C++?\n";
    cout << "a) v.length();\n";
    cout << "b) v.size();\n";
    cout << "c) v.capacity();\n";
    char respuesta13;
    cin >> respuesta13;
    if (respuesta13 == 'b' || respuesta13 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 14: ¿Cómo se añade un elemento al final de un vector 'v'?\n";
    cout << "a) v.pushBack();\n";
    cout << "b) v.append();\n";
    cout << "c) v.push_back();\n";
    char respuesta14;
    cin >> respuesta14;
    if (respuesta14 == 'c' || respuesta14 == 'C') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 15 ¿Cómo se elimina el último elemento de un vector 'v'?\n";
    cout << "a) v.removeLast();\n";
    cout << "b) v.popBack();\n";
    cout << "c) v.pop_back();\n";
    char respuesta15;
    cin >> respuesta15;
    if (respuesta15 == 'c' || respuesta15 == 'C') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 16: ¿Cómo se verifica si un vector 'v' está vacío?\n";
    cout << "a) v.empty();\n";
    cout << "b) v.is_empty();\n";
    cout << "c) v.size() == 0;\n";
    char respuesta16;
    cin >> respuesta16;
    if (respuesta16 == 'a' || respuesta16 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 17 ¿Cómo se ordena un vector 'v' en orden ascendente?\n";
    cout << "a) sort(v);\n";
    cout << "b) v.sort();\n";
    cout << "c) ascending_sort(v);\n";
    char respuesta17;
    cin >> respuesta17;
    if (respuesta17 == 'a' || respuesta17 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 18: ¿Cuál es el algoritmo de ordenamiento más comúnmente utilizado en C++?\n";
    cout << "a) QuickSort\n";
    cout << "b) MergeSort\n";
    cout << "c) std::sort\n";
    char respuesta18;
    cin >> respuesta18;
    if (respuesta18 == 'c' || respuesta18 == 'C') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 19: ¿Cómo se utiliza std::sort para ordenar un vector 'v' en orden descendente?\n";
    cout << "a) std::sort(v, descending);\n";
    cout << "b) std::sort(v, std::greater<int>());\n";
    cout << "c) std::sort.descending(v);\n";
    char respuesta19;
    cin >> respuesta19;
    if (respuesta19 == 'b' || respuesta19 == 'B') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    }
    cout << "\nPregunta 20: ¿En qué biblioteca de C++ se encuentra la función std::sort?\n";
    cout << "a) <algorithm>\n";
    cout << "b) <vector>\n";
    cout << "c) <iostream>\n";
    char respuesta20;
    cin >> respuesta20;
    if (respuesta20 == 'a' || respuesta20 == 'A') {
    cout << "¡Respuesta correcta!\n";
    puntaje++;
    } else {
    cout << "Respuesta incorrecta.\n";
    cout << "Puntaje: " <<puntaje;
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
