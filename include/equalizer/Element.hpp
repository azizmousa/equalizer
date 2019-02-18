#ifndef _ELEMENT_FILE
#define _ELEMENT_FILE

#include <string>
#include<vector>

class Element{
private:
    int leftRatio, topRatio, rightRatio, endRatio;
    std::string view;
    
public:
    Element();
    Element(std::string view, int leftRatio, int topRatio, int rightRatio, int endRatio);
    void setLeft(int left);
    void setTop(int top);
    void setRight(int start);
    void setEnd(int end);
    void setView(std::string view);
    

    int getLeft();
    int getTop();
    int getRight();
    int getEnd();

    std::string getView();
    std::string toString();
};

#endif