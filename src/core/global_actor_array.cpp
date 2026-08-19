//
// Created by Administrator on 2026/8/18.
//

#include "global_actor_array.h"
void Global_actor_array::clean_up() {
  std::erase_if(_actor_array, [](const auto &p) { return !p->is_alive(); });
}
void Global_actor_array::render() const {
  for (const auto &actor_ptr : _actor_array) {

    const Vector2 location = actor_ptr->get_actor_location();
    const float rotation = actor_ptr->get_actor_rotation();
    const float scale = actor_ptr->get_actor_scale();
    const Texture2D texture = actor_ptr->get_texture();

    DrawTextureEx(texture, location, rotation, scale, WHITE);
  }
}