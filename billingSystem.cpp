#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
  int productCode;
  float productPrice;
  float productDiscount;
  string productName;

public:
  void menu();
  void administrator();
  void buyer();
  void addProduct();
  void edit();
  void removeProduct();
  void list();
  void receipt();
};

void shopping ::menu()
{
m:
  int choice;
  string email;
  string password;

  cout << "\t\t\t\t______________________________________\n";
  cout << "\t\t\t\t                                      \n";
  cout << "\t\t\t\t          Supermarket Main Menu       \n";
  cout << "\t\t\t\t                                      \n";
  cout << "\t\t\t\t______________________________________\n";
  cout << "\t\t\t\t                                      \n";
  cout << "\t\t\t\t|  1) Administrator   |\n";
  cout << "\t\t\t\t|                     |\n";
  cout << "\t\t\t\t|  2) Buyer           |\n";
  cout << "\t\t\t\t|                     |\n";
  cout << "\t\t\t\t|  3) Exit            |\n";
  cout << "\t\t\t\t|                     |\n";
  cout << "\n\t\t\t Please select!";
  cin >> choice;

  switch (choice)
  {
  case 1:
    cout << "\n\t\t\t\t Please Select Login\n";

    cout << "\n\t\t\t\t Enter email : ";
    cin >> email;

    cout << "\n\t\t\t\t Enter password : ";
    cin >> password;

    if (email == "12" && password == "12")
    {
      administrator();
    }
    else
    {
      cout << "\n\t\t\t\tInvalid user or password";
    }
    break;

  case 2:
  {
    buyer();
  }

  case 3:
  {
    exit(0);
  }

  default:
  {
    cout << "\n\t\t\t\tPlease Select the correct option : ";
  }
  }
  goto m;
}

void shopping::administrator()
{
m:
  int choice;
  cout << "\n\n\n\t\t\t\t Administrator Panel \n";
  cout << "\n\t\t\t\t| 1. Add the Product      |";
  cout << "\n\t\t\t\t|                         |";
  cout << "\n\t\t\t\t| 2. Modify the Product   |";
  cout << "\n\t\t\t\t|                         |";
  cout << "\n\t\t\t\t| 3. Delete the Product   |";
  cout << "\n\t\t\t\t|                         |";
  cout << "\n\t\t\t\t| 4. Back to main menu    |";
  cout << "\n\t\t\t\t|                         |";

  cout << "\n\n\t\t\t\t Please enter your choice : ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    addProduct();
    break;

  case 2:
    edit();
    break;

  case 3:
    removeProduct();
    break;

  case 4:
    menu();
    break;

  default:
    cout << "\n\t\t\t\tInvalid choice" << endl;
  }
  goto m;
}

void shopping::buyer()
{
m:
  int choice;

  cout << "\t\t\t\t      Buyer         \n";
  cout << "\t\t\t\t--------------------\n";

  cout << "\t\t\t\t  1. Buy Product   \n";
  cout << "                         \n";
  cout << "\t\t\t\t  2. Go Back       \n";
  cout << "                       \n\n";

  cout << "\t\t\t\t Enter your choice : ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    receipt();
    break;

  case 2:
    menu();

  default:
    cout << "\n\t\t\t\tInvalid choice";
  }

  goto m;
}

void shopping ::addProduct()
{
m:
  fstream data;
  int code;
  int token = 0;
  float price;
  float discount;
  string name;

  cout << "\n\n\t\t\t\t Add a New Product"
       << endl;
  cout << "\n\t\t\t\t ENTER Product code of the product: ";
  cin >> productCode;

  cout << "\n\t\t\t\t ENTER the Name of the product : ";
  cin >> productName;

  cout << "\n\t\t\t\t ENTER the price of the product : ";
  cin >> productPrice;

  cout << "\n\t\t\t\t ENTER the discount on product : ";
  cin >> productDiscount;

  data.open("database.txt", ios::in);

  if (!data)
  {
    data.open("database.txt", ios::app | ios::out);
    data << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
    data.close();
  }
  else
  {
    data >> code >> name >> price >> discount;

    while (!data.eof())
    {
      if (code == productCode)
      {
        token++;
      }
      data >> code >> name >> price >> discount;
    }
    data.close();

    if (token == 1)
      goto m;
    else
    {
      data.open("database.txt", ios::app | ios::out);
      data << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
      data.close();
    }
  }
  cout << "\n\t\t\t\t Record inserted!";
}

