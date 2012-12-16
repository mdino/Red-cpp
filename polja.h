
struct tpacijent {
    int xi,yi,prioritet,transakcija,godina;
    char ime[40],prezime[40],devizni_valuta[40];
    float tekuci,devizni;
    tpacijent*sljedeci;
};
struct telement {
    tpacijent* front,*rear;
};
int AddOne(int n) {
    return((n+1)%10000);
}
int InitQ(telement*element) {
    tpacijent*glava=new tpacijent;
    glava->sljedeci=NULL;
    element->front=glava;
    element->rear=glava;
}
bool IsEmptyQ(telement*element) {
    if(element->rear==element->front)return 1;
    return 0;
}
void EnQueueQ(tpacijent*pacijent,telement*element) {
    element->rear->sljedeci=pacijent;
    pacijent->sljedeci=NULL;
    element->rear=pacijent;
}
tpacijent*FrontQ(telement*element) {
    tpacijent*pacijent;
    pacijent=element->front->sljedeci;
    return pacijent;
}
void DeQueueQ(telement*element) {
    tpacijent*glava=element->front;
    element->front=glava->sljedeci;
    delete glava;
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


