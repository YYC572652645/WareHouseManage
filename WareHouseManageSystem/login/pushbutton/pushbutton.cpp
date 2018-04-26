#include "pushbutton.h"

PushButton::PushButton(QWidget *parent, int type) : QPushButton(parent), type(0)
{
    this->type = type;
}

void PushButton::mousePressEvent(QMouseEvent *event)
{
    emit clicked(type);
}
