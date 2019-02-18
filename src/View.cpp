
#include<string>
#include<equalizer/View.hpp>

const std::string View::VIEW_KEY = "view";
const std::string View::ID_KEY = "id";
const std::string View::Start_PERCENT_KEY = "start_percent";
const std::string View::TOP_PERCENT_KEY = "top_percent";
const std::string View::END_PERCENT_KEY = "end_percent";
const std::string View::BOTTOM_PERCENT_KEY = "bottom_percent";


View::View(){
}
View::View(std::string view, std::string id, double start_percent, 
double top_percent, double end_percent, double bottom_percent){
    this->view = view;
    this->id = id;
    this->start_percent = start_percent;
    this->top_percent = top_percent;
    this->end_percent = end_percent;
    this->bottom_percent = bottom_percent;
}

void View::setView(std::string view){
    this->view = view;
}
void View::setId(std::string id){
    this->id = id;
}
void View::setStartPercent(double percent){
    this->start_percent = percent;
}
void View::setTopPercent(double percent){
    this->top_percent = percent;
}
void View::setEndPercent(double percent){
    this->end_percent = percent;
}
void View::setBottomPercent(double percent){
    this->bottom_percent = percent;
}

std::string View::getView()const{
    return this->view;
}
std::string View::getId()const{
    return this->id;
}
double View::getStartPercent()const{
    return this->start_percent;
}
double View::getTopPercent()const{
    return this->top_percent;
}
double View::getEndPercent()const{
    return this->end_percent;
}
double View::getBottomPercent()const{
    return this->bottom_percent;
}