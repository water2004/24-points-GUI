#ifndef PROBLEM_H
#define PROBLEM_H

#include <QObject>

class problem : public QObject
{
    Q_OBJECT
public:
    explicit problem(QObject *parent = nullptr);

signals:

};

#endif // PROBLEM_H
