void Reset ()
{
  if (inicie == 1 or PANIC == 1) {

    if (digitalRead(RESET) == 0 and RST == 0)
    {

      Serial.println("SE APRETO RESET 1 VEZ");
      interruptCounter = 3;
      treset = millis();
      RST = 1;
      Serial.println(treset);
      Serial.println(tpress);
      Serial.println(treset + tpress);
    }
    else if (digitalRead(RESET) == 1)
    {
      RST = 0;
    }

    if (millis() - tpress > treset and digitalRead(RESET) == 0)
    {
      Serial.println("REINICIANDO PORQUE SE APRETO 3SEG");
      finish = 0;
      interruptCounter = 0;
      inicie = 0;
      RST = 0;
      PANIC = 0;
      digitalWrite(LEDOK, LOW);
      digitalWrite(LEDFAULT, HIGH);
      delay(2000);
      digitalWrite(LEDFAULT, LOW);
    }

  }
}
