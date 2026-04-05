#include <bits/stdc++.h>
using namespace std;

class thirdParty
{
public:
    string weatherAPI()
    {
        return "Acc to your current location weather is ";
    }
};
class provideJSON
{
public:
    virtual void provideJson(string text) = 0;
};
class adaptor : public provideJSON
{
    thirdParty *p;

public:
    adaptor(thirdParty *obj)
    {
        this->p = obj;
    }
    void provideJson(string text) override
    {
        // call third party get xml data convert it to json and print
        string s = p->weatherAPI();

        s += text;
        cout << s << "JSON Format" << endl;
    }
};

int main()
{

    // client;
    thirdParty *obj = new thirdParty;
    provideJSON *newobj = new adaptor(obj);
    newobj->provideJson("India");
    return 0;
}