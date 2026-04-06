#include <bits/stdc++.h>
using namespace std;

class ModelTrainer
{
public:
    virtual void takeData() = 0;
    virtual void preprocessData() = 0;
    virtual void trainModel() = 0;
    virtual void findAccuracy() = 0;

    void giveTemplate()
    {
        takeData();
        preprocessData();
        trainModel();
        findAccuracy();
    }
};
class DecisionTree : public ModelTrainer
{
public:
    void takeData() override
    {
        cout << "Method to override takeData in DecisionTree" << endl;
    }
    void preprocessData() override
    {
        cout << "Method to override preprocessData in DecisionTree" << endl;
    }
    void trainModel() override
    {
        cout << "Method to override trainModel in DecisionTree" << endl;
    }
    void findAccuracy() override
    {
        cout << "Method to override findAccuracy in DecisionTree" << endl;
    }
};
class NeuralNetwork : public ModelTrainer
{
public:
    void takeData() override
    {
        cout << "Method to override takeData in NeuralNetwork" << endl;
    }
    void preprocessData() override
    {
        cout << "Method to override preprocessData in NeuralNetwork" << endl;
    }
    void trainModel() override
    {
        cout << "Method to override trainModel in NeuralNetwork" << endl;
    }
    void findAccuracy() override
    {
        cout << "Method to override findAccuracy in NeuralNetwork" << endl;
    }
};

int main()
{

    // client;
    ModelTrainer *mt = new NeuralNetwork();
    mt->giveTemplate();
    return 0;
}