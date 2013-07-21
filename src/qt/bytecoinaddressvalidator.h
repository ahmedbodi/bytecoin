#ifndef BYTECOINADDRESSVALIDATOR_H
#define BYTECOINADDRESSVALIDATOR_H

#include <QRegExpValidator>

/** Base48 entry widget validator.
   Corrects near-miss characters and refuses characters that are no part of base48.
 */
class BytecoinAddressValidator : public QValidator
{
    Q_OBJECT
public:
    explicit BytecoinAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 35;
signals:

public slots:

};

#endif // BYTECOINADDRESSVALIDATOR_H
