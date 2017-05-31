#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    unsigned long long int unos;
    int brojArtikla = 0;
    int izbor;
    int MAX = 50;
    unsigned long long int barkod[MAX];
    float cijena[MAX];
    string artikli[MAX];
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;



    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos novog artikla" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema bar kodu artikla" << endl;
        cout << "4. Pretraga prema nazivu artikla" << endl;
        cout << "5. Izmjena podataka prema bar kodu" << endl;
        cout << "6. Ispisi sortirano prema nazivu artikla" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout <<"Unesite bar kod artikla :" ;
            cin >> barkod[brojArtikla];
            cout << "Unesite naziv artikla: ";
            cin.ignore();
            getline(cin, artikli[brojArtikla]);
            cout <<"Unesite cijenu s PDV-om:";
            cin>> cijena[brojArtikla];


            datotekaUpisivanje.open("artikli.txt",ios::app);
            datotekaUpisivanje<<barkod[brojArtikla]<<endl;
            datotekaUpisivanje<<artikli[brojArtikla]<<endl;
            datotekaUpisivanje<<cijena[brojArtikla]<<endl;
            datotekaUpisivanje.close();

            brojArtikla++;



        }
        else if( izbor == 2 )
        {
            cout << "bar kod" << "\t" << "naziv artikla" << "\t" << "cijena" << endl;
            for( int i = 0; i < brojArtikla; i++ )
            {
                cout << artikli[i] << "\t";
                cout << "Cijena:"<<cijena[i]<<"\t";
                cout <<"Bar kod:"<<barkod[i]<<endl;
            }
        }
        else if( izbor == 3 )
        {
            cout <<"Unesite bar kod koji zelite pretraziti:";
            cin>> unos;
            bool pronaden=false;
            for( int i = 0; i < brojArtikla; i++ )
            {
                if(unos ==barkod[i])
                {
                    cout << artikli[i] << "\t";
                    cout << "Cijena:"<<cijena[i]<<"\t";
                    cout <<"Bar kod:"<<barkod[i]<<endl;
                    pronaden= true;
                    break;
                }
                if(pronaden=false)
                {
                    cout <<"Artikl nije pronaden.";
                }
            }
        }
        else if( izbor == 4 )
        {
            cout <<"Unesite artikl koji zelite pronaci :";
            string imeartikla;
            cin.ignore();
            getline(cin, imeartikla);
            bool pronadjen=false;
            for( int i = 0; i < brojArtikla; i++ )
            {
              if(imeartikla == artikli[i])
              {
                cout <<"Artikl: "<< artikli[i] << "\t";
                cout << "Cijena: "<<cijena[i]<<"\t";
                cout <<"Bar kod: "<<barkod[i]<<endl;
                pronadjen = true;
              }
              if(pronadjen=false)
              {
                cout<<"Artikl nije pronadjen.";
              }
            }

        }
        else if( izbor == 5 )
        {
            cout <<"Unesite bar kod koji zelite promjeniti:";
            cin>> unos;
            int novacijena;
            bool pronaden=false;
            for( int i = 0; i < brojArtikla; i++ )
            {
                if(unos ==barkod[i])
                {
                    cout << artikli[i] << "\t";
                    cout << "Cijena:"<<cijena[i]<<"\t";
                    cout <<"Bar kod:"<<barkod[i]<<endl;
                    pronaden= true;
                    if(pronaden=true)
                    {
                        cout<<"Unesite novo cijenu artikla:";
                        cin >>  novacijena;
                        cijena[i]=novacijena;
                    }
                    break;
                }
                if(pronaden=false)
                {
                    cout <<"Artikl nije pronaden.";
                }
            }
        }
        else if( izbor == 6 )
        {
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
