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

#include <WiFi.h>
#include <ezTime.h>
#include "Debug.h"
#include "Settings.h"

void setup() {
  enable_debug_log();
  
  connectWifi();
  initializeEzTime();
}

void loop() {
  // put your main code here, to run repeatedly:
  events();
}

void connectWifi() {
  WiFi.begin(readSettings().wifi_ssid, readSettings().wifi_password);
}

void initializeEzTime() {
  if (readSettings().enable_debug_output) {
    setDebug(INFO);
  }
  
  setServer(readSettings().ntp_server);
  waitForSync();
}
