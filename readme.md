# 3diode binary clock
a simple concept. Regular digital clock but with a plot twist - 
instead of decimal it uses binary to display values.

Ideally setup would require 10 diodes:

      X X X X => 8 4 2 1 
      X X X X X X => 32 16 8 4 2 1
      // clock showing 10:30 X for active diode, O for unactive
      X O X O
      O X X X X O
      // it's easy to write in hex
      0xA
      0x1E

How do we accomplish such a thing with mere 3 diodes though?

        // 1. youngest of the working diodes is blinking
        // 2. with speed1 if hour is odd or speed2 if hour isn't odd
        // 3. it does either blink without longer pause
        //    or blinks with either 2-blink or 3-blink bursts
        //    depending on the minutes. There are three brackets
        //    1 - time<20 - continuous blinking
        //    2 - time<40 - 2blink burst
        //    3 - time<60 - 3blink burst

This way we can tell the time with mere three diodes and some inaccuracy. PM/AM can be infered so it's unnecessary to convey that datum. 

