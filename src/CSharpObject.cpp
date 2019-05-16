
#include <string>

#include "equalizer/CSharpObject.hpp"


const std::string CSharpObject::OBJECT_KEY = "object";
const std::string CSharpObject::ID_KEY = "id";
const std::string CSharpObject::Start_KEY = "start";
const std::string CSharpObject::TOP_KEY = "top";
const std::string CSharpObject::END_KEY = "end";
const std::string CSharpObject::BOTTOM_KEY = "bottom";


CSharpObject::CSharpObject(){}
CSharpObject::CSharpObject(std::string object, std::string id, double start, double top, double end, double bottom){
    this->object = object;
    this->id = id;
    this->start = start;
    this->top = top;
    this->end = end;
    this->bottom = bottom;
}

void CSharpObject::setObject(std::string object){
    this->object = object;
}
void CSharpObject::setId(std::string id){
    this->id = id;
}
void CSharpObject::setStart(double start){
    this->start = start;
}
void CSharpObject::setTop(double top){
    this->top = top;
}
void CSharpObject::setEnd(double end){
    this->end = end;
}
void CSharpObject::setBottom(double bottom){
    this->bottom = bottom;
}

std::string CSharpObject::getObject()const{
    return this->object;
}
std::string CSharpObject::getId()const{
    return this->id;
}
double CSharpObject::getStart()const{
    return this->start;
}
double CSharpObject::getTop()const{
    return this->top;
}
double CSharpObject::getEnd()const{
    return this->end;
}
double CSharpObject::getBottom()const{
    return this->bottom;
}