#ifndef DOUBLECLICKQLABEL_H
#define DOUBLECLICKQLABEL_H

#include <QLabel>


class DoubleClickQLabel : public QLabel {
    Q_OBJECT

private:
    const char type;
public:
    explicit DoubleClickQLabel(QWidget* parent = nullptr, const char type = 0);
    explicit DoubleClickQLabel(QWidget* parent = nullptr);

signals:
    void doubleClicked(char);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);
};

#endif // DOUBLECLICKQLABEL_H