void shopping ::edit()
{
  fstream data, tempData;
  int productKey;
  int token = 0;
  int code;
  float price;
  float discount;
  string name;

  cout << "\n\t\t\t\tModify the record";
  cout << "\n\t\t\t\tENTER Product code : ";
  cin >> productKey;

  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "\n\nFile doesn't exist! ";
  }
  else
  {

    tempData.open("database1.txt", ios::app | ios::out);

    data >> productCode >> productName >> productPrice >> productDiscount;
    while (!data.eof())
    {
      if (productKey == productCode)
      {
        cout << "\n\t\t\t\t ENTER new code for the product : ";
        cin >> code;

        cout << "\n\t\t\t\t ENTER the name of the product : ";
        cin >> name;

        cout << "\n\t\t\t\t ENTER the price : ";
        cin >> price;

        cout << "\n\t\t\t\t ENTER the Discount : ";
        cin >> discount;

        tempData << " " << code << " " << name << " " << price << " " << discount << "\n";
        cout << "\n\n\t\t\t\t  Record Edited" << endl;
        token++;
      }
      else
      {
        tempData << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
      }
      data >> productCode >> productName >> productPrice >> productDiscount;
    }
    data.close();
    tempData.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0)
    {
      cout << "\n\n\t\t\t\t Sorry, Record not found";
    }
  }
}
void shopping::removeProduct()
{

  fstream data, data1;
  int productKey;
  int token = 0;
  cout << "\n\t\t\t\t Delete the product";

  cout << "\n\n\t\t\t\t Enter the product code : ";
  cin >> productKey;
  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "File doesnt exist";
  }

  else
  {
    data1.open("database1.txt", ios::app | ios::out);
    data >> productCode >> productName >> productPrice >> productDiscount;
    while (!data.eof())
    {
      if (productCode == productKey)
      {
        cout << "\n\n\t\t\t\t Product deleted Successfully";
        token++;
      }
      else
      {
        data1 << " " << productCode << " " << productName << " " << productPrice << " " << productDiscount << "\n";
      }
      data >> productCode >> productName >> productPrice >> productDiscount;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");

    if (token == 0)
    {
      cout << "\n\n\t\t\t\t Record not found";
    }
  }
}

void shopping::list()
{
  fstream data;
  data.open("database.txt", ios::in);

  cout << " \n\t\t\t\tProduct code\t\tProduct Name \t\tPrice\t\tDiscount\n\n";

  data >> productCode >> productName >> productPrice >> productDiscount;
  while (!data.eof())
  {
    cout << "\t\t\t\t" << productCode << "\t\t\t" << productName << "\t\t\t" << productPrice << "\t\t" << productDiscount << endl;
    data >> productCode >> productName >> productPrice >> productDiscount;
  }
  data.close();
}

void shopping::receipt()
{
  system("cls");
  fstream data;

  int codes[100], quantity[100];
  char choice;
  int index = 0;
  float amount = 0;
  float discount = 0;
  float total = 0;
  cout << "\n\n\t\t\t\t RECIEPT";
  data.open("database.txt", ios::in);
  if (!data)
  {
    cout << "\n\n\t\t\t\t Empty Database";
  }
  else
  {
    data.close();
    list();
    cout << "\t\t\t\t           _______________________________ " << endl;
    cout << "\t\t\t\t           |    Please Place the order     |" << endl;
    cout << "\t\t\t\t           |_______________________________|" << endl;
    do
    {
    m:
      cout << "\t\t\t\t Enter the product code : ";
      cin >> codes[index];
      cout << "\t\t\t\t Enter the poduct quantity : ";
      cin >> quantity[index];
      for (int i = 0; i < index; i++)
      {
        if (codes[index] == codes[i])
        {
          cout << "\n\n\t\t\t\tDuplicate Product Code. Please try again!\n";
          goto m;
        }
      }
      index++;
      cout << "\n\n\t\t\t\t Want to buy another product? Press y for yes and n for no : ";
      cin >> choice;
    } while (choice == 'y');

    system("cls");

    cout << "\t\t\t\t----------------- RECIEPT -----------------" << endl;
    // cout << "\nProduct Num.\tProduct Name\tQuantity \tPrice \tAmount \tAmount with discount\n";
     cout << "\n\t\t\t\tSr. No.\t\tProduct Name \t\tQuantity \t\tPrice \t\t Amount  \t\tAmount with Discount " << endl;

    for (int i = 0; i < index; i++)
    {
      data.open("database.txt", ios::in);
      data >> productCode >> productName >> productPrice >> discount;
      while (!data.eof())
      {
        if (productCode == codes[i])
        {
          amount = productPrice * quantity[i];
          discount = amount - (amount * discount / 100);
          total = total + discount;
          cout << "\n\t\t\t\t"
                << i + 1 << "\t\t\t" << productName << "\t\t\t" << quantity[i] << "\t\t\t" << productPrice << "\t\t\t" << amount <<  "\t\t\t" << discount;
        }
        data >> productCode >> productName >> productPrice >> discount;
      }
      data.close();
    }
    cout << "\n\t\t\t\t----------------------------------------";
    cout << "\n\t\t\t\t Total Amount : " << total;
  }
}

int main()
{
  shopping s;
  s.menu();
}
