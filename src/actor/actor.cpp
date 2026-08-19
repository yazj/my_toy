//
// Created by Administrator on 2026/8/18.
//

#include "actor.h"

#include <utility>

#include "core/global_actor_array.h"

Actor::Actor(Global_actor_array *global_actor_array, const Vector2 loc,
             const float rot, const char *img_path)
    : _location(loc), _rotation(rot), _global_actor_array(global_actor_array) {
  set_image(img_path);
}

Actor::~Actor() { UnloadImage(_img); }

void Actor::destroy() { _alive = false; }

void Actor::move(const Vector2 vec) {
  _location = Vector2{.x = _location.x + vec.x * _delta_time,
                      .y = _location.y + vec.y * _delta_time};
}

void Actor::rotate(const float rot) { _rotation += rot * _delta_time; }

void Actor::set_image(const char *img_path) { _img = LoadImage(img_path); }
