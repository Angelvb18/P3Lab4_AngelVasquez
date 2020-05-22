#include <iostream>
#include <vector>
using namespace std;
#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
	private:
	string name,lastname,password;
	int key;
	vector<string> mensajes;
	public:
		Persona(string , string  , string );
		~Persona();
		string getName();
		string getLastname();
		string getPassword();
		int getKey();
		void setKey();
		vector<string> getMensajes();
	protected:
};

#endif
