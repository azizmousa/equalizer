#ifndef ANDROID_VIEWS_WRITER_
#define ANDROID_VIEWS_WRITER_

#include <vector>

#include "equalizer/ObjectsTreeController.hpp"
#include "equalizer/Element.hpp"
#include "equalizer/AndroidView.hpp"

class AndroidViewsWriter: public ObjectsTreeController{
private:
    std::vector<AndroidView> androidViews;
public:
    AndroidViewsWriter(std::vector<Element> elements);
    void createObjectsTree();
    void writeObjectsTree(std::string path);
    ~AndroidViewsWriter();
};



#endif