
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
void EnQueueQ(tljudi*ljudi,telement*element) {
    element->rear->sljedeci=ljudi;
    ljudi->sljedeci=NULL;
    element->rear=ljudi;
}
tljudi*FrontQ(telement*element) {
    tljudi*ljudi;
    ljudi=element->front->sljedeci;
    return ljudi;
}
void DeQueueQ(telement*element) {
    tljudi*glava=element->front;
    element->front=glava->sljedeci;
    delete glava;
}


