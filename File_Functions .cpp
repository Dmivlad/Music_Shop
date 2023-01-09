#include <iostream>
#include "File_Functions .h"
#include <fstream>
#include "Shop.h"
#include <windows.h>

using namespace std;

void intro()
{
    cout << "\n\n\n\t  Music Shop";
    cout << "\n\n\t Downloading...";
    Sleep(3000);
    cout << "\n\n\t Almost here...";
    Sleep(2000);
    cout << "\n\n\n\nPress enter to continue...";

    cin.get();
}
void WriteProduct(char *file)
{
    Shop thing;
    ofstream outFile;

    outFile.open(file, ios::binary | ios::app);
    thing.Create_Prod();
    outFile.write(reinterpret_cast<char *>(&thing), sizeof(thing));
    outFile.close();
    cout << "\nPress Enter.";
}//Add the product in the file
void DisplayProduct(char *file, int number)
{
    Shop thing;
    ifstream inFile;
    bool exist_flag = false;

    inFile.open(file, ios::binary);
    if (!inFile)
    {
        cout << "File could not open !! Press any Key...";
        return;
    }

    cout << "\nProduct Details\n";
    while (inFile.read(reinterpret_cast<char *>(&thing), sizeof(thing)))
    {
        if (thing.Get_NumbOfProd() == number)
        {
            exist_flag = true;
            thing.Show_Prod();
        }
    }
    inFile.close();

    if (!exist_flag)
        cout << "\nProduct Number does not exist";
    cout << "\nPress Enter.";
} //Display the special product in the file
void EditProduct(char *file, int number)
{
    Shop thing;
    fstream InOutFile;
    bool exist_flag = false;

    InOutFile.open(file,ios::binary | ios::in | ios::out);
    if (!InOutFile)
    {
        cout << "File could not open !! Press any Key...";
        return;
    }
    while (!InOutFile.eof() && !exist_flag)
    {
        InOutFile.read(reinterpret_cast<char *>(&thing),sizeof(thing));
        if (thing.Get_NumbOfProd() == number)
        {
            thing.Show_Prod();
            cout << "\n\nEnter the New Details of account" << endl;
            thing.Edit_Prod();
            int PosOfProd = (-1) * static_cast<int>(sizeof(thing));
            InOutFile.seekp(PosOfProd, ios::cur);
            InOutFile.write(reinterpret_cast<char *>(&thing),sizeof(thing));

            cout << "\nProduct is updated " << endl;
            exist_flag = true;
        }
    }
    InOutFile.close();
    if (!exist_flag)
        cout << "\nProduct Number does not exist\n";
    cout << "\nPress Enter.";
} //Edit the special product in the file
void DeleteProduct(char* file, int number)//Delete the special product in the file
{
    ifstream inFile;
    ofstream outFile;
    Shop thing;

    inFile.open(file, ios::binary);
    outFile.open("temp.dat", ios::binary | ios::out);
    if(!inFile)
    {
        cout << "File could not open !! Press any Key...";
        return;
    }

    inFile.seekg(0, ios::beg);
    while (inFile.read(reinterpret_cast<char *>(&thing), sizeof(thing)))
    {
        if(thing.Get_NumbOfProd() != number)
        {
            outFile.write(reinterpret_cast<char *>(&thing), sizeof(thing));
        }
    }
    inFile.close();
    outFile.close();
    remove(file);
    rename("temp.dat", file);
    cout << "\n\nProduct deleted... \n";
    cout << "\nPress Enter.";
}
void DisplayAllProd(char *file)
{
    ifstream inFile;
    Shop thing;

    inFile.open(file, ios::binary);
    if (!inFile)
    {
        cout << "File could not open !! Press any Key...";
        return;
    }

    cout << "\n\n\tPRODUCTS HOLDER LIST\n\n";
    cout << "====================================================\n";
    cout << "Number      NAME               Price $\n";
    cout << "====================================================\n";
    while(inFile.read(reinterpret_cast<char *>(&thing), sizeof (thing)))
    {
        thing.ShowAllProd();
    }
    inFile.close();
    cout << "\nPress Enter.";
} //Display all products in File

