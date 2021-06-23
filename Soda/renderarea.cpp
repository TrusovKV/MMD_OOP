#include "renderArea.h"


renderArea::renderArea(QWidget* parent) :
    QFrame(parent)
{
    QPalette pl;

    this->setAutoFillBackground(true);
    this->setPalette(pl);
}

void renderArea::setAxes(Axis const& x, Axis const& y)
{
    axis_x = x;
    axis_y = y;
}

void renderArea::renderAxes()
{

    if (!axis_x.isValid() || !axis_y.isValid())
        return;


    QPainter painter(this);

    qreal c_x = this->width() / 2;
    qreal c_y = this->height() / 2;

    qreal step_x = (2 * c_x) / axis_x.getNumberDivisions();
    qreal step_y = (2 * c_y) / axis_y.getNumberDivisions();

    painter.translate(c_x, c_y);
    painter.setPen(QPen(Qt::black, Qt::DashLine));
    painter.drawLine(-c_x, 0, c_x, 0);
    painter.drawLine(0, -c_y, 0, c_y);
    painter.setFont(QFont("Arial", -1, -1, false));
    QRectF rect(0., 0., 20., 20.);
    painter.drawText(rect, Qt::AlignCenter, "0");

    int number = 1;
    for (qreal x = step_x; x <= c_x; x += step_x, ++number)
    {
        painter.setPen(QPen(Qt::gray, Qt::SolidLine));
        painter.drawLine(x, -c_y, x, c_y);
        painter.drawLine(-x, -c_y, -x, c_y);
        painter.setPen(QPen(Qt::black, Qt::SolidLine));
        QRectF rect1(x, 0., 20., 20.), rect2(-x, 0., 20., 20.);
        painter.drawText(rect1, Qt::AlignCenter, QString::number(number));
        painter.drawText(rect2, Qt::AlignCenter, QString::number(-number));
    }
    number = 1;
    for (qreal y = step_y; y <= c_y; y += step_y, ++number)
    {
        painter.setPen(QPen(Qt::gray, Qt::SolidLine));
        painter.drawLine(-c_x, y, c_x, y);
        painter.drawLine(-c_x, -y, c_x, -y);

        painter.setPen(QPen(Qt::black, Qt::SolidLine));
        QRectF rect1(0., y, 20., 20.), rect2(0., -y, 20., 20.);
        painter.drawText(rect1, Qt::AlignCenter, QString::number(-number));
        painter.drawText(rect2, Qt::AlignCenter, QString::number(number));
    }
    painter.setPen(QPen(Qt::darkBlue, Qt::SolidLine));
    QRectF rect_x(c_x - 20., -20., 20., 20.);
    QRectF rect_y(-20., -c_y, 20., 20.);
    painter.drawText(rect_x, Qt::AlignCenter, axis_x.getLabel());
    painter.drawText(rect_y, Qt::AlignCenter, axis_y.getLabel());
}
// calculating and plotting data
void renderArea::setGraphPoints(QVector<QPointF> const & points)
{
    graphPoints = points;
    update();
}

void renderArea::renderGraph()
{
    if (!axis_x.isValid() || !axis_y.isValid())
        return;

    QPainter painter(this);
    double c_x = this->width() / 2;
    double c_y = this->height() / 2;
    painter.translate(c_x, c_y);
    painter.rotate(180.);
    painter.setPen(QPen(Qt::red, Qt::DashLine));
    double dx = (2 * c_x) / axis_x.getNumberDivisions();
    double dy = (2 * c_y) / axis_y.getNumberDivisions();
    if (graphPoints.size() > 1)
    {
        size_t size = graphPoints.size();
        for (size_t i = 1; i < size; ++i)
            painter.drawLine(-graphPoints[i - 1].x()*dx, graphPoints[i - 1].y()*dy,
                                -graphPoints[i].x()*dx, graphPoints[i].y()*dy);
    }
}

void renderArea::paintEvent(QPaintEvent* event)
{
    renderAxes();
    renderGraph();
}
