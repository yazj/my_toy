//
// Created by Administrator on 2026/8/19.
//

#ifndef MY_TOY_PLAYER_H
#define MY_TOY_PLAYER_H
#include "actor/actor.h"

class Player : public Actor {
public:
  Player(Global_actor_array &global_actor_array, const Vector2 loc,
         const float rot, const float scale, const char *img_path)
      : Actor(global_actor_array, loc, rot, scale, img_path) {}
  ~Player() override = default;

  void begin_play() override;
  void tick() override;
  void end_play() override;

  void move(Vector2 vec) override;

protected:
  float health{100.0f};
  float speed{3.0f};
};

#endif // MY_TOY_PLAYER_H
