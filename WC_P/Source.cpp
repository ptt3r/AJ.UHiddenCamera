#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"

int main()
{
	//Creating video capturing object
	cv::VideoCapture video(0);

	//check video opened or not
	if (!video.isOpened()) return -1;

	//for saving the frame
	cv::Mat frame;

	//Get the video
	int frameWidth = video.get(cv::CAP_PROP_FRAME_WIDTH);
	int frameHeight = video.get(cv::CAP_PROP_FRAME_HEIGHT);

	//create vidoe writer object
	cv::VideoWriter output("output.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, cv::Size(frameWidth, frameHeight));


	while (video.read(frame)) {

		//display the frame
		cv::imshow("Video frame", frame);

		//write video frame
		output.write(frame);

		//for ending the video early
		if (cv::waitKey(25) >= 0) {
			break;
		}
	}

	//Release towards to saving the file

	output.release();
	video.release();

	//Destroy the window
	cv::destroyAllWindows();

	return 0;
}