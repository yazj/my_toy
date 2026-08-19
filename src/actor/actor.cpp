//
// Created by Administrator on 2026/8/18.
//

#include "actor.h"
#include "core/global_actor_array.h"

Actor::Actor(Global_actor_array &global_actor_array, const Vector2 loc,
             const float rot, const float scale, const char *img_path)
    : _location(loc), _rotation(rot), _scale(scale),
      _global_actor_array(global_actor_array) {
  set_texture(img_path);
}

Actor::~Actor() { UnloadTexture(_tex); };

void Actor::destroy() {
  end_play();
  _alive = false;
}

void Actor::move(const Vector2 vec) {
  _location = Vector2{.x = _location.x + vec.x, .y = _location.y + vec.y};
}

void Actor::rotate(const float rot) { _rotation += rot; }

void Actor::set_texture(const char *img_path) {
  const Image img = LoadImage(img_path);
  _tex = LoadTextureFromImage(img);
  UnloadImage(img);
}
