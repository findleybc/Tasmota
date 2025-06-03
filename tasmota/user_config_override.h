/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2021  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

/*
Examples :

// -- Master parameter control --------------------
#undef  CFG_HOLDER
#define CFG_HOLDER        4617                   // [Reset 1] Change this value to load SECTION1 configuration parameters to flash

// -- Setup your own Wifi settings  ---------------
#undef  STA_SSID1
#define STA_SSID1         "YourSSID"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "YourWifiPassword"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "your-mqtt-server.com" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "YourMqttUser"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "YourMqttPass"         // [MqttPassword] Optional password

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'

#ifdef MY_IP
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS     MY_IP                // Set to 0.0.0.0 for using DHCP or enter a static IP address
#endif

#ifdef MY_GW
#undef  WIFI_GATEWAY
#define WIFI_GATEWAY        MY_GW                // if not using DHCP set Gateway IP address
#endif

#ifdef MY_DNS
#undef  WIFI_DNS
#define WIFI_DNS            MY_DNS               // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

#ifdef MY_DNS2
#undef  WIFI_DNS2
#define WIFI_DNS2           MY_DNS2              // If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)
#endif

// !!! Remember that your changes GOES AT THE BOTTOM OF THIS FILE right before the last #endif !!!
*/

#define USE_THERMOSTAT                           // Add support for Thermostat
  #define THERMOSTAT_CONTROLLER_OUTPUTS         2         // Number of outputs to be controlled independently
  #define THERMOSTAT_SENSOR_NAME                "AM2301" // Name of the local sensor to be used
  #define THERMOSTAT_SENSOR_NUMBER              1         // Number of local sensors to be used
  #define THERMOSTAT_RELAY_NUMBER               1         // Default output relay number for the first controller (+i for following ones)
  #define THERMOSTAT_SWITCH_NUMBER              1         // Default input switch number for the first controller (+i for following ones)
  #define THERMOSTAT_TIME_ALLOW_RAMPUP          300       // Default time after last target update to allow ramp-up controller phase in minutes
  #define THERMOSTAT_TIME_RAMPUP_MAX            960       // Default time maximum ramp-up controller duration in minutes
  #define THERMOSTAT_TIME_RAMPUP_CYCLE          30        // Default time ramp-up cycle in minutes
  #define THERMOSTAT_TIME_SENS_LOST             30        // Maximum time w/o sensor update to set it as lost in minutes
  #define THERMOSTAT_TEMP_SENS_NUMBER           1         // Default temperature sensor number
  #define THERMOSTAT_TIME_MANUAL_TO_AUTO        60        // Default time without input switch active to change from manual to automatic in minutes
  #define THERMOSTAT_TIME_RESET                 12000     // Default reset time of the PI controller in seconds
  #define THERMOSTAT_TIME_PI_CYCLE              30        // Default cycle time for the thermostat controller in minutes
  #define THERMOSTAT_TIME_MAX_ACTION            20        // Default maximum thermostat time per cycle in minutes
  #define THERMOSTAT_TIME_MIN_ACTION            4         // Default minimum thermostat time per cycle in minutes
  #define THERMOSTAT_TIME_MIN_TURNOFF_ACTION    3         // Default minimum turnoff time in minutes, below it the thermostat will be held on
  #define THERMOSTAT_PROP_BAND                  4         // Default proportional band of the PI controller in degrees celsius
  #define THERMOSTAT_TEMP_RESET_ANTI_WINDUP     8         // Default range where reset antiwindup is disabled, in tenths of degrees celsius
  #define THERMOSTAT_TEMP_HYSTERESIS            1         // Default range hysteresis for temperature PI controller, in tenths of degrees celsius
  #define THERMOSTAT_TEMP_FROST_PROTECT         40        // Default minimum temperature for frost protection, in tenths of degrees celsius
  #define THERMOSTAT_TEMP_RAMPUP_DELTA_IN       4         // Default minimum delta temperature to target to get into rampup mode, in tenths of degrees celsius
  #define THERMOSTAT_TEMP_RAMPUP_DELTA_OUT      2         // Default minimum delta temperature to target to get out of the rampup mode, in tenths of degrees celsius
  #define THERMOSTAT_TEMP_PI_RAMPUP_ACC_E       200       // Default accumulated error when switching from ramp-up controller to PI in hundreths of degrees celsius
  #define THERMOSTAT_TIME_OUTPUT_DELAY          180       // Default output delay between state change and real actuation event (f.i. valve open/closed)
  #define THERMOSTAT_TEMP_INIT                  180       // Default init target temperature for the thermostat controller
  #define THERMOSTAT_TIME_MAX_OUTPUT_INCONSIST  3         // Default maximum time where the input and the outpus shall differ (for diagnostic) in minutes
  #define THERMOSTAT_TIME_MAX_AUTOTUNE          21600     // Maximum time for the PI autotune function to complete in seconds
  #define THERMOSTAT_DUTYCYCLE_AUTOTUNE         35        // Default duty cycle (in % over PI cycle time) for the step response of the autotune PI function
  #define THERMOSTAT_PEAKNUMBER_AUTOTUNE        8         // Default number of peak temperatures (max or min) to be used for the autotune PI function
  #define THERMOSTAT_TEMP_BAND_NO_PEAK_DET      1         // Default temperature band in thenths of degrees celsius within no peak will be detected
  #define THERMOSTAT_TIME_STD_DEV_PEAK_DET_OK   10        // Default standard deviation in minutes of the oscillation periods within the peak detection is successful




#endif  // _USER_CONFIG_OVERRIDE_H_
