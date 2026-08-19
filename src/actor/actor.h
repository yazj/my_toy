//
// Created by Administrator on 2026/8/18.
//

#ifndef MY_TOY_ACTOR_H
#define MY_TOY_ACTOR_H

#include "core/global_actor_array.h"

#include <raylib.h>
class Global_actor_array;

class Actor {
public:
  explicit Actor(Global_actor_array &global_actor_array, Vector2 loc, float rot,
                 float scale, const char *img_path);
  virtual ~Actor();

  virtual void begin_play() = 0;
  virtual void tick() = 0;
  virtual void end_play() = 0;

  void destroy();

  [[nodiscard]] Vector2 get_actor_location() const { return _location; }
  [[nodiscard]] float get_actor_rotation() const { return _rotation; }
  [[nodiscard]] float get_actor_scale() const { return _scale; }

  [[nodiscard]] bool is_alive() const { return _alive; }

  virtual void move(Vector2 vec);
  void rotate(float rot);

  void set_texture(const char *img_path);
  [[nodiscard]] Texture2D get_texture() const { return _tex; }

protected:
  bool _alive = true;
  float _delta_time = 0.01667f;

  Vector2 _location{};
  float _rotation{0.0f};
  float _scale{1.0f};

private:
  Texture2D _tex{};
  Global_actor_array &_global_actor_array;
};

#endif // MY_TOY_ACTOR_H
