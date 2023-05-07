### real world usage

So far the ESP-01 seems to go down, maybe related to the relay turning on/off causing a surge... idk.

Not supposed to matter with a current supply like this eg. 10x what is being used.

Once ESP-01 goes down, does not reconnect as expected

I think there's an issue as well with risidual power/clean restart (after unplugging wall charger)

A problem is when the ESP-01 boots up the GPIO2 is high, which triggers the relay

I'm going to remove the reconnect call... the issue is the server listener blocks the main loop

Yeah... it might have been a mistake to use GPIO2 as the trigger... since it has to be held at high or else low means fimrware update

https://www.esp8266.com/viewtopic.php?p=32822

Yeah... I think I'm gonna have to use separate power supplies in the end.

Because when the relay turns on the ESP-01 goes down ha, maybe power fluctuates

Oh well... let's do it again... omg

4:14 PM

...

hmmm I think I have to switch trigger pins

even with separate power supplies when the relay turns on ESP-01 goes down

I'm going to try and use GPIO1 (tx pin)

hmm... looks like same problem, tx outputs boot logs

I may try and put a transistor where it needs low to turn on

This is one of those times you think before you act sort of thing

I've had this kind of problem in the past, like leaking current has brown out condition... made a project fail

I don't know what's going on, why I didn't notice this problem before... it's the startup that's a problem now

I did realize I had the VCC in on the relay connected to 5V vs. 3.3V, let me change that real quick, it's been that way this whole time though...

There's leakage on the swithc, I can see it glowing a little after boot the relay on red led

wth... when GPIO2 is not connected to anything wifi won't go on

I did take the boot low down on setup

I'm reading...

maybe I can use rx pin, if you don't use serial.begin they're just pins apparently

also my relay is not an octoupler one seems like, active high vs. low

omg lmao... yes using rx pin works however... I gotta unsolder and go back to shared power supply lmao oh man...

alright... will see what other problems occur, it's 5:04 PM, 91F outside, 83F inside... I'm drowning in sweat damn

ugh... still problems with the ESP-01 going down/not reconnecting

I was thinking maybe it's a serial buffer building up or something, but I'm not using serial
