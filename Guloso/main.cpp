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
// precisa de alteração para trabalhar com fila de prioridade 
int path( Grafo* g, int origem, int destino, map<int, int> val ){

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
		pair<int,int> pairCurrent = queue.front();
		int vertex = pairCurrent.first;
		queue.pop();

		if(visitedList[vertex] == false){
			visitedList[vertex] = true;
			for(auto aux : g->adjList[vertex]){
						int adjVertex = aux.first;
						int costEdge = aux.second;
						if(visitedList[adjVertex] == false) {
							pair<int, int> children;
							distanceList[adjVertex] = distanceList[vertex] + costEdge;
							children = make_pair(adjVertex, distanceList[adjVertex]);
							//cout << distanceList[adjVertex] << " ";
							if(adjVertex == destino) return distanceList[destino];
							queue.push(children);
						}
			}
		}
	}
	return (-1);
}

int main(){
	Grafo *g;
  int custo, vertices, ;
	string origem, destino;
	map<int, int> heur;

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
					in >> custo;
					//cout << origem << destino << custo << endl;
					/* Adicionando as arestas */
					g->addAresta(transf(origem), transf(destino));
	  }
		while( in2 >> origem ) {
					in2 >> custo;
					heur.insert(pair<int, int>(transf(origem), custo))	
	  }
	}

	//g->imprimeAdjList();
	//cout << Arad << Bucharest ;
	int a = path(g, Neamt, Bucharest, heur);

	cout << a << endl;
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
