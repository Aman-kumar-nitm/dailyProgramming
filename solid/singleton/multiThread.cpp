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
    static mutex mtx;

public:
    // make this function static so that it will not be more associated with each obj instead we can directly call it without creating an instance of obj
    static createSingleton *createObj()
    {

        if (createdObj == nullptr)
        { // probably two thread can come here one will wait when mtx will free it will create obj again thats problem right
            lock_guard<mutex> lock(mtx);
            if (createdObj == nullptr)
            {
                createdObj = new createSingleton();
            }
        }

        return createdObj;
    }
};
// in c++ initialization of static obj is done outside the class
createSingleton *createSingleton::createdObj = nullptr;
mutex createSingleton::mtx;
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