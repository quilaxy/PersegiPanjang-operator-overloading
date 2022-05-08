#include <iostream>
#include <vector>

#include "include/PersegiPanjang.hpp"

using namespace std;

void PrintPP(PersegiPanjang& pp){

    cout << "Center X   : " << pp.GetCenterX() << "        ";
    cout << "Center Y   : " << pp.GetCenterY() << endl;
    cout << "Width      : " << pp.GetWidth() << "        ";
    cout << "Height     : " << pp.GetHeight() << endl;
    cout << "X Min      : " << pp.GetXMin() << "        ";
    cout << "X Max      : " << pp.GetXMax() << endl;
    cout << "Y Min      : " << pp.GetYMin() << "        ";
    cout << "Y Max      : " << pp.GetYMax() << endl;
}

int main(){
    float centerX, centerY;
    int width, height;

    system("CLS||clear");

    cout << "Masukkan Persegi Panjang 1" << endl;

    cout << endl << "Masukkan Titik Tengah X: ";
    cin >> centerX;
    cout << endl << "Masukkan Titik Tengah Y: ";
    cin >> centerY;
    cout << endl << "Masukkan Panjang: ";
    cin >> width;
    cout << endl << "Masukkan Lebar: ";
    cin >> height;

    PersegiPanjang pp1(centerX, centerY, width, height);

    system("CLS||clear");

    cout << "Masukkan Persegi Panjang 2" << endl;

    cout << endl << "Masukkan Titik Tengah X: ";
    cin >> centerX;
    cout << endl << "Masukkan Titik Tengah Y: ";
    cin >> centerY;
    cout << endl << "Masukkan Panjang: ";
    cin >> width;
    cout << endl << "Masukkan Lebar: ";
    cin >> height;

    PersegiPanjang pp2(centerX, centerY, width, height);

    while(1){
        system("CLS||clear");

        cout << "Persegi Panjang 1" << endl;
        PrintPP(pp1);
        cout << endl;
        cout << "Persegi Panjang 2" << endl;
        PrintPP(pp2);

        cout << endl;
        cout << "Menu: " << endl;
        cout << "1. +" << endl;
        cout << "2. -" << endl;
        cout << "3. ==" << endl;
        cout << "4. ++" << endl;
        cout << "5. --" << endl;
        cout << "6. []" << endl;
        cout << "0. Keluar" << endl;
        cout << endl << "Pilih menu : ";

        int input;
        cin >> input;
        cin.ignore();

        switch (input)
        {
        case 1:
        {
            system("CLS||clear");

            if(!(pp1 == pp2)) {
                cout << "Persegi Panjang Tidak Beririsan";
                cin.ignore();
                break;
            }

            PersegiPanjang pp3 = pp1 + pp2;
            
            cout << "Persegi Panjang Baru" << endl;
            PrintPP(pp3);

            cin.ignore();
            break;
        }

        case 2:
        {
            system("CLS||clear");

            if(!(pp1 == pp2)) {
                cout << "Persegi Panjang Tidak Beririsan";
                cin.ignore();
                break;
            }

            PersegiPanjang pp3 = pp1 - pp2;
            
            cout << "Persegi Panjang Baru" << endl;
            PrintPP(pp3);

            cin.ignore();
            break;
        }
        
        case 3:
        {
            system("CLS||clear");
            cout << "Apakah Persegi Panjang Beririsan?" << endl;
            cout << "-> ";
            cout << (pp1 == pp2 ? "Ya" : "Tidak");

            cin.ignore();
            break;
        }

        case 4:
        {
            system("CLS||clear");

            PersegiPanjang pp4 = ++pp1;
            PersegiPanjang pp5 = ++pp2;
            pp1--;
            pp2--;

            cout << "Persegi Panjang Baru" << endl << endl;
            cout << "Persegi Panjang 1" << endl;
            PrintPP(pp4);
            cout << endl;
            cout << "Persegi Panjang 2" << endl;
            PrintPP(pp5);

            cin.ignore();
            break;
        }

        case 5:
        {
            system("CLS||clear");

            PersegiPanjang pp6 = --pp1;
            PersegiPanjang pp7 = --pp2;
            pp1++;
            pp2++;

            cout << "Persegi Panjang Baru" << endl << endl;
            cout << "Persegi Panjang 1" << endl;
            PrintPP(pp6);
            cout << endl;
            cout << "Persegi Panjang 2" << endl;
            PrintPP(pp7);

            cin.ignore();
            break;
        }

        case 6:
        {
            system("CLS||clear");

            cout << "Persegi Panjang 1" << endl;
            cout << "[0] " << pp1[0] << "   ";
            cout << "[1] " << pp1[1] << "   ";
            cout << "[2] " << pp1[2] << "   ";
            cout << "[3] " << pp1[3] << "   ";

            cout << endl << endl;

            cout << "Persegi Panjang 2" << endl;
            cout << "[0] " << pp2[0] << "   ";
            cout << "[1] " << pp2[1] << "   ";
            cout << "[2] " << pp2[2] << "   ";
            cout << "[3] " << pp2[3] << "   ";

            cin.ignore();
            break;
        }

        case 0:
            return 0;
        
        default:
            break;
        }

    }

    return 0;
}