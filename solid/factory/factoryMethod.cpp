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
class basicBurgerK : public Burger
{
public:
    void prepare() override
    {
        cout << "Basic burger of king prep" << endl;
    }
};
class premiumBurgerK : public Burger
{
public:
    void prepare() override
    {
        cout << "Premium burger of king prep" << endl;
    }
};
class mediumBurgerK : public Burger
{
public:
    void prepare() override
    {
        cout << "medium burger of king prep" << endl;
    }
};
class BurgerFactory
{
public:
    virtual Burger *create(string type) = 0;
};
class singh : public BurgerFactory
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
class king : public BurgerFactory
{
public:
    Burger *create(string type)
    {
        if (type == "basic")
        {
            return new basicBurgerK();
        }
        else if (type == "premium")
        {
            return new premiumBurgerK();
        }
        else if (type == "medium")
        {
            return new mediumBurgerK();
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
    BurgerFactory *b1 = new singh();
    BurgerFactory *b2 = new king();
    // client code
    string type = "premium";
    Burger *obj = b1->create(type);
    obj->prepare();
    Burger *obj2 = b2->create(type);
    obj2->prepare();
    return 0;
}