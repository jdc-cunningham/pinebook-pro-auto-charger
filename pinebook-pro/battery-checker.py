import subprocess
import requests

esp01_api = 'http://192.168.1.185'

def get_battery_capacity():
  return subprocess.check_output('cat /sys/class/power_supply/cw2015-battery/capacity', shell=True)

def turn_charger_off():
  requests.post(esp01_api, {'stop_charging': True})

def turn_charger_on():
  requests.post(esp01_api, {'start_charging': True})

def check_battery():
  battery_capacity = int(get_battery_capacity())

  if (battery_capacity <= 70):
    turn_charger_on()
  else:
    turn_charger_off()

check_battery()
