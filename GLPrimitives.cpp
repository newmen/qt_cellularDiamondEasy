#include "lifeviewer.h"

void specifyCoords(const coord &center, float a, float &x, float &y, float &z, float &az) {
    x = center.X;
    y = center.Y;
    z = center.Z * .5f;
    az = a * .5f;

    if (center.Z % 4 == 3) {
        y -= .5f;
    } else if (center.Z % 4 == 2) {
//		x += .5f;
    } else if (center.Z % 4 == 1) {
        x -= .5f;
    } else {
        x -= .5f;
        y -= .5f;
    }
}

// Cube
void LifeViewer::primCube(const coord& center, float a)
{
    float x, y, z, az;
    specifyCoords(center, a, x, y, z, az);

    glBegin(GL_QUADS);
    glVertex3f(x + a, y + a, z + az);
    glVertex3f(x + a, y - a, z + az);
    glVertex3f(x - a, y - a, z + az);
    glVertex3f(x - a, y + a, z + az);

    glVertex3f(x + a, y + a, z - az);
    glVertex3f(x + a, y - a, z - az);
    glVertex3f(x - a, y - a, z - az);
    glVertex3f(x - a, y + a, z - az);

    glVertex3f(x + a, y + a, z + az);
    glVertex3f(x + a, y + a, z - az);
    glVertex3f(x + a, y - a, z - az);
    glVertex3f(x + a, y - a, z + az);

    glVertex3f(x - a, y + a, z + az);
    glVertex3f(x - a, y + a, z - az);
    glVertex3f(x - a, y - a, z - az);
    glVertex3f(x - a, y - a, z + az);

    glVertex3f(x + a, y + a, z + az);
    glVertex3f(x + a, y + a, z - az);
    glVertex3f(x - a, y + a, z - az);
    glVertex3f(x - a, y + a, z + az);

    glVertex3f(x + a, y - a, z + az);
    glVertex3f(x + a, y - a, z - az);
    glVertex3f(x - a, y - a, z - az);
    glVertex3f(x - a, y - a, z + az);
    glEnd();
}

// Cube wireframe
void LifeViewer::primCubeWF(const coord& center, float a)
{
    float x, y, z, az;
    specifyCoords(center, a, x, y, z, az);

    glBegin(GL_LINE_LOOP);
    glVertex3f(x + a, y + a, z + az);
    glVertex3f(x + a, y + a, z - az);
    glVertex3f(x + a, y - a, z - az);
    glVertex3f(x + a, y - a, z + az);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3f(x - a, y + a, z + az);
    glVertex3f(x - a, y + a, z - az);
    glVertex3f(x - a, y - a, z - az);
    glVertex3f(x - a, y - a, z + az);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(x + a, y + a, z + az);
    glVertex3f(x - a, y + a, z + az);
    glVertex3f(x + a, y + a, z - az);
    glVertex3f(x - a, y + a, z - az);
    glVertex3f(x + a, y - a, z - az);
    glVertex3f(x - a, y - a, z - az);
    glVertex3f(x + a, y - a, z + az);
    glVertex3f(x - a, y - a, z + az);
    glEnd();
}

void LifeViewer::primCubeWF(const coord& p1, const coord& p2)
{
    glBegin(GL_LINE_LOOP);
    glVertex3i(p1.X, p1.Y, p1.Z);
    glVertex3i(p2.X, p1.Y, p1.Z);
    glVertex3i(p2.X, p2.Y, p1.Z);
    glVertex3i(p1.X, p2.Y, p1.Z);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3i(p1.X, p1.Y, p2.Z);
    glVertex3i(p2.X, p1.Y, p2.Z);
    glVertex3i(p2.X, p2.Y, p2.Z);
    glVertex3i(p1.X, p2.Y, p2.Z);
    glEnd();
    glBegin(GL_LINES);
    glVertex3i(p1.X, p1.Y, p1.Z);
    glVertex3i(p1.X, p1.Y, p2.Z);
    glVertex3i(p2.X, p1.Y, p1.Z);
    glVertex3i(p2.X, p1.Y, p2.Z);
    glVertex3i(p2.X, p2.Y, p1.Z);
    glVertex3i(p2.X, p2.Y, p2.Z);
    glVertex3i(p1.X, p2.Y, p1.Z);
    glVertex3i(p1.X, p2.Y, p2.Z);
    glEnd();
}
