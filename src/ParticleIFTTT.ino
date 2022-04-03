
int photoresistor = A0;
int analogValue;
int i = 4;
int high = 0;
int low = 0;

void light()
{
  while (i != 0 && i != 7)
  {
    analogValue = analogRead(photoresistor);
    if (analogValue > 6)
    {
      Serial.println("IsLight");
      Serial.println(i);
      i++;
    }
    else
    {
      Serial.println("NoLight");
      Serial.println(i);
      i--;
    }
    delay(2s);
  }
}

void setup()
{

  Serial.begin(9600);
  pinMode(photoresistor, INPUT);
}

void loop()
{

  light();

  Serial.println("BreakOut");

  if (i == 7)
  {
    if (high == 0)
    {
      Serial.println("Notify light on");
      Particle.publish("on", "on");
      low = 0;
      high = 1;
    }
    else
    {
      Serial.println("Already Notified light on");
    }
  }
  else
  {
    if (low == 0)
    {
      Serial.println("Notify light off");
      Particle.publish("off", "off");
      high = 0;
      low = 1;
    }
    else
    {
      Serial.println("Already Notified light off");
    }
  }

  i = 4;

  delay(2s);
}
