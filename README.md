# Circut Diagram

![image](https://github.com/advay-c/robot-shenanigans/assets/134825013/dba47502-902a-4478-b350-24b36612fbb5)

**Neck Servo D0**

# Installation

1. Install [Arduino 1.8.9](https://www.arduino.cc/en/software/OldSoftwareReleases)
2. Install the [MightyCore](https://github.com/MCUdude/MightyCore) arduino library
3. Select the [board and port](https://support.arduino.cc/hc/en-us/articles/4406856349970-Select-board-and-port-in-Arduino-IDE) (Arduino Nano)

# Functions

```c++
void convert_slow()
{
  count_angle = right_hip + 46;
  count_angle1 = right_foot + 46;
  count_angle2 = left_hip + 46;
  count_angle3 = left_foot + 46;
  count_angle4 = left_hand + 46;
  count_angle5 = right_hand + 46;
  _delay_us(3500);
}
void convert()
  {
    count_angle = right_hip + 46;
    count_angle1 = right_foot + 46;
    count_angle2 = left_hip + 46;
    count_angle3 = left_foot + 46;
    count_angle4 = left_hand + 46;
    count_angle5 = right_hand + 46;
    _delay_us(1200);
  }
void home_position()
  {
    right_hip = 90;
    right_foot = 90;
    left_hip = 90;
    left_foot = 90;
    left_hand = 140;
    right_hand = 40;    
  }

  ISR (TIMER1_COMPA_vect)
{
  count++;
  if (count <= count_angle)
  {
    setbit(PORTD, bitn(4));
  }
 else if ((count > count_angle) && (count < 1818))
 {
  clearbit (PORTD,bitn(4));
 }
  else if (count >= 1818)
  {
    count=0;
  }
  if (count <= count_angle1)
  {
    setbit(PORTD, bitn(5));
  }
 else if ((count > count_angle) && (count < 1818))
 {
  clearbit (PORTD,bitn(5));
 }
  if (count <= count_angle2)
  {
    setbit(PORTD, bitn(6));
  }
 else if ((count > count_angle2) && (count < 1818))
 {
  clearbit (PORTD,bitn(6));
 }
  if (count <= count_angle3)
  {
    setbit(PORTD, bitn(7));
  }
 else if ((count > count_angle3) && (count < 1818))
 {
  clearbit (PORTD,bitn(7));
 }
 
  if (count <= count_angle4)
  {
    setbit(PORTD, bitn(3));
  }
 else if ((count > count_angle4) && (count < 1818))
 {
  clearbit (PORTD,bitn(3));
 }
 
  if (count <= count_angle5)
  {
    setbit(PORTD, bitn(2));
  }
 else if ((count > count_angle5) && (count < 1818))
 {
  clearbit (PORTD,bitn(2));
 }
 }
```
