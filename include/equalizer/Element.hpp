#ifndef _ELEMENT_FILE
#define _ELEMENT_FILE

#include <string>
#include<vector>

class Element{
private:
    int leftRatio, topRatio, rightRatio, bottomRatio;
    std::string view;
    
public:
    Element();
    Element(std::string view, int leftRatio, int topRatio, int rightRatio, int bottomRatio);
    void setLeft(int left);
    void setTop(int top);
    void setRight(int start);
    void setBottom(int bottom);
    void setView(std::string view);
    

    int getLeft();
    int getTop();
    int getRight();
    int getBottom();

    std::string getView();
    std::string toString();
};

#endif