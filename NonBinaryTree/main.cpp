#include <stdio.h>
#include "body.cpp"

int main()
{

    Isi_Tree tree1;
    infotype isi;
    int pilih, jmlNode;

    fflush(stdin);
    printf("Berapa jumlah node yang akan dibuat : ");
    scanf("%d", &jmlNode);

    Create_tree(tree1, jmlNode);
    fflush(stdin);
    printf("Tambahkan parent: ");
    scanf("%c", &isi);

    addParent(tree1, isi);

    while (true)
    {
        fflush(stdin);
        printf("1. Insert\n2. Search\n3. Traversal\n4. Delete\n5. Keluar\nPilih: ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            fflush(stdin);
            printf("Masukkan karakter/isi: ");
            scanf("%c", &isi);
            addChild(tree1, isi);
            break;
        case 2:
            InOrder(tree1);
            break;
        default:
            break;
        }
    }
    return 0;
}