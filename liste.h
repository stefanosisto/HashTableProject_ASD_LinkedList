#ifndef LISTE_H
#define LISTE_H
#include <list>
#include "parole.h"


using namespace std;
class LISTE
{
	private:
		list<PAROLE> lista;
	
		
		
	public:
		LISTE();
		bool inserisci(PAROLE parola);
		void rimuovi(string parola);
		bool cerca(string parola);
		void stampa();
		list<PAROLE> testa() { return lista; };
		~LISTE();
		
};

#endif
