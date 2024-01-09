//
// Created by bishan_ on 1/8/24.
//

#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include <functional>
#include <ranges>
#include <unordered_map>

#include "Node.hpp"
#include "math/number.hpp"


namespace bcake {
  class Node;

  template <typename... Args>
  class event {

  public:
    explicit event(const char *name = "") :
      name(name),
      uid(reinterpret_cast<usize>(this)) {}

  private:
    const char *name;

    const usize uid;


    std::unordered_map<Node *, std::vector<std::function<void(Args...)>>> listeners{};

  public:
    void subscribe(Node &node, const std::function<void(Args...)> &callback) {

      listeners[&node].push_back(callback);

      if (auto &receivers = node.get_dependent_receivers(); receivers.contains(uid)) {
        receivers[uid].count++;
      }
      else {
        const Node::signal_dependecy dep = {
          [&] { listeners.erase(&node); },
          0
        };
        receivers.emplace(uid, dep);
      }
    }

    void operator ()(Args... args) const {
      for (const auto &callbacks : listeners | std::views::values) {
        for (const auto &callback : callbacks) {
          callback(args...);
        }
      }
    }

    ~event() noexcept {
      for (auto &node : listeners | std::views::keys) {
        node->get_dependent_receivers().erase(uid);
      }
    }

    event &operator =(const event &rhs) = delete;
    event &operator =(const event &&rhs) = delete;
  };
}

#endif //SIGNAL_HPP
