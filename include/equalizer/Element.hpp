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

    int getLeft();
    int getTop();
    int getWidth();
    int getHeight();

    static bool compareTop(Element &e1, Element &e2);
    static bool compareLeft(Element &e1, Element &e2);
    std::string getView();
    std::string toString();
};

#endif