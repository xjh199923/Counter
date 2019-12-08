#ifndef OTHERFORM_H
#define OTHERFORM_H

#include <QWidget>

namespace Ui {
class otherForm;
}

class otherForm : public QWidget
{
    Q_OBJECT

public:
    explicit otherForm(QWidget *parent = nullptr);
    ~otherForm();

private:
    Ui::otherForm *ui;
};

#endif // OTHERFORM_H
