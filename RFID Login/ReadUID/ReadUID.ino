#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN       9
#define SS_PIN        10

MFRC522 mfrc522(SS_PIN, RST_PIN);
String UIDString;
String UID;




void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  
}

void SerialPrintHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? "0" : "");
    Serial.print(buffer[i], HEX);
  }
}



void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  SerialPrintHex(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();
  
}
     
