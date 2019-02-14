
#include<string>
#include<vector>

#include <equalizer/Element.hpp>

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

bool Element::compareTop(Element &e1, Element &e2){
    return e1.getTop() < e2.getTop();
}

bool Element::compareLeft(Element &e1, Element &e2){
    return e1.getLeft() < e2.getLeft();
}
std::string Element::getView(){
    return this->view;
}

std::string Element::toString(){
    return this->view + "\nleft: " + std::to_string(this->leftRatio) + "\ntop: "
            + std::to_string(this->topRatio) + "\nright: " + std::to_string(this->widthRatio) 
            + "\nbottom: " + std::to_string(this->heightRatio);
}


void Element::setDirections(Directions direcitons){
    this->directions = direcitons;
}

Directions Element::getDirections(){
    return this->directions;
}

std::vector<std::string> Element::getExistsDirections(){
    std::vector<std::string> dirs;
    if(this->directions.getConstraintStart_toStartOf() != "")
        dirs.push_back(this->directions.getConstraintStart_toStartOf());
    if(this->directions.getConstraintStart_toEndOf() != "")
        dirs.push_back(this->directions.getConstraintStart_toEndOf());

    if(this->directions.getConstraintTop_toTopOf() != "")
        dirs.push_back(this->directions.getConstraintTop_toTopOf());
    if(this->directions.getConstraintTop_toTopOf() != "")
        dirs.push_back(this->directions.getConstraintTop_toTopOf());

    if(this->directions.getConstraintEnd_toStartOf() != "")
        dirs.push_back(this->directions.getConstraintEnd_toStartOf());
    if(this->directions.getConstraintEnd_toEndOf() != "")
        dirs.push_back(this->directions.getConstraintEnd_toEndOf());

    if(this->directions.getConstraintBottom_toTopOf() != "")
        dirs.push_back(this->directions.getConstraintBottom_toTopOf());
    if(this->directions.getConstraintBottom_toBottomOf() != "")
        dirs.push_back(this->directions.getConstraintBottom_toBottomOf());

    return dirs;
}
