#include "MainWindowController.h"

Controllers::MainWindowController::MainWindowController(Views::MainWindow *v, Models::AppService *m)
    : view(v), model(m) {}

Controllers::MainWindowController::~MainWindowController(void) {}


