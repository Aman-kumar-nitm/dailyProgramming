#include <bits/stdc++.h>
using namespace std;

class iobserver
{
public:
    virtual void update() = 0;
};

class iobservable
{
public:
    virtual void add(iobserver *obj) = 0;
    virtual void remove(iobserver *obj) = 0;
    virtual void notify() = 0;
};

class concreteobservable : public iobservable
{
    vector<iobserver *> observers;

public:
    void add(iobserver *obj) override
    {
        observers.push_back(obj);
    }

    void remove(iobserver *obj) override
    {
        cout << "removed" << endl;
    }

    void notify() override
    {
        for (auto it : observers)
        {
            it->update();
        }
    }

    void getvalues()
    {
        cout << "New video uploaded: 2 hour 15 min long" << endl;
    }
};

class observer : public iobserver
{
    concreteobservable *obj;

public:
    observer(concreteobservable *t)
    {
        obj = t;
    }

    void update() override
    {
        obj->getvalues();
    }
};

int main()
{
    concreteobservable youtuber;

    vector<observer *> subs;

    for (int i = 0; i < 3; i++)
    {
        observer *m = new observer(&youtuber);
        youtuber.add(m);
        subs.push_back(m);
    }

    youtuber.notify();

    return 0;
}