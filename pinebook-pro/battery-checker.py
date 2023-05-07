import os
import requests

esp01_api = 'http://192.168.1.185'

def get_battery_capacity():
  return os.system('cat /sys/class/power_supply/cw2015-battery/capacity')

def turn_charger_off():
  requests.post(esp01_api, {'stop_charging': True})

def turn_charger_on():
  requests.post(esp01_api, {'start_charging': True})

def check_battery():
  battery_capacity = get_battery_capacity()

  if (battery_capacity <= 80):
    turn_charger_on()
  else:
    turn_charger_off()

check_battery()
