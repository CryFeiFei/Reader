#include "MultiViwer.h"


MultiViwer::MultiViwer(QWidget* parent) : QMdiArea(parent)
{
	setViewMode(QMdiArea::TabbedView);
}

MultiViwer::~MultiViwer()
{

}
