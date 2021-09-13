/*
###############################################################################
#                                                                             #
# The MIT License                                                             #
#                                                                             #
# Copyright (C) 2017 by Juergen Skrotzky (JorgenVikingGod@gmail.com)          #
#               >> https://github.com/Jorgen-VikingGod                        #
#                                                                             #
# Sources: https://github.com/Jorgen-VikingGod/Qt-Frameless-Window-DarkStyle  #
#                                                                             #
###############################################################################
*/

#ifndef FRAMELESSWINDOW_H
#define FRAMELESSWINDOW_H

#include "windowdragger.h"

#include <QLabel>
#include <QToolButton>
#include <QWidget>
#include <qboxlayout.h>


class FramelessWindow : public QWidget {
  Q_OBJECT

 public:
  explicit FramelessWindow(QWidget *parent = Q_NULLPTR);
  virtual ~FramelessWindow();
  void setContent(QWidget *w);

 private:
  bool leftBorderHit(const QPoint &pos);
  bool rightBorderHit(const QPoint &pos);
  bool topBorderHit(const QPoint &pos);
  bool bottomBorderHit(const QPoint &pos);
  void styleWindow(bool bActive, bool bNoState);

 public slots:
  void setWindowTitle(const QString &text);
  void setWindowIcon(const QIcon &ico);

 private slots:
  void on_applicationStateChanged(Qt::ApplicationState state);
  void on_minimizeButton_clicked();
  void on_restoreButton_clicked();
  void on_maximizeButton_clicked();
  void on_closeButton_clicked();
  void on_windowTitlebar_doubleClicked();

 protected:
  virtual void changeEvent(QEvent *event);
  virtual void mouseDoubleClickEvent(QMouseEvent *event);
  virtual void checkBorderDragging(QMouseEvent *event);
  virtual void mousePressEvent(QMouseEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent *event);
  virtual bool eventFilter(QObject *obj, QEvent *event);

 private:
  WindowDragger *m_WindowDragger;
  QWidget *m_windowFrame;
  QVBoxLayout *m_mainLayout;
  QVBoxLayout *m_vertivalLayout;
  QHBoxLayout *m_topLayout;
  QToolButton *m_closeButton;
  QToolButton *m_maximizeButton;
  QToolButton *m_minimizeButton;
  QToolButton *m_restoreButton;
  QLabel *m_icon;
  QLabel *m_titleText;

  QRect m_StartGeometry;
  const quint8 CONST_DRAG_BORDER_SIZE = 15;
  bool m_bMousePressed;
  bool m_bDragTop;
  bool m_bDragLeft;
  bool m_bDragRight;
  bool m_bDragBottom;

private:
  void setupUi();
  void insertWidgetsIntoLayout();
};

#endif  // FRAMELESSWINDOW_H
