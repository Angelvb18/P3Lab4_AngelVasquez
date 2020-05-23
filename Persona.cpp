#include "Persona.h"
#include  <stdlib.h>
#include  <time.h>
Persona::Persona(std::string name , std::string lastname,std::string password)
{
	this -> name = name;
	this -> lastname = lastname;
	this -> password = password;
	cout << "Su usuario es:\n";
	cout << "Nombre: " <<  name << endl;
	cout << "Apellido: " <<  lastname << endl;
	cout << "Contrasena: " <<  password << endl;
	setKey();
}

Persona::~Persona()
{
}
string Persona::getName(){
	return name;
}
string Persona::getLastname(){
	return lastname;
	
}
string Persona::getPassword(){
	return password;
}
int Persona::getKey(){
   return key;
}
void Persona::setKey(){
	srand(time (NULL));
	key = 3;
	//key =  1 + rand ()% ( 14 );
}
vector<string> Persona::getMensajes(){
   return mensajes;
}
void Persona::setMensajes(string k){
	mensajes.push_back(k);
}


