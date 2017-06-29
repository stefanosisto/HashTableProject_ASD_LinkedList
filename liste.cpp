#include "liste.h"

LISTE::LISTE(){}

bool LISTE::inserisci(PAROLE parola)
{	char scelta;
	list<PAROLE>::iterator it;
	for(it=lista.begin(); it != lista.end(); it++)
		{	if( it->getP() == parola.getP() )
				{cout<<"Il termine inserito esiste gia' ed ha questa definizione:"<<endl<<endl;
				   cout<<it->getD()<<endl<<endl;	
				   cout<<"Se vuoi aggiornare la descrizione digita Y "<<endl;
				   cin>>scelta;
				   if ( scelta == 'Y' || scelta == 'y') {it->UP_D(parola.getD() );}
				   return false;
				}
				 
		}
    lista.push_back(parola);
    return true;
}

void LISTE::rimuovi(string parola)
{   list<PAROLE>::iterator it;
	int size=lista.size();
	it=lista.begin();
	if(size == 0) {cout<<"Il termine che vuoi eliminare non e' presente"<<endl; return;}

	while(it != lista.end() && it->getP() != parola) 
	it++; 

			if(it != lista.end() && it->getP() == parola)
					{lista.erase(it); cout<<"Termine eliminato"<<endl;}
			else
			cout<<"Il termine che vuoi eliminare non e' presente"<<endl;
			
}


bool LISTE::cerca(string parola)
{	list<PAROLE>::iterator it;
	it=lista.begin();
	int size=lista.size(); 
	if ( size== 0   ) return false;
	while( it != lista.end() ) 
	{  if(it->getP() == parola)
		{ cout<<"Definizione: "<<it->getD()<<endl;
		   return true;}
		   it++; }
	 return false;		
}


void LISTE::stampa()
{    
	list<PAROLE>::iterator it;
	for(it=lista.begin(); it != lista.end(); it++)
	     if(it->getP() != "") cout<<it->getP()<<endl;

}

LISTE::~LISTE()
{}
