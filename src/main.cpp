
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<boost/property_tree/ptree.hpp>
#include<boost/property_tree/json_parser.hpp>

#include<equalizer/Element.hpp>
#include<equalizer/View.hpp>

int getPercent(int sub, int max);
void wirteViews(std::vector<View> &views, std::string filename);
std::string getFileName(std::string path);

std::string VIEWS_FILE;

int main(int argc, char const *argv[])
{
	if(argc > 1){
		for(int i =1; i<argc ; ++i){
			std::string file = std::string(argv[i]);
			VIEWS_FILE = getFileName(file) + ".json";
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
				Element e(view, id,getPercent(left, width), getPercent(top, height), 
				getPercent(right, width), getPercent(bottom, height));

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

			wirteViews(views, VIEWS_FILE);

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

std::string getFileName(std::string path){
    char slash = '/';
    char dot = '.';
#ifdef _WIN32
    slash = '\\';
#endif
    int last;
    last = path.find_last_of(slash);
    std::string name;
    if(last != std::string::npos){
        name = path.substr(last+1);
    }else{
        name = path;
    }

    last = name.find_last_of(dot);
    if(last != std::string::npos){
        name = name.substr(0, last);
    }
    return name;
    
}
