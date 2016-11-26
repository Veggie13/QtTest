#include <QtGui/QShowEvent>
#include "QtTestWidget.h"


QtTestWidget::QtTestWidget(QWidget* parent, Qt::WindowFlags f)
    : QWidget(parent, f)
{
    setupUi(this);
}

void QtTestWidget::showEvent(QShowEvent* e)
{
}
