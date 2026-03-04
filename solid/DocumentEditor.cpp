// #include <bits/stdc++.h>
// using namespace std;
// // breaks single responsibility as well as open close in render
// //  class TextEditor{
// //      vector<string>document;
// //      public:
// //      void addText(string text){
// //          document.push_back(text);
// //          return;
// //      }
// //      void addImage(string pathfile){
// //          document.push_back(pathfile);
// //          return;
// //      }
// //      void save(){
// //          //perform db operation to save it
// //          return;
// //      }
// //      void render(){
// //          //if text then render text
// //          //if stringpath then using library render it
// //          return;
// //      }
// //  };
// class DocumentEditor
// {
//     Document Doc;
//     Persistance db;

// public:
//     DocumentEditor(Document d1, Persistance p1)
//     {
//         this->Doc = d1;
//         this->db = p1;
//     }
//     void addText(string val)
//     {
//         Doc.addElement(new renderText(val));
//     }
//     void addImage(string val)
//     {
//         Doc.addElement(new renderImage(val))
//     }
//     void saveElement()
//     {
//         P1.save()
//     }
//     void renderElement()
//     {
//         Doc.render();
//     }
// };
// class Document
// {
//     vector<DocumentElement> element;

// public:
//     void addElement(DocumentElement el)
//     {
//         element.push_back(el);
//     }
//     void render()
//     {
//         for (auto a : element)
//         {
//             a.render();
//         }
//     }
// };
// class DocumentElement
// {
// public:
//     virtual void render() const = 0;
//     virtual ~DocumentElement() = default;
// };
// class renderText : DocumentElement
// {
//     string text;

// public:
//     renderText(string val)
//     {
//         this->text = val;
//     }
//     void render() override
//     {
//         cout << "Rendering Text: " << text << endl;
//     }
// };
// class renderImage : DocumentElement
// {
//     string path;

// public:
//     renderImage(string val)
//     {
//         this->path = val;
//     }
//     void render() override
//     {
//         cout << "Rendering Image: " << text << endl;
//     }
// };
// class Persistance
// {
// public:
//     virtual void save() = 0;
// };
// class savetofile : public Persistance
// {
// public:
//     void save() override
//     {
//         cout << "saving to file" << endl;
//     }
// };
// class savetoDB : public Persistance
// {
// public:
//     void save() override
//     {
//         cout << "saving to db" << endl;
//     }
// } int main()
// {
//     Document d1 = new Document();
//     Persistance p1 = new savetofile();
//     DocumentEditor e1 = new DocumentEditor(d1, p1);
//     e1.addText("Helll its me aman");
//     e1.addImage("Image path is https://www.google.com");
//     e1.renderElement();
//     e1.saveElement();
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

/* ================= DocumentElement ================= */

class DocumentElement
{
public:
    virtual void render() const = 0;
    virtual ~DocumentElement() = default;
};

/* ================= Text ================= */

class renderText : public DocumentElement
{
    string text;

public:
    renderText(string val) : text(val) {}

    void render() const override
    {
        cout << "Rendering Text: " << text << endl;
    }
};

/* ================= Image ================= */

class renderImage : public DocumentElement
{
    string path;

public:
    renderImage(string val) : path(val) {}

    void render() const override
    {
        cout << "Rendering Image: " << path << endl;
    }
};

/* ================= Document ================= */

class Document
{
    vector<unique_ptr<DocumentElement>> element;

public:
    void addElement(unique_ptr<DocumentElement> el)
    {
        element.push_back(move(el));
    }

    void render() const
    {
        for (const auto &a : element)
        {
            a->render();
        }
    }
};

/* ================= Persistence ================= */

class Persistance
{
public:
    virtual void save() = 0;
    virtual ~Persistance() = default;
};

class savetofile : public Persistance
{
public:
    void save() override
    {
        cout << "Saving to file" << endl;
    }
};

class savetoDB : public Persistance
{
public:
    void save() override
    {
        cout << "Saving to DB" << endl;
    }
};

/* ================= DocumentEditor ================= */

class DocumentEditor
{
    Document Doc;
    unique_ptr<Persistance> db;

public:
    DocumentEditor(Document d1, unique_ptr<Persistance> p1)
        : Doc(move(d1)), db(move(p1)) {}

    void addText(string val)
    {
        Doc.addElement(make_unique<renderText>(val));
    }

    void addImage(string val)
    {
        Doc.addElement(make_unique<renderImage>(val));
    }

    void saveElement()
    {
        db->save();
    }

    void renderElement()
    {
        Doc.render();
    }
};

/* ================= MAIN ================= */

int main()
{

    Document d1;
    auto p1 = make_unique<savetofile>();

    DocumentEditor e1(move(d1), move(p1));

    e1.addText("Helll its me aman");
    e1.addImage("Image path is https://www.google.com");

    e1.renderElement();
    e1.saveElement();

    return 0;
}