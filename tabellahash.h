#ifndef TABELLAHASH_H
#define TABELLAHASH_H
#include "liste.h"
#include <vector>


class TabellaHash 
{
	private:
		vector<LISTE> hashtable;
		int size_table;
	
	public:
		
		TabellaHash(int lunghezza); 
		int hash(string s);
		bool inserimento(PAROLE par);
		void rimozione(string par);
		bool ricerca(string par);
		void stampaT();
		int size();
		vector<LISTE> head() { return hashtable;  }
		~TabellaHash();
	
};

#endif
