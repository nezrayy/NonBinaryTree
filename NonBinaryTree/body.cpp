#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "spesifikasi.h"

void Create_tree(Isi_Tree X, int Jml_Node)
{
    X[Jml_Node];
    X[0].info = ' ';
}

boolean IsEmpty(Isi_Tree P)
{
    if (P == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void addParent(Isi_Tree P, infotype X)
{
    P[1].ps_pr = 0;
    P[1].ps_nb = 0;
    P[1].ps_fs = 0;
    P[1].info = X;
    printf("%c menjadi parent/root. Parent berada pada Level 0", X);
    getch();
    system("cls");
}

void addChild(Isi_Tree P, infotype X)
{
    int idChild, idParent;
    nbtree pCur;
    if (!IsEmpty(P)) // child
    {
        printf("Pilih index child, masukkan index: ");
        scanf("%d", &idChild);
        P[idChild].info = X;
        printf("Pilih parent, masukkan index: ");
        scanf("%d", &idParent);
        P[idChild].ps_pr = idParent;
        P[idChild].ps_nb = 0;
        P[idChild].ps_fs = 0;
        if (P[idParent].ps_fs != 0)
        {
            pCur = P[P[idParent].ps_fs];
            if (P[idChild].ps_pr == pCur.ps_pr)
            {
                P[P[idParent].ps_fs].ps_nb = idChild;
            }
        }
        else
        {
            P[idParent].ps_fs = idChild;
        }
    }
    else
    {
        printf("Belum ada parent!");
        return;
    }
    getch();
    system("cls");
}

void PostOrder(Isi_Tree P)
{
    int pCur = 1;
    bool resmi = true;

    while (pCur != 0)
    {
        if (P[pCur].ps_fs != 0 && resmi)
        {
            pCur = P[pCur].ps_fs;
        }
        else
        {
            fflush(stdin);
            printf("%c ", P[pCur].info);
            if (P[pCur].ps_nb != 0)
            {
                pCur = P[pCur].ps_nb;
                resmi = true;
            }
            else
            {
                pCur = P[pCur].ps_pr;
                resmi = false;
            }
        }
    }
    printf("\n");
}

void PreOrder(Isi_Tree P)
{
    int Pcur;   // Posisi Node Aktif
    bool Resmi; // Sifat kunjungan resmi
    Pcur = 1;
    printf("%c", P[Pcur].info);
    Resmi = true;
    do
    {
        if (P[Pcur].ps_fs != 0 && Resmi)
        {
            Pcur = P[Pcur].ps_fs;
            printf("%c", P[Pcur].info);
        }
        else if (P[Pcur].ps_nb != 0)
        {
            Pcur = P[Pcur].ps_nb;
            printf("%c", P[Pcur].info);
            Resmi = true;
        }
        else
        {
            Pcur = P[Pcur].ps_pr;
            Resmi = false;
        }
    } while ((P[Pcur].ps_pr != 0));
    printf("\n");
}

void InOrder(Isi_Tree P)
{
    int Pcur;   // Posisi Node Aktif
    bool Resmi; // Sifat kunjungan resmi
    Pcur = 1;
    Resmi = true;
    while (Pcur != 0)
    {
        if (P[Pcur].ps_fs != 0 && Resmi)
        {
            Pcur = P[Pcur].ps_fs;
        }
        else
        {
            if (Resmi)
            {
                printf("%c", P[Pcur].info);
            }

            if (Pcur == P[P[Pcur].ps_pr].ps_fs)
            {
                printf("%c", P[P[Pcur].ps_pr].info);
            }

            if (P[Pcur].ps_nb != 0)
            {
                Pcur = P[Pcur].ps_nb;
                Resmi = true;
            }
            else
            {
                Pcur = P[Pcur].ps_pr;
                Resmi = false; // Numpang lewat
            }
        }
    }
    printf("\n");
}
