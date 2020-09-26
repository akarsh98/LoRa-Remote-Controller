# LoRa Based Remote Controller | Universal Remote Controller

Video Link:[https://youtu.be/b2fUYxnji_g](https://youtu.be/b2fUYxnji_g)

![alt text](https://github.com/akarsh98/LoRa-Remote-Controller/blob/master/LoRa%20Remote/4.JPG)

In this project, We are going to make a breadboard prototype of a LoRa based Remote Controller we made few projects back. You can head over to that project from [here]().
With the help of this remote controller we will be able to control instruments from a distance of several kms and that to without any Internet. The main thing of this project is the RYLR907 LoRa module from Reyax which will transmit and receive the data and send it to the ESP8266 for performing operations for which the command has been sent.

![alt text](https://github.com/akarsh98/LoRa-Remote-Controller/blob/master/LoRa%20Remote/c2.jpg)

![alt text](https://github.com/akarsh98/LoRa-Remote-Controller/blob/master/LoRa%20Remote/Capture.PNG)
PCBGOGO, established in 2015, offers turnkey PCB assembly services, including [PCB manufacturing](https://www.pcbgogo.com/), PCB assembly, components sourcing, functional testing, and IC programing. 
Its manufacturing bases are equipped with the most advanced production equipment such as YAMAHA pick and place machine, Reflow oven, Wave soldering Machine, X-RAY, AOI testing machine; and the most professional technical personnel.
Though it’s only five years old, their factories have the experience in PCB industry for over 10 years in Chinese markets. It is a leading specialist in surface-mount, thru-hole and mixed technology PCB assembly and electronic manufacturing services as well as [turnkey PCB assembly](https://www.pcbgogo.com/pcb-assembly.html). 
PCBGOGO provides the order service from prototype to mass production, join them now.
We will be making two circuits in this project. First will be the Remote controller which have a LoRa module, an ESP8266 module and a push button. The ESP8266 is programmed in such a manner that whenever the button is pressed, it will send a signal to turn on an LED on the receiver side through LoRa module. On the receiver end there is another LoRa module connected with another ESP8266 module which is programmed in such a way that on the reception of the appropriate signals it performs the tasks such as turning LED ON and OFF. This remote control can also be used for controlling your home appliances and several other things you want to control over a large distance but without any Internet. 

![alt text](https://github.com/akarsh98/LoRa-Remote-Controller/blob/master/LoRa%20Remote/24c1_bb.jpg)

