#include "problem.h"

problem::problem(QObject *parent) : QObject(parent)
{
    std::srand((unsigned)time(NULL));
}
