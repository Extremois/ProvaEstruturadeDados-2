#include <iostream>
#include <cstdlib>
#include <cstdio>

#define inf 99999999

using namespace std;

class Graph
{
private:
	int V;
	int A;

public:
	int **adj;
	int **dist;
	int *grau;

	Graph()
	{
		V = 0;
		A = 0;
		cout << "Grafo G(V,A) instanciado!" << endl;
	}

	~Graph()
	{
		cout << "Grafo G(V,A) desalocado da memoria!" << endl;
	}

	void Insere_Arco(int v, int w, int peso)
	{
		if (adj[v][w] == 0)
		{
			adj[v][w] = 1;
			adj[w][v] = 1;
			dist[v][w] = peso;
			dist[w][v] = peso;
			A++;
		}
	}

	void Remove_Arco(int v, int w)
	{
		if (adj[v][w] == 1)
		{
			adj[v][w] = 0;
			adj[w][v] = 0;
			dist[v][w] = inf;
			dist[w][v] = inf;
			A--;
		}
	}

	void Mostra_Grafo()
	{
		cout << "\t Grafo G(V,A)" << endl;
		cout << "\t Numero de Vertices: " << V << endl;
		cout << "\t Numero de Arestas: " << A << endl;
		cout << "\t --------------------------------------------" << endl;
		cout << "\t | VERTICE |            ARESTAS             |" << endl;
		cout << "\t --------------------------------------------" << endl;
		for (int v = 0; v < V; ++v)
		{
			cout << "\t |    " << v << "    |";
			for (int w = 0; w < V; ++w)
				if ((adj[v][w] == 1) && (v < w))
					cout << "  " << v << " - " << w << ",";
			cout << endl;
		}
		system("pause");
	}

	void Imprime_Matriz(int tipo) // tipo 1-distancia 2-adjacencia
	{
		int i, j;
		if (tipo == 1)
		{
			cout << "\t----------------------------------" << endl;
			cout << "\t   Matriz de Distancias de G(V,A) " << endl;
			cout << "\t----------------------------------" << endl;
			for (i = 0; i < V; i++)
			{
				if (i != 0)
					cout << endl;
				for (j = 0; j < V; j++)
					cout << "\t" << dist[i][j];
			}
			cout << endl;
		}
		else
		{
			cout << "\t----------------------------------" << endl;
			cout << "\t  Matriz de Adjacencia de G(V,A)  " << endl;
			cout << "\t----------------------------------" << endl;
			for (i = 0; i < V; i++)
			{
				if (i != 0)
					cout << endl;
				for (j = 0; j < V; j++)
					cout << "\t" << adj[i][j];
			}
			cout << endl;
		}
		system("pause");
	}

	void Gera_Matriz_Adj()
	{
		// separa a matriz de adjacência
		adj = (int **)malloc(V * sizeof(int *));
		for (int i = 0; i < V; i++)
			adj[i] = (int *)malloc(V * sizeof(int));

		// peenche a matriz de adjacência baseada na matriz de distâncias
		A = 0;
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (i != j && dist[i][j] != inf && dist[i][j] > 0)
				{
					adj[i][j] = 1;
					if (i < j)
						A++;
				}
				else
				{
					adj[i][j] = 0;
				}
			}
		}
	}

	int Ent_Grafo(char Arq[30])
	{
		int C, L, nv, Peso = 0;
		FILE *arquivo;
		arquivo = fopen(Arq, "r");

		if (!arquivo)
		{
			printf("O arquivo %s nao pode ser aberto\n", Arq);
			getchar();
			exit(1);
		}

		if (fscanf(arquivo, "%d", &nv) != 1)
		{
			printf("Erro ao ler numero de vertices\n");
			fclose(arquivo);
			exit(1);
		}

		V = nv;

		dist = (int **)malloc(V * sizeof(int *));
		for (int i = 0; i < V; i++)
			dist[i] = (int *)malloc(V * sizeof(int));

		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				dist[i][j] = (i == j) ? 0 : inf;

		L = 0;
		C = 0;
		while (fscanf(arquivo, "%d", &Peso) == 1)
		{
			if (Peso == -1)
			{
				L++;
				C = 0;
				if (L >= V)
					break;
			}
			else
			{
				if (L < V && C < V)
				{
					dist[L][C] = Peso;
					C++;
				}
			}
		}

		fclose(arquivo);

		Gera_Matriz_Adj();

		grau = (int *)malloc(V * sizeof(int));

		cout << "Grafo carregado com " << V << " vertices e " << A << " arestas!" << endl;

		return V;
	}

	int Menu_Grafo();

	void GrauG()
	{
		int i, j;
		for (i = 0; i < V; i++)
			grau[i] = 0;
		for (i = 0; i < V; i++)
			for (j = 0; j < V; j++)
				if (adj[i][j] == 1)
					grau[i]++;
	}

	void MostraGrauG()
	{
		GrauG();
		int i;

		cout << "\t----------------------------------------" << endl;
		cout << "\t      Grau dos Vertices de G(V,A)       " << endl;
		cout << "\t----------------------------------------" << endl;
		for (i = 0; i < V; i++)
			cout << "\tV[" << i << "]=" << grau[i] << endl;
		system("pause");
	}

	//---------------------------------------------------------------------------
	//                              FUNCOES AUXILIARES
	//---------------------------------------------------------------------------

	// Alocacao de uma matriz de inteiros
	int **Aloca_MatrizInt(int l, int c, int **m)
	{
		m = (int **)malloc(l * sizeof(int *));
		for (int i = 0; i < l; i++)
			m[i] = (int *)malloc(c * sizeof(int));
		return m;
	}
};
