#include <QtGui>
#include "iconeditor.h"

IconEditor::IconEditor(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    curcolor = Qt::black;
    zoom = 8;
    image = QImage(16, 16, QImage::Format_ARGB32);
    image.fill(qRgba(0,0,0,0));
}

QSize IconEditor::sizeHint() const
{
    QSize size = zoom * image.size();
    if (zoom >=3)
        size += QSize(1,1);
    return size;
}

void IconEditor::SetPenColor(const QColor &newcolor)
{
    curcolor = newcolor;
}

void IconEditor::SetIconImage(const QImage &newimage)
{
    if (newimage != image)
    {
        image = newimage.convertToFormat(QImage::Format_ARGB32);
        update();
        updateGeometry();
    }
}

void IconEditor::SetZoomFactor(int newzoom)
{
    if (newzoom < 1) newzoom = 1;
    if (newzoom !=zoom)
    {
        zoom = newzoom;
        update();
        updateGeometry();
    }
}

void IconEditor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (zoom>=3)
    {
        painter.setPen(palette().foreground().color());
        for(int i=0;i<=image.width();++i)
            painter.drawLine(zoom * i,0,zoom *i, zoom * image.height());
        for(int j=0;j<=image.height();++j)
            painter.drawLine(0,zoom * j, zoom * image.width(), zoom*j);
    }
    for(int i = 0; i< image.width();++i)
        for (int j =0; i< image.height();++j)
        {
            QRect rect = PixelRect(i,j);
            if (!event->region().intersects(rect))
            {
                QColor color = QColor::fromRgba(image.pixel(i,j));
                if (color.alpha() <255) painter.fillRect(rect,Qt::white);
                painter.fillRect(rect,color);
            }
        }
}

QRect IconEditor::PixelRect(int i, int j) const
{
    if (zoom >= 3) return QRect(zoom *i +1, zoom*j+1, zoom-1, zoom-1);
    else return QRect(zoom *i, zoom*j, zoom, zoom);
}

void IconEditor::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) SetImagePixel(event->pos(), true);
    else if (event->button() == Qt::RightButton ) SetImagePixel(event->pos(), false);        
}

void IconEditor::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) SetImagePixel(event->pos(), true);
    else if (event->buttons() & Qt::RightButton) SetImagePixel(event->pos(), false);
}

void IconEditor::SetImagePixel(const QPoint &pos, bool opaque)
{
    int i = pos.x()/zoom;
    int j = pos.y()/zoom;
    if (image.rect().contains(i,j))
    {
        if (opaque)image.setPixel(i,j,PenColor().rgba());
        else image.setPixel(i,j,qRgba(0,0,0,0));
        update(PixelRect(i,j));
    }
}

