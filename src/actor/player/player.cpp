//
// Created by Administrator on 2026/8/19.
//

#include "player.h"
void Player::begin_play() {}
void Player::tick() {}
void Player::end_play() {}

void Player::move(const Vector2 vec) {
  const float x = _location.x + vec.x * speed;
  const float y = _location.y + vec.y * speed;
  _location = Vector2(x, y);
}