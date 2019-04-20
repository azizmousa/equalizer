
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

#include "equalizer/Element.hpp"
#include "equalizer/View.hpp"
#include "equalizer/Files.h"

const std::string OUTPUT_DIR = "json";
const int scaller = 5;

int getPercent(int sub, int max);
void wirteViews(std::vector<View> &views, std::string filename);
int round(int perc, int maxScal);
void processViewFile(std::string file);


int main(int argc, char const *argv[])
{
	if(argc > 1){
		Files::initializeOutputDires(OUTPUT_DIR);
		for(int i =1; i<argc ; ++i){
			std::string file = std::string(argv[i]);
			
			if(Files::is_file(file.c_str())){
				processViewFile(file);
			}else{
				std::vector<std::string> files;
				Files::getDirFiles(file, ".viw", files);
				for(size_t j=0; j< files.size();++j){
					processViewFile(file + Files::slash() + files[j]);
				}
			}

		}
	}

	
	return 0;
}


int getPercent(int sub, int max){
	double rat = sub / (double) max;
	return (rat * 100);
}

void wirteViews(std::vector<View> &views, std::string filename){
	using boost::property_tree::ptree;
	ptree viewsTree;
	ptree viewsArray;
	for(size_t i =0; i<views.size();++i){
		ptree child;
		child.add<std::string>(View::VIEW_KEY, views[i].getView());
		child.add<std::string>(View::ID_KEY, views[i].getId());
		child.add<double>(View::Start_PERCENT_KEY, views[i].getStartPercent());
		child.add<double>(View::TOP_PERCENT_KEY, views[i].getTopPercent());
		child.add<double>(View::END_PERCENT_KEY, views[i].getEndPercent());
		child.add<double>(View::BOTTOM_PERCENT_KEY, views[i].getBottomPercent());
		viewsArray.push_back(std::make_pair("", child));
	}
	viewsTree.add_child("views", viewsArray);
	write_json(filename, viewsTree);
}


int round(int perc, int maxScal){
	int rem = perc % maxScal;
	perc -= rem;
	return (rem > rem/2)? perc + maxScal : perc;
}


void processViewFile(std::string file){
	std::string viewsFileName = Files::getFileName(file) + ".json";
	std::cerr << "path: " << file <<std::endl;
	std::fstream input(file);
	std::vector<Element> elmentsVec;
	int width, height;
	
	input >> width;
	input >> height;

	std::string view, id, temp;
	int left, top, right, bottom;

	while(!input.eof()){
		input >> view;
		
		if(input.peek() == EOF)
			break;
		input >> id;
		input >> left;
		input >> top;
		input >> right;
		input >> bottom;
		input >> temp;
		Element e(view, id,round(getPercent(left, width), scaller), round(getPercent(top, height), scaller), 
		round(getPercent(right, width), scaller), round(getPercent(bottom, height), scaller));
		
		//std::cout<<e.toString()<<std::endl<<std::endl;
		elmentsVec.push_back(e);
	}
	input.close();

	std::vector<View> views;
			
	for(size_t i =0; i<elmentsVec.size();++i){
		View v(elmentsVec[i].getView(), elmentsVec[i].getId(), 
		elmentsVec[i].getLeft(), elmentsVec[i].getTop(), elmentsVec[i].getRight(),
		elmentsVec[i].getBottom());
		views.push_back(v);
	}

	wirteViews(views, OUTPUT_DIR + Files::slash() + viewsFileName);
}