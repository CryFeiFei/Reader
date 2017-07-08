#include "TOCTreeItem.h"

TOCTreeItem::TOCTreeItem(TOCInfo* TOCInfo, TOCTreeItem* parentItem): m_TOCInfo(TOCInfo), m_parentItem(parentItem)
{

}

TOCTreeItem::~TOCTreeItem()
{

}

void TOCTreeItem::appendChild(TOCTreeItem *child)
{

}

int TOCTreeItem::childCount() const
{
	return 0;
}

int TOCTreeItem::columnCount() const
{
	return 0;
}

int TOCTreeItem::rowCount() const
{
	return 0;
}

TOCTreeItem* TOCTreeItem::parentItem()
{
	return NULL;
}

