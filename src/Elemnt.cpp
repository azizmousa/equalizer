#include <equalizer/Element.hpp>

#include<string>


Element::Element(){
    this->leftRatio = 0;
    this->topRatio = 0;
    this->widthRatio = 0;
    this->heightRatio = 0;
}

Element::Element(std::string view, int left, int top, int right, int bottom){
    this->view = view;
    this->leftRatio = left;
    this->topRatio = top;
    this->widthRatio = right;
    this->heightRatio = bottom;
}

void Element::setLeft(int left){
    this->leftRatio = left;
}

void Element::setView(std::string view){
    this->view = view;
}

void Element::setTop(int top){
    this->topRatio = top;
}

void Element::setWidth(int widthRatio){
    this->widthRatio = widthRatio;
}

void Element::setHeight(int heightRatio){
    this->heightRatio = heightRatio;
}

int Element::getLeft(){
    return this->leftRatio;
}

int Element::getTop(){
    return this->topRatio;
}

int Element::getWidth(){
    return this->widthRatio;
}

int Element::getHeight(){
    return this->heightRatio;
}

std::string Element::getView(){
    return this->view;
}

std::string Element::toString(){
    return this->view + "\nleft: " + std::to_string(this->leftRatio) + "\ntop: "
            + std::to_string(this->topRatio) + "\nright: " + std::to_string(this->widthRatio) 
            + "\nbottom: " + std::to_string(this->heightRatio);
}
