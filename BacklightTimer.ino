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

#include <M5stack.h>
#include <M5ez.h>

uint16_t turnOffBacklight() {
  M5.lcd.setBrightness(1);
  //ez.removeEvent(turnOffBacklight);

  return 1;
}

void turnOnBacklight(bool autoTurnOff = true) {
  M5.lcd.setBrightness(100);
  /*ez.removeEvent(turnOffBacklight);

  if (autoTurnOff) {
    ez.addEvent(turnOffBacklight, 8000); 
  }*/
}
