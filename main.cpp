#include <iostream>
#include "lcs.h"
#include "filetesto.h"

int main() {
cout<<"-----------------------------------------"<<endl;
cout<<" Traccia A    Sisto Stefano mat.0124/899 "<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"Hash Table con concatenazione. In caso di fallimento, utilizza l'algoritmo LCS"<<endl<<"per fornire una lista delle parole piu' prossime."<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"Prima di cominciare definisci il size della tua hashtable."<<endl;
cout<<"Se 0, il size sara' settato a 5."<<endl;
unsigned int size=0;   string nome_dizionario;
cin>>size;     
TabellaHash table(size);
PAROLE parola;   
LCS lcs; 
FileTesto dizionario;
char scelta=0;
cout<<"Vuoi caricare il tuo dizionario (di tipo .txt !) ? premi Y per caricare"<<endl;
fflush(stdin); cin>>scelta;
if(scelta == 'y' || scelta == 'Y') { cout<<"Inserisci il nome del file senza l'estensione: "; fflush(stdin); getline(cin,nome_dizionario);
									 nome_dizionario=parola.set(nome_dizionario);
									 dizionario.carica(table,nome_dizionario);}
string par,descr,lcs1,lcs2;
system("cls");
cout<<"-----------------------------------------"<<endl;
cout<<"Hai ora la possibilita' di inserire,rimuovere o cercare un nuovo termine"<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"Premi la lettera tra parentesi per scegliere."<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<" MENU' "<<endl;
cout<<"-----------------------------------------"<<endl;
cout<<"(i) - inserisci un nuovo termine"<<endl;
cout<<"(c) - cerca un termine"<<endl;
cout<<"(r) - rimuovi un termine"<<endl;
cout<<"(s) - stampa il dizionario"<<endl;
cout<<"(l) - stampa la matrice LCS tra due parole"<<endl;
cout<<"(e) - esci e salva il dizionario"<<endl;
cout<<"-----------------------------------------"<<endl;
fflush(stdin);
cin>>scelta;
while(scelta != 'e')
	{     system("cls");
		switch(scelta)
			{   
				case 'i':
						
						cout<<"Inserisci il termine: "; fflush(stdin); getline(cin,par); fflush(stdin);
						cout<<"Inserisci la descrizione: "; getline(cin,descr);
						parola.UP_P(par); parola.UP_D(descr);
						cout<<endl;
						if(table.inserimento(parola) == true) cout<<"Termine inserito!"<<endl;
						
						break;
				case 'c':
						
						cout<<"Quale termine vuoi cercare?"<<endl; fflush(stdin); getline(cin,par); par=parola.set(par);
						if(table.ricerca(par) == false) {cout<<"Non ho trovato il termine. Provo con l'algoritmo LCS "<<endl;
														if (lcs.calcoloLCS(par,table) == false)
														cout<<"Mi dispiace, ma non ho riscontri con l'algoritmo LCS"<<endl;
														}
						break;
				case 'r': 
						
						cout<<"Quale termine vuoi eliminare?"<<endl; fflush(stdin); getline(cin,par); par=parola.set(par);
						table.rimozione(par);
						break;
				case 's':
						
						table.stampaT();
						break;
				case 'l': 
						
						cout<<"Inserisci la prima parola: "; fflush(stdin); cin>>lcs1;  
						cout<<"Inserisci la seconda parola: "; fflush(stdin); cin>>lcs2;
						lcs.stampaLCS2(lcs1,lcs2);
						break; 
			}
			
			cout<<"-----------------------------------------"<<endl;
			cout<<"Premi la lettera tra parentesi per scegliere."<<endl;
			cout<<"-----------------------------------------"<<endl;
			cout<<" MENU'"<<endl;
			cout<<"-----------------------------------------"<<endl;
			cout<<"(i) - inserisci un nuovo termine"<<endl;
			cout<<"(c) - cerca un termine"<<endl;
			cout<<"(r) - rimuovi un termine"<<endl;
			cout<<"(s) - stampa il dizionario"<<endl;
			cout<<"(l) - stampa la matrice LCS tra due parole"<<endl;
			cout<<"(e) - esci e salva il dizionario"<<endl;
			cout<<"-----------------------------------------"<<endl;
			fflush(stdin);
			cin>>scelta;  
	}
	cout<<endl<<endl;  
	cout<<"Vuoi salvare il tuo dizionario? premi Y per salvare "<<endl;
		fflush(stdin); cin>>scelta;
		if(scelta == 'y' || scelta == 'Y') { cout<<"ATTENZIONE! Salvando il tuo nuovo dizionario con un nome uguale al vecchio sovrascriverai il tuo vecchio dizionario."<<endl;
											 cout<<"Vuoi continuare? Y per procedere"<<endl;
											fflush(stdin); cin>>scelta;
											if(scelta == 'y' || scelta == 'Y') { 
													cout<<"Inserisci il nome con cui vuoi salvare il dizionario"<<endl; 
													fflush(stdin); getline(cin,nome_dizionario); nome_dizionario=parola.set(nome_dizionario);
													dizionario.salva(table,nome_dizionario); cout<<"Ho salvato il tuo dizionario"<<endl;}
											else cout<<"Hai scelto di non salvare il dizionario"<<endl;	}
	cout<<endl<<"Codice scritto da Stefano Sisto per l'esame di Algoritmi e Strutture Dati"<<endl<<endl;
	cout<<"Arrivederci"<<endl;


	return 0;
}
