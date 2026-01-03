int butoane[3] = {2, 3, 4};
int leduri[3]  = {8, 9, 10};
int buzzer = 11;
int switchButton = 12;

int current = -1;
int roundCount = 0;
unsigned long startTime;
bool gameStarted = false;
bool gameOver = true; 
bool waitingForStart = true;
int gameMode = 0; // 0 = Viteza 10, 1 = Reactie contra timp

unsigned long ledOnTime = 0;
float reactionTime = 2000;
const float minReactionTime = 400;
const float decreaseStep = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));

  for(int i=0; i<3; i++){
    pinMode(butoane[i], INPUT_PULLUP);
    pinMode(leduri[i], OUTPUT);
    digitalWrite(leduri[i], LOW);
  }

  pinMode(buzzer, OUTPUT);
  pinMode(switchButton, INPUT_PULLUP);

  Serial.println("Alege modul (switch) si apasa orice buton de joc pentru start.");
  printCurrentMode();
}

void loop() {
  if(digitalRead(switchButton) == LOW){
    delay(250); 
    if(gameMode == 1)
      gameMode = 0;
    else 
      gameMode = 1;
    printCurrentMode();
    blinkAllLEDs(1, 100); 
  }

  if(waitingForStart){
    for(int i=0; i<3; i++){
      if(digitalRead(butoane[i]) == LOW){
        delay(200);
        startGame();
      }
    }
    return; 
  }

  if(gameMode == 0) playViteza10();
  else playReactieContraTimp();
}

void printCurrentMode() {
  Serial.print("MOD SELECTAT: ");
  if (gameMode == 0)
    Serial.println("Viteza 10\n");
  else
    Serial.println("Reactie contra timp\n");
}

void startGame() {
  Serial.println("\nJOCUL INCEPE ACUM!");
  waitingForStart = false;
  gameOver = false;
  gameStarted = true;
  roundCount = 0;
  reactionTime = 2000;
  startTime = millis();
  nextLed();
}

void playViteza10(){
  for(int i=0; i<3; i++){
    if(digitalRead(butoane[i]) == LOW){
      if(i == current){
        digitalWrite(leduri[current], LOW);
        tone(buzzer, 1000, 80);
        roundCount++;
        if(roundCount >= 10){
          unsigned long totalTime = millis() - startTime;
          Serial.print("FELICITARI! Timp final: ");
          Serial.print(totalTime / 1000.0);
          Serial.println(" secunde.");
          endGame();
        } else {
          delay(150);
          nextLed();
        }
      } else {
        fail("Gresit! Ai apasat butonul incorect.");
      }
    }
  }
}


void playReactieContraTimp(){
  for(int i=0; i<3; i++){
    if(digitalRead(butoane[i]) == LOW){
      if(i == current){
        digitalWrite(leduri[current], LOW);
        tone(buzzer, 1200, 80);
        roundCount++;
        if(reactionTime > minReactionTime) reactionTime -= decreaseStep;
        delay(100);
        nextLed();
      } else {
        fail("Gresit!");
      }
    }
  }
  if(millis() - ledOnTime > (unsigned long)reactionTime){
    fail("PREA LENT! Timpul a expirat.");
  }
}

void nextLed(){
  int prev = current;
  while(current == prev){
    current = random(0,3);
  }
  digitalWrite(leduri[current], HIGH);
  ledOnTime = millis();
}

void fail(String msg){
  Serial.println(msg);
  Serial.print("Scor final: ");
  Serial.print(roundCount + "\n");
  tone(buzzer, 150, 600);
  endGame();
}

void endGame(){
  for(int i=0; i<3; i++) digitalWrite(leduri[i], LOW);
  gameOver = true;
  waitingForStart = true; 
  Serial.println("Joc terminat. Astept o noua comanda...\n");
  blinkAllLEDs(3, 80);
}

void blinkAllLEDs(int times, int delayTime){
  for(int t=0; t<times; t++){
    for(int i=0; i<3; i++) digitalWrite(leduri[i], HIGH);
    delay(delayTime);
    for(int i=0; i<3; i++) digitalWrite(leduri[i], LOW);
    delay(delayTime);
  }
}