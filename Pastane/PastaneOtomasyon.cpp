/*ismet Eren 2412721033
Pastane Otomasyonu*/

#include<iostream>
#include<fstream>
#include<string>
#include<locale.h>

using namespace std;

struct urun
{
    string ad;
    double fiyat;
};

void siparisleriKaydet(urun siparis[],int siparissayisi)
{
    ofstream siparisdosya("siparis.txt");
    if(siparisdosya.is_open()){
        for(int i=0;i<siparissayisi;i++){
            siparisdosya<<siparis[i].ad<<" - "<<siparis[i].fiyat<<" TL\n";

        }
        cout<<"Sipari�ler kaydedildi \n";
    }else{
        cout<<"Sipari�ler al�namad� \n";
    } 
    siparisdosya.close();
}

void urunlerilistele(urun urunler[],int urunsayisi)
{
    cout<<"\n Pastanemize Ho�geldiniz \n";
    cout<<"-------------------------\n";
    for(int i=0;i<urunsayisi;i++){
        cout<<i+1<<". "<<urunler[i].ad<<"-"<<urunler[i].fiyat<<" TL\n";
    }
}

int siparisal(urun urunler[],int urunsayisi,urun siparis[])
{
    double toplam=0.0;
    int secim;
    int siparisSayisi=0;

    cout<<"\nSipari� vermek i�in �r�n numaras�n� se�in(sipari�i bitirmek i�in 0 a bas�n): \n";

    while(true){
        cout<<"�r�n Se�imi: ";
        cin>>secim;

        if(secim==0){
            cout<<"\nToplam �cret: "<<toplam<<" TL"<<"\n\n";
            break;
        }
        if(secim<1 || secim>urunsayisi){
            "B�yle bir �r�n yok,Tekrar Deneyiniz\n";
            continue;
        }
        if(secim>=1 && secim<=urunsayisi){
            toplam+=urunler[secim-1].fiyat;
        }

        siparis[siparisSayisi]=urunler[secim-1];
        siparisSayisi++;
        cout<<urunler[secim-1].ad<<" sipari�inize eklendi.\n";
        
    }

  return siparisSayisi;
}

int main()
{
    setlocale(LC_ALL,"Turkish");

    urun urunler[]={
        {"�ikolatali Pasta",350.0},
        {"�ilekli Pasta",380.0},
        {"Meyveli Pasta",400.0},
        {"Do�um g�n� Pastas� (4 ki�ilik)",420.0},
        {"Bademli Kurabiye 500g",320.0},
        {"Pudral� Bademli Kurabiye",245.0},
        {"F�st�kl� Baklava",1200.0},
        {"Cevizli Baklava",1100.0},
        {"Cheescake",200.0},
        {"F�r�n S�tla�",220.0},
        {"Tiramisu Mini Kup",95.0},
        {"Macaron 6'l� Kutu",480.0},
        {"Macaron 8'l� Kutu",640.0},
        {"F�st�kl� Lokum",550.0},
        {"Kazandibi",185.0},
        {"Profiterol",185.0},
        {"Frambuazl� Minik Ekler",660.0},
        {"Karamelli Minik Ekler",660.0},
        {"�ikolatal� Minik Ekler",660.0},
        {"Kestane �ekeri Paketli",500.0},
        {"Kestane �ekeri Varakl�",835.0},
        {"Kestane �ekeri B�y�k Kutu",900.0},
        {"Kestane �ekeri K���k Kutu",550.0}
    };
    
    urun siparis[100];
    int secim;

    int urunsayisi=sizeof(urunler)/sizeof(urunler[0]);

    while(true){
        cout<<"------Pastane Otomasyonu------\n";
        cout<<"1. �r�nleri Listele\n";
        cout<<"2. Sipari� ver\n";
        cout<<"3. Sipari�leri Listele\n";
        cout<<"4. ��k��\n";
        cout<<"Se�iminizi Yap�n: ";
        cin>>secim;

        if(secim==1){
            urunlerilistele(urunler,urunsayisi);
            cout<<"\n";
        }

        else if(secim==2){
            int SiparisSayisi=siparisal(urunler,urunsayisi,siparis);
            if(SiparisSayisi>0){
                siparisleriKaydet(siparis,SiparisSayisi);
            }
            
        }

        else if(secim==3){
            cout<<"\n";
            string satir;
            ifstream siparislistele("siparis.txt");
            
            while(getline(siparislistele,satir)){
                cout<<satir<<"\n";
            }
            cout<<"\n";
        }
        
        else if(secim==4){
            cout<<"\n";
            
            cout<<"Sistemden ��k�l�yor...\n";
            ofstream siparisdosya("siparis.txt");
            siparisdosya.is_open();
            siparisdosya.close();break;
        }

        else{
            cout<<"\nB�yle bir se�enek yok,Tekrar Deneyiniz \n\n";
        }
        
    }
    
 return 0;
}