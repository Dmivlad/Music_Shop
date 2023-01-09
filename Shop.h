
#ifndef MUSIC_SHOP_SHOP_H
#define MUSIC_SHOP_SHOP_H

class Shop //Class of Products in the shop
{
  int NumbOfProd; //Number of product
  char NameOfProd[50]; //Name of product
  int PriceOfProd; //Price of product
public:
    void Show_Prod() const;
    int Get_NumbOfProd() const;
    void ShowAllProd() const;
    void Create_Prod();
    void Edit_Prod();
};

#endif
