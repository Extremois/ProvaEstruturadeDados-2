#include "ArvoreBinaria.h"
#include <iostream>

using namespace std;

Arvore Av1;

int main()
{
    int opc;
    int n;
    string nomeAux;
    vector<string> nomesM[10];
    int contM = 0;
    vector<string> nomesF[10];
    int contF = 0;

    Av1 = InicializaArv(Av1);

    do
    {
        system("cls");
        opc = MenuArvore();
        switch (opc)
        {
        case 1:
            cout << "Quantos nOs serao inseridos: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                No *novo = new No;
                cout << "Digite o nome do individuo " << i + 1 << ": ";
                cin >> novo->nome;
                cout << "Digite o genero do individuo " << i + 1 << ": ";
                cin >> novo->sexo;
                cout << "Digite a idade do individuo " << i + 1 << ": ";
                cin >> novo->idade;
                cout << "Digite o peso do individuo " << i + 1 << ": ";
                cin >> novo->peso;
                novo->esq = NULL;
                novo->dir = NULL;
                Av1 = Insere(Av1, novo);
                system("cls");
            }
            break;

        case 2:
            system("cls");
            Ordem(Av1);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Digite a chave a ser consultada: ";
            cin >> nomeAux;
            Busca(Av1, nomeAux);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "========================================================" << endl;
            cout << "    LISTA DE HOMENS (Ordenada por Ordem Alfabetica)     " << endl;
            cout << "========================================================" << endl;
            ImprimirHomens(Av1);
            cout << "\n\n";
            cout << "========================================================" << endl;
            cout << "   LISTA DE MULHERES (Ordenada por Ordem Alfabetica)    " << endl;
            cout << "========================================================" << endl;
            ImprimirMulheres(Av1);
            system("pause");
            break;

        case 5:
            system("cls");
            cout << "Digite a chave do no a ser removido: ";
            cin >> nomeAux;
            Av1 = Remover(Av1, nomeAux);
            system("pause");
            break;

        case 6:
            cout << "Saindo do programa..." << endl;
            DestroiArvore(Av1);
            system("pause");
            break;
        }
    } while (opc != 6);
}