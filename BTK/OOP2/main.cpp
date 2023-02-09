#include <iostream>

using namespace std;

class Payment
{
public:
    float cost;
    string currency;
    Payment(bool isCustomer, string a)
    {
        if (isCustomer)
            cost = 0.35;
        else
            cost = 1.25;
        currency = "TL";
        cout << "Constructor " + a << endl;
    };
    Payment(){};
    ~Payment(){
        cout << "Deconstructor" << endl;
    };
    void pay(float cost)
    {
        this->cost += cost;
        cout << "Payment is done: " << this->cost << " " + currency << endl;
    }
};

int main()
{
    Payment payment(true, "Hello");
    payment.currency = "TL";
    payment.pay(10.25);

    Payment payment2(false, "Hello2");
    payment2.pay(10.25);

    return 0;
}