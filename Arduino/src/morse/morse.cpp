#include <Arduino.h>
#include <Servo.h>
#include <Keypad.h>

#define CODE_SIZE 4

char code[CODE_SIZE] = {'1', '2', '3', '4'};
int pinServo = 13;
int speaker = 11;
int state = 0;
Servo servo;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void note(int freq, int time)
{
	tone(speaker, freq, time);
	delay(time);
}

void musicBad()
{
	int i = 500; // The starting pitch
	while(i > 100) {
		i--;
		tone(speaker, i); // Emit the noise
		delay(1);
	}
	//delay(100); // A short break in between each whoop
    noTone(speaker);
}

// <editor-fold desc='Music'>

char notes[] = "gabygabyxzCDxzCDabywabywzCDEzCDEbywFCDEqywFGDEqi        azbC"; // a space represents a rest
int length = sizeof(notes); // the number of notes
int beats[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 2,3,3,16,};
int tempo = 75;

void playTone(int tone, int duration) {
	for (long i = 0; i < duration * 1000L; i += tone * 2) {
		digitalWrite(speaker, HIGH);
		delayMicroseconds(tone);
		digitalWrite(speaker, LOW);
		delayMicroseconds(tone);
	}
}

void playNote(char note, int duration) {
	char names[] = { 'c', 'd', 'e', 'f', 'g', 'x', 'a', 'z', 'b', 'C', 'y', 'D', 'w', 'E', 'F', 'q', 'G', 'i' };
	// c=C4, C = C5. These values have been tuned.
	int tones[] = { 1898, 1690, 1500, 1420, 1265, 1194, 1126, 1063, 1001, 947, 893, 843, 795, 749, 710, 668, 630, 594 };

	// play the tone corresponding to the note name
	for (int i = 0; i < 18; i++) {
		if (names[i] == note) {
			playTone(tones[i], duration);
		}
	}
}

void zeldaSong()
{
	tone(speaker, 1000, 1);
	delay(10);

	for (int i = 0; i < length; i++) {
		if (notes[i] == ' ') {
			delay(beats[i] * tempo); // rest
		} else {
			playNote(notes[i], beats[i] * tempo);
		}
		// pause between notes
		delay(tempo / 2);
	}
}
//</editor-fold>

bool sameArrays(char arr1[], char arr2[], int size)
{
	for (int i = 0; i < size; i++) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

bool detectCode()
{
	char codeBuffer[CODE_SIZE];
	char pressed = '\0';
	int i =0;

	while ( i < CODE_SIZE) {
		pressed = customKeypad.getKey();
		if(pressed)
		{
			Serial.print("Detected: ");
			Serial.println(pressed);
			codeBuffer[i] = pressed;
			i++;
		}
	}
	if (sameArrays(codeBuffer, code, CODE_SIZE))
	{
		Serial.println("Code OK");
		return true;
	}
	else
	{
		Serial.println("Bad CODE!");
		return false;
	}
}

void openDoor()
{
	Serial.println("OPEN");
	servo.write(140);
	digitalWrite(LED_BUILTIN, HIGH);
}

void closeDoor()
{
	Serial.println("CLOSED");
	servo.write(35);
	digitalWrite(LED_BUILTIN, LOW);
}



void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	Serial.begin(115200);
	Serial.println("Beggin");
	servo.attach(pinServo);
	openDoor();
	musicBad();
}

void loop()
{
	if(detectCode())
	{
		zeldaSong();
		openDoor();
	}
	else
	{
        musicBad();
		closeDoor();
	}

}    //*/
