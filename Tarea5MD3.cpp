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

struct Objetos{
	string sCad;
	int peso;
	int valor;
	bool apilado;
};

bool objFav_esta(vector<Objetos> a, string b){
	Objetos aux;	
	bool retornar=false;
	for(int j=0; j<a.size(); j++){
		aux.sCad=a[j].sCad;
		if ( aux.sCad == b ) retornar = true;
	} 
	return retornar;
}

int main (){
	int casosdPrueba;
	int cantObjetos;
	int capMochila;
	string objFav;
	vector<Objetos> listObjetos;
	cin >>casosdPrueba; 
	//Inician los casos de prueba
	for (int i=0; i<casosdPrueba; i++){
		//Leo los objetos del caso de prueba i
		cin >> cantObjetos >> capMochila;
		for (int j=0; j<cantObjetos; j++){
			Objetos obj;
			string sAux;
			int a=0, b=0;
			cin >> sAux >> a >> b;
			obj.sCad = sAux;
			obj.peso = a;
			obj.valor = b;
			obj.apilado=false;
			listObjetos.push_back(obj);
		}
		//Leo el objeto favorito del caso de prueba i
		cin >> objFav;
		vector<Objetos> pilaMochila;
		//Lleno la mochila
		for(int k=0; k<capMochila; k++){
			Objetos apilame;
			int posicion;
			int mayor=0;
			int mayor_peso;
			//Busco el objeto de mayor valor
			for(int o=0; o<listObjetos.size(); o++){
				if( listObjetos[o].valor > mayor && !(listObjetos[o].apilado) ){
					apilame.sCad = listObjetos[o].sCad;
					apilame.valor = listObjetos[o].valor;
					apilame.peso = listObjetos[o].peso;
					posicion = o;
					mayor_peso = listObjetos[o].peso;
					mayor = listObjetos[o].valor;
				}
			}
			listObjetos[posicion].apilado = true;
			pilaMochila.push_back(apilame);
		}

		//Obtengo la cantidad de objetos mayor peso que mi obj favorito.
		double escribeme=0.0;
		double uno = 1.0;
		int cont_mayor=0;
		int peso_fav;
		if(objFav_esta(pilaMochila, objFav) == false){
			escribeme = 0;
			printf("%.3f\n", escribeme);
		}else{
			for(int i=0; i<pilaMochila.size(); i++){
				if(pilaMochila[i].sCad == objFav) peso_fav=pilaMochila[i].peso;
			}
			for(int i=0; i<pilaMochila.size(); i++){
				if(pilaMochila[i].peso >= peso_fav) cont_mayor++;
			}
			if (cont_mayor == 0){
				printf("%.3f\n",escribeme);
			}else{
				escribeme = uno/cont_mayor;
				printf("%.3f\n",escribeme);
			}	
		}
	}//Termina el caso de prueba i
return 0;	
}

