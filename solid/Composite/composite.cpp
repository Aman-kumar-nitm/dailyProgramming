#include <bits/stdc++.h>
using namespace std;

class FileSystem
{
public:
    virtual void openAll() = 0;
};
class Folder : public FileSystem
{
public:
    string name;
    vector<FileSystem *> children;
    void openAll()
    {
        cout << this->name << endl;
        for (auto it : children)
        {
            it->openAll();
        }
    }
};
class File : public FileSystem
{
public:
    string name;
    void openAll()
    {
        cout << this->name << endl;
    }
};

int main()
{
    Folder *root = new Folder();
    root->name = "root";
    for (int i = 0; i < 5; i++)
    {
        Folder *newFolder = new Folder();
        newFolder->name = "Folder" + to_string(i);
        for (int j = 0; j <= i; j++)
        {
            File *newFile = new File();
            newFile->name = "File" + to_string(i * 10 + j);
            newFolder->children.push_back(newFile);
        }
        root->children.push_back(newFolder);
    }

    root->openAll();

    return 0;
}