#include <iostream>
#include "Shop.h"
#include <iomanip>

using namespace std;

void Shop::Create_Prod() //Create the product
{
    cout << " Type the number of the Product: "; cin >> NumbOfProd;
    cin.ignore();
    cout << " Type the name of the Product: "; cin.getline(NameOfProd, 50);
    cout << " Type the cost of the Product: "; cin >> PriceOfProd;
    cin.ignore();
    cout << "Product has been created! ";
}
void Shop::Show_Prod() const //Show special product
{
    cout << "\nNumber of the product: " << NumbOfProd;
    cout << "\nName of the product: " << NameOfProd;
    cout << "\nPrice of the product: " << PriceOfProd << "$";
}
void Shop::Edit_Prod() //Edit the product
{
    cout << " Type new number of the Product: "; cin >> NumbOfProd;
    cin.ignore();
    cout << " Type new name of the Product: "; cin.getline(NameOfProd, 50);
    cout << " Type new cost of the Product: "; cin >> PriceOfProd;
    cin.ignore();
    cout << "Product has been created! ";
}
int Shop::Get_NumbOfProd() const //Give the number of product
{
    return NumbOfProd;
}
void Shop::ShowAllProd() const
{
    cout << NumbOfProd << setw(10) << " " << NameOfProd << setw(15) << " " << PriceOfProd << " $" << endl;
} //Show all products in the shop