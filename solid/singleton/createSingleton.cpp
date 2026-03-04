#include <bits/stdc++.h>
using namespace std;
// our goal is that no two or more than that instance can be created for our singleton class
class createSingleton
{
    // first thing put constructor into private so that no more new createSingleton exist
private:
    createSingleton()
    {
        cout << "new object creation is being done" << endl;
    }
    static createSingleton *createdObj;

public:
    // make this function static so that it will not be more associated with each obj instead we can directly call it without creating an instance of obj
    static createSingleton *createObj()
    {
        if (createdObj)
        {
            return createdObj;
        }
        createdObj = new createSingleton();
        return createdObj;
    }
};
// in c++ initialization of static obj is done outside the class
createSingleton *createSingleton::createdObj = nullptr;
int main()
{
    // calling static function since we dont need obj to call it
    createSingleton *obj1 = createSingleton::createObj();
    createSingleton *obj2 = createSingleton::createObj();
    if (obj1 == obj2)
    {
        cout << "wooh wooh successfull" << endl;
    }
    return 0;
}