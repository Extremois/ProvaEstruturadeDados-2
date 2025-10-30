#include "ArvoreBinaria.h"
#include <iostream>

using namespace std;

Arvore Av1;

int main()
{
    int opc;
    int n = 8;
    int k;
    int dados[] = {20, 5, 12, 36, 27, 45, 9, 2, 6, 17, 40};

    Av1 = Inicializa_Arv(Av1);

    do
    {
        system("cls");
        opc = MenuArvore();
        switch (opc)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                No *novo = new No;
                novo->info = dados[i];
                novo->chave = dados[i];
                novo->esq = NULL;
                novo->dir = NULL;
                Av1 = Insere(Av1, novo);
            }
            cout << "Itens inseridos com sucesso" << endl;
            system("pause");
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
            cout << "Digite a chave do no a ser removido: ";
            cin >> k;
            Av1 = Remover(Av1, k);
            system("pause");
            break;

        case 6:
            cout << "Saindo do programa..." << endl;
            free(Av1);
            system("pause");
            break;
        }
    } while (opc != 6);
}