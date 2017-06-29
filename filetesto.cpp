#include "filetesto.h"

FileTesto::FileTesto()
{};

FileTesto::~FileTesto()
{};

void FileTesto::salva(TabellaHash par,string s)
{
s=s+".txt";
fstream file(s.c_str(),ios::out);
list<PAROLE>::iterator it;
list<PAROLE> punt;

for(int i=0;i<par.size();i++)
{
		
		punt=par.head().at(i).testa();
		it=punt.begin();
			while (it != punt.end())
					{
						if(it->getP() != "")
							{ file<<it->getP()<<endl;
							  file<<it->getD()<<endl;
							}
							it++;
					}
					
}

				file.close();
}

void FileTesto::carica(TabellaHash &tab,string s)
{
string chiave,des;
PAROLE p;
s=s+".txt";
fstream file;
file.open(s.c_str(),ios::in);
if(!file) cout<<"NON HO TROVATO IL FILE!"<<endl;
		while ( file.is_open() == false )
				{ cout<<"Prova a reinserire il nome, oppure digita esci se non intendi piu' caricarlo!"<<endl;
					fflush(stdin); getline(cin,s); s=p.set(s); s=s+".txt"; file.open(s.c_str(),ios::in);
					if(s == "Esci.txt") return;
				}


while( getline(file,chiave) )
{
	getline(file,des);
	p.UP_P(chiave); p.UP_D(des);
	tab.inserimento(p);
}
file.close();
}
