#include <iostream>
using namespace std;

struct tljudi {
    int xi,yi,prioritet,transakcija,godina;
    char ime[40],prezime[40],devizni_valuta[40];
    float tekuci,devizni;
    tljudi*sljedeci;
};
int AddOne(int n) {
    return((n+1)%10000);
}
struct telement {
    tljudi*ljudi[10000];
    int front,rear;
};
void EnQueueQ (tljudi*ljudi, telement *element) {
    if (AddOne(AddOne(element->rear)) == (element->front))
        cout<<"RED JE PUN!!\n\n";
    else {
        element->rear = AddOne(element->rear);
        element->ljudi[element->rear] = ljudi;
    }
}
int IsEmptyQ(telement*element) {
    int rear=element->rear;
    if(AddOne(rear)==element->front)return 1;
    return 0;
}
tljudi*FrontQ(telement*element) {
    if(!IsEmptyQ)cout<<"RED JE PRAZAN!\n";
    return element->ljudi[element->front];
}
void DeQueueQ(telement*element) {
    element->front++;
}
void InitQ(telement*element) {
    element->front=0;
    element->rear=9999;
}

