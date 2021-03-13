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

int toInt(string s) {

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
	if(s == "Neamt") return 19;
}

int path( Grafo* g, int origem, int destino ){

	distanceList.resize(g->ordem());
	visitedList.resize(g->ordem());
	
	/* Estrutura FILA utiilizado na BFS */
	queue<pair<int,int>> queue;	

	/* Preencher o vetor das distancias com INFINITO e
			o vetor de visitas com false */
	for (int i = 0; i < g->ordem() ;i++){
		distanceList[i] = 0; //INFINITO;
		visitedList[i] = false;
	}

	/* Define a distance do primeiro ponto para ele mesmo */
	distanceList[origem] = 0;

 /* Adiciona a distancia e a origem na fila de execução */
	queue.push(make_pair(origem, distanceList[origem]));

	while( !(queue.empty()) ){

		/* Obtem o primeiro elemento da fila de execução e o retira da fila */
		pair<int,int> pairCurrent = queue.front();
		int vertex = pairCurrent.first;
		queue.pop();

		/* Verifica se já foi visitado. Se nunca foi, o marca como visitado */
		if(visitedList[vertex] == false){
			visitedList[vertex] = true;

			for( auto aux : g->adjList[vertex] ){
						int adjVertex = aux.first;
						int costEdge = aux.second;

						/* Verifica se o vértice já foi visitado */
						if(visitedList[adjVertex] == false) {
							pair<int, int> children;
							distanceList[adjVertex] = distanceList[vertex] + costEdge;
							children = make_pair(adjVertex, distanceList[adjVertex]);

							/* Verifica se é o vértice de destino */
							if( adjVertex == destino ) return distanceList[destino];

							/* Adiciona filho na borda */
							queue.push(children);
						}
			}
		}
	}
	return (-1);
}

int main( int argc, char *argv[] ){
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
					g->addAresta(toInt(origem), toInt(destino), custo);
	  }
	}

	// Recebe os parâmetros
	string firstParam = argv[1];
	string secondParam = argv[2];

	// Retorna o custo da solução
	int valueSolution = path(g, toInt(firstParam), toInt(secondParam));

	cout << valueSolution << endl;

	delete g;

	in.close();
	out.close();

	return 0;
}
