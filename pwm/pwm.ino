//Initializing LED Pin
int led_pin = 6;
int led_pinD = 4;
void setup() {
  //Declaring LED pin as output
  pinMode(led_pin, OUTPUT);
  pinMode(led_pinD, OUTPUT);
}
enum
{
  Estado_Subindo=0,
  Estado_Descendo,
};
void loop() {
  //Fading the LED
  static int32_t estado = 0;
  static int32_t counter=0;
  switch(estado)
  {
    case Estado_Subindo:
      
      
      if(counter >=254)
      {
        estado = Estado_Descendo;
      }
      counter++;
      break;
    case Estado_Descendo:
      
      if(counter ==1)
      {
        estado = Estado_Subindo;
      }
      counter--;
      break;
    default:
      break;
  }
  analogWrite(led_pin, counter);
  delay(5);

}
