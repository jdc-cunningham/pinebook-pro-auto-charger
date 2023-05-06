05/06/2023

10:38 AM

I gotta figure out how this relay works, will use my power supply to measure current draw used to turn it on.

The product page I bought this from is gone lol, trying to find a manual.

it's the funny the silkscreen is backwards for the stuff on the bottom of the board.

10:49 AM

I'm concerned this won't work (wrong relay) and while I have gotten help to design a low to high mosfet switch before... I'm trying to use this relay

It looks like I have two options: trigger goes on, turns load on or off... I think off makes sense because the trigger will use some more current to stay on/reducing charging ability.

I want this thing to be simple so I'm stealing power from the charger itself.

I'm expecting at worse around 300mA or so where ESP-01 is at peak wifi and relay is on/powering coil.

10:54 AM

I'm trying to figure out what these jumpers do.

I want the coil/relay to use a separate power source since the ESP-01 can't power it.

Says trigger current is 3mA

Working current is 65mA

So I think I want to take off Jumper 1 (top with letters upright)

Since it says "JP1 is used to connect VCC of the signal terminals and V+ of the relay" as in same power source.

I'll verify with a multimeter/connection test.

Well... I have 5 of them 5 tries lmao

I bought parts but I can't find them, so much shit everywhere

11:06 AM

been a while since I programmed an ESP-01... gotta find one that still works, bunch of them I broke trying to solder the reset pin

I'm referring to my failed moisture sensor project from a while back

https://github.com/jdc-cunningham/seeeduino-moisture-sensor/blob/master/arduino/esp_01/esp_01.ino

For the base trigger pin code and http server

looking at this

https://github.com/esp8266/Arduino/blob/bed2fa339d1d6cfd281c06594431f19096d1ca10/libraries/ESP8266HTTPClient/examples/BasicHttpClient/BasicHttpClient.ino

Hmm... I need to test the relay first

I'll use a battery as the load I'm turning on/off

11:31 AM

distracted by my ac not working well,

I'm going to use a coin cell to be my trigger at 3V

11:45 AM

hmm I think there is a fatal mistake here with this relay... it won't work for this charger since it's 5V... and this thing is designed for 30V

I'm still verifying I was thinking it would allow any voltage through up to 30V

11:57 AM

not going well, not able to get voltage out on the other side of the relay

I'm going to check the low power circuit thing I worked on in the past to see what current it can do.

12:23 PM

hmm... it's not going well

I was able to switch the relay on (have to keep the jumper 1 attached) but the output side doesn't put anything out

on either side eg. NC/NO

maybe I have bad ones? I can try all 5, I tried 2

what's annoying is there are so many sellers of this product and the reviews sometimes don't match the product

12:44 PM

omg I got it... I didn't understand how this wiring works

this picture is the key

https://www.circuitbasics.com/wp-content/uploads/2015/11/Arduino-Temperature-Dependent-Light-Bulb-With-5V-Relay-Updated-1638x860.png

the relay is a switch, obviously... but it breaks a line, not connects power and ground

I had black/red going to NO/C and actually I want to use NC where it's normally outputting power until the high switch goes on to turn it off.

It sucks but since it uses power, makes sense to turn it on when you don't want to charge... so you use most of the current for charging

see my scumbag test area

< PIC >

the 5V fan was my load

I need to verify the power on is acceptable for ESP-01 pin out 12mA

then I'll be able to make a little circuit board and wire this all up, design/print the housing with that Pine64 logo schwag

12:53 PM

there's no current draw on the switch... weird

the other thing I don't know right now is the POST request receive on ESP-01, I need to verify that, then I can package everything into a board

1:00 PM

what sucks is how big this relay is, the ESP/related circuitry is small so you have this odd L shape

I'm wiring up the circuit board now/soldering it

2:51 PM

I gotta say this is one of the worst projects I've worked on in a while, mostly because my AC is not working, hot af/making me pissed off

Also the 3A wire gauge stuff is harder to solder and I didn't have much so I reduced the length of the wire... it should all work though

3:38 PM

my god it's hot...

stupid "why isn't it working?" typo between WiFi and Wifi

4:13 PM

the low/high is reversed on the blue LED? hmm

4:18 PM

struggling on the arg receive... lost the pings... is connected/running

what's kind of annoying is this server handler blocks everything, I can't write anything else to handle bad scenarios

like wifi goes down, I put a reconnect on there but don't know if it will work, you could test it...

I set the blue LED to indicate it's on wifi though for visual

4:24 PM

hmm... seems like the blue LED and serial tx are the same line... so can't use them both at the same time

4:38 PM

dumb... the hasArg thing needs x-ww-form-urlencoded, will have to figure out how to set that on python

4:57 PM

pbp is at 0 right now, just tested the relay for realsies it's working, just wondering how much slower it is to charge with some of the current taken away while charging

5:00 PM

if it stays at 0% after 10 minutes I'm going to assume it doesn't have enough power to charge, I'll have to rework the ESP-01 code and wiring (flip output) so it charges automatically if there's no "stop charge" command (high trigger on)

there's no real damage other than the battery being at 100% too long = crystals forming or something overtime

5:04 PM

ehh... I'm calling it, it is not progressing

5:22 PM

I'm getting the dimensions so I can start doing the body design/start printing it out
