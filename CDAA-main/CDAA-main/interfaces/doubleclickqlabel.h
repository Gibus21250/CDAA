#ifndef DOUBLECLICKQLABEL_H
#define DOUBLECLICKQLABEL_H

#include <QLabel>


class DoubleClickQLabel : public QLabel {
    Q_OBJECT

private:
    const char type;
public:
    /**
     * @brief QLabel special qui emet un signal double clique
     * @param parent
     * @param type : (0 = nom, 1 = prenom, 2 = tel, 3 = mail, 4 = entreprise, 5 = photo)
     */
    explicit DoubleClickQLabel(QWidget* parent = nullptr, const char type = 0);
    explicit DoubleClickQLabel(QWidget* parent = nullptr);

signals:
    /**
     * @brief Signal emit lors du double clique sur ce QLabel
     * @param c
     */
    void doubleClicked(char c);

protected:
    /**
     * @brief Redifinition de l'evennement double clique, emettant un signal receptionnable
     * @param event 
     */
    void mouseDoubleClickEvent(QMouseEvent* event);
};

#endif // DOUBLECLICKQLABEL_H
