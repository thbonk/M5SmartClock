/*
   Copyright 2020 Thomas Bonk

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 */

#include <Preferences.h>
#include <M5Stack.h>
#include <ezTime.h>
#include <M5ez.h>
#include "Constants.h"

void setup() {
  #include <themes/default.h>
  #include <themes/dark.h>
  
  ez.begin();
  M5.Power.setPowerBoostKeepOn(true);
}

void loop() {
  bool firstRun = isFirstRun();
  
  if (firstRun) {
    ez.settings.menu();
    firstRunFinished();
    firstRun = false;
  } else {
    // Show Clock
    //showClockCanvas();
  }
}

bool isFirstRun() {
  Preferences prefs;
  bool result;

  prefs.begin(APPLICATION_NAME, true);
  result = prefs.getBool(PREF_IS_FIRST_RUN, true);
  prefs.end();

  return result;
}

void firstRunFinished() {
  Preferences prefs;
  
  prefs.begin(APPLICATION_NAME, false);
  prefs.putBool(PREF_IS_FIRST_RUN, false);
  prefs.end();
}
