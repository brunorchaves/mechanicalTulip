
int led_pin = 6;
int button = 4;

void setup() {
  
  pinMode(led_pin, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  int buttonState = 0;
  buttonState = digitalRead(button);

  machineLEds(buttonState);
  machineServoMotor();
}
enum
{
  State_readButton=0,
  State_Rising,
  State_Fading,
};
void machineLEds(int button)
{
  static int state = 0;
  static int32_t counter=0;
  static int direction = 0;
  switch(state)
  {
    case State_readButton:
      if(button !=1)
      {
        direction ^=1;
        if(direction == 1)
          state = State_Rising;
        else
          state = State_Fading;
      }
      break;
    case State_Rising:
      if(counter >=254)
      {
        state = State_readButton;
      }
      counter++;
      delay(5);
      break;
    case State_Fading:
      
      if(counter ==1)
      {
        state = State_readButton;
      }
      counter--;
      delay(5);
      break;
    default:
      break;
  }
  analogWrite(led_pin, counter);
  
}
