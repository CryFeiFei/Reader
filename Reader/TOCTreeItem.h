#ifndef TOCTREEITEM_H
#define TOCTREEITEM_H

#include "ReadDefine.h"

class TOCTreeItem
{
public:
	explicit TOCTreeItem(TOCInfo* TOCInfo, TOCTreeItem* parentItem);
	~TOCTreeItem();

	void appendChild(TOCTreeItem* child);
	int childCount() const;
	int columnCount() const;
	int rowCount() const;
	TOCTreeItem* parentItem();

private:
	QList<TOCTreeItem*> m_childItems;
	TOCInfo* m_TOCInfo;
	TOCTreeItem* m_parentItem;
};

#endif // TOCTREEITEM_H
