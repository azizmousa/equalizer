
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <map>
#include <string>

#include "equalizer/Element.hpp"
#include "equalizer/AndroidView.hpp"
#include "equalizer/Files.h"
#include "equalizer/ObjectsTreeController.hpp"
#include "equalizer/AndroidViewsWriter.hpp"


const std::string OUTPUT_DIR = "json";
const int scaller = 5;

int getPercent(int sub, int max);
void wirteViews(std::vector<AndroidView> &views, std::string filename);
int round(int perc, int maxScal);
void readElementsFile(std::string file);

std::vector<Element> elmentsVec;

enum FLAGES{ANDROID, HTML};
std::map<std::string, int> FlagesParser = {
	{"--android", FLAGES::ANDROID},
	{"--html", FLAGES::HTML}
};


int main(int argc, char const *argv[])
{
	if(argc > 2){
		Files::initializeOutputDires(OUTPUT_DIR);
		for(int i =1; i<argc ; ++i){
			std::string file = std::string(argv[i]);
			
			if(Files::is_file(file.c_str())){
				readElementsFile(file);
			}else{
				std::vector<std::string> files;
				Files::getDirFiles(file, ".viw", files);
				for(size_t j=0; j< files.size();++j){
					readElementsFile(file + Files::slash() + files[j]);
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



int round(int perc, int maxScal){
	int rem = perc % maxScal;
	perc -= rem;
	return (rem > rem/2)? perc + maxScal : perc;
}


void readElementsFile(std::string file){
	std::string viewsFileName = Files::getFileName(file) + ".json";
	std::cerr << "path: " << file <<std::endl;
	std::fstream input(file);
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
		Element e(view, id,getPercent(left, width), getPercent(top, height), 
		getPercent(right, width), getPercent(bottom, height));
		
		//std::cout<<e.toString()<<std::endl<<std::endl;
		elmentsVec.push_back(e);
	}
	input.close();
}

void createOutputFile(FLAGES flag){
	ObjectsTreeController* objectsTree;
	switch (flag)
	{
	case FLAGES::ANDROID:
			objectsTree = new AndroidViewsWriter(elmentsVec);
		break;
	
	default:
		return;
	}

	objectsTree->createObjectsTree();
	objectsTree->writeObjectsTree();

}