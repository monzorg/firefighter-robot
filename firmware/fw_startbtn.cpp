#include "arduinoConfig.h"

#include "fw_startbtn.h"
#include "config.h"

extern bool shouldStart;
extern bool Debug;

void StartButtonClick() {
    shouldStart = true;
}

void StartButtonHold() {

    StartButtonClick();
    Debug = true;
}
