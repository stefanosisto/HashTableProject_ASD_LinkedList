#include "tabellahash.h"


TabellaHash::TabellaHash(int lunghezza)
{   if (lunghezza == 0) size_table=5;
	else size_table = lunghezza;
	hashtable.resize(size_table);
	cout<<"Il tuo dizionario e' pronto!"<<endl;
}

int TabellaHash::hash(string s)
{ 
	char *temp=	(char *)s.c_str();
	int h=0, a = 127;
 	for(; *temp !=0; temp++) 
   	h= (a *h + *temp) %size_table;
 return h;
}

bool TabellaHash::inserimento(PAROLE par)
{   
	int posizione=hash(par.getP());
	if( hashtable.at(posizione).inserisci(par) == true)
	return true;
	else return false;
}

void TabellaHash::rimozione(string par)
{ 
	
	int posizione=hash(par);
	hashtable.at(posizione).rimuovi(par);
}

bool TabellaHash::ricerca(string par)
{   
	int posizione=hash(par);
	if ( hashtable.at(posizione).cerca(par) == false ) {return false;}
	else return true;
}

void TabellaHash::stampaT()
{	 
	cout<<"Dizionario :"<<endl<<endl;
	for(int i=0;i<size_table;i++)
		{
			
			hashtable.at(i).stampa();
			 
		} 
		cout<<endl;
		
}

int TabellaHash::size()
{return size_table;}

TabellaHash::~TabellaHash()
{}
