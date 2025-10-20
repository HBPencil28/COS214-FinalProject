#include "Zone.h"

void Zone::add(Greenhouse* child) {
    if (!child) {
        throw std::invalid_argument("Cannot add null child to Zone");
    }
    children.push_back(child);
}

void Zone::remove(Greenhouse* child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it == children.end()) {
        throw std::runtime_error("Child not found in Zone");
    }
    children.erase(it);
}

Greenhouse* Zone::getChild(std::size_t index) {
    if (index >= children.size()) {
        throw std::out_of_range("Index out of range in Zone::getChild");
    }
    return children[index];
}

const std::vector<Greenhouse*>& Zone::getChildren() const {
    return children;
}

bool Zone::isComposite() const {
    return true;
}

void Zone::execute() {
    // Execute operation on all children
    for (auto* child : children) {
        if (child) {
            child->execute();
        }
    }
}