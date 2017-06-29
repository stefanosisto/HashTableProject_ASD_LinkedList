#ifndef FILETESTO_H
#define FILETESTO_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "tabellahash.h"

using namespace std;
class FileTesto 
{
	public:
		FileTesto();
		void salva(TabellaHash par,string s);
		void carica(TabellaHash &tab,string s);
		~FileTesto();
	
};

#endif
