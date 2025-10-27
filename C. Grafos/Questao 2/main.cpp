#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Grafo.h"


// o algoritmo le o arquivo que esta na pasta output do projeto "Dist5.txt"


int Graph::Menu_Grafo()
{
  int opc;
  cout << "=-=-=-=-=-=-=-=-= QUESTAO 1 DE C. GRAFOS =-=-=-=-=-=-=-=-=" << endl;
  cout << "    [1] MOSTRAR GRAFO G(V,A)" << endl;
  cout << "    [2] MOSTRAR MATRIZ DE ADJACENCIA DE G(V,A)" << endl;
  cout << "    [3] MOSTRAR MATRIZ DE DISTANCIA DE  G(V,A)" << endl;
  cout << "    [4] INSERIR ARCO EM G(V,A)" << endl;
  cout << "    [5] REMOVER ARCO DE G(V,A)" << endl;
  cout << "    [6] GRAU DOS VERTICES DE G(V,A)" << endl;
  cout << "=-=-=-=-=-=-=-=-= QUESTAO 2 DE C. GRAFOS =-=-=-=-=-=-=-=-=" << endl;
  cout << "    [7] EXECUTAR ALGORITMO DE FLOYD-WARSHALL" << endl;
  cout << "    [8] EXECUTAR ALGORITMO DE FLOYD-WARSHALL COM CAMINHO" << endl;
  cout << "    [9] SAIR DO PROGRAMA" << endl;
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-==-==-=-=-=-=-=-=-=" << endl;
  cout << "Escolha um Item do Menu acima: ";
  cin >> opc;
  return opc;
}

int main()
{
  int option;
  int v, w;
  int peso;

  Graph graph;
  char arquivo[30] = "Dist5.txt";
  graph.Ent_Grafo(arquivo);

  do
  {
    option = graph.Menu_Grafo();
    system("cls");
    switch (option)
    {
    case 1:
      graph.Mostra_Grafo();
      break;
    case 2:
      graph.Imprime_Matriz(2);
      break;
    case 3:
      graph.Imprime_Matriz(1);
      break;
    case 4:
      cout << "Digite o vertice de origem: ";
      cin >> v;
      cout << "Digite o vertice de destino: ";
      cin >> w;
      cout << "Digite o peso do arco: ";
      cin >> peso;
      graph.Insere_Arco(v, w, peso);
      break;
    case 5:
      cout << "Digite o vertice de origem: ";
      cin >> v;
      cout << "Digite o vertice de destino: ";
      cin >> w;
      graph.Remove_Arco(v, w);
      break;
    case 6:
      graph.MostraGrauG();
      break;
      case 7:
          graph.FloydWarshall();
          break;
      case 8:
          graph.FloydWarshallComCaminho();
          break;
    }
    system("cls");
  } while (option != 9);

  graph.~Graph();
  return 0;
}