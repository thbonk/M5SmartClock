#pragma once;

#include "Preferences.h"
#include "static_settings.h"

Preferences readSettings() {
  return settings;
}

void saveSettings(Preferences settings) {
  // empty for now
}
