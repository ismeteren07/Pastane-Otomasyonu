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
        cout<<"Sipariþler kaydedildi \n";
    }else{
        cout<<"Sipariþler alýnamadý \n";
    } 
    siparisdosya.close();
}

void urunlerilistele(urun urunler[],int urunsayisi)
{
    cout<<"\n Pastanemize Hoþgeldiniz \n";
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

    cout<<"\nSipariþ vermek için ürün numarasýný seçin(sipariþi bitirmek için 0 a basýn): \n";

    while(true){
        cout<<"ürün Seçimi: ";
        cin>>secim;

        if(secim==0){
            cout<<"\nToplam ücret: "<<toplam<<" TL"<<"\n\n";
            break;
        }
        if(secim<1 || secim>urunsayisi){
            "Böyle bir ürün yok,Tekrar Deneyiniz\n";
            continue;
        }
        if(secim>=1 && secim<=urunsayisi){
            toplam+=urunler[secim-1].fiyat;
        }

        siparis[siparisSayisi]=urunler[secim-1];
        siparisSayisi++;
        cout<<urunler[secim-1].ad<<" sipariþinize eklendi.\n";
        
    }

  return siparisSayisi;
}

int main()
{
    setlocale(LC_ALL,"Turkish");

    urun urunler[]={
        {"Çikolatali Pasta",350.0},
        {"Çilekli Pasta",380.0},
        {"Meyveli Pasta",400.0},
        {"Doðum günü Pastasý (4 kiþilik)",420.0},
        {"Bademli Kurabiye 500g",320.0},
        {"Pudralý Bademli Kurabiye",245.0},
        {"Fýstýklý Baklava",1200.0},
        {"Cevizli Baklava",1100.0},
        {"Cheescake",200.0},
        {"Fýrýn Sütlaç",220.0},
        {"Tiramisu Mini Kup",95.0},
        {"Macaron 6'lý Kutu",480.0},
        {"Macaron 8'lý Kutu",640.0},
        {"Fýstýklý Lokum",550.0},
        {"Kazandibi",185.0},
        {"Profiterol",185.0},
        {"Frambuazlý Minik Ekler",660.0},
        {"Karamelli Minik Ekler",660.0},
        {"Çikolatalý Minik Ekler",660.0},
        {"Kestane Þekeri Paketli",500.0},
        {"Kestane Þekeri Varaklý",835.0},
        {"Kestane Þekeri Büyük Kutu",900.0},
        {"Kestane Þekeri Küçük Kutu",550.0}
    };
    
    urun siparis[100];
    int secim;

    int urunsayisi=sizeof(urunler)/sizeof(urunler[0]);

    while(true){
        cout<<"------Pastane Otomasyonu------\n";
        cout<<"1. Ürünleri Listele\n";
        cout<<"2. Sipariþ ver\n";
        cout<<"3. Sipariþleri Listele\n";
        cout<<"4. Çýkýþ\n";
        cout<<"Seçiminizi Yapýn: ";
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
            
            cout<<"Sistemden çýkýlýyor...\n";
            ofstream siparisdosya("siparis.txt");
            siparisdosya.is_open();
            siparisdosya.close();break;
        }

        else{
            cout<<"\nBöyle bir seçenek yok,Tekrar Deneyiniz \n\n";
        }
        
    }
    
 return 0;
}