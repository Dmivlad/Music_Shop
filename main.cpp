#include <iostream>
#include "Shop.h"
#include "File_Functions .h"
//#include

using namespace std;

char file[15] = "products.dat";

int main()
{
    int number;
    char option;

    intro();
    do
    {
        system("cls");
        cout << "\n\n\n\tMAIN MENU";
        cout << "\n\n\t1. New Product";
        cout << "\n\n\t2. Display Product";
        cout << "\n\n\t3. Edit Product";
        cout << "\n\n\t4. Delete Product";
        cout << "\n\n\t5. Display All Products";
        cout << "\n\n\t6. Exit";
        cout << "\n\n\tSelect Your Option (1-6) ";
        cin >> option;
        system("cls");
        switch (option)
        {
            case '1':
                WriteProduct(file);
                break;
            case '2':
                cout << "\n\n\tWrite the number of the product you want to see: "; cin >> number;
                DisplayProduct(file, number);
                break;
            case '3':
                cout << "\n\n\tWrite the number of the product you want to edit: "; cin >> number;
                EditProduct(file, number);
                break;
            case '4':
                cout << "\n\n\tWrite the number of the product you want to delete: "; cin >> number;
                DeleteProduct(file,number);
                break;
            case '5':
                DisplayAllProd(file);
                break;
            case '6':
                cout << "\n\n\tThanks for visit, see you next time!";
                break;
            default:
                cout << "Wrong option, try again!";
                main();
        }
        cin.ignore();
        cin.get();
    }
    while(option != '6');
    return 0;
}