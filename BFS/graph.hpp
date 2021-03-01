#ifndef GRAPHLIST
#define GRAPHLIST

#include <bits/stdc++.h>

using namespace std;

	class Grafo {

	    public:
	    	vector<pair<int,int>> *adjList; // Lista de adjacência
	        int vertices; // Número de vértices
	        bool direcionado; // Indicação da natureza do grafo

	        Grafo(int numVertices, bool d);
	        ~Grafo();
	        void addAresta(int origem, int destino, int custo);
	        void imprimeAdjList();
	        int ordem();	
	};

    /* Construtor e Destrutor */
    Grafo::Grafo(int numVertices, bool d){

        vertices = numVertices;
        direcionado = d;

        /* Aloca a lista com todos os vértices */
        adjList = new vector<pair<int,int>>[vertices];
    }
    Grafo::~Grafo(){

        /* Libera memória da lista de adjacência de cada vértice */
        for(int i = 0;i < vertices;i++){
            adjList[i].clear();
        }

        /* Libera a lista de vértices */
        delete[] adjList;
    }

    /* Métodos */
    void Grafo::addAresta(int origem, int destino, int custo){

        /* Insere uma nova aresta na lista de adjacência do vertice(origem) */
        adjList[origem].insert(adjList[origem].begin(), make_pair(destino, custo));

        /* Verifica se o grafo é direcionado ou não */
         if(!direcionado){
            adjList[destino].insert(adjList[destino].begin(), make_pair(origem, custo));
         }
    }

    void Grafo::imprimeAdjList(){
       for(int i = 0;i < vertices;i++){ 
            cout << "A lista de adjacência do vértice " << i << " :";
            for(auto aresta : adjList[i]){
               cout << aresta.first << " ";
            }
            cout << endl;     
       }
    }

    int Grafo::ordem(){
        return vertices;
    }

#endif