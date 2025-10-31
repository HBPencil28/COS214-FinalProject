#include "StaffHandler.h"

StaffHandler::StaffHandler() : nextHandler(nullptr) {}

void StaffHandler::setNextHandler(StaffHandler* handler) {
    this->nextHandler = handler;
}

StaffHandler::~StaffHandler() {}