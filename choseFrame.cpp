#include "choseFrame.h"
#include<QMouseEvent>

choseFrame::choseFrame(const QPixmap& screen,QWidget *parent)
	: QDialog(parent),m_image(screen)
{
	// 在paintEvent之前生效
	m_dragging = false;
	flag = 0;
	onlyOneScreen = 0;
	confirm= new confirmWidget(this);
	confirm->setWindowFlags(Qt::FramelessWindowHint);
	confirm->hide();
	setMouseTracking(true);
	setAttribute(Qt::WA_TranslucentBackground);
	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
	//showMaximized();
	showFullScreen();
	connect(confirm->returnBtnSave(), SIGNAL(clicked()), this, SLOT(SavePixmap()));
	connect(confirm->returnBtnCancel(), SIGNAL(clicked()), this, SLOT(cancelSave()));
	
}

choseFrame::~choseFrame()
{
}



void choseFrame::SavePixmap()
{
	flag = 0;
	confirm->close();
	accept();
	
}

void choseFrame::cancelSave()
{
	flag = 0;
	confirm->close();
	reject();
	
}

void choseFrame::paintEvent(QPaintEvent *event)
{
	// 先调用QT框架的画法，如果需要透明叠加要需要调用这个
	QWidget::paintEvent(event);


	int w = width(), h = height();

	// 画背景图片 
	QPainter painter(this);

	QRectF target(0, 0, width(), height());
	QRectF source(0, 0, m_image.width(), m_image.height());
	painter.drawPixmap(target, m_image, source);


	QPixmap temp_dim_pix(m_image.width(), m_image.height());
	temp_dim_pix.fill((QColor(0, 0, 0, 180)));
	QPixmap  *backgroundScreen_ =new QPixmap(m_image);
	painter.drawPixmap(0, 0,temp_dim_pix);
	

	// 画十字线
	int x = m_pos.x(), y = m_pos.y();
	//x -= 1; y -= 1;
	x += 1; y += 1;
	//qDebug("repaint: (%dx%d)", x, y);
	painter.setPen(QColor(255, 0, 0, 150));
	painter.drawLine(0, y, w, y);
	painter.drawLine(x, 0, x, h);
	painter.setPen(QColor(160, 160, 160, 150));
	painter.drawLine(0, y, w, y);
	painter.drawLine(x, 0, x, h);

	
	if (flag) {
		QRect selected;
		if (temp_start.x() < temp_end.x()) {
			if (temp_start.y() < temp_end.y()) {
				selected = QRect(temp_start, temp_end);
				m_BottomRightPoint = temp_end;
			}
			else {
				selected = QRect(temp_start.x(), temp_end.y(), temp_end.x()- temp_start.x(), temp_start.y() - temp_end.y());
				m_BottomRightPoint = QPoint(temp_end.x(), temp_start.y());
			}
		}
		else {
			if (temp_start.y() < temp_end.y()) {
				selected = QRect(temp_end.x(), temp_start.y(), temp_start.x() - temp_end.x(), temp_end.y() - temp_start.y());
				m_BottomRightPoint = QPoint(temp_start.x(), temp_end.y());
			}
			else {
				selected = QRect(temp_end.x(), temp_end.y(), temp_start.x() - temp_end.x(), temp_start.y() - temp_end.y());
				m_BottomRightPoint = temp_start;
			}
		}
		
		//QRect selected(temp_start, temp_end);
		temp_pix_white = m_image.copy(selected);
		painter.drawPixmap(selected, temp_pix_white);
	}
	if ( m_dragging&&!onlyOneScreen)
	{
		QRect selected;
		if (m_start.x() < m_pos.x()) {
			if (m_start.y() < m_pos.y()) {
				selected = QRect(m_start.x(),m_start.y(), m_pos.x()-m_start.x(), m_pos.y() - m_start.y());
			}
			else {
				selected = QRect(m_start.x(), m_pos.y(), m_pos.x() - m_start.x(), m_start.y() - m_pos.y());
			}
		}
		else {
			if (m_start.y() < m_pos.y()) {
				selected = QRect(m_pos.x(), m_start.y(), m_start.x() - m_pos.x(), m_pos.y() - m_start.y());
			}
			else {
				selected = QRect(m_pos.x(), m_pos.y(), m_start.x() - m_pos.x(), m_start.y() - m_pos.y());
			}
		}
		
		
		//QRect selected(m_start, m_pos);
		// 区域
		painter.setPen(QColor(30, 30, 30));
		painter.drawRect(selected);

		temp_pix_white = m_image.copy(selected);
		painter.drawPixmap(selected, temp_pix_white);
		// 显示文本：所选区域的大小
		QRect textRect(0, 0, 60, 18);
		textRect.moveCenter(selected.center());
		// 文本背景
		painter.setBrush(QColor(30, 30, 30));
		painter.drawRect(textRect);
		// 文本
		painter.setPen(QColor(255, 255, 255));
		char text[32];
		sprintf(text, "%dx%d", selected.width(), selected.height());
		painter.drawText(textRect, Qt::AlignCenter, text);
	}
}

void choseFrame::mouseMoveEvent(QMouseEvent * event)
{
	m_pos = event->pos();
	update();
}

void choseFrame::mousePressEvent(QMouseEvent * event)
{
	if (onlyOneScreen == 1) {
		confirm->close();
		reject();
	}
	//
	flag = 1;
	m_dragging = true;
	m_start = event->pos();
}

void choseFrame::mouseReleaseEvent(QMouseEvent * event)
{
	onlyOneScreen = 1;
	m_end = event->pos();
	m_dragging = false;
	update();
	temp_start = m_start;
	temp_end = m_end;
	
	if (m_start.x() < m_end.x()) {
		if (m_start.y() < m_end.y()) {
			selectRegion = QRect(m_start.x(), m_start.y(), m_end.x() - m_start.x(), m_end.y() - m_start.y());
		}
		else {
			selectRegion = QRect(m_start.x(), m_end.y(), m_end.x() - m_start.x(), m_start.y() - m_end.y());
		}
	}
	else {
		if (m_start.y() < m_end.y()) {
			selectRegion = QRect(m_end.x(), m_start.y(), m_start.x() - m_end.x(), m_end.y() - m_start.y());
		}
		else {
			selectRegion = QRect(m_end.x(), m_end.y(), m_start.x() - m_end.x(), m_start.y() - m_end.y());
		}
	}

	QSound::play("shutter.wav");
	//selectRegion = QRect(m_start, m_end);
	confirm->move(selectRegion.bottomRight().x()-confirm->width(), selectRegion.bottomRight().y());
	confirm->show();
}




