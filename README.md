Arduino code for building an apparatus to spray seawater at a bunch of limpets
on a time cycle. 

The main program, Limpet_splasher_vX_X.ino, runs on an Arduino (Uno etc) with a 
DS1307 or DS3231 real time clock attached for time keeping. It activates a 
relay on a set cycle to actuate something (like a sprinkler solenoid valve) 
that will spray water on limpets. The splashing halts during "low tide" when 
the natural tide is lower than the virtual shore level defined in the 
program. To change the tide height at which the splashing starts, alter the value of
``virtualShoreHeight`` in the Limpet_splasher_v1_2.ino sketch. 

Install a copy of RTClib in your Arduino/libraries/ directory. If there is not already a libraries directory, create it now. RTClib can be downloaded from https://github.com/millerlp/RTClib. If the copy you download and unzip is called "RTClib-master", rename the folder to simply be "RTClib".

Copy the folder with the tide library for your site (i.e. TidelibMontereyHarbor) into Arduino/libraries/. Libraries for other sites can be found at https://github.com/millerlp/Tide_calculator. 

Copy the Limpet_splasher_v1_2 folder (or most recent version) into your Arduino folder where your other sketches are normally stored. 


If the real time clock attached to the Arduino is not yet set, you need to set it one time before loading the tide prediction software onto the Arduino. Open the Arduino software and go to File>Examples>RTClib>settime_exact.ino. Follow the instructions at the top of that sketch to upload the correct time to your real time clock. Make sure the time you enter is in your local standard time, not Daylight Savings Time (which runs Mar-Nov in most places). The tide prediction routine relies on the time being set to local standard time for your site, otherwise you won't get the current tide height out. After running the settime_exact.ino sketch, before unplugging the Arduino, immediately upload a different sketch (such as the Tide_controller sketch) to the Arduino so that the clock doesn't try to reset itself repeatedly when the Arduino restarts.

This project is a branch of my other work, particularly
http://github.com/millerlp/Tide_switch

