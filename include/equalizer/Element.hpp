#ifndef _ELEMENT_FILE
#define _ELEMENT_FILE

#include <string>

class Element{
private:
    int leftRatio, topRatio, widthRatio, heightRatio;
    std::string view;
public:
    Element();
    Element(std::string view, int leftRatio, int topRatio, int widthRatio, int heightRatio);
    void setLeft(int left);
    void setTop(int top);
    void setWidth(int width);
    void setHeight(int height);
    void setView(std::string view);
    friend bool operator<(const Element &e1, const Element &e2);

    int getLeft();
    int getTop();
    int getWidth();
    int getHeight();

    std::string getView();
    std::string toString();
};

#endif