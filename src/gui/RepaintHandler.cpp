#include "RepaintHandler.h"

#include "PageView.h"
#include "XournalView.h"

#include "widgets/XournalWidget.h"

RepaintHandler::RepaintHandler(XournalView* xournal)
{
	XOJ_INIT_TYPE(RepaintHandler);

	this->xournal = xournal;
}

RepaintHandler::~RepaintHandler()
{
	XOJ_CHECK_TYPE(RepaintHandler);

	this->xournal = NULL;

	XOJ_RELEASE_TYPE(RepaintHandler);
}

void RepaintHandler::repaintPage(PageView* view)
{
	XOJ_CHECK_TYPE(RepaintHandler);

	int x1 = view->getX();
	int y1 = view->getY();
	int x2 = x1 + view->getDisplayWidth();
	int y2 = y1 + view->getDisplayHeight();
	gtk_xournal_repaint_area(this->xournal->getWidget(), x1, y1, x2, y2);
}

void RepaintHandler::repaintPageArea(PageView* view, int x1, int y1, int x2, int y2)
{
	XOJ_CHECK_TYPE(RepaintHandler);

	int x = view->getX();
	int y = view->getY();
	gtk_xournal_repaint_area(this->xournal->getWidget(), x + x1, y + y1, x + x2, y + y2);
}

void RepaintHandler::repaintPageBorder(PageView* view)
{
	XOJ_CHECK_TYPE(RepaintHandler);

	gtk_widget_queue_draw(this->xournal->getWidget());
}
