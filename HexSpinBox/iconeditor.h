#ifndef ICONEDITOR_H
#define ICONEDITOR_H

#include <QColor>
#include <QImage>
#include <QWidget>
#include <QPoint>

class IconEditor :public QWidget
{
  Q_OBJECT
    Q_PROPERTY(QColor PenColor READ PenColor WRITE SetPenColor )
    Q_PROPERTY(QImage IconImage READ IconImage WRITE SetIconImage )
    Q_PROPERTY(int ZoomFactor READ ZoomFactor WRITE SetZoomFactor )
public:
    IconEditor(QWidget * parent = 0);
    void SetPenColor(const QColor &newcolor);
    QColor PenColor() const {return curcolor;}
    void SetZoomFactor(int newzoom);
    int ZoomFactor() const {return zoom;}
    void SetIconImage (const QImage &newimage);
    QImage IconImage () const {return image;}
    QSize sizeHint()const;
protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
private:
    void SetImagePixel(const QPoint &pos, bool opaque);
    QRect PixelRect(int i, int j) const;
    QColor curcolor;
    QImage image;
    int zoom;
};

#endif // ICONEDITOR_H
