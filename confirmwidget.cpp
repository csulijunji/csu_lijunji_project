#include "confirmwidget.h"
#include<QKeyEvent>

confirmWidget::confirmWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	/*connect(ui.btnsave, SIGNAL(clicked()), this, SLOT(SavePixmap()));
	connect(ui.btncancel, SIGNAL(clicked()), this, SLOT(cancelSave()));*/
	connect(ui.btncancel, SIGNAL(clicked()), this, SLOT(cancelClose()));
}

confirmWidget::~confirmWidget()
{
}

QPushButton * confirmWidget::returnBtnSave()
{
	QPushButton *p = ui.btnsave;
	return p;
}

QPushButton * confirmWidget::returnBtnCancel()
{
	QPushButton *p = ui.btncancel;
	return p;
}

void confirmWidget::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Return) {
		ui.btnsave->clicked();
	}
}

void confirmWidget::cancelClose()
{
	close();
}

