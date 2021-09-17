#ifndef ADDPLAYERWIDGET_H
#define ADDPLAYERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QList>
#include <QLineEdit>

class AddPlayerWidget : public QWidget
{
    Q_OBJECT
  public:
    explicit AddPlayerWidget(QWidget *parent = nullptr);
    void addPlayerLineEdit(const QString &name = "");
    void removePlayerLineEdit();
    void randomise(QList< QString > players);
    QList< QString > getPlayerNames();


  signals:

  private:
    QVBoxLayout *layout = Q_NULLPTR;
    QList< QLineEdit * > lineEdits;

    void removeAll();
};

#endif  // ADDPLAYERWIDGET_H
