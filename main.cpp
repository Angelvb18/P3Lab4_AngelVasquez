#include "Persona.h"
#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void VerMensajes(vector<Persona*> , int);
void EnviarMensaje(vector<Persona*>& , int);
void menu();


int main() {
	 
	menu();
}
/*


*/
int esta(vector<Persona*>, string , string);
void menu(){
	int opcion;
	vector <Persona*> Personas;
	do{
	    cout << "***CLI-MESSENGER-SERVICE***\n(1) Registrarse\n(2) Ingresar\n(0) Salir\n->Ingrese su opcion:";
	    cin >> opcion;
	    switch(opcion){
			case 1:{
				string name,lastname,password;
				cout << "***REGISTRO***" << endl;
				cout << "->Ingrese su nombre: ";
				cin >> name;
				cout << "->Ingrese su apellido:";
				cin >> lastname;
				cout << "->Ingrese su contrasena: ";
				cin >> password;
				Personas.push_back(new Persona(name,lastname,password));
				break;
			}
			case 2:{
				string name ,pass;
				if(Personas.size() == 0 ){
					cout <<"-X- No hay usuarios\n\n";
				}else{
					cout << "*****LOG IN****\nIngrese su nombre: ";
					cin >> name;
					cout << "Ingrese su contrasena:";
					cin >> pass;
					int posicion = esta(Personas,name, pass); 
					if(posicion != -1){
						int opcion2;
						do{
							cout << "****Bienvenido:" << Personas[posicion] ->getName() << "***" << endl;
							cout << "(1) Enviar mensaje\n(2) Ver mensajes\n(3) Ver mi llave\n(0) Salir\n->Ingrese su opcion:";
							cin >> opcion2;
							switch(opcion2){
								case 1 :{
									EnviarMensaje(Personas , posicion);
									break;
								}
								case 2 :{
									if(Personas[posicion] -> getMensajes().size() > 0){
										VerMensajes(Personas,posicion);
									}else{
									    cout << "-X- No hay mensajes\n\n";
									}
									
									break;
								}
								case 3:{
									cout << "-!- Su llave es: ["<< Personas[posicion] -> getKey() << "]\n" << endl;
									break;
								}
								case 0:{
									break;
								}
								default :{
									cout << "\n\n\n";
									break;
								}
							}
						}while(opcion2 != 0);

					}else{
					
					    cout << "-X- Usuario o contrasena invalido\n\n";
					}
				}
				break;
			}
			default :{
				cout << "\n\n\n";
				break;
			}
		}
	}while(opcion != 0);
}
int esta(vector<Persona*> Personas, string usser, string pass){
	int encontre = -1;
	for(int i = 0 ; i < Personas.size() ; i++){
		if(Personas[i] -> getName() == usser && Personas[i] -> getPassword() == pass){
		   encontre = i;
		   i = Personas.size();
		}
	}
	return encontre;
}
void VerMensajes(vector<Persona*>personas , int posicion){
	int pomen;
	cout << "***Enviar mensajes***\n\n";
	cout << ":Usuarios:" << endl;
	for(int i = 0 ; i < personas[posicion] ->  getMensajes().size(); i++){
	    cout << i+1 << ". " << personas[posicion] -> getMensajes()[i]<< endl;
	}
	do{
		cout << "->Seleccione el mensaje: ";
		cin >> pomen;
	}while(pomen > personas[posicion] -> getMensajes().size() || pomen < 1);
	
	
	
	
}
void EnviarMensaje(vector<Persona*>& lsitapersonas, int posicion){
    int destinatario;
    cout << "***Enviar mensajes***\n\n:Usuarios:\n";
    for(int i = 0 ; i < lsitapersonas.size() ; i++){
	     cout << i << ". " << lsitapersonas[i] -> getName() << " " << lsitapersonas[i] -> getPassword() << endl;
	}
	cout << "\n->Seleccione el destinatario: ";
	cin >> destinatario;
	  
}

