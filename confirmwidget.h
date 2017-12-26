#pragma once

#include <QWidget>
#include "ui_confirmwidget.h"
#include<QPushButton>

class confirmWidget : public QWidget
{
	Q_OBJECT

public:
	confirmWidget(QWidget *parent = Q_NULLPTR);
	~confirmWidget();
	QPushButton *returnBtnSave();
	QPushButton *returnBtnCancel();
	virtual void keyPressEvent(QKeyEvent* event);
public slots:
	void cancelClose();
private:
	Ui::confirmWidget ui;
};
