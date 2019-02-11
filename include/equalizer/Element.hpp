#ifndef _ELEMENT_FILE
#define _ELEMENT_FILE

#include <string>

class Element{
private:
    int left, top, right, bottom;
public:
    Element();
    Element(int left, int top, int right, int bottom);
    void setLeft(int left);
    void setTop(int top);
    void setRight(int right);
    void setBottom(int bottom);

    int getLeft();
    int getTop();
    int getRight();
    int getBottom();
    std::string toString();
};

#endif