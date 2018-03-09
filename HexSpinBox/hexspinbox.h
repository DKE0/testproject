#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H
#include <QSpinBox>
#include <QRegExpValidator>


class HexSpinBox: public QSpinBox
{
    Q_OBJECT
public:
    HexSpinBox( QWidget * parent = 0 );
protected:
    QValidator::State validate(QString &input, int &pos) const;
    int valueFromText(const QString &text) const;
    QString textFromValue(int val) const;

private:
    QRegExpValidator * validator;
};

#endif // HEXSPINBOX_H
