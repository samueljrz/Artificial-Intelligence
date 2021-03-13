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
	if(s == "Neamt") return 19;
}

int path( Grafo* g, int origem, int destino, map<int, int> val ){

	distanceList.resize(g->ordem());
	visitedList.resize(g->ordem());
	
	/* Estrutura FILA utiilizado na BFS */
  priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

	/* Preencher o vetor das distancias com INFINITO e
			o vetor de visitas com false */
	for (int i = 0; i < g->ordem() ;i++){
		distanceList[i] = 0; //INFINITO;
		visitedList[i] = false;
	}

	/* Define a distance do primeiro ponto para ele mesmo */
	int distanceOrigem = val.find(origem)->second;
	// cout << "Distancia origem" << distanceOrigem << endl;
	distanceList[origem] = distanceOrigem;

 /* Adiciona a distancia e a origem na fila de execução */
	pq.push(make_pair(distanceList[origem], origem));

	while( !(pq.empty()) ){

		pair<int, int> pairCurrent = pq.top();
		pq.pop();

		int vertex = pairCurrent.second;
		// cout << "" << vertex << endl;

		if( vertex == destino ) return distanceList[destino];

		if ( visitedList[vertex] == false ){

			visitedList[vertex] = true;

			for( auto aux : g->adjList[vertex] ){

						int adjVertex = aux;
						int custoVertex = val.find(adjVertex)->second;

						if(visitedList[adjVertex] == false) {
							pair<int, int> children;
							distanceList[adjVertex] = val.find(adjVertex)->second;
							children = make_pair(distanceList[adjVertex], adjVertex);
							//cout << distanceList[adjVertex] << " ";
							pq.push(children);
							// cout << children.first << " " << children.second << endl;
						}
			}
			int vertexCurrent = pq.top().second;
			distanceList[vertexCurrent] = distanceList[vertex] + val.find(vertexCurrent)->second;
			cout << vertexCurrent << endl;
		}
	}
	return (-1);
}

int main(int argc, char *argv[]){

	Grafo *g;
  int custo, vertices;
	string origem, destino;
	map<int, int> map;

  /* Abertura dos arquivos de entrada e saída*/
	ifstream in, in2;
	ofstream out;
	in.open("in.txt");
	in2.open("in2.txt");
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
					// cout << origem << destino << endl;
					/* Adicionando as arestas */
					g->addAresta(transf(origem), transf(destino));
	  }
		while( in2 >> origem ) {
					in2 >> custo;
					map.insert(pair<int, int>(transf(origem), custo));	
	  }
	}

	// Recebe os parâmetros
	string firstParam = argv[1];
	string secondParam = argv[2];

	int valueSolution = path(g, transf(firstParam), transf(secondParam), map);

	cout << valueSolution << endl;

	delete g;

	return 0;
}
