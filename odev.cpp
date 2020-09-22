/****************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** PROGRAMLAMAYA GİRİŞİ DERSİ
**
** ÖDEV NUMARASI…...:1
** ÖĞRENCİ ADI...............:Ekhtiram KHUDİEV
** ÖĞRENCİ NUMARASI.:B161210558
** DERS GRUBU…………:1A
****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showCurrentData(const char* file_name, int n)//verdiyimiz dosyada verdiyimiz satiri ekrana bastiriyor
{
    ifstream is(file_name);

    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no == n)
            cout << c;
    }
    is.close();
}
void delete_line(const char* file_name,int n)//verdiyimiz dosyada verdiyimiz satiri siliyor
{
    ifstream is(file_name);

    ofstream ofs;
    ofs.open("../temp.txt", ofstream::out);

    char c;
    int line_no = 1;
    while (is.get(c))
    {
        if (c == '\n')
            line_no++;

        if (line_no != n)
            ofs << c;
    }

    ofs.close();
    is.close();

    remove(file_name);//var olan dosyani siliyor
    rename("../temp.txt", file_name);//yeri kurdugumuz dosyanin ismini eski dosya ismiyle degistiriyoruz
}
void products() //urunler icin yapilan islemler
{
    int secim;
    cout << "\n1.Urun Ekle\n";
    cout << "2.Urun Listele\n";
    cout << "3.Urun Sil\n";
    cout << "4.Urun Bul\n";
    cout << "Secim: "; cin >> secim;
    if (secim == 1) {
        ofstream myfile;
        myfile.open("../urunler.txt", std::ios_base::app);
        int urunNo;
        string urunAdi;
        string birim;
        string birimfiyati;
        string markasi;
        cin.ignore();
        cout << "Urun Adi: "; getline(cin, urunAdi);
        cout << "Birim: "; getline(cin, birim);
        cout << "Birim Fiyati: "; getline(cin, birimfiyati);
        cout << "Markasi: "; getline(cin, markasi);

        //---------------------------------------------Generate random unique number
        int counter;
        ifstream forCounter;
        forCounter.open("../counterforproducts.txt");//urunler icin UrunNo nun tekrarlanmasi icin en son kullanilan UrunNo`yu dosyada tuttum.
        string line;
        getline(forCounter, line);
        counter = line == "" ? 0 : stoi(line);
        counter++;
        urunNo = counter;
        //----------------------------------------------

        //----------------------------------------------Paste in file
        myfile << "UrunNo: " << urunNo << "\n";
        myfile << "Urun Adi: " << urunAdi << "\n";
        myfile << "Urun Birimi: " << birim << "\n";
        myfile << "Urun Birim Fiyati: " << birimfiyati << "\n";
        myfile << "Urun Markasi: " << markasi << "\n";
        myfile << "---------------------\n";
        //----------------------------------------------

        //----------------------------------------------Paste new next unique number
        ofstream oforCounter;
        oforCounter.open("../counterforproducts.txt");
        oforCounter << counter;
        //----------------------------------------------

        //----------------------------------------------Close
        oforCounter.close();
        forCounter.close();
        myfile.close();
        //----------------------------------------------
    }
    else if (secim == 2) {
        ifstream myfile;
        myfile.open("../urunler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else if (secim == 3) {
        ifstream myfile;
        myfile.open("../urunler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
        string urunNo;
        cin.ignore();
        cout << "Hangi urun silinecek: "; getline(cin, urunNo);
        string searchLine = "UrunNo: " + urunNo;
        ifstream deletedFile;
        deletedFile.open("../urunler.txt");
        string line2;
        int sayac = 1;
        while (getline(deletedFile, line2))
        {
            if (searchLine != line2)sayac++;//gereken satir bulmak icin esit olmadigi surecte sayaci birer artiriyoruz
            else if (searchLine == line2)break;
        }
        deletedFile.close();
        sayac = sayac + 5;
        for (int i = 0; i < 6; i++) {
            delete_line("../urunler.txt",sayac);
            sayac--;
        }
    }
    else if (secim == 4) {
        string urunNo;
        cin.ignore();
        cout << "Urun No: "; getline(cin, urunNo);
        ifstream myfile;
        myfile.open("../urunler.txt");
        string line;
        int sayac = 1;
        while (getline(myfile, line))
        {
            if ("UrunNo: " + urunNo == line) {
                break;
            }
            sayac++;
        }
        for (int i = 0; i < 6; i++)//6 adimda ilerletiyor gereken satirdan,cunki bir urun alt alta 6 satir bilgi icerir
        {
            showCurrentData("../urunler.txt",sayac);//ve fonskiyonumuz cagiriyoruz
            sayac++;
        }
        myfile.close();
    }
}
void projects()//projelerde uzerinde islemler 
{
    int secim;
    cout << "\n1.Proje Ekle\n";
    cout << "2.Proje Listele\n";
    cout << "3.Proje Sil\n";
    cout << "4.Proje Bul\n";
    cout << "Secim: "; cin >> secim;
    if (secim == 1) {
        ofstream myfile;
        myfile.open("../projeler.txt", std::ios_base::app);
        int projeNo;
        string projeAdi;
        string projeYurutucuFirma;
        string projeSorumlusu;
        string projeKontroloru;
        cin.ignore();
        cout << "Proje Adi: "; getline(cin, projeAdi);
        cout << "Proje Yurutucu Firma: "; getline(cin, projeYurutucuFirma);
        cout << "Proje Sorumlusu: "; getline(cin, projeSorumlusu);
        cout << "Proje Kontroloru: "; getline(cin, projeKontroloru);
        //----------------------------------------------Generate random unique number
        int counter;
        ifstream forCounter;
        forCounter.open("../counterforprojects.txt");
        string line;
        getline(forCounter, line);
        counter = line == "" ? 0 : stoi(line);
        counter++;
        projeNo = counter;
        //----------------------------------------------

        //----------------------------------------------Paste new project
        myfile << "ProjeNo: " << projeNo << "\n";
        myfile << "Proje Adi: " << projeAdi << "\n";
        myfile << "Proje Yurutucu Firma: " << projeYurutucuFirma << "\n";
        myfile << "Proje Sorumlusu: " << projeSorumlusu << "\n";
        myfile << "Proje Kontroloru: " << projeKontroloru << "\n";
        myfile << "---------------------\n";
        //----------------------------------------------

        //----------------------------------------------Paste new project number
        ofstream oforCounter;
        oforCounter.open("../counterforprojects.txt");
        oforCounter << counter;
        //----------------------------------------------

        oforCounter.close();
        forCounter.close();
        myfile.close();
    }
    else if (secim == 2) {
        ifstream myfile;
        myfile.open("../projeler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else if (secim == 3) {
        ifstream myfile;
        myfile.open("../projeler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
        string urunNo;
        cin.ignore();
        cout << "Hangi proje silinecek: "; getline(cin, urunNo);
        ifstream control;
        control.open("../hakedisler.txt");

        string searchLine = "ProjeNo: " + urunNo;
        ifstream deletedFile;
        deletedFile.open("../projeler.txt");
        string line2;
        int sayac = 1;
        while (getline(deletedFile, line2))
        {
            if (searchLine != line2)sayac++;
            else if (searchLine == line2)break;
        }
        deletedFile.close();
        sayac = sayac + 5;
        for (int i = 0; i < 6; i++) {
            delete_line("../projeler.txt", sayac);
            sayac--;
        }
    }
    else if (secim == 4) {
        string urunNo;
        cin.ignore();
        cout << "Proje No: "; getline(cin, urunNo);
        ifstream myfile;
        myfile.open("../projeler.txt");
        string line;
        int sayac = 1;
        while (getline(myfile, line))
        {
            if ("ProjeNo: " + urunNo == line) {
                break;
            }
            sayac++;
        }
        for (int i = 0; i < 6; i++)
        {
            showCurrentData("../projeler.txt", sayac);
            sayac++;
        }
        myfile.close();
    }
}
void hakedisurunler( int lineOfproject);
void raporla() {
    cout << "Raporla" << endl;
}
void hakedis()//hakedis uzerinde degisiklik 
{
    int secim;
    cout << "\n1.Hakedis Ekle\n";
    cout << "2.Hakedis Listele\n";
    cout << "3.Hakedis Urunler Menusu\n";
    cout << "Secim: "; cin >> secim;
    if (secim == 1) {
        ofstream myfile;
        myfile.open("../hakedisler.txt", std::ios_base::app);
        string projeNo;
        string hakedisDonemi;
        string urunNo;
        string urunAdet;
        string urunlerVeAdetler;
        string projeYurutucuFirma;
        string projeSorumlusu;
        string projeKontroloru;
        cin.ignore();
        cout << "ProjeNo: "; getline(cin, projeNo);
        ifstream oku;
        oku.open("../projeler.txt");
        string geciciLine;
        bool isAviable=false;
        //----------------------------------------------Proje kontrolu
        while (getline(oku, geciciLine)) {
            if ("ProjeNo: " + projeNo == geciciLine)isAviable=true;
        }
        if (isAviable == false) {
            cout << "Boyle bir proje yok!\n";
        }
        //----------------------------------------------

        else {
            cout << "Hakedis donemi: "; cin >> hakedisDonemi;
            cout << "UrunNo: "; cin >> urunNo;
            ifstream urun;
            urun.open("../urunler.txt");
            string geciciLine2;
            bool isAviable2 = false;
            //----------------------------------------------Urun kontrolu
            while (getline(urun, geciciLine2)) {
                if ("UrunNo: " + urunNo == geciciLine2)isAviable2 = true;
            }
            if (isAviable2 == false) {
                cout << "Boyle bir urun yok!\n";
                return;
            }
            else {
                cout << "Adet: "; cin >> urunAdet;
                urunlerVeAdetler += urunNo + " " + urunAdet + ",";
                system("CLS");
            }
            //----------------------------------------------


            bool isAddProduct = true;
            while (isAddProduct) {
                string secim;
                cout << "1.Urun eklemek\n" << "2.Urun eklemeden cikis etmek\n" << "Secim: "; cin >> secim;
                if (secim == "1") {
                    isAddProduct = true;
                    ifstream urun2;
                    urun2.open("../urunler.txt");
                    string geciciLine3;
                    bool isAviable3 = false;
                    cout << "UrunNo: "; cin >> urunNo;
                    //----------------------------------------------Urun kontrolu
                    while (getline(urun2, geciciLine3)) {
                        if ("UrunNo: " + urunNo == geciciLine3)isAviable3 = true;
                    }
                    if (isAviable3 == false) {
                        cout << "Boyle bir urun yok!\n";
                        cout << "Once giris ettiginiz urunler projede hakkedisde kullanilan urunlere eklenmistir!\n";
                        break;
                    }
                    else {
                        cout << "Adet: "; cin >> urunAdet;
                        urunlerVeAdetler += urunNo + " " + urunAdet + ",";
                        system("CLS");
                    }
                    //----------------------------------------------
                }
                else {
                    isAddProduct = false;
                    break;
                }
                
            }

            myfile << "ProjeNo: "<<projeNo + "\n";

            myfile << "Hakedis donemi: "<<hakedisDonemi + "\n";

            size_t pos = 0;
            string grab = ",";
            string token;
            while ((pos = urunlerVeAdetler.find(grab)) != string::npos) {
                token = urunlerVeAdetler.substr(0, pos);
                myfile << "Urun(adet): " << token + "\n";
                urunlerVeAdetler.erase(0, pos + grab.length());
            }

            myfile << "---------------------\n";
            
        }
        myfile.close();
    }
    else if (secim == 2) {
        ifstream myfile;
        myfile.open("../hakedisler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
    }
    else if (secim == 3) {
        ifstream myfile;
        myfile.open("../hakedisler.txt");
        string line;
        while (getline(myfile, line))
        {
            cout << line << endl;
        }
        myfile.close();
        string projeNo;
        bool isprojeAviable=false;
        cin.ignore();
        cout << "Hangi Hakkedis icin urun guncellemesi yapilacak?: "; getline(cin, projeNo);
        ifstream myfile1;
        myfile1.open("../hakedisler.txt");
        string line1;
        int sayac = 1;
        while (getline(myfile1, line1))
        {
            if ("ProjeNo: " + projeNo == line1)
            {
                isprojeAviable = true;
                break;
            }
            sayac++;
        }
        myfile1.close();
        if (isprojeAviable) {
            hakedisurunler(sayac);
        }
        else cout << "Hakedis bulunamadi\n";
    }
}
void hakedisurunler(int lineOfproject)//hakedis urunleri uzerinde islemleri
{
    lineOfproject++;
    int secim;
    cout << "\n1.Urun Ekle\n";
    cout << "2.Urun Listele\n";
    cout << "3.Urun Bul\n";
    cout << "4.Urun Adedi Guncelle\n";
    cout << "Secim: "; cin >> secim;
    if (secim == 1) {
        ifstream readfile;
        ofstream writefile;
        writefile.open("../example.txt");
        readfile.open("../hakedisler.txt");
        string line;
        int count = 1;
        bool isAddProduct = true;
        while (getline(readfile, line))
        {
            writefile << line << endl;
            if (lineOfproject == count) {
                while (isAddProduct) {
                    string secim;
                    cin.ignore();
                    cout << "1.Urun eklemek\n" << "2.Urun eklemeden cikis etmek\n" << "Secim: "; getline(cin, secim);
                    if (secim == "1") {
                        string urunNo;
                        int urunAdet;
                        isAddProduct = true;
                        ifstream urun2;
                        urun2.open("../urunler.txt");
                        string geciciLine3;
                        bool isAviable3 = false;
                        cout << "UrunNo: "; getline(cin, urunNo);
                        while (getline(urun2, geciciLine3)) {
                            if ("UrunNo: " + urunNo == geciciLine3)isAviable3 = true;
                        }
                        if (isAviable3 == false) {
                            cout << "Boyle bir urun yok!\n";
                            readfile.close();
                            writefile.close();
                            remove("../example.txt");
                            return;
                        }
                        else {
                            cout << "Adet: "; cin >> urunAdet;
                            writefile << "Urun(adet): " << urunNo << " " << urunAdet << endl;
                        }

                    }
                    else if (secim == "2") {
                        isAddProduct = false;
                        break;
                    }

                }
            }
            count++;
        }
        readfile.close();
        writefile.close();
        remove("../hakedisler.txt");
        rename("../example.txt", "../hakedisler.txt");

    }
    else if (secim == 2) {
        lineOfproject++;
        ifstream readfile;
        readfile.open("../hakedisler.txt");
        string line;
        int counter = 1;
        cout << endl;
        while (getline(readfile, line)) {
            if (counter== lineOfproject) {
                if (line != "---------------------") {
                    size_t pos = 0;
                    string grab = " ";
                    string token;
                    int sayac = 1;
                    while ((pos = line.find(grab)) != string::npos) {
                        token = line.substr(0, pos);
                        if (sayac % 2 == 0) {
                            ifstream myfile;
                            myfile.open("../urunler.txt");
                            string line;
                            int hesap = 1;
                            while (getline(myfile, line))
                            {
                                if ("UrunNo: " + token == line)break;
                                hesap++;
                            }
                            for (int i = 0; i < 5; i++)
                            {
                                showCurrentData("../urunler.txt", hesap);
                                hesap++;
                            }
                            cout << endl;
                            myfile.close();
                        }
                        line.erase(0, pos + grab.length());
                        sayac++;
                    }
                    //cout << line << endl;
                    lineOfproject++;
                }
            }
            counter++;
        }
    }
    else if (secim == 3) {
       
    }
    else if (secim == 4) {
        
    }
}
int main() {
    for (;;) {
        int secim;//menu secimi
        cout << "Ana Menudesiniz\n" << "1.Urunler Menusu\n" << "2.Projeler Menusu\n"<<"3.Hakedis Menusu\n"<<"4.Raporla\n"<< "5.Cikis\n" << "Secim: "; cin >> secim;
        switch (secim)
        {
        case 1:
            products();//urunler menusune gecit
            break;
        case 2:
            projects();//projeler menusune gecit
            break;
        case 3:
            hakedis();//hakkedis menusune gecit
            break;
		case 4:
			raporla();//rapolar
			break;
        case 5:
            return 0;//cikis
        default:
            break;
        }
        system("PAUSE");
        system("CLS");//ekrani temizler
    }
    return 0;
}