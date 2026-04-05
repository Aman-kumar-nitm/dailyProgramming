#include <bits/stdc++.h>
using namespace std;
class Command
{
public:
    virtual void execute() = 0;
};
class Light
{
public:
    void turnOn()
    {
        cout << "Light ON\n";
    }

    void turnOff()
    {
        cout << "Light OFF\n";
    }
};
class LightOnCommand : public Command
{
private:
    Light *light;

public:
    LightOnCommand(Light *l)
    {
        light = l;
    }

    void execute() override
    {
        light->turnOn();
    }
};
class LightOffCommand : public Command
{
private:
    Light *light;

public:
    LightOffCommand(Light *l)
    {
        light = l;
    }

    void execute() override
    {
        light->turnOff();
    }
};
class RemoteControl
{
private:
    Command *command;

public:
    void setCommand(Command *c)
    {
        command = c;
    }

    void pressButton()
    {
        command->execute();
    }
};
int main()
{

    Light light;

    LightOnCommand onCommand(&light);
    LightOffCommand offCommand(&light);

    RemoteControl remote;

    remote.setCommand(&onCommand);
    remote.pressButton();

    remote.setCommand(&offCommand);
    remote.pressButton();
    return 0;
}