#include "ChildViewer.h"

ChildViewer::ChildViewer(IMainViewer* iMainViewer) : m_IMainViewer(iMainViewer),m_docstate(SINGLE_CONTINUOUS),
	m_dCurDocMultiple(1)
{
	// 为了使关闭窗口时都关闭
	setAttribute(Qt::WA_DeleteOnClose);
	m_strFileName = m_IMainViewer->getFileName();

	m_splitterMain = new QSplitter(Qt::Horizontal, this);
	m_ViewModel = new ViewModel(this);

	m_navigationBar = new NaviViewer(this);
	m_pDocWidget = new DocWidget(this);

	m_splitterMain->addWidget(m_navigationBar);
	m_splitterMain->addWidget(m_pDocWidget);
	m_splitterMain->setStretchFactor(1,1);
	m_splitterMain->setAutoFillBackground(true);
	m_splitterMain->show();

	//绑定主界面工具栏
	m_pDocWidgetScrollBar =  m_pDocWidget->getScrollArea()->verticalScrollBar();
	connect(m_pDocWidgetScrollBar, SIGNAL(valueChanged(int)), this, SLOT(lineEditChange()));

}

//恶心，用布局重新写
void ChildViewer::resizeEvent(QResizeEvent *event)
{
	m_splitterMain->resize(this->size());
}

void ChildViewer::CreatNavigationBar()
{

}

ChildViewer::~ChildViewer()
{

}

void ChildViewer::RefreshWindow()
{
	m_pDocWidget->RefreshWindow();
 //   m_pDocWidget->paintEvent(NULL);
//    m_ViewModel->RefreshWindow();
}

void ChildViewer::InitOutline()
{

}

void ChildViewer::InitThumbnail()
{

}

void ChildViewer::InitSemantic()
{

}

void ChildViewer::ZoomIn()
{
	m_dCurDocMultiple += 0.25;
	m_dCurDocMultiple = m_dCurDocMultiple > 2 ? 2 : m_dCurDocMultiple;
	m_ViewModel->SetDocMultiple(m_dCurDocMultiple);
}

void ChildViewer::ZoomOut()
{
	m_dCurDocMultiple -= 0.25;
	m_dCurDocMultiple = m_dCurDocMultiple < 0.25 ? 0.25 : m_dCurDocMultiple;
	m_ViewModel->SetDocMultiple(m_dCurDocMultiple);
//    RefreshWindow();
}

void ChildViewer::ZoomReset()
{
	m_dCurDocMultiple = 1;
	m_ViewModel->SetDocMultiple(1);
//    RefreshWindow();
}

void ChildViewer::PreviousPage()
{
	int nPageNum = getCurPageNum();
	int nCurPageNum = (nPageNum == 0) ? 0 : (nPageNum - 1);
	m_ViewModel->GotoPage(nCurPageNum);
}

void ChildViewer::NextPage()
{
	int nPageNum = getCurPageNum();
	int nPageCount = getPageCount();
	int nCurPageNum = (nPageNum == nPageCount) ? nPageCount : (nPageNum + 1);
	m_ViewModel->GotoPage(nCurPageNum);
}

void ChildViewer::lineEditChange()
{
	int nPageNum = getCurPageNum() + 1;
	QLineEdit* lineEdit = m_IMainViewer->getPageNumLineEdit();
	QString strPageNum = QString::number(nPageNum);
	lineEdit->setText(strPageNum);
}


