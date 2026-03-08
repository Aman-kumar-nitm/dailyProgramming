#include <bits/stdc++.h>
using namespace std;
class character
{
public:
    virtual string getAbility() = 0;
};
class Mario : public character
{
public:
    string getAbility() override
    {
        return "Mario character with simple ability";
    }
};

class Decorator : public character
{
public:
    character *ch;
    virtual string getAbility() = 0;
};
class heightUp : public Decorator
{
public:
    heightUp(character *obj)
    {
        this->ch = obj;
    }
    string getAbility() override
    {
        string ans = ch->getAbility();
        return ans + "and having power of Height UP";
    }
};
class widthUp : public Decorator
{
public:
    widthUp(character *obj)
    {
        this->ch = obj;
    }
    string getAbility() override
    {
        string ans = ch->getAbility();
        return ans + "and having power of Width UP";
    }
};
class Star : public Decorator
{
public:
    Star(character *obj)
    {
        this->ch = obj;
    }
    string getAbility() override
    {
        string ans = ch->getAbility();
        return ans + "and having power of Star";
    }
};
int main()
{

    // create three mario one with simple power one with height up only one with all power
    character *obj = new Mario();
    cout << obj->getAbility() << endl;
    ;
    obj = new heightUp(new Mario());
    cout << obj->getAbility() << endl;
    obj = new heightUp(new Star(new widthUp(new Mario())));
    cout << obj->getAbility() << endl;
    return 0;
}