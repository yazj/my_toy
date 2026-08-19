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
  template <typename T, typename... Args> T &spawn_actor(Args &&...args) {
    static_assert(std::is_base_of_v<Actor, T>, "T must be a subclass of Actor");
    static_assert(!std::is_abstract_v<T>, "Cannot spawn an abstract Actor");
    _actor_array.push_back(
        std::make_unique<T>(*this, std::forward<Args>(args)...));
    return *_actor_array.back();
  }

  void clean_up();

protected:
  friend class Actor;
  std::vector<std::unique_ptr<Actor>> _actor_array;
};

#endif // MY_TOY_GLOBAL_ACTOR_ARRAY_H
