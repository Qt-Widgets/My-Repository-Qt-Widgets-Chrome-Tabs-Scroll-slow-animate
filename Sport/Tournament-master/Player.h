#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
  public:
    Player(const QString &m_Name);

    QString getName() const;
    void setName(const QString &value);

  private:
    QString m_Name;
};

#endif  // PLAYER_H
