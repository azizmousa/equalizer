
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

#include<equalizer/Element.hpp>


int getPercent(int sub, int max);

int main(int argc, char const *argv[])
{

	std::fstream input("objects.obj");
	std::vector<Element> elmentsVec;
	int width, height;
	
	input >> width;
	input >> height;

	std::string view, temp;
	int left, top, right, bottom;

	while(!input.eof()){
		input >> view;
		
		if(input.peek() == EOF)
			break;

		input >> left;
		input >> top;
		input >> right;
		input >> bottom;
		input >> temp;
		
		Element e(view, getPercent(left, width), getPercent(top, height), 
		getPercent(right - left, width), getPercent(bottom - top, height));

		std::cout<<e.toString()<<std::endl<<std::endl;
		elmentsVec.push_back(e);
	}
	input.close();
	
	//std::sort(elmentsVec.begin(), elmentsVec.end());

	for(int i =0; i<elmentsVec.size();++i){
		std::cout << elmentsVec[i].getView() << std::endl;
		std::cout << elmentsVec[i].getLeft() << std::endl;
		std::cout << elmentsVec[i].getTop() << std::endl;
		std::cout << elmentsVec[i].getWidth() << std::endl;
		std::cout << elmentsVec[i].getHeight() << std::endl;
	}

	return 0;
}


int getPercent(int sub, int max){
	double rat = sub / (double) max;
	return (rat * 100);
}

