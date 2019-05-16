
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

#include "equalizer/CSharpWriter.hpp"
#include "equalizer/Element.hpp"
#include "equalizer/Utilities.hpp"

CSharpWriter::CSharpWriter(std::vector<Element> elements, int width, int height)
:ObjectsTreeController(elements){
    this->width = width;
    this->height = height;
}

CSharpWriter::~CSharpWriter(){}

void CSharpWriter::createObjectsTree(){
	// std::cout << "elments size: " << ObjectsTreeController::elements.size() << std::endl;
    for(size_t i =0; i < ObjectsTreeController::elements.size();++i){
		CSharpObject v(ObjectsTreeController::elements[i].getView(), 
        ObjectsTreeController::elements[i].getId(), 
		ObjectsTreeController::elements[i].getLeft(), 
        ObjectsTreeController::elements[i].getTop(), 
        ObjectsTreeController::elements[i].getRight(),
		ObjectsTreeController::elements[i].getBottom());
		this->csharpObject.push_back(v);
	}
	// std::cout << "android views size: " << androidViews.size() << std::endl;
    boost::property_tree::ptree viewsArray;
	for(size_t i =0; i<this->csharpObject.size();++i){
		boost::property_tree::ptree child;
		child.add<std::string>(CSharpObject::OBJECT_KEY, this->csharpObject[i].getObject());
		child.add<std::string>(CSharpObject::ID_KEY, this->csharpObject[i].getId());
		child.add<double>(CSharpObject::Start_KEY, this->csharpObject[i].getStart());
		child.add<double>(CSharpObject::TOP_KEY, this->csharpObject[i].getTop());
		child.add<double>(CSharpObject::END_KEY, this->csharpObject[i].getEnd());
		child.add<double>(CSharpObject::BOTTOM_KEY, this->csharpObject[i].getBottom());
		viewsArray.push_back(std::make_pair("", child));
	}
	ObjectsTreeController::objectsTree.put("width", this->width);
    ObjectsTreeController::objectsTree.put("height", this->height);
	ObjectsTreeController::objectsTree.add_child("objects", viewsArray);
}
