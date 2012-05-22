#ifndef LIFEVIEWER_H
#define LIFEVIEWER_H

#include <QGLViewer/qglviewer.h>
#include <QHash>
#include "common.h"

class LifeViewer : public QGLViewer
{
Q_OBJECT
public:
    explicit LifeViewer(QWidget *parent = 0) : QGLViewer(parent), _animationDirection(1)
    {
        parent_ = parent;
        setSnapshotFormat("PNG");
        drawingMode_ = BCUBES;
        textShown_ = false;
        color0_.setRgbF(0.f, 0.f, 0.f, .5f);

        default_colors_[1].setRgbF(.45f, .45f, .45f, 0.f); // серый
        default_colors_[2].setRgbF(1.f, .96f, .1f, 0.f); // жёлтый
        default_colors_[3].setRgbF(.4f, .9f, .4f, 0.f); // зелёный
        default_colors_[4].setRgbF(.9f, .6f, .6f, 0.f); // розовый
        default_colors_[5].setRgbF(0.f, .8f, 1.f, 0.f); // голубой
        default_colors_[6].setRgbF(1.f, .2f, .2f, 0.f); // красный
        default_colors_[7].setRgbF(.2f, .2f, 0.9f, 0.f); // синий
        default_colors_[8].setRgbF(1.f, .66f, 0.f, 0.f); // оранжевый
    }
    ~LifeViewer() { }

    int frameMax()
    {
    	return data_.size()-1;
    }

    void setColor(int w, QColor color)
    {
    	colors_[w] = color;
    	repaint();
    }
    void setDefColor(QColor color)
    {
    	color0_ = color;
    	repaint();
    }
    QColor getColor(int w)
    {
    	return colors_.value(w, default_colors_.value(w, color0_));
    }
    QColor getDefColor() {
    	return color0_;
    }
    QHash<int,QColor> getColors() {return QHash<int,QColor>(colors_);}

    static const int POINTS = 0;
    static const int CUBES = 1;
    static const int BCUBES = 2;
    static const int WCUBES = 3;


protected:
    virtual void draw();
    virtual void init();
    virtual void animate();
    virtual QString helpString() const;

signals:
    void frameChanged(int);
    void frameMaxChanged(int);

public slots:
    void startReverseAnimation();

    void nextFrame()
    {
    	gotoFrame(curFrame_+1);
    }
    void prevFrame()
    {
    	gotoFrame(curFrame_-1);
    }
    void gotoFrame( int );
    void loadData();
    void setShowText( bool textShown )
    {
    	textShown_ = textShown;
    	repaint();
    }
    void setDrawingMode( int drawingMode )
    {
    	drawingMode_ = drawingMode;
    	repaint();
    }

private:
    frames data_;
    int curFrame_;
    bool textShown_, coloring_;
    QColor color0_;
    QString filename_;
    QWidget *parent_;
    QHash<int,QColor> colors_;
    QHash<int,QColor> default_colors_;
    int drawingMode_;
    coord cmin, cmax;

    int _animationDirection;

    void setRadiusAndCenter();
    void loadFromFile(QString file);
    // GL Primitives
    // Implemented in 'GLPrimitives.cpp'
    void primCube(const coord& center, float a);  //Cube
    void primCubeWF(const coord& center, float a);     // Cube wireframe
    void primCubeWF(const coord& p1, const coord& p2);     // Cube wireframe
};

#endif // LIFEVIEWER_H
