#pragma once

#include <QtWidgets/QWidget>
#include "ui_grabscreen.h"
#include<QApplication>
#include<QPixmap>
#include<QDateTime>
#include<QMessageBox>
#include<QDesktopWidget>
#include<QSystemTrayIcon>
#include<QAction>

class grabScreen : public QWidget
{
	Q_OBJECT

public:
	grabScreen(QWidget *parent = Q_NULLPTR);
	virtual void keyPressEvent(QKeyEvent* event);
	//--窗口鼠标事件，用于窗口拖动--
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	void createActions();
public slots:
	void onTrayIconClicked(QSystemTrayIcon::ActivationReason reason);
	void grabFullScreen();
	void onCapture();
	void showWidget(bool t);
	void quitWidget(bool t);
	void onMin();
	void onClose();
	
private:
	Ui::grabScreenClass ui;
	QSystemTrayIcon trayIcon;
	QAction *action_show;
	QAction *action_quit;
	//--用于窗口拖动--
	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;

};
