#include <avr/io.h>
#include <avr/interrupt.h>
#define clearbit(x,y)(x &=~y)
#define setbit(x,y) (x |= y)
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))

int count=0;
int right_hip,count_angle, right_foot, count_angle1,
left_hip,count_angle2, left_foot, count_angle3,
left_hand, count_angle4,right_hand,
count_angle5;
int main()
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0X02;
  SREG = 0x80;
  home_position();
  convert();
  while(1)
  {
    for (int c = 1; c <=25; c++)
    {
      right_foot++;
      left_hand--;
      right_hand--;
      convert();
    }
    for (int c = 1; c <=25; c++)
    {
      right_foot--;
      left_hand++;
      right_hand++;
      convert();
    }
    for (int c = 1; c <=25; c++)
    {
      left_foot--;
      left_hand++;
      right_hand++;
      convert();
    }
    for (int c = 1; c <= 25; c++)
    {
      left_foot++;
      left_hand--;
      right_hand--;
      convert();
    }
  }
}
void convert()
  {
    count_angle = right_hip + 46;
    count_angle1 = right_foot + 46;
    count_angle2 = left_hip + 46;
    count_angle3 = left_foot + 46;
    count_angle4 = left_hand + 46;
    count_angle5 = right_hand + 46;
    _delay_us(1500); 
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
 else if ((count > count_angle1) && (count < 1818))
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
