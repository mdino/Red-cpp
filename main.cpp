#include <iostream>
#include <ctime>
//#include "polja.h"
#include "pok.h"
#include <cstdlib>
#include <cstring>

using namespace std;

telement*element=new telement;
int ukupno=0;

struct cetvorka{  
	int ai,bi,ci,di;
};

cetvorka*podaci;
telement*red=new telement;
tpacijent*pomocni=new tpacijent;
telement*pomocni_red=new telement;

void ispis(tpacijent*covjek){
	cout<<"Podaci o osobi\n-----------------------\n";
	cout<<"Ime= "<<covjek->ime<<endl;
	cout<<"Prezime= "<<covjek->prezime<<endl;
	cout<<"Godina rodenja= "<<covjek->godina<<endl;
	cout<<"Tekuci stanje= "<<covjek->tekuci<<endl;
	cout<<"Devizni stanje= "<<covjek->devizni<<"  "<<covjek->devizni_valuta<<endl;
	cout<<"ai= "<<covjek->xi<<endl;
	cout<<"bi= "<<covjek->yi<<endl;
	cout<<"Prioritet= "<<covjek->prioritet<<endl;
	cout<<"Vrsta transakcije= "<<covjek->transakcija<<endl;
}

void prvi() {
    cout<<"N = ";
    int N;
    cin>>N;
    ukupno+=N;
    srand(time(0));
    rand();
    podaci=new cetvorka[N];
    for(int i=0; i<N; i++) {
        podaci[i].ai=rand()%401+100;
        podaci[i].bi=rand()%401+100;
        podaci[i].ci=rand()%6+1;
        podaci[i].di=rand()%4+1;
        if(podaci[i].ci==6&&podaci[i].di==2)i--;
    }
}

int drugi_zad(){
	for(int i=0;i<ukupno;i++){
		tpacijent*covjek=new tpacijent;
		cout<<"Ime= ";
		cin>>covjek->ime;
		cout<<"Prezime= ";
		cin>>covjek->prezime;
		cout<<"Godina rodenja= ";
		cin>>covjek->godina;
		cout<<"Tekuci stanje= ";
		cin>>covjek->tekuci;
		cout<<"Devizni je u: ";
		cin>>covjek->devizni_valuta;
		cout<<"Devizni stanje= ";
		cin>>covjek->devizni;
		covjek->xi=podaci[i].ai;
		covjek->yi=podaci[i].bi;
		covjek->prioritet=podaci[i].ci;
		covjek->transakcija=podaci[i].di;
		cout<<"dodajem covjeka u red\n\n";
		cout<<"----------------------\n";
		EnQueueQ(covjek,red);
	}
	tpacijent*covjek=new tpacijent;
	tpacijent novi[ukupno];
	tpacijent*novi2=new tpacijent;
	for(int i=0; i<ukupno; i++) {
        novi2=FrontQ(red);
        //cout<<"Novi 2 na poziciji: "<<i<<" je : "<<novi2->ime<<endl;
        DeQueueQ(red);
        memcpy(&novi[i],novi2,sizeof(tpacijent));
    }
    for(int i=1; i<ukupno; i++) {
        int j=i-1;
        int pom=novi[i].prioritet;
        tpacijent pom2=novi[i];
        while(j>=0&&novi[j].prioritet>pom) {
            novi[j+1]=novi[j--];
            novi[j+1]=pom2;
        }
    }
    red=new telement;
    InitQ(red);
    for(int i=0;i<ukupno;i++){
    	pomocni=new tpacijent;
    	if(novi[i].devizni>10000)cout<<"KLIJENT : "<<novi[i].ime<<", "<<novi[i].prezime<<" ima preko 10000 "<<novi[i].devizni_valuta<<endl;
    	memcpy(pomocni,&novi[i],sizeof(tpacijent));
    	//cout<<"IMEEEEE= "<<pomocni->ime<<endl;
    	EnQueueQ(pomocni,red);
    	pomocni=FrontQ(red);
    	//cout<<"Vraceno ime: "<<pomocni->ime<<endl;
    }
}


