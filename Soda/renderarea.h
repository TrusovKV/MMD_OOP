#ifndef RENDERAREA_H
#define RENDERAREA_H
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QFrame>
#include <QVector>
#include <QSharedPointer>

class renderArea :
      public QFrame
{
        Q_OBJECT
public:
    explicit renderArea(QWidget *parent = nullptr);
    renderArea(renderArea const&) = delete;
    renderArea(renderArea&&) = delete;
    renderArea& operator=(renderArea const&) = delete;
    renderArea& operator=(renderArea&&) = delete;
    virtual ~renderArea() override {}

};

#endif // RENDERAREA_H
