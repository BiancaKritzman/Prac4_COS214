#include "ResponseTeam.h"

#include "LiveResponseMovement.h"
#include "SnapshotResponseMovement.h"

#include <iostream>
#include <algorithm>

void ResponseTeam::addResponse(ResponseComponent* response) {
    if (response != nullptr) {
        responses.push_back(response);
    }
}

void ResponseTeam::removeResponse(ResponseComponent* response) {
    if (response == nullptr) {
        return;
    }
    auto it = std::find(responses.begin(), responses.end(), response);
    if (it != responses.end()) {
        delete *it;
        responses.erase(it);
    }
}

void ResponseTeam::checkIn() {
    std::cout << "Response team checking in." << std::endl;
    for (ResponseComponent* response : responses) {
        if (response != nullptr) {
            response->checkIn();
        }
    }
}

ResponseMovement* ResponseTeam::createMovement(std::string method) {
    if (method == "snapshot") {
        return new SnapshotResponseMovement(this);
    }
    return new LiveResponseMovement(this);
}

ResponseTeam::~ResponseTeam() {
    for (ResponseComponent* response : responses) {
        delete response;
    }
}