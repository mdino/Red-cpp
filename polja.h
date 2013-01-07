struct tljudi {
    int xi,yi,prioritet,transakcija,godina;
    char ime[40],prezime[40],devizni_valuta[40];
    float tekuci,devizni;
    tljudi*sljedeci;
};
struct telement {
    tljudi* front,*rear;
};
int AddOne(int n) {
    return((n+1)%10000);
}
int InitQ(telement*element) {
    tljudi*glava=new tljudi;
    glava->sljedeci=NULL;
    element->front=glava;
    element->rear=glava;
}
bool IsEmptyQ(telement*element) {
    if(element->rear==element->front)return 1;
    return 0;
}
void EnQueueQ(tljudi*pacijent,telement*element) {
    element->rear->sljedeci=pacijent;
    pacijent->sljedeci=NULL;
    element->rear=pacijent;
}
tljudi*FrontQ(telement*element) {
    tljudi*pacijent;
    pacijent=element->front->sljedeci;
    return pacijent;
}
void DeQueueQ(telement*element) {
    tljudi*glava=element->front;
    element->front=glava->sljedeci;
    delete glava;
}
