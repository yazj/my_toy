//
// Created by Administrator on 2026/8/18.
//

#include "global_actor_array.h"
void Global_actor_array::clean_up() {
  std::erase_if(_actor_array, [](const auto &p) { return !p->is_alive(); });
}