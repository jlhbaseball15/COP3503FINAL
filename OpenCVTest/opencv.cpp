
#include "opencv.h"

#include<sstream>

using namespace cv;

using namespace std;


string TRAINEDMODEL = "trainedmodel.yaml";

void detectNewUser(Mat &frame, int &j, string name);

void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';')
{
    
    std::ifstream file(filename.c_str(), ifstream::in);
    
    if (!file)
    {
        string error_message = "No valid input file was given, please check the given filename.";
        
        cout<<endl;
        
        CV_Error(CV_StsBadArg, error_message);
    }
    
    string line, path, classlabel;
    
    while (getline(file, line))
    {
        
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        
        if(!path.empty() && !classlabel.empty())
        {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}



string g_listname_t[]=
{
    "Archit Rathi",
    "Brad Pitt",
    
};



void trainModel(){
    
}

void recognize(vector<string> label) {
    // Check for valid command line arguments, print usage
    // if no arguments were given.
    //if (argc != 4) {
    //    cout << "usage: " << argv[0] << " </path/to/haar_cascade> </path/to/csv.ext> </path/to/device id>" << endl;
    //    cout << "\t </path/to/haar_cascade> -- Path to the Haar Cascade for face detection." << endl;
    //    cout << "\t </path/to/csv.ext> -- Path to the CSV file with the face database." << endl;
    //    cout << "\t <device id> -- The webcam device id to grab frames from." << endl;
    //    exit(1);
    //}
    //// Get the path to your CSV:
    //string fn_haar = string(argv[1]);
    //string fn_csv = string(argv[2]);
    //int deviceId = atoi(argv[3]);
    //// Get the path to your CSV:
    // please set the correct path based on your folder
    string fn_haar = "haarcascade_frontalface_alt.xml";
    //string fn_csv = "/Users/Archit/Downloads/DetectsAndRecognizeFaces/Python\ script/csv.ext";
    int deviceId = 0;			// here is my webcam Id.
    // These vectors hold the images and corresponding labels:
    vector<Mat> images;
    // Read in the data (fails if no valid input filename is given, but you'll get an error message):
    
    // Get the height from the first image. We'll need this
    // later in code to reshape the images to their original
    // size AND we need to reshape incoming faces to this size
    
    // Create a FaceRecognizer and train it on the given images:
    Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
    model->load(TRAINEDMODEL);
    // That's it for learning the Face Recognition model. You now
    // need to create the classifier for the task of Face Detection.
    // We are going to use the haar cascade you have specified in the
    // command line arguments:
    //
    CascadeClassifier haar_cascade;
    haar_cascade.load(fn_haar);
    // Get a handle to the Video device:
    VideoCapture cap(deviceId);
    // Check if we can use this device at all:
    if(!cap.isOpened()) {
        cerr << "Capture Device ID " << deviceId << "cannot be opened." << endl;
    }
    // Holds the current frame from the Video device:
    Mat frame;
    for(;;) {
        cap >> frame;
        // Clone the current frame:
        Mat original = frame.clone();
        // Convert the current frame to grayscale:
        Mat gray;
        cvtColor(original, gray, CV_BGR2GRAY);
        // Find the faces in the frame:
        vector< Rect_<int> > faces;
        haar_cascade.detectMultiScale(gray, faces);
        // At this point you have the position of the faces in
        // faces. Now we'll get the faces, make a prediction and
        // annotate it in the video. Cool or what?
        for(int i = 0; i < faces.size(); i++) {
            // Process face by face:
            Rect face_i = faces[i];
            // Crop the face from the image. So simple with OpenCV C++:
            Mat face = gray(face_i);
            // Resizing the face is necessary for Eigenfaces and Fisherfaces. You can easily
            // verify this, by reading through the face recognition tutorial coming with OpenCV.
            // Resizing IS NOT NEEDED for Local Binary Patterns Histograms, so preparing the
            // input data really depends on the algorithm used.
            //
            // I strongly encourage you to play around with the algorithms. See which work best
            // in your scenario, LBPH should always be a contender for robust face recognition.
            //
            // Since I am showing the Fisherfaces algorithm here, I also show how to resize the
            // face you have just found:
            Mat face_resized;
            cv::resize(face, face_resized, Size(200, 200), 1.0, 1.0, INTER_CUBIC);
            // Now perform the prediction, see how easy that is:
            
            int prediction = 0;
            double confidence = 0.0;
            model->predict(face_resized,prediction,confidence);
            // And finally write all we've found out to the original image!
            // First of all draw a green rectangle around the detected face:
            rectangle(original, face_i, CV_RGB(0, 255,0), 1);
            // Create the text we will annotate the box with:
            string box_text;
            box_text = format( "Prediction = " );
            // Get stringname
            if ( prediction >= 0)
            {
                cout<<label[prediction]<<'\n';
                cout << confidence << endl;
                box_text.append( label[prediction] );
                
            }
            else {
                box_text.append( "User Unknown" );
                cout << confidence << endl;
            }
            // Calculate the position for annotated text (make sure we don't
            // put illegal values in there):
            int pos_x = std::max(face_i.tl().x - 10, 0);
            int pos_y = std::max(face_i.tl().y - 10, 0);
            // And now put it into the image:
            putText(original, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(255,255,0), 2.0);
        }
        
        if (faces.size() > 1) {
            
        }
        // Show the result:
        imshow("face_recognizer", original);
        // And display it:
        char key = (char) waitKey(20);
        // Exit this loop on escape:
        if(key == 27)
            break;
    }
    
}

void addNewUser(string name, vector<string> &labels){
    VideoCapture capture;
    Mat frame;
    
    capture.open(-1);
    
    if ( !capture.isOpened() ) {
        printf("--(!)Error opening video capture\n");
    }
    
    int count = 0;
    
    string folder = name;
    string folderCreateCommand = "mkdir cropped/" + folder;
    system(folderCreateCommand.c_str());

    while (capture.read(frame) && (count < 50))
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        
        
        //-- 3. Apply the classifier to the frame
        detectNewUser(frame, count, name);
        string window_name = "Capture - Face detection";
        namedWindow(window_name, WINDOW_AUTOSIZE );
        imshow(window_name, frame);
        
        int c = waitKey(10);
        if( (char)c == 27 ) { break; }
    }
    
    capture.release();
    
    string path = "cropped/";
    vector<Mat> images;
    vector<int> nameIndex;
    
    vector<string>::iterator it;
    int i = 0;
    for(it = labels.begin() ; it < labels.end(); it++, i++) {
        // found nth element..print and break.
        for (int j = 0; j < 50; j++){
            string file = path + *it + "/" + to_string(j) + ".jpg";
            Mat image = imread(file, 0);
            Mat newImage;
            cv::resize(image, newImage, Size(200, 200), 0, 0, INTER_LINEAR);
            images.push_back(newImage);
            nameIndex.push_back(i);
        }
    }
    
    Ptr<FaceRecognizer> model = createFisherFaceRecognizer();
    model->train(images,nameIndex);
    model->save(TRAINEDMODEL);
    
}

void detectNewUser(Mat &frame, int &j, string name)
{
    Mat cropped;
    std::vector<Rect> faces;
    Mat frame_gray;
    
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
   
    string fn_haar = "haarcascade_frontalface_alt.xml";
    
    //-- Detect faces
    CascadeClassifier haar_cascade;
    
    if( !haar_cascade.load( fn_haar ) ){
        printf("--(!)Error loading face cascade\n");
        return;
    };
   
    haar_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    
    if (faces.size() != 0) {
        Point topleft(faces[0].x,faces[0].y);
        Point bottomright(faces[0].x + faces[0].width,faces[0].y + faces[0].height);
        
        rectangle(frame, topleft, bottomright, Scalar(255,255,0));
        
        Mat faceROI = frame_gray(faces[0]);
        
        cropped = frame(Rect(faces[0].x,faces[0].y,faces[0].width,faces[0].height));
        
        //saves faces to folder
        string folder = name;
        imwrite("cropped/" + folder + "/" + to_string(j) + ".jpg", cropped);
        cout << "cropped/" + folder + "/" + to_string(j) + ".jpg" << endl;
        j++;
    }
    
    
        //-- In each face, detect eyes
        //-- Show what you got
    
    
}


/*int main() {
    //recognize();
    vector<string> label;
    label.push_back("Kevin");
    label.push_back("Susanne");
    label.push_back("Archit");
    label.push_back("John");
    
//  string name;
//  cin >> name;
//    
//  label.push_back(name);
//    
//  addNewUser(name,label);
    recognize(label);
    return 0;
}*/




