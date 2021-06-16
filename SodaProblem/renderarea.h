#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QFrame>
#include <QVector>
#include <QSharedPointer>
//Other

class renderArea :
    public QFrame
{
    Q_OBJECT
private:
    bool flag;
public:
    void getFlag(bool flg) {flag = flg;}


    class Axis
    {
    public:
        Axis() :
            valid(false)
        {}
        Axis(QString const& label_, int nd_ = 10) :
            label(label_),
            number_divisions(nd_),
            valid(true)
        {}
        Axis(Axis const& r) :
            label(r.label),
            number_divisions(r.number_divisions),
            valid(r.valid)
        {}
        Axis(Axis&& r) :
            label(std::move(r.label))
        {
            std::swap(number_divisions, r.number_divisions);
            std::swap(valid, r.valid);
        }
        Axis& operator=(Axis const& r)
        {
            label = r.label;
            number_divisions = r.number_divisions;
            valid = r.valid;

            return *this;
        }
        Axis& operator=(Axis&& r)
        {
            label = std::move(r.label);
            std::swap(number_divisions, r.number_divisions);
            std::swap(valid, r.valid);

            return *this;
        }
        ~Axis() {}
        QString getLabel() { return label; }
        qreal getNumberDivisions() { return number_divisions; }

        bool isValid() { return valid; }

    private:
        QString label;
        int number_divisions;
        bool valid;
    };


    explicit renderArea(QWidget *parent = nullptr);

    renderArea(renderArea const&) = delete;
    renderArea(renderArea&&) = delete;
    renderArea& operator=(renderArea const&) = delete;
    renderArea& operator=(renderArea&&) = delete;
    virtual ~renderArea() override {}

    void setAxes(Axis const& x, Axis const& y);
    void setGraphPoints(QVector<QPointF> const& points);


public slots:

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void renderAxes();
    void renderGraph();

private:
    Axis axis_x;
    Axis axis_y;
    QVector<QPointF> graphPoints;
};
