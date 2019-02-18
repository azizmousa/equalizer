
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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

		//std::cout<<e.toString()<<std::endl<<std::endl;
		elmentsVec.push_back(e);
	}
	input.close();

	std::vector<std::vector<Element>> matrix;

	for(size_t i =0; i<elmentsVec.size();++i){
		std::sort(elmentsVec.begin(), elmentsVec.end(), Element::compareTop);
		std::vector<Element> row;
		int initTopVal = elmentsVec[0].getTop();
		size_t j;
		for(j =0; ( elmentsVec[j].getTop() - initTopVal <= 5) && j < elmentsVec.size();++j){
			row.push_back(elmentsVec[j]);
		}
		elmentsVec.erase(elmentsVec.begin(), elmentsVec.begin()+j);
		std::sort(row.begin(), row.end(), Element::compareLeft);
		matrix.push_back(row);
		i = 0;
	}
	
	for(size_t i =0; i<matrix.size();++i){	
		for(size_t j =0; j<matrix[i].size();++j){
			Directions dirs;
			int previous = 0, next = 0, up = 0, down = 0;
			if(j != 0)
				previous = matrix[i][j - 1].getLeft() + matrix[i][j - 1].getWidth();
			
			if(j != matrix[i].size() - 1)
				next = matrix[i][j + 1].getLeft();
			
			int prevDif = std::abs(previous - matrix[i][j].getLeft());
			int nexDif = std::abs(next - (matrix[i][j].getLeft() + matrix[i][j].getWidth()));
			
			if(prevDif > nexDif){
				if(j != matrix[i].size() - 1)
					dirs.setConstraintEnd_toStartOf(matrix[i][j + 1].getView());
				else
					dirs.setConstraintEnd_toEndOf("parent");
			}else{
				if(j != 0)
					dirs.setConstraintEnd_toStartOf(matrix[i][j - 1].getView());
				else
					dirs.setConstraintStart_toStartOf("parent");
			}
				

			matrix[i][j].setDirections(dirs);
		}
	}

	for(size_t i =0; i<matrix.size();++i){	
		for(size_t j =0; j<matrix[i].size();++j){
			std::vector<std::string> vec = matrix[i][j].getExistsDirections();
			std::cout << matrix[i][j].getView() << ": " << std::endl;
			for(size_t k =0; k<vec.size();++k){
				std::cout << vec[k] << std::endl;
			}
			std::cout << std::endl;
		}
	}

	return 0;
}


int getPercent(int sub, int max){
	double rat = sub / (double) max;
	return (rat * 100);
}

