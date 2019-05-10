/*
   Copyright 2019 Thomas Bonk

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
#include <M5ez.h>

void setup() {
  ez.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isFirstRun()) {
    ez.settings.menu();
    firstRunFinished();
  } else {
    // Show Clock
  }
  
  events();
}

bool isFirstRun() {
  Preferences prefs;
  bool result;

  prefs.begin("M5SmartClock", true);
  result = prefs.getBool("firstRun", true);
  prefs.end();

  return result;
}

void firstRunFinished() {
  Preferences prefs;
  
  prefs.begin("M5SmartClock", false);
  prefs.getBool("firstRun", false);
  prefs.end();
}
