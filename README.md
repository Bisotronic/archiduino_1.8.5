**-------------------------------------------------------------------------------------------**

**HOW TO SETUP THE ARCHIDUINO BOARDS ON ARDUINO IDE**

#Archiduino folder

- Close your Arduino IDE.
- Create a subfolder named **archiduino** in your *c:\program folder\arduino\hardware* folder.
- Create a subfolder named **avr** in your *c:\program folder\arduino\hardware\archiduino* folder.
- Download this package.
- Unzip the package, then open *archiduino1284BT-master* folder. 
- Copy its content (all its content) it in your **c:\program folder\arduino\hardware\archiduino\avr\** folder. 
- Open Arduino IDE
- You'll see the Archiduino boards in your board selection menu.
- Choose proper board (Archiduino, Archiduino 1284, Archiduino 1284 BT, GuardUino32)
- Go invent!

**-------------------------------------------------------------------------------------------**

**NEW RELEASE NOTES: 18/07/2017**

1) Added GuardUino32 in boards.txt

2) Some minor edit of RELAY1284.h

3) Added GuardUino32 library


**NEW RELEASE NOTES: 27/03/2017**

1) Removed annoying warnings on compile (it affects pins_arduino.h in "variants" folders)

2) VREF and PSU overheating

  Since the LM4030-2.5 Voltage reference is mounted as default on the Archiduino CPU, it's **MANDATORY** to upgrade the Arduino IDE configuration to this release. We edited the file:

  *%arduino_IDE_path%\hardware\archiduino\avr\cores\arduino\Wiring_analog.c* 

  at line #30 as follow:

```
  uint8_t analog_reference = EXTERNAL; 
```

  The above instruction shuts down the ATMega1284p internal voltage reference and let the external LM4030 work without a huge power consuption.   

  If you want, you could add to you sketch's *setup { }* the instruction:

```
  analogReference(EXTERNAL);
```

  This was the previous config method, but everybody, everytime, forget to put it in setup routine, with hilarious (or potentially dramatic) effects.

**-------------------------------------------------------------------------------------------**

**-------------------------------------------------------------------------------------------**

##What the FAQ is Archiduino?

To quickly get an idea of what is Archiduino, what can it do for you and how it can improve your life, we think the best way is a list of FAQ (frequently asked questions) and related answers. Our FAQs are presented as a dialogue, as if you were here talking to us. Some of them may look a little basic, but we do believe that everyone has the right to learn. Don’t you?

**What is Archiduino?**

Archiduino is an universal modular controller. It means that if you have anything electrically driven, you can acquire its data and control it with Archiduino.

**How can I program it?**

Archiduino is 100% software compatible with Arduino. The Archiduino32 mounts the same Atmel processor ATMega32U4 of Arduino Leonardo. In fact, you get the USB cable, connect it from PC to Archiduino and open Arduino IDE. Then, in Tools menu, set the Arduino type as Arduino Leonardo, giving it the right communication port and… voila, you’re ready to go. The Archiduino1284 mounts ATMega1284p MCU; this processor need a specific board definition that you could find in our repository.

**Are you saying that I can load any Arduino sketch into Archiduino?**

Yes, of course. Taking care of the MCU compatibility.

**Has the Arduino sketch to be modified in order to run on Archiduino?**

Just a little. The port addressing and the pin names are different because Archiduino has a particular output mapping. But there are no difficulties doing it: on this site you can find all the mapping tables you need. Also the code examples can help you, even more than thousand words.

**Give me an example…**

An Archiduino code like this:

```
digitalWrite(M7A, LOW);
digitalWrite(M7A, LOW);
```

is equivalent to an Arduino code as follow:

```
digitalWrite(A3, LOW);
digitalWrite(A3, LOW);
```

The configuration files make the magic and route your signals between processor and I/O modules (hence the prefix M). With the code above we said to the CPU that a LOW status must be written on the A channel of Module 7. So the dual relay SnipCard we put in the socket of module n. 7 receive our command on channel A. If we need to operate on the second channel, we just change the pin to M7B.

**Is Archiduino reliable and enough electrically protected, in order to be used in critical environments?**

Assuming that it is a product made to work at very low voltage environments (12 Vcc supply, 36 Vcc max for relay contacts), we designed Archiduino with specific care to avoid dangerous voltage surges and spikes. The same design of the SnipCards is engineered to avoid the direct connection to MCU pins (contrary to what happens on most common platforms like Arduino and so on). In our boards we have put a plenty of varistors, transil diodes and inductance filters in order to minimize common risks of blazing the digital components and turn in ashes all the work just done.

**So, Archiduino could be considered as indestructible?**

We don’t have been overwhelmed by the Titanic syndrome. Archiduino is more robust and sturdy than the majority of similar platforms currently available on the market. That’s the truth. Obviously, if you apply mains voltage on digital pins, nothing could protect it (hint: DON’T TRY IT). Even if you put it under a 20 tons hydraulic press, or if you throw it in the water when powered on. It’s an electronic device, it should be treated with typical care that this kind of devices deserves. Not only for this reason it must be used exclusively:
- after reading the user’s manuals of each component and SnipCard;
- according to safety instructions;
- according to the disclaimer.

**What if I try to use it in a challenging industrial environment?**

Archiduino is born with same technology of his older brother, Archimede (an ARM STM32 running in .NET), which is currently used in a wide range of environments. Both are EMC certified according to EN 61326-1:2013 class A requirements, then we say: yes, you can use it in an industrial environment, according to the disclaimer.

**What do I do if I need to use Archiduino in critical environments?**

Archiduino has been engineered and designed to meet the needs of people working in industrial environments. Every SnipCard is protected with ESD/EMI/RF/Transients/Spikes rejector devices. Transient voltage suppressor are scattered in any potential external connection. Even simple external pushbuttons are connected to Archiduino through 2.5KV-capable optocouplers. There are NO BARE PINS directly connected to the real world! Beyond these considerations, if you need to use it in kinda critical applications and you're not sure if... you're sure, feel free to contact us: we’ll be glad to give you every advice or information you need about.

**Okay, that’s great, but: is Archiduino *too industrial* to be used for hobby purposes?**

Oh, man. No! Archiduino is born to be a reliable playfellow for everybody operating in the range from “rookie maker” to “Tenth-Dan master of electronics”. It uses the familiar Arduino language, easy and commonly known, and the easiest I/O logic of the Arduino environment in order to meet the hobbyist needs. But, at same time, it’s strong and well armored to be applied on such battle field like industrial environments. In other words: **USE IT everywhere you want, it’s great, it’s reliable, it’s sturdy and easy to use.** *What else, guy?*

**About us**

Archiduino has been designed and built in Italy by Seletronica s.a.s.
Archiduino is Open Hardware. You can find every schematic and infos clicking one of following links:

Seletronica website: www.seletronica.com 

Archiduino website: www.archiduino.com (don't forget to visit our **shop**!)

BisoTronic website: www.bisotronic.it

**License**

This repository is released under the Creative Commons ShareAlike 4.0 International license. You are welcome to use this code for commercial purposes. If you'll build your own Archiduino and/or you'll improve our (poor) code, please let us know writing your thoughts here: info 'at' seletronica 'dot' com. We just started learning! 

Please consider contributing back to this repository or others to help the open-source hardware community continue to thrive and grow!
