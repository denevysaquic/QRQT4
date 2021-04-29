#ifndef MYQRCODE_H
#define MYQRCODE_H

#include <QObject>

#include <QPrinter>
#include <QPainter>
#include "qrlib/QrCode.hpp"

class MyQRCode : public QObject
{
    Q_OBJECT
public:
    explicit MyQRCode(QObject *parent = nullptr);
    void paintQR(QPainter &painter, QPoint point,const QSize sz, const QString &data, QColor fg);

signals:

public slots:
};

#endif // MYQRCODE_H
