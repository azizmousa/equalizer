#ifndef _ELEMENT_FILE
#define _ELEMENT_FILE

#include <string>

class Element{
private:
    int left, top, right, bottom;
    std::string view;
public:
    Element();
    Element(std::string view, int left, int top, int right, int bottom);
    void setLeft(int left);
    void setTop(int top);
    void setRight(int right);
    void setBottom(int bottom);
    void setView(std::string view);
    friend bool operator<(const Element &e1, const Element &e2);

    int getLeft();
    int getTop();
    int getRight();
    int getBottom();

    std::string getView();
    std::string toString();
};

#endif