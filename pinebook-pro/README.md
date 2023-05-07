### Running this script

This python script is ran with cron in the case of Manjaro "cronie".

My pbp is setup to just turn the screen off when the lid is closed.

I lock screen before I close the lid.

The cron entry I'm using is this:

`*/5 * * * * /usr/bin/python /home/<username>/pinebook-pro-auto-charger/pinebook-pro/battery-checker.py >> /var/log/battery-checker.log 2>&1`

Check that this command runs, mine didn't due to permission writing the file into log folder
