
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

#include "equalizer/AndroidViewsWriter.hpp"
#include "equalizer/Element.hpp"

AndroidViewsWriter::AndroidViewsWriter(std::vector<Element> elements)
:ObjectsTreeController(elements){
    
}

AndroidViewsWriter::~AndroidViewsWriter(){}

void AndroidViewsWriter::createObjectsTree(){
	// std::cout << "elments size: " << ObjectsTreeController::elements.size() << std::endl;
    for(size_t i =0; i < ObjectsTreeController::elements.size();++i){
		AndroidView v(ObjectsTreeController::elements[i].getView(), 
        ObjectsTreeController::elements[i].getId(), 
		ObjectsTreeController::elements[i].getLeft(), 
        ObjectsTreeController::elements[i].getTop(), 
        ObjectsTreeController::elements[i].getRight(),
		ObjectsTreeController::elements[i].getBottom());
		this->androidViews.push_back(v);
	}
	// std::cout << "android views size: " << androidViews.size() << std::endl;
    boost::property_tree::ptree viewsArray;
	for(size_t i =0; i<this->androidViews.size();++i){
		boost::property_tree::ptree child;
		child.add<std::string>(AndroidView::VIEW_KEY, this->androidViews[i].getView());
		child.add<std::string>(AndroidView::ID_KEY, this->androidViews[i].getId());
		child.add<double>(AndroidView::Start_PERCENT_KEY, this->androidViews[i].getStartPercent());
		child.add<double>(AndroidView::TOP_PERCENT_KEY, this->androidViews[i].getTopPercent());
		child.add<double>(AndroidView::END_PERCENT_KEY, this->androidViews[i].getEndPercent());
		child.add<double>(AndroidView::BOTTOM_PERCENT_KEY, this->androidViews[i].getBottomPercent());
		viewsArray.push_back(std::make_pair("", child));
	}
	
	ObjectsTreeController::objectsTree.add_child("views", viewsArray);
}