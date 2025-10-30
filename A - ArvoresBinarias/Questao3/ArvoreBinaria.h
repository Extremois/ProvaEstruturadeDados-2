#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

typedef struct Reg
{
    string nome;
    char sexo;
    int idade;
    float peso;
    Reg *esq;
    Reg *dir;
} No;

typedef No *Arvore;

Arvore InicializaArv(No *Tree)
{
    return Tree = NULL;
}

Arvore Insere(Arvore Tree, No *novo)
{
    if (Tree == NULL)
    {
        return novo;
    }

    if (Tree->nome > novo->nome)
    {
        Tree->esq = Insere(Tree->esq, novo);
    }
    else if (Tree->nome < novo->nome)
    {
        Tree->dir = Insere(Tree->dir, novo);
    }
    else
    {
        cout << "Nome ja existente!" << endl;
    }
    return Tree;
}

int MenuArvore()
{
    int opc;
    system("cls");
    cout << "========================================================" << endl;
    cout << "            ESCOLHA UMA OPCAO NO MENU ABAIXO            " << endl;
    cout << "========================================================" << endl;
    cout << "  [1] INSERIR NOME NA ARVORE                            " << endl;
    cout << "  [2] IMPRIMIR EM ORDEM ALFABETICA                      " << endl;
    cout << "  [3] CONSULTAR NOME NA ARVORE                          " << endl;
    cout << "  [4] CONSULTAR LISTA ORDENADA DE NOMES                 " << endl;
    cout << "  [5] EXCLUIR NOME DA ARVORE                            " << endl;
    cout << "  [6] SAIR DO PROGRAMA                                  " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "  OPCAO ESCOLHIDA: ";
    cin >> opc;
    return opc;
}

void PreOrdem(Arvore Tree)
{
    if (Tree != NULL)
    {
        cout << "Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
        PreOrdem(Tree->esq);
        PreOrdem(Tree->dir);
    }
}

void Ordem(Arvore Tree)
{
    if (Tree != NULL)
    {
        Ordem(Tree->esq);
        cout << "Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
        Ordem(Tree->dir);
    }
}

void PosOrdem(Arvore Tree)
{
    if (Tree != NULL)
    {
        PosOrdem(Tree->esq);
        PosOrdem(Tree->dir);
        cout << "Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
    }
}

No *Busca(Arvore Tree, string nome)
{
    int result;

    if (Tree == NULL)
    {
        cout << "No nao encontrado!" << endl;
        return NULL;
    }

    if (Tree->nome == nome)
    {
        cout << "No encontrado! - Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
        return Tree;
    }

    if (nome < Tree->nome)
    {
        return Busca(Tree->esq, nome);
    }
    else
    {
        return Busca(Tree->dir, nome);
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

Arvore Remover(Arvore Tree, string nome)
{
    if (Tree == NULL)
    {
        cout << "No nao encontrado!" << endl;
        return NULL;
    }

    if (nome < Tree->nome)
    {
        Tree->esq = Remover(Tree->esq, nome);
    }
    else if (nome > Tree->nome)
    {
        Tree->dir = Remover(Tree->dir, nome);
    }
    else
    {
        cout << "No [Chave: " << nome << "] removido!" << endl;
        Tree = RemoveRaiz(Tree);
    }
    return Tree;
}

void DestroiArvore(Arvore Tree)
{
    if (Tree != NULL)
    {
        DestroiArvore(Tree->esq);
        DestroiArvore(Tree->dir);
        delete Tree;
    }
}

void ImprimirHomens(Arvore Tree)
{
    if (Tree != NULL)
    {
        ImprimirHomens(Tree->esq);
        if (Tree->sexo == 'm' || Tree->sexo == 'M')
        {
            cout << "Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
        }
        ImprimirHomens(Tree->dir);
    }
}

void ImprimirMulheres(Arvore Tree)
{

    if (Tree != NULL)
    {
        ImprimirMulheres(Tree->esq);
        if (Tree->sexo == 'f' || Tree->sexo == 'F')
        {
            cout << "Nome: " << Tree->nome << " - Sexo: " << Tree->sexo << " - Idade: " << Tree->idade << " - Peso: " << Tree->peso << endl;
        }
        ImprimirMulheres(Tree->dir);
    }
}