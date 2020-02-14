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

#include <M5ez.h>

#define BTN_MENU      "Menu"
#define BTN_LIGHT_ON  "Light on"
#define BTN_LIGHT_OFF "Light off"

void showClockCanvas() {
  while (true) {
    turnOnBacklight();
    ez.header.show("Clock");
  
    ez.buttons.clear();
    ez.buttons.show("Light on#Menu#Light off");
    _dispatchClockCanvasButtons(); 
  }
}

void _dispatchClockCanvasButtons() {
  time_t last = 0;
  
  while (true) {
    String button = ez.buttons.poll();

    last = _updateTimeDisplay(last);

    if (button == BTN_MENU) {
      _showMainMenu();
      return;
    } else if (button == BTN_LIGHT_ON) {
      turnOnBacklight();
    } else if (button == BTN_LIGHT_OFF) {
      turnOffBacklight();
    }
  }
}

void _showMainMenu() {
  turnOnBacklight(false);
  ezMenu menu("Menu");

  menu.txtSmall();
  menu.buttons("up#Back#select##down#");
  menu.addItem("System Settings", ez.settings.menu);
  menu.upOnFirst("last|up");
  menu.downOnLast("first|down");
  menu.run();
}

time_t _updateTimeDisplay(time_t last) {
  Timezone time = ez.clock.tz;
  ez.clock.yield();
  
  time_t result = last;

  if ((time.now() - last) >= 1) {
    m5.lcd.fillRect(
      ez.canvas.left(), ez.canvas.top(), 
      ez.canvas.width(), ez.canvas.height(),
      ez.theme->background);
  
    ez.canvas.font(&FreeMonoBold24pt7b);
  
    
    String timeString = time.dateTime("H:i.s");
    int textWidth = m5.lcd.textWidth(timeString);
    ez.canvas.pos((ez.canvas.width() - textWidth) / 2, ez.canvas.top() + 20);
    ez.canvas.print(timeString);

    result = time.now();
  }

  return result;
}
