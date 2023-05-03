#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void mostrarAhorcado(int intentos) {
	
	cout << " +---+" << endl;
	cout << " |   |" << endl;
	cout << " " << ((intentos < 7) ? "|" : " ") << ((intentos < 6) ? "O" : "") << endl;
	cout << " " << ((intentos < 4) ? "/" : "") << " " << ((intentos < 5) ? "|" : "") << ((intentos < 3) ? "\\" : "") << endl;
	cout << " " << ((intentos < 2) ? "/" : "") << " " << ((intentos < 1) ? "\\" : "") << endl;
	cout << "=============" << endl;
}

void jugarAhorcado(string palabra) {
	int intentos = 7;
	string palabraOculta(palabra.length(), '_');
	bool adivinoTodo = false;
	
	while (intentos > 0 && !adivinoTodo) {
		mostrarAhorcado(intentos);
		
		cout << "Palabra: " << palabraOculta << endl;
		cout << "Intentos restantes: " << intentos << endl;
		
		char letra;
		cout << "Ingresa una letra o la palabra completa: ";
		cin >> letra;
		
		if (letra == palabra[0]) {
			adivinoTodo = true;
		} else if (palabra.find(letra) != string::npos) {
			cout<<"Esta letra se encuentra en la palabra";
			for (int i = 0; i < palabra.length(); i++) {
				if (palabra[i] == letra) {
					palabraOculta[i] = letra;
				}
			}
		} else {
			cout << "La letra no se encuentra dentro de la palabra ";
			intentos--;
		}
		
		cout << endl;
	}
	
	mostrarAhorcado(intentos);
	
	if (adivinoTodo) {
		cout << "¡Ganaste! Adivinaste la palabra." << endl;
	} else {
		cout << "¡Perdiste! La palabra era: " << palabra << endl;
	}
}

int main() {
	// Configuración del idioma del programa
	string idioma;
	cout << "Selecciona el idioma (español/ingles): ";
	cin >> idioma;
	
	if (idioma == "ingles") {
		srand(time(0));
		string palabras[] = {"apple", "banana", "orange", "strawberry", "watermelon"};
		int numPalabras = sizeof(palabras) / sizeof(palabras[0]);
		int indiceAleatorio = rand() % numPalabras;
		jugarAhorcado(palabras[indiceAleatorio]);
	} else {
		srand(time(0));
		string palabras[] = {"manzana", "platano", "naranja", "fresa", "sandia"};
		int numPalabras = sizeof(palabras) / sizeof(palabras[0]);
		int indiceAleatorio = rand() % numPalabras;
		jugarAhorcado(palabras[indiceAleatorio]);
	}
	
	return 0;
}
