/***************************//***************************/
/*Alumno: Daniel Romero
C.I 23.624.323
Preparador: Oswaldo Diaz
Seccion: C3
*/
/***************************//*************************/

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std; 

struct Info_estado 
{
	int voy;
	string sTrans;
	string sCad;
};

int main (){
	//variables
	int t=0;
	int n=0, m=0, q=0, u=0, d=0, l=0, r=0;
	int cont=1;
	bool sioke=true;

	//Lectura
	cin >> t;
	if(t<1 || t>100) return 0;

	//Acciones
	for (int i=0; i<t;i++){
		cin >> n >> m >> q;
		vector <Info_estado> array_aux[n+1];
		for (int j=0; j<m; j++){
			int a=0, b=0;
			string c,d;
			cin >> a >> b >> c >> d;	
			Info_estado aux;
			aux.voy = b;
			aux.sTrans = c;
			aux.sCad = d;
			array_aux[a].push_back(aux);
		}
		
		for (int j=0;j<q;j++){
			string aux_cad;
			cin >> aux_cad;
			cont = 1;
			for (int k=0; k<aux_cad.length(); k++){
				for (int o=0; o<array_aux[cont].size(); o++){
					string a,b;
					a = aux_cad[k];
					b = array_aux[cont][o].sTrans;
					if ( a.compare(b) == 0 ){
						char c = array_aux[cont][o].sCad[0];
						if ( c == 'U' ){ u++;sioke=true;}
						if ( c == 'D' ){ d++;sioke=true;}
						if ( c == 'L' ){ l++;sioke=true;}
						if ( c == 'R' ){ r++;sioke=true;}
						cont = array_aux[cont][o].voy;
						o=array_aux[cont].size();
					}else{
						sioke=false;
					}
				}
				if (sioke == false){
					k=aux_cad.length();
					break;
				}
			}
			cout << r-l << " " << u-d <<endl;
			u=d=l=r=0;
		}
	}
return 0;
}

