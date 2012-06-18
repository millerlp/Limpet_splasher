Arduino code for building an apparatus to spray seawater at a bunch of limpets
on a time cycle. 

The main program, Limpet_splasher_vX_X.ino, runs on an Arduino (Uno etc) with a DS1307 or DS3231 real time clock attached for time keeping. It activates a 
relay on a set cycle to actuate something (like a sprinkler solenoid valve) 
that will spray water on limpets. The splashing halts during "low tide" when 
the natural tide is lower than the virtual shore level defined in the 
program.

To get this working properly, the two library folders, RTClib and 
TideMontereyHarborlib must be copied into the arduino-1.x.x/libraries/ folder
on your computer before launching the arduino.exe (arduino.app on Mac) 
program.

The program RealTimeClock_reset is provided to get the time set on a new
real time clock that hasn't already been initialized. Read the instructions
inside that arduino sketch, since it should only be uploaded and run one time,
and then you must immediately load a different sketch on the Arduino to avoid
reseting the time more than once (since it stores the old time from compile).
