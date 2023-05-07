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

it's still going down dang

when the ESP-01 is on the serial programmer, nothing connected to it, wifi is reliable, doesn't go down...

maybe it is a power source issue

ugh... I can't move on, I keep thinking it's done but you leave it alone long enough it's not actually working

hmmm.... maybe I do have to have separate power supplies in the end...

I see power bleeding into the relay led

it won't connect when in the charger mount ugh...

my current guess right now is the laptop battery charger needs a high current draw... the ESP-01 on its own is throwing it off/not providing constant power... so the ESP-01's power supply is unstable... after separating power supply wifi connection is constant

the wifi works/stays on now, so I'll keep an eye on it regarding long term use

omg... lmao, as I was putting the cover on it lost wifi connection hmm...

but when I rebooted it (unplug/replug) it reconnected again to wifi so that part is better

wifi went down... ugh...

the relay led is a little on, I think it's bleeding power from rx pin into the relay trigger...

ugh... man this is annoying

it's that issue again of pins stealing power from each other, the nuclear option is to use an overpowered wifi board where the pin is definitely nothing

I unplugged the esp-01 and pulled it out of the socket, booted correctly...

Is it a serial buildup? I don't even use serial though

I just saw it do something where it went down, seems like restarting the relay light comes on a little

I think the culprit is the rx pin... being connected to the relay, on power up/boot

This sounds superstituous lol but it's possbile too the unplugged laptop charger has capacitance/has power on that side... pulled back up into esp... doesn't make sense... since ground is not shared between the two power supplies

I'm so annoyed too because of how hot it is/everything is sticky ugh

I plugged in the ESP-01 into the programmer, while it's running did requests to it, responded, no output on serial monitor...

so I don't think that is a problem

I don't know what to do... for some reason this thing doesn't work, it's not reliable

so the top jumper is needed to actually turn the relay on/off, probably already said this before

I pull the esp-01 out and put it back in, helps reset it

it's funny it just worked on its own (cron job fired/turned charger back on since capacity < 80) but the ESP-01 wifi connection is not reliable

now it's being reliable... idk what to do, right now though barrel charger is plugged into the wall as well

is it a short? barrel is plugged into laptop too

wtf... now I can't get it to fail lol

3... 2... 1... lol goes down as soon as I put the screws in... nah it's still working now but I haven't changed anything
