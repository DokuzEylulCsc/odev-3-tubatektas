#include <iostream>
#include <fstream>
#include <vector>
#include <string>
  
  
/*ödev3
  tuba tektaş
  2018280042
  */
  
//KAYNAKÇA https://hakanceran.com.tr/cplusplus-dosya-acma-ve-kapatma/


//https://www.w3schools.com, https://www.yusufsezer.com.tr/cpp-dosya-islemleri/,https://code.sololearn.com/c1m6GrO526f6/#cpp



int main(void) {
    int Soru-sayisi = 0;
    int i;
    int Puan = 0;
    int k = 0;
    int OgrenciSayisi = 0;
    int Ortalamasi = 0;
    int Toplam = 0;
    int Aciklik;
    int OgrencininPuanlari[OgrenciSayisi+5];
    char y = '\0';
    char CevapAnahtari[Soru-sayisi];
    char OgrencininCevabı[Soru-sayisi+1];
    std::fstream Dosya;
    
    Dosya.open("input.txt");
    
    std::cout << "girilen sınavdaki soru sayısı?";
    std::cin  >> Soru-sayisi;
    
    std::cout << "girilen sınavın cvp anahtarı?"<<end1;
    for (i = 0; i < Soru-sayisi; i++) {
        std::cin >> CevapAnahtari[i];
            if (Dosya.is_open()) {
                for(int i = 0; i < Soru-sayisi; i++) {
                    Dosya << CevapAnahtari[i];
                }
            }
    }
        
    std::cout << "sınava giren öğrenci sayısı(max 100 tane öğrenci için işlem yapılabilir!):";
    std::cin >> OgrenciSayisi;
    if (OgrenciSayisi <= 100) {
        for (i = 1; i <= OgrenciSayisi; i++) {
            std::cout << "Öğrencinin numarasını girdikten sonra cevaplarını giriniz( boş ise y yazın!):";
            
            for (i = 0; i <= Soru-sayisi; i++) {
                std::cin >> OgrencininCevabı[i+1];
                if (Dosya.is_open()) {
                    for(int i = 0; i < Soru-sayisi+1; i++) {
                        Dosya << OgrencininCevabı[i+1];
                    }
                }
                
                for (i = 0; i <= Soru-sayisi; i++) {
                    if (CevapAnahtari[i] == OgrencininCevabı[i+1]) {
                        Puan += 4;
                    }
                    else if (CevapAnahtari[i] != OgrencininCevabı[i+1]) {
                        Puan = Puan - 1;
                    }
                    else if(OgrencininCevabı[i+1] == y){
                        Puan += 0;
                    }
                    
                    OgrencininPuanlari[i] = Puan;
                    Toplam += Puan;
                }
                
            }
            if (Puan < 0) {
                Puan = 0;
            }
        }
    }
    
    for (i = 0; i <= OgrenciSayisi; i++) {
        if (OgrencininPuanlari[i] > OgrencininPuanlari[i+1]) {
            OgrencininPuanlari[i] = k;
            OgrencininPuanlari[i+1] = OgrencininPuanlari[i];
            OgrencininPuanlari[i+1] = k;
        }
    }
    
    Ortalamasi = Toplam % OgrenciSayisi;
    Aciklik = OgrencininPuanlari[OgrenciSayisi] - OgrencininPuanlari[0];
    
    OgrencininPuanlari[OgrenciSayisi+1] = OgrencniniPuanlari[0]; // minimum not.
    OgrencininPuanlari[OgrenciSayisi+2] = OgrencininPuanlari[OgrenciSayisi]; //maksimum not.
    OgrencininPuanlari[OgrenciSayisi+3] = Ortalamasi;
    OgrencininPuanlari[OgrenciSayisi+4] = OgrencininPuanlari[OgrenciSayisi % 2];
    OgrencininPuanlari[OgrenciSayisi+5] = Aciklik;
    
    Dosya.close();
    
    return 0;
}
