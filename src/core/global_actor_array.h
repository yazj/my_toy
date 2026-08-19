//
// Created by Administrator on 2026/8/18.
//

#ifndef MY_TOY_GLOBAL_ACTOR_ARRAY_H
#define MY_TOY_GLOBAL_ACTOR_ARRAY_H
#include "actor/actor.h"

#include <memory>
#include <type_traits>
#include <utility>
#include <vector>
class Actor;

class Global_actor_array {
public:
  static Global_actor_array &get() {
    static Global_actor_array instance;
    return instance;
  }

  Global_actor_array(const Global_actor_array &) = delete;
  Global_actor_array &operator=(const Global_actor_array &) = delete;

  Global_actor_array(Global_actor_array &&) = delete;
  Global_actor_array operator=(Global_actor_array &&) = delete;

  template <typename T, typename... Args> T &spawn_actor(Args &&...args) {
    static_assert(std::is_base_of_v<Actor, T>, "T must be a subclass of Actor");
    static_assert(!std::is_abstract_v<T>, "Cannot spawn an abstract Actor");
    auto &slot = _actor_array.emplace_back(
        std::make_unique<T>(*this, std::forward<Args>(args)...));
    slot->begin_play();
    return static_cast<T &>(*slot);
  }

  void clean_up();

  void render() const;

protected:
  friend class Actor;
  Global_actor_array() = default;
  std::vector<std::unique_ptr<Actor>> _actor_array;
};

#endif // MY_TOY_GLOBAL_ACTOR_ARRAY_H
