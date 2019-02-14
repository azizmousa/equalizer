
#include<string>

#include<equalizer/Directions.hpp>


void Directions::setConstraintStart_toStartOf(std::string objectName){
    this->constraintStart_toStartOf = objectName;
}
void Directions::setConstraintStart_toEndOf(std::string objectName){
    this->constraintStart_toEndOf = objectName;
}


void Directions::setConstraintTop_toTopOf(std::string objectName){
    this->constraintTop_toTopOf = objectName;
}
void Directions::setConstraintTop_toBottomOf(std::string objectName){
    this->constraintTop_toBottomOf = objectName;
}

void Directions::setConstraintEnd_toStartOf(std::string objectName){
    this->constraintEnd_toStartOf = objectName;
}
void Directions::setConstraintEnd_toEndOf(std::string objectName){
    this->constraintEnd_toEndOf = objectName;
}

void Directions::setConstraintBottom_toTopOf(std::string objectName){
    this->constraintBottom_toTopOf = objectName;
}
void Directions::setConstraintBottom_toBottomOf(std::string objectName){
    this->constraintBottom_toBottomOf = objectName;
}


std::string Directions::getConstraintStart_toStartOf(){
    return this->constraintStart_toStartOf;
}
std::string Directions::getConstraintStart_toEndOf(){
    return this->constraintStart_toEndOf;
}

std::string Directions::getConstraintTop_toTopOf(){
    return this->constraintTop_toTopOf;
}
std::string Directions::getConstraintTop_toBottomOf(){
    return this->constraintTop_toBottomOf;
}

std::string Directions::getConstraintEnd_toStartOf(){
    return this->constraintEnd_toStartOf;
}
std::string Directions::getConstraintEnd_toEndOf(){
    return this->constraintEnd_toEndOf;
}

std::string Directions::getConstraintBottom_toTopOf(){
    return this->constraintBottom_toTopOf;
}
std::string Directions::getConstraintBottom_toBottomOf(){
    return this->constraintBottom_toBottomOf;
}