#include "SnapshotResponseMovement.h"
#include "ResponseTeam.h"

SnapshotResponseMovement::SnapshotResponseMovement(ResponseTeam* root) : position(0) {
    buildSnapshot(root);
}

void SnapshotResponseMovement::buildSnapshot(ResponseComponent* component) {
    if (component == nullptr) {
        return;
    }
    snapshot.push_back(component);
    ResponseTeam* team = dynamic_cast<ResponseTeam*>(component);
    if (team != nullptr) {
        for (ResponseComponent* child : team->responses) {
            buildSnapshot(child);
        }
    }
}

void SnapshotResponseMovement::first() {
    position = 0;
}

void SnapshotResponseMovement::next() {
    if (!isDone()) {
        position++;
    }
}

bool SnapshotResponseMovement::isDone() {
    return position >= static_cast<int>(snapshot.size());
}

ResponseComponent* SnapshotResponseMovement::currentItem() {
    if (isDone()) {
        return nullptr;
    }
    return snapshot[position];
}

SnapshotResponseMovement::~SnapshotResponseMovement() {}