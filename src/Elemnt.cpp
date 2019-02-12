#include <equalizer/Element.hpp>

#include<string>


Element::Element(){
    this->left = 0;
    this->top = 0;
    this->right = 0;
    this->bottom = 0;
}

Element::Element(std::string view, int left, int top, int right, int bottom){
    this->view = view;
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
}

bool operator<(const Element &e1, const Element &e2){
    return (e1.top < e2.top) ?true:false;
}

void Element::setLeft(int left){
    this->left = left;
}

void Element::setView(std::string view){
    this->view = view;
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

int Element::getStartRatio(const int maxWidth)const{
    double rat = this->left / (double) maxWidth;
    return rat * 100;
}

int Element::getEndRatio(const int maxWidth)const{
    double rat = this->right / (double) maxWidth;
    return rat * 100;
}

int Element::getTopRatio(const int maxHeight)const{
    double rat = this->top / (double) maxHeight;
    return rat * 100;
}


std::string Element::getView(){
    return this->view;
}

std::string Element::toString(){
    return this->view + "\nleft: " + std::to_string(this->left) + "\ntop: "
            + std::to_string(this->top) + "\nright: " + std::to_string(this->right) 
            + "\nbottom: " + std::to_string(this->bottom);
}
