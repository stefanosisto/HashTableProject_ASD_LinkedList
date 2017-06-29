#include "lcs.h"

LCS::LCS()
{}

int LCS::valoreLCS(string a,string b)
{	vector < vector<int> > mat;
	int lung_a=a.length();
	int lung_b=b.length();
	int lcs=0;
	
	mat.resize(lung_a+1, vector<int> (lung_b+1) );

	
	for(int i=0;i<=lung_a;i++)   mat[i][0]=0;  
	for(int i=0;i<=lung_b;i++)   mat[0][i]=0;  
	
	for(int i=1;i<=lung_a;i++)
	{
		for(int j=1;j<=lung_b;j++)
			{
				if(a[i-1]==b[j-1])  mat[i][j]=mat[i-1][j-1]+1;
				else
									mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
	}
	
	lcs=mat[lung_a][lung_b];
	return lcs;
}

bool LCS::calcoloLCS(string par,TabellaHash tab)
{ 
	int n=0;
	valori.clear();   
    int posizione=0;  int contatore=0;
    string chiave;     int val=0;
    list<PAROLE> punt;
    list<PAROLE>::iterator it;
    	while(posizione<tab.size() )
    				{   punt=tab.head().at(posizione).testa();
    					it=punt.begin();
    					while(it != punt.end() )
    						{   chiave = it->getP();
    							val=valoreLCS(par,chiave);
								if(val>1) {valori[chiave]=val; contatore++;}
								it++;
    						}
    					
						posizione++;}
		if(contatore==0) return false;
		else 
			{cout<<"L'algoritmo LCS ha prodotto "<<contatore<<" risultati."<<endl; }
			 cout<<"Quanti vuoi visualizzarne?"<<endl;
			 fflush(stdin); cin>>n;
			 if(n<=contatore) { setE(n);  stampaLCS( elementi() ); return true;}
			 else
			 	{do{ cout<<"Vuoi visualizzare un numero di elementi maggiore di quelli trovati!"<<endl;
			 		cout<<"Inserisci nuovamente il valore!"<<endl;
			 		cin>>n;}while(n>contatore);}
			 		 setE(n);  stampaLCS( elementi() );
				return true;	
    
}

int LCS::elementi()
{ return elem;}

void LCS::setE(int n)
{ elem=n;}

void LCS::stampaLCS(int n)
{
	cout<<endl;
	vett.clear();
	map<string,int>::iterator it;
	for ( it = valori.begin(); it != valori.end(); it++ )
  		{ 
		  vett.push_back(pair<int,string>(it->second, it->first));
		}
			
			
			sort(vett.rbegin(),vett.rend());
		
				for( int i=0;i<n;i++)
				{ 
					cout<<"parola: "<<vett.at(i).second<<". LCS: "<<vett.at(i).first<<endl;
				}
					
					
}

void LCS::stampaLCS2(string a,string b)
{
	vector < vector<int> > mat;

	int lung_a=a.length();
	int lung_b=b.length();
	int lcs=0;		
	
	mat.resize(lung_a+1, vector<int> (lung_b+1) );
	
	for(int i=0;i<=lung_a;i++)   mat[i][0]=0;
	for(int i=0;i<=lung_b;i++)   mat[0][i]=0;
	
	for(int i=1;i<=lung_a;i++)
	{
		for(int j=1;j<=lung_b;j++)
			{
				if(a[i-1]==b[j-1])  mat[i][j]=mat[i-1][j-1]+1;
				else
									mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
	}
	
	lcs=mat[lung_a][lung_b];
	cout<<"Le parole "<<a<<" e "<<b<<" hanno un LCS pari a: "<<lcs<<"."<<endl;
	cout<<"La matrice da cui e' stato ottenuto e': "<<endl<<endl;		
	cout<<"    ";
	for(int i=0;i<=lung_b;i++) cout<<b[i]<<" ";
	cout<<endl<<endl;
	for(int i=0;i<=lung_a;i++)
		{	if(i ==0 ) cout<<"  ";
			else cout<<endl<<a[i-1]<<" ";
			for(int j=0;j<=lung_b;j++)
			{	 
				 cout<<mat[i][j]<<" ";
			}
			
			cout<<endl;
		}

		cout<<endl;
}

LCS::~LCS()
{}
