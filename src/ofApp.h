#pragma once

#include "ofMain.h"
#include "arc.h"
#include "videoRecorder.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();
	void exit();

	void mousePressed(int x, int y, int button);
	void keyPressed(int key);

	int saveImageCounter = 0;
	void saveFrame(bool bUseViewport)
	{
		string zeroes = "00000";
		zeroes = zeroes.substr(0, zeroes.length() - (ofToString(saveImageCounter).length()));

		string fileName = "./" + zeroes + ofToString(saveImageCounter) + ".png";

		if (bUseViewport)
		{
			ofSaveViewport(fileName);
		}
		else
		{
			ofSaveScreen(fileName);
		}
		saveImageCounter++;
	}

	VideoRecorder video_recorder;

	// glm::vec3 guide[4];
	// ofNode node1, node2, emitter;
	// float radius, roll1 = 1, roll2 = 0, angle;
	// ofPolyline polyline;
	// bool wait, cant_move;
	// int limit = 100;
	vector<Arc *> arcs;

	// void step()
	// 	{
	// 		radius = ofRandom(15, 100);
	//
	// 		glm::vec3 node1_global_position = node1.getGlobalPosition();
	// 		glm::vec3 node2_global_position = node2.getGlobalPosition();
	// 		glm::vec3 emitter_global_position = emitter.getGlobalPosition();
	// 		glm::quat node1_global_orientation = node1.getGlobalOrientation();
	// 		glm::quat node2_global_orientation = node2.getGlobalOrientation();
	//
	// 		node1_global_position = {
	// 			emitter_global_position.x - cos(angle) * radius,
	// 			emitter_global_position.y - sin(angle) * radius, 0};
	// 		node2_global_position = {
	// 			emitter_global_position.x + cos(angle) * radius,
	// 			emitter_global_position.y + sin(angle) * radius, 0};
	//
	// 		if (roll1)
	// 		{
	// 			roll1 = 0;
	// 			roll2 = -1;
	// 			node2.clearParent();
	// 			node2.setGlobalPosition(node2_global_position);
	// 			node2.setGlobalOrientation(node2_global_orientation);
	// 			node1.setParent(node2);
	// 			node1.setGlobalPosition(node1_global_position);
	// 			node1.setGlobalOrientation(node1_global_orientation);
	// 		}
	// 		else
	// 		{
	// 			roll1 = 1;
	// 			roll2 = 0;
	// 			node1.clearParent();
	// 			node1.setGlobalPosition(node1_global_position);
	// 			node1.setGlobalOrientation(node1_global_orientation);
	// 			node2.setParent(node1);
	// 			node2.setGlobalPosition(node2_global_position);
	// 			node2.setGlobalOrientation(node2_global_orientation);
	// 		}
	// 		emitter.setGlobalPosition(emitter_global_position);
	// 	}
};

// void keyReleased(int key);
// void mouseMoved(int x, int y);
// void mouseDragged(int x, int y, int button);
// void mouseReleased(int x, int y, int button);
// void mouseEntered(int x, int y);
// void mouseExited(int x, int y);
// void windowResized(int w, int h);
// void dragEvent(ofDragInfo dragInfo);
// void gotMessage(ofMessage msg);