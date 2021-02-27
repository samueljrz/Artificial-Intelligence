#include <bits/stdc++.h>

#include "graph.hpp"

#define Direcionado true
#define Nao_direcionado false
#define INFINITO 10000000

enum romenia { 
	Arad,
	Zerind,
	Sibiu,
	Timisoara,
	Oradea,
	Fagaras,
	Rimnicu_Vilcea,
	Lugoj,
	Bucharest,
	Pitesti,
	Craiova,
	Mehadia,
	Urziceni,
	Giurgiu,
	Drobeta,
	Vaslui,
	Hirsova,
	Iasi,
	Eforie,
	Neamt
};

using namespace std;

vector<int> distanceList, visitedList;

int transf(string s) {

	if(s == "Arad") return 0;
	if(s == "Zerind") return 1;
	if(s == "Sibiu") return 2;
	if(s == "Timisoara") return 3;
	if(s == "Oradea") return 4;
	if(s == "Fagaras") return 5;
	if(s == "Rimnicu_Vilcea") return 6;
	if(s == "Lugoj") return 7;
	if(s == "Bucharest") return 8;
	if(s == "Pitesti") return 9;
	if(s == "Craiova") return 10;
	if(s == "Mehadia") return 11;
	if(s == "Urziceni") return 12;
	if(s == "Giurgiu") return 13;
	if(s == "Drobeta") return 14;
	if(s == "Vaslui") return 15;
	if(s == "Hirsova") return 16;
	if(s == "Iasi") return 17;
	if(s == "Eforie") return 18;
	if(s == "Neamt") return 29;
}

bool path( Grafo* g, int origem, int destino ){

	distanceList.resize(g->ordem());
	visitedList.resize(g->ordem());
	
	/* Estrutura FILA utiilizado na BFS */
	queue<pair<int,int>> queue;

	/* Preencher o vetor das distancias com INFINITO e
			o vetor de visitas com false */
	for (int i = 0; i < g->ordem() ;i++){
		distanceList[i] = INFINITO;
		visitedList[i] = false;
	}

	/* Define a distance do primeiro ponto para ele mesmo */
	distanceList[origem] = 0;

 /* Adiciona a distancia e a origem na fila de execução */
	queue.push(make_pair(distanceList[origem], origem));

	while( !(queue.empty()) ){

		/* Adiciona a distancia e a origem na fila de execução */
		pair<int,int> pairCurrent = queue.front();
		int vertex = pairCurrent.second;

		/* Retira o elemento atual da fila */
		queue.pop();

		/* Verifica se o vértice já foi visitado */
		if ( visitedList[vertex] == false ) {
			
			/* Marca vertex como visitado */
			visitedList[vertex] = true;

			/* Percorre a lista de adjacência de vertex */
			for(auto aux : g->adjList[vertex]){
				
				/* Obtem o vértice adjacente a vertex e 
						o peso da aresta  									*/

						int adjVertex = aux.second;
						int costEdge = aux.first;

						/* Decide se adiciona ou não adjVertex
								como caminho, baseando sua escolha
								no custo da aresta								*/

						if ( distanceList[adjVertex] > distanceList[vertex] + costEdge) {

								/* Atualiza a distância de adjVertex e o insere na fila */
								distanceList[adjVertex] = distanceList[vertex] + costEdge;
								queue.push(make_pair(distanceList[adjVertex], adjVertex));
						}
			}
		}
	}
	return distanceList[destino];
}

int main(){

	Grafo *g;
  int custo, vertices;
	string origem, destino;

  /* Abertura dos arquivos de entrada e saída*/
	ifstream in;
	ofstream out;
	in.open("in.txt");
	out.open("out.txt");

	in >> vertices;

	/* Criação do Grafo */
	g = new Grafo(vertices, Nao_direcionado);
	if( vertices == 0 ) {
		return 0;
	}else {
		/* Lendo os vértices */
		while( in >> origem ) {
					in >> destino;
					in >> custo;
					//cout << origem << destino << custo << endl;
					/* Adicionando as arestas */
					g->addAresta(transf(origem), transf(destino), custo);
	  }
	}

	//g->imprimeAdjList();
	//out << Arad << Bucharest ;
	int a = path(g, Arad, Bucharest);

	//cout << a << endl;
	     	// /* Chamada da função de coloração */
		    // if (!path(g, origem, destino)){
		    // 	out << "NAO"<< endl;
		    // }else{
		    // 	out << "SIM" << endl;
				// for (int i=0 ; i<g->ordem() ; i++){
				// 	string color = (colorList[i]==0) ? "R" : "B";
				// 	out << i << " " <<  color << endl;
				// }
		    // }
		    delete g;

	return 0;
}
