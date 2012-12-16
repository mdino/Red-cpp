#include <iostream>
using namespace std;

struct tpacijent {
    int xi,yi,prioritet,transakcija,godina;
    char ime[40],prezime[40],devizni_valuta[40];
    float tekuci,devizni;
    tpacijent*sljedeci;
};
int AddOne(int n) {
    return((n+1)%10000);
}
struct telement {
    tpacijent*pacijent[10000];
    int front,rear;
};
void EnQueueQ (tpacijent*pacijent, telement *element) {
    if (AddOne(AddOne(element->rear)) == (element->front))
        cout<<"RED JE PUN!!\n\n";
    else {
        element->rear = AddOne(element->rear);
        element->pacijent[element->rear] = pacijent;
    }
}
int IsEmptyQ(telement*element) {
    int rear=element->rear;
    if(AddOne(rear)==element->front)return 1;
    return 0;
}
tpacijent*FrontQ(telement*element) {
    if(!IsEmptyQ)cout<<"RED JE PRAZAN!\n";
    return element->pacijent[element->front];
}
void DeQueueQ(telement*element) {
    element->front++;
}
void InitQ(telement*element) {
    element->front=0;
    element->rear=9999;
}
//FrontQ(Q) - Funkcija koja vraca vrijednost
//elementa koji se trenutno nalazi na celu reda.
//EnQueueQ(x,Q) - Procedura koja dodaje
//novi element s vrijednoscu x na zacelje reda.
//DeQueueQ(Q) - Procedura koja brise
//element s cela reda.
//InitQ(Q) - Procedura koja inicira prazan red.
//IsEmptyQ(Q) - logicka funkcija koja odgovara
//na pitanje da li je red prazan.
