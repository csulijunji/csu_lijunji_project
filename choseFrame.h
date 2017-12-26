#pragma once

#include <QDialog>
#include<QPainter>
#include<QSound>
#include<QPoint>
#include"confirmwidget.h"

class choseFrame : public QDialog
{
	Q_OBJECT

public:
	choseFrame(const QPixmap& screen,QWidget *parent);
	~choseFrame();
	/*QPoint FindBigRectBottomPoint();*/

public slots:
	void SavePixmap();
	void cancelSave();
private:
	virtual void paintEvent(QPaintEvent *event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	
private:
	QPixmap m_image;
	QPoint m_start, m_end;
	QPoint temp_start, temp_end;
	QPoint m_pos;

	QPoint m_BottomRightPoint;
	bool m_dragging;
	confirmWidget *confirm;
	QPixmap temp_pix_white;
	bool flag;//控制白底图片的显示
	bool onlyOneScreen;
public:
	QRect selectRegion; // 输出选中的区域
};

