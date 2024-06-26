 /****************************************************************************
 **
 ** Copyright (C) 2004-2008 Trolltech ASA. All rights reserved.
 **
 ** This file is part of the documentation of the Qt Toolkit.
 **
 ** This file may be used under the terms of the GNU General Public
** License versions 2.0 or 3.0 as published by the Free Software
** Foundation and appearing in the files LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file.  Alternatively you may (at
** your option) use any later version of the GNU General Public
** License if such license has been publicly approved by Trolltech ASA
** (or its successors, if any) and the KDE Free Qt Foundation. In
** addition, as a special exception, Trolltech gives you certain
** additional rights. These rights are described in the Trolltech GPL
** Exception version 1.2, which can be found at
** http://www.trolltech.com/products/qt/gplexception/ and in the file
** GPL_EXCEPTION.txt in this package.
**
** Please review the following information to ensure GNU General
** Public Licensing requirements will be met:
** http://trolltech.com/products/qt/licenses/licensing/opensource/. If
** you are unsure which license is appropriate for your use, please
** review the following information:
** http://trolltech.com/products/qt/licenses/licensing/licensingoverview
** or contact the sales department at sales@trolltech.com.
**
** In addition, as a special exception, Trolltech, as the sole
** copyright holder for Qt Designer, grants users of the Qt/Eclipse
** Integration plug-in the right for the Qt/Eclipse Integration to
** link to functionality provided by Qt Designer and its related
** libraries.
**
** This file is provided "AS IS" with NO WARRANTY OF ANY KIND,
** INCLUDING THE WARRANTIES OF DESIGN, MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE. Trolltech reserves all rights not expressly
** granted herein.
 **
 ** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 ** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 **
 ****************************************************************************/

 #ifndef PIEVIEW_H
 #define PIEVIEW_H

 #include <QAbstractItemView>
 #include <QFont>
 #include <QItemSelection>
 #include <QItemSelectionModel>
 //#include <QModelIndex>
 //#include <QRect>
 //#include <QSize>
 //#include <QPoint>
 #include <QWidget>
 #include <QScrollBar>

 class QRubberBand;

 class PieView : public QAbstractItemView
 {
     Q_OBJECT

 public:
     PieView(QWidget *parent = 0);

     QRect visualRect(const QModelIndex &index) const;
     void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
     QModelIndex indexAt(const QPoint &point) const;

 protected slots:
     void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight);
     void rowsInserted(const QModelIndex &parent, int start, int end);
     void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end);

 protected:
     bool edit(const QModelIndex &index, EditTrigger trigger, QEvent *event);
     QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,
                            Qt::KeyboardModifiers modifiers);

     int horizontalOffset() const;
     int verticalOffset() const;

     bool isIndexHidden(const QModelIndex &index) const;

     void setSelection(const QRect&, QItemSelectionModel::SelectionFlags command);

     void mousePressEvent(QMouseEvent *event);

     void mouseMoveEvent(QMouseEvent *event);
     void mouseReleaseEvent(QMouseEvent *event);

     void paintEvent(QPaintEvent *event);
     void resizeEvent(QResizeEvent *event);
     void scrollContentsBy(int dx, int dy);

     QRegion visualRegionForSelection(const QItemSelection &selection) const;

 private:
     QRect itemRect(const QModelIndex &item) const;
     QRegion itemRegion(const QModelIndex &index) const;
     int rows(const QModelIndex &index = QModelIndex()) const;
     void updateGeometries();

     int margin;
     int totalSize;
     int pieSize;
     int validItems;
     double totalValue;
     QPoint origin;
     QRubberBand *rubberBand;
 };

 #endif