void treci(){
	tpacijent brze_transakcije[ukupno];
	tpacijent stare_transakcije[ukupno];
	int pomocni_brojac_brze_transakcije=0;
	int pomocni_brojac_stare_transakcije=0;
	tpacijent*pomocnipacijent=new tpacijent;
	for(int i=0;i<ukupno;i++){
		pomocnipacijent=FrontQ(red);
		//cout<<"Pacijent "<<pomocnipacijent->ime<<endl;
		if(pomocnipacijent->transakcija==4){
			memcpy(&brze_transakcije[pomocni_brojac_brze_transakcije],pomocnipacijent,sizeof(tpacijent));
			pomocni_brojac_brze_transakcije++;
		}
	    else{
	    	memcpy(&stare_transakcije[pomocni_brojac_stare_transakcije],pomocnipacijent,sizeof(tpacijent));
	    	pomocni_brojac_stare_transakcije++;
	    }
		DeQueueQ(red);
	}
	cout<<"Stanje glavnog reda\n";
	cout<<endl<<endl;
	for(int i=0;i<pomocni_brojac_stare_transakcije;i++){
		ispis(&stare_transakcije[i]);
		memcpy(pomocni,&stare_transakcije[i],sizeof(tpacijent));
		EnQueueQ(pomocni,red);
	}
	ukupno=pomocni_brojac_stare_transakcije;
	cout<<endl<<endl<<endl;
	cout<<"Stanje pomocnog reda\n";
	cout<<endl<<endl;
	for(int i=0;i<pomocni_brojac_brze_transakcije;i++){
		ispis(&brze_transakcije[i]);
	}
}

void cetvrti(){
	tpacijent pomocnired[ukupno];
	int pomocni_brojac=0;
	for (int i=0;i<ukupno;i++){
		pomocni=FrontQ(red);
		if((pomocni->godina>1982&&pomocni->transakcija==1&&pomocni->prioritet==4)||(pomocni->prioritet==1&&pomocni->transakcija==2&&pomocni->tekuci>5000)){
			cout<<"Izbacujem osobu: "<<pomocni->ime<<pomocni->prezime<<endl;
		}
		else{
			memcpy(&pomocnired[pomocni_brojac],pomocni,sizeof(tpacijent));
			pomocni_brojac++;
		}
		DeQueueQ(red);
	}
	cout<<endl<<endl;
	cout<<"Stanje na glavnom stogu\n\n";
	ukupno=pomocni_brojac;
	for(int i=0;i<ukupno;i++){
		memcpy(pomocni,&pomocnired[i],sizeof(tpacijent));
		EnQueueQ(pomocni,red);
		ispis(pomocni);
	}
}

void peti(int brojac_sedamdeset,int brojac_za_red){
	if(IsEmptyQ(red)==1)return;
	tpacijent*p=new tpacijent;
	if(brojac_za_red<=brojac_sedamdeset-1){
		p=FrontQ(red);
		cout<<"P= "<<p->ime<<endl;
		brojac_za_red++;
		DeQueueQ(red);
		peti(brojac_sedamdeset,brojac_za_red);
	}
	else {
		//cout<<"ulazim gdje je pomocni red\n";
		while(IsEmptyQ(red)==0){
			tpacijent*d=new tpacijent;
			d=FrontQ(red);
		//	cout<<"D= "<<d->ime<<endl;
			EnQueueQ(d,pomocni_red);
			DeQueueQ(red);
		}
	}
//	ispis(p);
	//cout<<"Vracam nazad u glavni red\n";
	//cout<<"Ime= "<<p->ime<<endl;
	//cout<<"------------------------\n";
	EnQueueQ(p,red);
}

void peti_nastavak(telement*neki_red){
	if(IsEmptyQ(neki_red)==1)return;
	tpacijent*p=new tpacijent;
	p=FrontQ(neki_red);
	DeQueueQ(neki_red);
	peti_nastavak(neki_red);
	EnQueueQ(p,neki_red);
	ispis(p);
}

int main() {
    InitQ(element);
    InitQ(red);
    InitQ(pomocni_red);
    int izbor;
    do {
        cout << "IZBORNIK\n-------\n";
        cout<<"1. Generiranje niza slucajnih brojeva\n";
        cout<<"2. Dolazak osoba\n";
        cout<<"3. Brze transakcije\n";
        cout<<"4. Brisanje klijenata\n";
        cout<<"5. Otvaranje novog saltera u banci\n";
        cin>>izbor;
        system("cls");
        switch(izbor) {
        case 1:
            prvi();
            break;
        case 2:
            drugi_zad();
            break;
        case 3:
        	treci();
        	break;
        case 4:
        	cetvrti();
        	break;
        case 5:
			int brojac_za_red=0;
			int brojac_sedamdeset=0.7*ukupno+1;
        	peti(brojac_sedamdeset,brojac_za_red);
        	cout<<"\n\n\nStanje na glavnom redu\n===============\n";
        	peti_nastavak(red);
        	cout<<"\n\n\nStanje na pomocnom redu\n===============\n";
        	peti_nastavak(pomocni_red);
        	break;
        
        }
    } while(izbor!=9);
    return 0;
}
