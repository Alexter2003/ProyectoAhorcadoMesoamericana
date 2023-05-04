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

bool encontrado(string letra, string palabra){
	int letras = palabra.length();
	int letrasEncontradas = 0;
	
	for(int i=0 ; i < palabra.length() ; i++){
		if(letra[i] == palabra[i]){
			letrasEncontradas++;
		}
	}
	return letras == letrasEncontradas;
}

void jugarAhorcado(string palabra, int idioma) {
	int intentos = 7;
	string letra;
	string palabraOculta(palabra.length(), '_');
	bool adivinoTodo = false;
	
	while (intentos > 0 && !adivinoTodo) {
		mostrarAhorcado(intentos);
		
		if(idioma == 1){
		cout << "Palabra: " << palabraOculta << endl;
		cout << "Intentos restantes: " << intentos << endl;
		
		
		cout << "Ingresa una letra o la palabra completa: ";
		cin >> letra;
		} else {
			cout << "Word: " << palabraOculta << endl;
			cout << "attempts remaining: " << intentos << endl;
			
			
			cout << "Enter a letter or the whole word: ";
			cin >> letra;
			
		}
		
		if (encontrado(letra, palabra)) {
			adivinoTodo = true;
		} else if (palabra.find(letra) != string::npos) {
			if(idioma == 1){
			cout<<"Esta letra se encuentra en la palabra";
			} else {
				cout<<"This letter is in the word";
			}
			for (int i = 0; i < palabra.length(); i++) {
				if (palabra[i] == letra[0]) {
					palabraOculta[i] = letra[0];
				}
			}
		} else {
			if(idioma == 1){
			cout << "La letra no se encuentra dentro de la palabra ";
			intentos--;
			} else {
				cout << "The letter is not inside the word ";
				intentos--;
			}
		}
		
		cout << endl;
	}
	
	mostrarAhorcado(intentos);
	
	if (adivinoTodo) {
		if(idioma == 1){
		cout << "¡Ganaste! Adivinaste la palabra." << endl;
		} else {
			cout << "Won! You guessed the word." << endl;
		}
	} else {
		if(idioma == 1){
		cout << "¡Perdiste! La palabra era: " << palabra << endl;
		} else {
			cout << "You lost! the word was: " << palabra << endl;
		}
	}
}


void rellenarBaseDeDatos(string palabrasIngles[], string palabrasSpanish[], bool baseDeDatosLlena, int idioma){
	if(idioma == 1){
	cout<<"Ingresando las palabras en español. Puedes ingresar hasta 10\n";
	}else{
		cout<<"Entering the words in Spanish. You can enter up to 10\n";
	}
	for(int i = 0; i<10 ; i++){
		string palabra;
		if(idioma == 1){
		cout<<"Digite una palabra en español: \n";
		}else{
			cout<<"Type a word in Spanish: \n";
		}
		cin>>palabra;
		palabrasSpanish[i] = palabra;
	}
	
	if(idioma == 1){
		cout<<"Ingresando las palabras en ingles. Puedes ingresar hasta 10\n";
	}else{
		cout<<"Entering the words in english. You can enter up to 10\n";
	}
	
	for(int i = 0; i<10 ; i++){
		string palabra;
		if(idioma == 1){
			cout<<"Digite una palabra en ingles: \n";
		}else{
			cout<<"Type a word in english: \n";
		}
		cin>>palabra;
		palabrasIngles[i] = palabra;
	}
	
	baseDeDatosLlena = true;
}
	

int main() {
	bool baseDeDatosLlena = false;
	bool salir = false;
	bool volverAJugar = true;
	string palabrasIngles[10];
	string palabrasSpanish[10];
	int opcion = 0;
	int idioma;
	cout << "Selecciona el idioma (español (1)/ingles (2)): ";
	cin >> idioma;
	
	while(!salir){
		if(idioma == 1){
			cout << "Bienvenido \n";
			cout << "Seleccione que desea realizar: \n";
			cout << "1. Rellenar base de datos (Se tiene que realizar para poder jugar)\n";
			cout << "2. Jugar con la computadora\n";
			cout << "3. Jugar con otro jugador\n";
			cout << "4. salir :(\n";
			cin >> opcion;
		} else {
			cout << "Welcome \n";
			cout << "Select what you want to do: \n";
			cout << "1. Fill database (It has to be done in order to play)\n";
			cout << "2. Play with the computer\n";
			cout << "3. play with another player\n";
			cout << "4. exit :(\n";
			cin >> opcion;
		}
		
		if(opcion == 1){
			rellenarBaseDeDatos(palabrasIngles,palabrasSpanish,baseDeDatosLlena,idioma);
			baseDeDatosLlena = true;
		}
		if(opcion == 2 && !baseDeDatosLlena){
			cout << "No haz rellenado la base de datos\n";
		} else if (opcion == 2 && baseDeDatosLlena){
			while(volverAJugar){
				if (idioma == 2) {
					srand(time(0));
					
					int numPalabras = sizeof(palabrasIngles) / sizeof(palabrasIngles[0]);
					int indiceAleatorio = rand() % numPalabras;
					jugarAhorcado(palabrasIngles[indiceAleatorio], idioma);
				} else {
					srand(time(0));
					
					int numPalabras = sizeof(palabrasSpanish) / sizeof(palabrasSpanish[0]);
					int indiceAleatorio = rand() % numPalabras;
					jugarAhorcado(palabrasSpanish[indiceAleatorio], idioma);
				}
				int opcion;
				cout<<"Quieres volver a jugar? (1. si - 2. no)";
				cin>>opcion;
				if(opcion == 2 ){
					volverAJugar = false;
				}
			}
		}
	}
	
	
	
	
	return 0;
}
