#include "grabscreen.h"
#include<choseFrame.h>
#include<QClipboard>
#include<QMimeData>
#include<QTimer>
#include<QKeyEvent>
#include<QDebug>
#include<QScreen>

grabScreen::grabScreen(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	//this->move(0, 0);
	connect(ui.btnGrabWindow, SIGNAL(clicked()), this, SLOT(onCapture()));
	connect(ui.btnclose, SIGNAL(clicked()), this, SLOT(onClose()));
	connect(ui.btnmin, SIGNAL(clicked()), this, SLOT(onMin()));

	QIcon icon(":/grabScreen/Resources/screen.png");
	trayIcon.setIcon(icon);
	trayIcon.setToolTip(QStringLiteral("截屏"));
	this->setFocusPolicy(Qt::StrongFocus);
	this->setFocus();
	if (trayIcon.isSystemTrayAvailable()) {
		qDebug("trayicon great....");
	}
	connect(&trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(onTrayIconClicked(QSystemTrayIcon::ActivationReason)));
	/*connect(action_show, SIGNAL(triggered(bool)), this, SIGNAL(showWidget()));
	connect(action_quit, SIGNAL(triggered(bool)), this, SIGNAL(quitWidget()));*/

	this->onMin();
}

//事件：响应鼠标在控件上按下的事件
void grabScreen::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();
	this->mousePos = event->globalPos();
	this->dPos = mousePos - windowPos;
}

//事件：响应鼠标在控件上移动的事件，一般是鼠标按下后移动的事件
void grabScreen::mouseMoveEvent(QMouseEvent *event)
{
	this->move(event->globalPos() - this->dPos);
}

void grabScreen::keyPressEvent(QKeyEvent* event)
{
	if (event->modifiers() == (Qt::AltModifier | Qt::ControlModifier) &&event->key() == Qt::Key_A) {
		ui.btnGrabWindow->clicked(true);
	}
}

void grabScreen::createActions()
{
	QIcon icon(":/grabScreen/Resources/screen.png");
	trayIcon.setIcon(icon);
	trayIcon.setToolTip(QStringLiteral("截屏"));

	//创建托盘项
	action_show = new QAction(this);
	action_quit = new QAction(this);   //修改工具fsaf
	

	////设置托盘项图标
	//action_show->setIcon(QIcon(":/icon/open"));
	//action_quit->setIcon(QIcon(":/icon/quit"));

	//设置托盘想文本
	action_show->setText(QStringLiteral("显示"));
	action_quit->setText(QStringLiteral("退出"));
	

	//添加菜单项
	this->addAction(action_show);
	this->addAction(action_quit);
	
}

void grabScreen::onTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		//单击
	case QSystemTrayIcon::Trigger:
		//恢复窗口显示
		this->setWindowState(Qt::WindowActive);
		this->setWindowOpacity(1.0);
		this->show();
		trayIcon.hide();

		showNormal();
		raise();
		activateWindow();
		break;
		//双击
	case QSystemTrayIcon::DoubleClick:
		break;
	default:
		break;
	}
}

void grabScreen::grabFullScreen()
{
	QScreen *screen = QGuiApplication::primaryScreen();
	QString fileName;
	QPixmap pix, region,pic;
	pix = screen->grabWindow(QApplication::desktop()->winId());

	choseFrame frm(pix,this);
	if (QDialog::Accepted == frm.exec())
	{
		//QPixmap pix_g = QPixmap::grabWindow(QApplication::desktop()->winId());
		region = pix.copy(frm.selectRegion);
		
	}

	this->showNormal();

	fileName = QDateTime::currentDateTime().toString("yyyy-MM-ddHH-mm-ss") + ".png";//通过时间命名文件


	QClipboard *cb = QApplication::clipboard();
	QMimeData *data = new QMimeData;
	

	if (region.isNull())
	{
		QMessageBox::information(this, "Error", QStringLiteral("截屏失败 !"), QMessageBox::Ok);

	}
	else
	{
		data->setImageData(region);
		cb->setMimeData(data, QClipboard::Clipboard);
		//region.save("../../screen/" + fileName, "PNG");
		if (!region.save("../screen/" + fileName, "PNG")) //das
		{
			QMessageBox::information(this, "Right", QStringLiteral("保存错误 !"), QMessageBox::Ok);

		}
		else
		{
			QMessageBox::information(this, "Grab", QStringLiteral("已复制到剪贴板\n保存成功!"), QMessageBox::Ok);

		}
	}
}

void grabScreen::onCapture()
{
	// 令本窗口隐藏
	this->hide();

	// 隐藏本窗口需要一定时间，故延时一段时间后才开始截图
	QTimer::singleShot(300, this, SLOT(grabFullScreen()));

}

void grabScreen::showWidget(bool t)
{
	this->show();
}

void grabScreen::quitWidget(bool t)
{
	this->close();
}

void grabScreen::onMin()
{
	//this->hide();
	this->setWindowOpacity(0.0);
	this->setFocus();
	trayIcon.show();
}

void grabScreen::onClose()
{
	this->setFocus();
	this->close();
}

