#ifndef _ELEMENT_DIRECTIONS
#define _ELEMENT_DIRECTIONS

#include <string>

class Directions{
private:

    std::string constraintStart_toStartOf;
    std::string constraintStart_toEndOf;

    std::string constraintTop_toTopOf;
    std::string constraintTop_toBottomOf;

    std::string constraintEnd_toStartOf;
    std::string constraintEnd_toEndOf;
    
    std::string constraintBottom_toTopOf;
    std::string constraintBottom_toBottomOf;

public:

    void setConstraintStart_toStartOf(std::string objectName);
    void setConstraintStart_toEndOf(std::string objectName);
   
    void setConstraintTop_toTopOf(std::string objectName);
    void setConstraintTop_toBottomOf(std::string objectName);
   
    void setConstraintEnd_toStartOf(std::string objectName);
    void setConstraintEnd_toEndOf(std::string objectName);
   
    void setConstraintBottom_toTopOf(std::string objectName);
    void setConstraintBottom_toBottomOf(std::string objectName);


    std::string getConstraintStart_toStartOf();
    std::string getConstraintStart_toEndOf();

    std::string getConstraintTop_toTopOf();
    std::string getConstraintTop_toBottomOf();

    std::string getConstraintEnd_toStartOf();
    std::string getConstraintEnd_toEndOf();

    std::string getConstraintBottom_toTopOf();
    std::string getConstraintBottom_toBottomOf();

};

#endif