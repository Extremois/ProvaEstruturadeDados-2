#include <iostream>

using namespace std;

typedef struct Reg
{
    int chave;
    int info;
    int ocorrenciasDeDuplicatas = 0;
    Reg *esq;
    Reg *dir;
} No;

typedef No *Arvore;

Arvore Inicializa_Arv(No *Tree)
{
    return Tree = NULL;
}

Arvore Insere(Arvore Tree, No *novo)
{
    if (Tree == NULL)
    {
        return novo;
    }

    if (Tree->chave > novo->chave)
    {
        Tree->esq = Insere(Tree->esq, novo);
    }
    else if (Tree->chave < novo->chave)
    {
        Tree->dir = Insere(Tree->dir, novo);
    }
    else
    {
        Tree->ocorrenciasDeDuplicatas++;
        cout << "Chave ja existente!" << endl;
    }
    return Tree;
}

int MenuArvore()
{
    int opc;
    system("cls");
    cout << "========================================================" << endl;
    cout << "            ESCOLHA UMA OPCAO NO MENU ABAIXO           " << endl;
    cout << "========================================================" << endl;
    cout << "  [1] INSERIR DADO NA ARVORE                            " << endl;
    cout << "  [2] IMPRIMIR EM ORDEM                                 " << endl;
    cout << "  [3] IMPRIMIR EM PRE-ORDEM                             " << endl;
    cout << "  [4] CONSULTAR DADO NA ARVORE                          " << endl;
    cout << "  [5] CONSULTAR MAIOR VALOR DA ARVORE                   " << endl;
    cout << "  [6] EXCLUIR DADO DA ARVORE                            " << endl;
    cout << "  [7] SAIR DO PROGRAMA                                  " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  OPCAO ESCOLHIDA: ";
    cin >> opc;
    return opc;
}

void PreOrdem(Arvore Tree)
{
    if (Tree != NULL)
    {
        cout << "Chave: " << Tree->chave << " - Info: " << Tree->info << " - Duplicatas: " << Tree->ocorrenciasDeDuplicatas << endl;
        PreOrdem(Tree->esq);
        PreOrdem(Tree->dir);
    }
}

void Ordem(Arvore Tree)
{
    if (Tree != NULL)
    {
        Ordem(Tree->esq);
        cout << "Chave: " << Tree->chave << " - Info: " << Tree->info << " - Duplicatas: " << Tree->ocorrenciasDeDuplicatas << endl;
        Ordem(Tree->dir);
    }
}

void PosOrdem(Arvore Tree)
{
    if (Tree != NULL)
    {
        PosOrdem(Tree->esq);
        PosOrdem(Tree->dir);
        cout << "Chave: " << Tree->chave << " - Info: " << Tree->info << " - Duplicatas: " << Tree->ocorrenciasDeDuplicatas << endl;
    }
}

No *Busca(Arvore Tree, int k)
{
    if (Tree == NULL)
    {
        cout << "No nao encontrado!" << endl;
        return NULL;
    }
    if (Tree->chave == k)
    {
        cout << "No encontrado! - Chave: " << Tree->chave << " - Info: " << Tree->info << endl;
        return Tree;
    }

    if (k < Tree->chave)
    {
        return Busca(Tree->esq, k);
    }
    else
    {
        return Busca(Tree->dir, k);
    }
}

Arvore RemoveRaiz(Arvore r)
{
    if (r == NULL)
    {
        cout << "No nao encontrado!" << endl;
        return NULL;
    }

    No *p, *q;
    if (r->esq == NULL)
    {
        q = r->dir;
        delete r;
        return q;
    }
    p = r;
    q = r->esq;

    while (q->dir != NULL)
    {
        p = q;
        q = q->dir;
    }
    if (p != r)
    {
        p->dir = q->esq;
        q->esq = r->esq;
    }
    q->dir = r->dir;

    delete r;
    return q;
}

Arvore Remover(Arvore Tree, int k)
{
    if (Tree == NULL)
    {
        cout << "No nao encontrado!" << endl;
        return NULL;
    }

    if (k < Tree->chave)
    {
        Tree->esq = Remover(Tree->esq, k);
    }
    else if (k > Tree->chave)
    {
        Tree->dir = Remover(Tree->dir, k);
    }
    else if (Tree->ocorrenciasDeDuplicatas > 0)
    {
        Tree->ocorrenciasDeDuplicatas--;
        cout << "Uma duplicata do no [Chave: " << k << "] foi removida! Restam " << Tree->ocorrenciasDeDuplicatas << " duplicatas." << endl;
    }
    else
    {
        cout << "No [Chave: " << k << "] removido!" << endl;
        Tree = RemoveRaiz(Tree);
    }
    return Tree;
}

int BuscaMaior(Arvore Tree)
{
    if (Tree == NULL)
    {
        cout << "Arvore nao existe" << endl;
        return NULL;
    }

    if (Tree->dir == NULL)
    {
        return Tree->chave;
    }

    return BuscaMaior(Tree->dir);
}