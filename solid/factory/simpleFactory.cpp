#include <bits/stdc++.h>
using namespace std;
class Burger
{
public:
    virtual void prepare() = 0;
};
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Basic burger prep" << endl;
    }
};
class mediumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "medium burger prep" << endl;
    }
};
class premiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Premium burger prep" << endl;
    }
};
class BurgerFactory
{
public:
    Burger *create(string type)
    {
        if (type == "basic")
        {
            return new BasicBurger();
        }
        else if (type == "premium")
        {
            return new premiumBurger();
        }
        else if (type == "medium")
        {
            return new mediumBurger();
        }
        else
        {
            cout << "not possible burger type" << endl;
            return nullptr;
        }
    }
};
int main()
{
    BurgerFactory b1;
    // client code
    string type = "premium";
    Burger *obj = b1.create(type);
    obj->prepare();
    return 0;
}