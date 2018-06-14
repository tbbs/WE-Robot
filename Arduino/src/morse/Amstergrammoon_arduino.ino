const unsigned int pinLED = LED_BUILTIN ;
const unsigned int pin0 = 0 ;
const unsigned int pin1 = 1 ;
const unsigned int pin2 = 2 ;
const unsigned int pin3 = 3 ;
const unsigned int pin4 = 4 ;
const unsigned int pin5 = 5 ;
const unsigned int pin6 = 6 ;
const unsigned int pin7 = 7 ;
const unsigned int pin8 = 8 ;
const unsigned int pin9 = 9 ;
const short digitCodeSafe = 1234 ;
const char morseCodeSafe[] = "Yes23" ;   

void setup() {
  pinMode(pinLED,OUTPUT) ;
  pinMode(pin0,INPUT) ;
  pinMode(pin1,INPUT) ;
  pinMode(pin2,INPUT) ;
  pinMode(pin3,INPUT) ;
  pinMode(pin4,INPUT) ;
  pinMode(pin5,INPUT) ;
  pinMode(pin6,INPUT) ;
  pinMode(pin7,INPUT) ;
  pinMode(pin8,INPUT) ;
  pinMode(pin9,INPUT) ;
}

void loop() {
  int i ;
  char charact ;

  for(i = 0 ; i < strlen(morseCodeSafe) ; i++)
  {
    charact = morseCodeSafe[i] ;
    charact = toLowerCase(charact) ;
    GenerateMorse(charact) ;
    delay(750) ;
  }
  delay(2500) ;
}

void GenerateMorse(char charact) {
  switch(charact)
  {
    case 'a':
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'b':
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case 'c':
      MorseDash() ;
      MorseDot() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    case 'd':
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case 'e':
      MorseDot() ;
      break ;
    case 'f':
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    case 'g':
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    case 'h':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case 'i':
      MorseDot() ;
      MorseDot() ;
      break ;
    case 'j':
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case 'k':
      MorseDash() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'l':
      MorseDot() ;
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case 'm':
      MorseDash() ;
      MorseDash() ;
      break ;
    case 'n':
      MorseDash() ;
      MorseDot() ;
      break ;
    case 'o':
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case 'p':
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    case 'q':
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'r':
      MorseDot() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    case 's':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case 't':
      MorseDash() ;
      break ;
    case 'u':
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'v':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'w':
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case 'x':
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case 'y':
      MorseDash() ;
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case 'z':
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case '0':
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      break ;    
    case '1':
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case '2':
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case '3':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      MorseDash() ;
      break ;
    case '4':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDash() ;
      break ;
    case '5':
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case '6':
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case '7':
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case '8':
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      MorseDot() ;
      break ;
    case '9':
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDash() ;
      MorseDot() ;
      break ;
    default:
      break ;
  }
}

void MorseDot() {
  digitalWrite(pinLED,HIGH) ;
  delay(500) ;
  digitalWrite(pinLED,LOW) ;
  delay(500) ;
}

void MorseDash() {
  digitalWrite(pinLED,HIGH) ;
  delay(2000) ;
  digitalWrite(pinLED,LOW) ;
  delay(500);
}

