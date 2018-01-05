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
	trayIcon.setToolTip(QStringLiteral("����"));
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

//�¼�����Ӧ����ڿؼ��ϰ��µ��¼�
void grabScreen::mousePressEvent(QMouseEvent *event)
{
	this->windowPos = this->pos();
	this->mousePos = event->globalPos();
	this->dPos = mousePos - windowPos;
}

//�¼�����Ӧ����ڿؼ����ƶ����¼���һ������갴�º��ƶ����¼�
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
	trayIcon.setToolTip(QStringLiteral("����"));

	//����������
	action_show = new QAction(this);
	action_quit = new QAction(this);   //�޸Ĺ���fsaf
	

	////����������ͼ��
	//action_show->setIcon(QIcon(":/icon/open"));
	//action_quit->setIcon(QIcon(":/icon/quit"));

	//�����������ı�
	action_show->setText(QStringLiteral("��ʾ"));
	action_quit->setText(QStringLiteral("�˳�"));
	

	//��Ӳ˵���
	this->addAction(action_show);
	this->addAction(action_quit);
	
}

void grabScreen::onTrayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason)
	{
		//����
	case QSystemTrayIcon::Trigger:
		//�ָ�������ʾ
		this->setWindowState(Qt::WindowActive);
		this->setWindowOpacity(1.0);
		this->show();
		trayIcon.hide();

		showNormal();
		raise();
		activateWindow();
		break;
		//˫��
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

	fileName = QDateTime::currentDateTime().toString("yyyy-MM-ddHH-mm-ss") + ".png";//ͨ��ʱ�������ļ�


	QClipboard *cb = QApplication::clipboard();
	QMimeData *data = new QMimeData;
	

	if (region.isNull())
	{
		QMessageBox::information(this, "Error", QStringLiteral("����ʧ�� !"), QMessageBox::Ok);

	}
	else
	{
		data->setImageData(region);
		cb->setMimeData(data, QClipboard::Clipboard);
		//region.save("../../screen/" + fileName, "PNG");
		if (!region.save("../screen/" + fileName, "PNG")) //das
		{
			QMessageBox::information(this, "Right", QStringLiteral("������� !"), QMessageBox::Ok);

		}
		else
		{
			QMessageBox::information(this, "Grab", QStringLiteral("�Ѹ��Ƶ�������\n����ɹ�!"), QMessageBox::Ok);

		}
	}
}

void grabScreen::onCapture()
{
	// ���������
	this->hide();

	// ���ر�������Ҫһ��ʱ�䣬����ʱһ��ʱ���ſ�ʼ��ͼ
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

