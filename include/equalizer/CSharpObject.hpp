#ifndef CSHARP_OBJECT_
#define CSHARP_OBJECT_

#include<string>

class CSharpObject{

private:
    std::string object;
    std::string id;
    double start;
    double top;
    double end;
    double bottom;

public:
    const static std::string OBJECT_KEY;
    const static std::string ID_KEY;
    const static std::string Start_KEY;
    const static std::string TOP_KEY;
    const static std::string END_KEY;
    const static std::string BOTTOM_KEY;

    CSharpObject();
    CSharpObject(std::string, std::string, double, double, double, double);

    std::string getObject()const;
    std::string getId()const;
    double getStart()const;
    double getTop()const;
    double getEnd()const;
    double getBottom()const;

    void setObject(std::string object);
    void setId(std::string id);
    void setStart(double start);
    void setTop(double top);
    void setEnd(double end);
    void setBottom(double bottom);
};

#endif