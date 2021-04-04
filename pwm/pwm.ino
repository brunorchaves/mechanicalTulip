
int led_pin = 6;
int button = 4;

void setup() {
  
  pinMode(led_pin, OUTPUT);
  pinMode(button, INPUT);
   Serial.begin(9600);
}

void loop() {
  int buttonState = 0;
  buttonState = digitalRead(button);
  Serial.println(buttonState);
  machineLEds(buttonState);
  //machineServoMotor();
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
      if(button == 0)
      {
        direction ^=1;
        if(direction == 1)       
        {
          state = State_Rising;
          counter = 1;
        }
        else
        {
          state = State_Fading;
          counter = 255;
        }
      }

      break;
    case State_Rising:
      if(counter >=254)
      {
        state = State_readButton;
      }
      counter++;
      analogWrite(led_pin, counter);
      delay(5);
      break;
    case State_Fading:
      
      if(counter ==1)
      {
        state = State_readButton;
      }
      counter--;
      analogWrite(led_pin, counter);
      delay(5);
      break;
    default:
      break;
  }
  
  
}
