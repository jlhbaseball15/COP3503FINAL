//
//  recognize.h
//  OpenCVTest
//
//  Created by Archit Rathi on 4/17/16.
//  Copyright © 2016 Archit Rathi. All rights reserved.
//

#ifndef recognize_h
#define recognize_h
#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/contrib/contrib.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class OpenCV {
private:
    
public:
    string recognize();
    void addNewUser();

};

#endif /* recognize_h */
