#include <equalizer/Element.hpp>

#include<string>


Element::Element(){
    this->left = 0;
    this->top = 0;
    this->right = 0;
    this->bottom = 0;
}

Element::Element(int left, int top, int right, int bottom){
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
}

void Element::setLeft(int left){
    this->left = left;
}

void Element::setTop(int top){
    this->top = top;
}

void Element::setRight(int right){
    this->right = right;
}

void Element::setBottom(int bottom){
    this->bottom = bottom;
}

int Element::getLeft(){
    return this->left;
}

int Element::getTop(){
    return this->top;
}

int Element::getRight(){
    return this->right;
}

int Element::getBottom(){
    return this->bottom;
}

std::string Element::toString(){
    return "left: " + std::to_string(this->left) + "\ntop: "
            + std::to_string(this->top) + "\nright: " + std::to_string(this->right) 
            + "\nbottom: " + std::to_string(this->bottom);
}
