#include "LiveResponseMovement.h"
#include "ResponseTeam.h"

LiveResponseMovement::LiveResponseMovement(ResponseTeam* root) : root(root), position(0) {
    buildTraversal(root);
}

void LiveResponseMovement::buildTraversal(ResponseComponent* component) {
    if (component == nullptr) {
        return;
    }
    traversal.push_back(component);
    ResponseTeam* team = dynamic_cast<ResponseTeam*>(component);
    if (team != nullptr) {
        for (ResponseComponent* child : team->responses) {
            buildTraversal(child);
        }
    }
}

void LiveResponseMovement::first() {
    traversal.clear();
    position = 0;

    buildTraversal(root);
}

void LiveResponseMovement::next() {
    if (!isDone()) {
        position++;
    }
}

bool LiveResponseMovement::isDone() {
    return position >= static_cast<int>(traversal.size());
}

ResponseComponent* LiveResponseMovement::currentItem() {
    if (isDone()) {
        return nullptr;
    }
    return traversal[position];
}

LiveResponseMovement::~LiveResponseMovement() {}