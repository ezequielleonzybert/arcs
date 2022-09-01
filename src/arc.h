#include "ofMain.h"

class Arc
{
public:
    glm::vec3 guide[4];
    ofNode node1, node2, emitter;
    float radius, roll1, roll2, angle;
    ofPolyline polyline;
    bool wait, cant_move;
    int limit;

    Arc()
    {
        roll1 = 1;
        roll2 = 0;
        limit = 100;
        wait = false;
        cant_move = false;
        radius = ofRandom(15, 100);
        node1.setPosition(ofRandom(300, 800), ofRandom(200, 500), 0);
        node2.setParent(node1);
        node2.setPosition(radius, 0, 0);
        emitter.setParent(node1);
        emitter.setPosition(radius / 2, 0, 0);
    };

    void step()
    {
        radius = ofRandom(15, 100);

        glm::vec3 node1_global_position = node1.getGlobalPosition();
        glm::vec3 node2_global_position = node2.getGlobalPosition();
        glm::vec3 emitter_global_position = emitter.getGlobalPosition();
        glm::quat node1_global_orientation = node1.getGlobalOrientation();
        glm::quat node2_global_orientation = node2.getGlobalOrientation();

        node1_global_position = {
            emitter_global_position.x - cos(angle) * radius,
            emitter_global_position.y - sin(angle) * radius, 0};
        node2_global_position = {
            emitter_global_position.x + cos(angle) * radius,
            emitter_global_position.y + sin(angle) * radius, 0};

        if (roll1)
        {
            roll1 = 0;
            roll2 = -1;
            node2.clearParent();
            node2.setGlobalPosition(node2_global_position);
            node2.setGlobalOrientation(node2_global_orientation);
            node1.setParent(node2);
            node1.setGlobalPosition(node1_global_position);
            node1.setGlobalOrientation(node1_global_orientation);
        }
        else
        {
            roll1 = 1;
            roll2 = 0;
            node1.clearParent();
            node1.setGlobalPosition(node1_global_position);
            node1.setGlobalOrientation(node1_global_orientation);
            node2.setParent(node1);
            node2.setGlobalPosition(node2_global_position);
            node2.setGlobalOrientation(node2_global_orientation);
        }
        emitter.setGlobalPosition(emitter_global_position);
    }

    void update()
    {
        node1.rollDeg(roll1 * 10);
        node2.rollDeg(roll2 * 10);
        polyline.addVertex(emitter.getGlobalPosition());

        if (ofGetFrameNum() % (int)ofRandom(1, 40) == 0)
        {
            wait = false;
        }

        // keep inside
        float x1 = emitter.getGlobalPosition().x;
        float y1 = emitter.getGlobalPosition().y;
        if (x1 < limit || x1 > ofGetWidth() - limit || y1 < limit || y1 > ofGetHeight() - limit)
        {
            cant_move = true;
        }
        else
            cant_move = false;

        // segment-point intersection
        angle = glm::eulerAngles(emitter.getGlobalOrientation()).z;
        glm::vec3 p1 = emitter.getGlobalPosition();
        glm::vec3 p2 = {p1.x + cos(angle + PI / 2) * 1000, p1.y + sin(angle + PI / 2) * 1000, 0};
        float segment_length = glm::distance(p1, p2);

        for (glm::vec3 g : guide)
        {
            float p1_to_guide = glm::distance(p1, g);
            float p2_to_guide = glm::distance(p2, g);
            if (p1_to_guide + p2_to_guide - segment_length < 1 && !wait && !cant_move)
            {
                step();
                wait = true;
            }
        }

        if (ofGetFrameNum() % 10 == 0 && !wait && !cant_move)
        {
            step();
            wait = true;
        }

        // polyline erease begin vertices
        if (polyline.size() > 150)
        {
            polyline.getVertices().erase(polyline.getVertices().begin());
        }
    }

    void draw()
    {
        // draw polyline normals
        float length = 30;
        float density = 400; // * polyline.getPerimeter();
        for (int i = 0; i < density; i++)
        {
            glm::vec3 point = polyline.getPointAtPercent(i / density);
            float index = polyline.getIndexAtPercent(i / density);
            glm::vec3 normal = polyline.getNormalAtIndexInterpolated(index);
            normal = glm::normalize(normal) * length;

            ofSetColor(255, 0, ofRandom(0, 255), 100);
            ofDrawLine(point - normal / 2, point + normal / 2);
        }
    }
};