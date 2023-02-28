#include <iostream>

using namespace std;

class Payment
{
private:
    float cost;

public:
    string currency;
    Payment(bool isCustomer, string a)
    {
        if (isCustomer)
            cost += 0.35;
        else
            cost += 1.25;
        currency = "TL";
        cout << "Constructor " + a << endl;
    };
    Payment(){};
    ~Payment()
    {
        cout << "Deconstructor" << endl;
    };

    void setCost(float cost)
    {
        if (cost > 0)
        {
            this->cost += cost;
        }
        else
        {
            this->cost += 0.99;
        }
    }

    void pay()
    {
        cout << "Payment is done: " << this->cost << " " + currency << endl;
    }
};

int main()
{
    Payment payment(true, "Hello");
    payment.currency = "TL";
    payment.setCost(10.25);
    payment.pay();

    Payment payment2(false, "Hello2");
    payment2.setCost(0);
    payment2.pay();

    return 0;
}