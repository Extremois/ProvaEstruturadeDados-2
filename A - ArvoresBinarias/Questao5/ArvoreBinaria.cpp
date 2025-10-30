#include "ArvoreBinaria.h"
#include <iostream>

using namespace std;

Arvore Av1;

int main()
{
    int opc;
    int n;
    int k;

    Av1 = Inicializa_Arv(Av1);

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
                cout << "Digite a chave do no " << i + 1 << ": ";
                cin >> novo->chave;
                cout << "Digite a info do no " << i + 1 << ": ";
                cin >> novo->info;
                novo->esq = NULL;
                novo->dir = NULL;
                Av1 = Insere(Av1, novo);
            }
            break;

        case 2:
            system("cls");
            Ordem(Av1);
            system("pause");
            break;

        case 3:
            system("cls");
            PreOrdem(Av1);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Digite a chave a ser consultada: ";
            cin >> k;
            Busca(Av1, k);
            system("pause");
            break;

        case 5:
            system("cls");

            if (ArvoreCheia(Av1))
            {
                cout << "Arvore eh cheia" << endl;
            }
            else
            {
                cout << "Arvore nao eh cheia" << endl;
            }
            
            system("pause");
            break;

        case 6:
            system("cls");
            cout << "Digite a chave do no a ser removido: ";
            cin >> k;
            Av1 = Remover(Av1, k);
            system("pause");
            break;

        case 7:
            cout << "Saindo do programa..." << endl;
            free(Av1);
            system("pause");
            break;
        }
    } while (opc != 7);
}