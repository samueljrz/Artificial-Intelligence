#include <bits/stdc++.h>

#include "graph.hpp"

#define Direcionado true
#define Nao_direcionado false

enum Color { RED , BLACK, GRAY };
vector<Color> colorList; // vetor auxiliar que armazena as cores dos vértices

using namespace std;

bool BFS( Grafo* g ){

	colorList.resize(g->ordem());

	/* Estrutura FILA utiilizado na BFS */
	queue<int> queue;

	/* Preencher as cores de todos os vertices com GRAY*/
	for (int i = 0; i < g->ordem() ;i++){
		colorList[i] = GRAY;
	}

	/* Colore o primeiro vértice(0) e o adiciona da fila*/
	colorList[0] = RED;
	queue.push(0);

	for (int i=0; i < g->ordem() ;i++) {
			if( colorList[i] == GRAY ) {
				colorList[i] = RED;
				queue.push(i);
			}

			while(!(queue.empty())){
				int vet = queue.front();
				queue.pop();
				/* Percorre a lista de adjacência de vet */
				for(auto aux : g->adjList[vet]){
					/* Se não foi visitado ainda */
					if(colorList[aux] == GRAY){
						if (colorList[vet] == RED) {
							colorList[aux] = BLACK;
						}else{
							colorList[aux] = RED;
						}
						queue.push(aux);
					/* Se possui cor igual */
					}else if(colorList[aux] == colorList[vet]){
						return false;
					}
				}
			}
	}
	return true;
}

int main(){

	Grafo *g;
    int vertices, origem, destino;

    /* Abertura dos arquivos de entrada e saída*/
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	while ( true ) {

		in >> vertices;

		/* Criação do Grafo */
		g = new Grafo(vertices, Nao_direcionado);

		if( vertices == 0 ) {
			return 0;
		}else {
			/* Lendo os vértices */
			while( in >> origem ) {
	         	in >> destino;

	         	if ( (origem==0) && (destino==0) ) break;
	         	else {
	         		/* Adicionando as arestas */
	         		g->addAresta(origem, destino);
	        	}
	     	}
	     	/* Chamada da função de coloração */
		    if (!BFS(g)){
		    	out << "NAO"<< endl;
		    }else{
		    	out << "SIM" << endl;
				for (int i=0 ; i<g->ordem() ; i++){
					string color = (colorList[i]==0) ? "R" : "B";
					out << i << " " <<  color << endl;
				}
		    }
		    delete g;
		}
	}
	return 0;
}
