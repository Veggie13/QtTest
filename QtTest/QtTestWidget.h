#pragma once

#include "linkage.h"
#include <QtWidgets/QWidget>
#include "generated/QtTestWidget.uih"


class QTTEST_LNKG QtTestWidget
    : public QWidget
    , private QT_PREPEND_NAMESPACE(Ui_QtTestWidget)
{
public:
    QtTestWidget(QWidget* parent = NULL, Qt::WindowFlags = 0);
    virtual ~QtTestWidget() {}

protected:
    virtual void showEvent(QShowEvent*);
};
