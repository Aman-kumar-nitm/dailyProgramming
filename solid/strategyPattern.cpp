#include <bits/stdc++.h>
using namespace std;

class walkable
{
public:
    virtual void walk() = 0;
};
class simplewalk : public walkable
{
public:
    void walk() override
    {
        cout << "this robot move one leg then other leg one by one" << endl;
    }
};
class nowalk : public walkable
{
public:
    void walk() override
    {
        cout << "this robot has no walking feature" << endl;
    }
};
class talkable
{
public:
    virtual void talk() = 0;
};
class simpletalk : public talkable
{
public:
    void talk() override
    {
        cout << "this robot talk too much hello user" << endl;
    }
};
class notalk : public talkable
{
public:
    void talk() override
    {
        cout << "this robot has no talking feature" << endl;
    }
};
class flyable
{
public:
    virtual void fly() = 0;
};
class simplefly : public flyable
{
public:
    void fly() override
    {
        cout << "this robot fly using wings" << endl;
    }
};
class jetfly : public flyable
{
public:
    void fly() override
    {
        cout << "this robot fly using jet" << endl;
    }
};
class Robot
{
    walkable *w1;
    talkable *t1;
    flyable *f1;

public:
    Robot(walkable *w, talkable *t, flyable *f)
    {
        this->w1 = w;
        this->t1 = t;
        this->f1 = f;
    }
    void walk()
    {
        w1->walk();
    }
    void talk()
    {
        t1->talk();
    }
    void fly()
    {
        f1->fly();
    }
    virtual void projection() = 0;
};

class companionRobot : public Robot
{
public:
    companionRobot(walkable *w, talkable *t, flyable *f) : Robot(w, t, f)
    {
    }
    void projection() override
    {
        cout << "Displaying friendly companion features..." << endl;
    }
};
class manualRobot : public Robot
{
public:
    manualRobot(walkable *w, talkable *t, flyable *f) : Robot(w, t, f)
    {
    }
    void projection() override
    {
        cout << "Displaying friendly manual features..." << endl;
    }
};
int main()
{
    companionRobot *r1 = new companionRobot(
        new nowalk(),
        new simpletalk(),
        new jetfly());
    r1->projection();
    r1->walk();
    r1->talk();
    r1->fly();
    return 0;
}