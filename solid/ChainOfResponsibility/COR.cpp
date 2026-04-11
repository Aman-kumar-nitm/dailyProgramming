#include <bits/stdc++.h>
using namespace std;
class Handler
{
protected:
    Handler *next;

public:
    virtual bool dispense(int amt) = 0;
    void setHandler(Handler *obj)
    {
        this->next = obj;
    }
};
class ThousandDispenser : public Handler
{
public:
    bool dispense(int amt) override
    {
        int total = amt / 1000;
        int rem = amt % 1000;
        bool temp = true;
        if (rem != 0)
        {
            temp = next->dispense(rem);
        }
        if (!temp)
        {
            return false;
        }
        cout << "No of 1000 Notes " << total << endl;
        return true;
    }
};

class HundredDispenser : public Handler
{
public:
    bool dispense(int amt) override
    {
        int total = amt / 100;
        int rem = amt % 100;

        if (rem != 0)
        {
            cout << "Denomination not possible" << endl;
            return false;
        }
        cout << "No of 100 Notes " << total << endl;
        return true;
    }
};

int main()
{
    // Client
    Handler *obj = new ThousandDispenser();
    obj->setHandler(new HundredDispenser());

    obj->dispense(2000);
    obj->dispense(1500);
    obj->dispense(3211);

    return 0;
}