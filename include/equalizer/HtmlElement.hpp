#ifndef HTML_ELEMENT_
#define HTML_ELEMENT_

#include<string>

class HtmlElement{

private:
    std::string element;
    std::string id;
    int start_column;
    int end_column;
    int width;
    int height;

public:
    const static std::string ELEMENT_KEY;
    const static std::string ID_KEY;
    const static std::string START_COLUMN_KEY;
    const static std::string END_COLUMN_KEY;
    const static std::string WIDTH_KEY;
    const static std::string HEIGHT_KEY;

    HtmlElement();
    HtmlElement(std::string, std::string, int, int, int, int);

    void setElementType(std::string element);
    void setId(std::string id);
    void setStartColumn(int s);
    void setEndColumn(int s);
    void setWidth(int s);
    void setHeight(int s);

    std::string getElementType()const;
    std::string getId()const;
    int getStartColumn()const;
    int getEndColumn()const;
    int getWidth()const;
    int getHeight()const;
};


#endif