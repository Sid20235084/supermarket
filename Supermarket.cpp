#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;


class Bill {
private:
    string Item;
    int Rate, Quantity;
public:
    Bill() : Item(""), Rate(0), Quantity(0) { }

    void setItem(string item) {
        Item = item;
    }

    void setRate(int rate) {
        Rate = rate;
    }

    void setQuant(int quant) {
        Quantity = quant;
    }

    string getItem() {
        return Item;
    }

    int getRate() {
        return Rate;
    }

    int getQuant() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Close" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter item name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter item rate: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter item quantity: ";
            cin >> quant;
            b.setQuant(quant);

            ofstream out("C:/Users/LENOVO/Desktop/OK tested/Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: Unable to open the file!" << endl;
            } else {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuant() << endl << endl;
                cout << "\tItem added successfully." << endl;
            }
            out.close();
            Sleep(3000);
        }

        else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tReturning to the main menu..." << endl;
            Sleep(3000);
        }
    }
}

void printBill() {
    system("cls");
    int count = 0;
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        cout << "\t1. Add to Bill" << endl;
        cout << "\t2. Close Session" << endl;
        cout << "\tEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            int quant;
            cout << "\tEnter item name: ";
            cin >> item;
            cout << "\tEnter quantity: ";
            cin >> quant;

            ifstream in("C:/Users/LENOVO/Desktop/OK tested/Bill.txt");
            ofstream out("C:/Users/LENOVO/Desktop/OK tested/Bill Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;

                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;
                        cout << "\tItem\tRate\tQuantity\tAmount" << endl;
                        cout << "\t" << itemName << "\t" << itemRate << "\t" << quant << "\t\t" << amount << endl;

                        int newQuant = itemQuant - quant;
                        count += amount;

                        out << "\t" << itemName << " : " << itemRate << " : " << newQuant << endl;
                    } else {
                        cout << "\tSorry, insufficient quantity for \"" << item << "\"!" << endl;
                    }
                } else {
                    out << line << endl;
                }
            }

            if (!found) {
                cout << "\tItem not found!" << endl;
            }

            out.close();
            in.close();
            remove("C:/Users/LENOVO/Desktop/OK tested/Bill.txt");
            rename("C:/Users/LENOVO/Desktop/OK tested/Bill Temp.txt", "C:/Users/LENOVO/Desktop/OK tested/Bill.txt");

            Sleep(3000);
        }

        else if (choice == 2) {
            close = true;
            cout << "\tCalculating total bill..." << endl;
            Sleep(3000);
        }
    }

    system("cls");
    cout << endl << endl;
    cout << "\tTotal Bill: " << count << endl << endl;
    cout << "\tThank you for shopping with us!" << endl;
    Sleep(5000);
}

int main() {
    Bill b;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to the Supermarket Billing System" << endl;
        cout << "\t*****************************************" << endl;
        cout << "\t1. Add Item" << endl;
        cout << "\t2. Print Bill" << endl;
        cout << "\t3. Exit" << endl;
        cout << "\tEnter your choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            addItem(b);
        }

        else if (val == 2) {
            printBill();
        }

        else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGoodbye!" << endl;
            Sleep(3000);
        }
    }
}
