#include "Player.h"

Player::Player(const QString &name) { m_Name = name; }

QString Player::getName() const { return m_Name; }

void Player::setName(const QString &value) { m_Name = value; }
