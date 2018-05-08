#include <SD.h>

int nMode = 0; //0-ожидание команды, 1-чтение, 2-запись

void WriteByte(int adr, int data){  

  int i;
  String sAdr, sData;
  
  // чтение
  digitalWrite(42, LOW);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);

  // сформируем строку адреса и данных
  sAdr = "";
  sData = "";
  for (i = sizeof(adr) * 8 - 1; i >= 0; --i)
  {
     sAdr = sAdr + (String)((adr >> i) & 1);
  }  
  for (i = sizeof(data) * 8 - 1; i >= 0; --i)
  {
     sData = sData + (String)((data >> i) & 1);
  }  

  // выберем адрес
  if (sAdr.substring(15) == "1")
    digitalWrite(39, HIGH);
  else 
    digitalWrite(39, LOW);
  if (sAdr.substring(14, 15) == "1")
    digitalWrite(38, HIGH);
  else 
    digitalWrite(38, LOW);    
  if (sAdr.substring(13, 14) == "1")
    digitalWrite(37, HIGH);
  else 
    digitalWrite(37, LOW);    
  if (sAdr.substring(12, 13) == "1")
    digitalWrite(36, HIGH);
  else 
    digitalWrite(36, LOW);    
  if (sAdr.substring(11, 12) == "1")
    digitalWrite(35, HIGH);
  else 
    digitalWrite(35, LOW);    
  if (sAdr.substring(10, 11) == "1")
    digitalWrite(34, HIGH);
  else 
    digitalWrite(34, LOW);    
  if (sAdr.substring(9, 10) == "1")
    digitalWrite(33, HIGH);
  else 
    digitalWrite(33, LOW);    
  if (sAdr.substring(8, 9) == "1")
    digitalWrite(32, HIGH);
  else 
    digitalWrite(32, LOW);    
  if (sAdr.substring(7, 8) == "1")
    digitalWrite(43, HIGH);
  else 
    digitalWrite(43, LOW);    
  if (sAdr.substring(6, 7) == "1")
    digitalWrite(41, HIGH);
  else 
    digitalWrite(41, LOW);    
  if (sAdr.substring(5, 6) == "1")
    digitalWrite(40, HIGH);
  else 
    digitalWrite(40, LOW);    

  // установим значение байта
  if (sData.substring(15) == "1")
    digitalWrite(24, HIGH);
  else 
    digitalWrite(24, LOW);
  if (sData.substring(14, 15) == "1")
    digitalWrite(25, HIGH);
  else 
    digitalWrite(25, LOW);    
  if (sData.substring(13, 14) == "1")
    digitalWrite(26, HIGH);
  else 
    digitalWrite(26, LOW);    
  if (sData.substring(12, 13) == "1")
    digitalWrite(27, HIGH);
  else 
    digitalWrite(27, LOW);    
  if (sData.substring(11, 12) == "1")
    digitalWrite(28, HIGH);
  else 
    digitalWrite(28, LOW);    
  if (sData.substring(10, 11) == "1")
    digitalWrite(29, HIGH);
  else 
    digitalWrite(29, LOW);    
  if (sData.substring(9, 10) == "1")
    digitalWrite(30, HIGH);
  else 
    digitalWrite(30, LOW);    
  if (sData.substring(8, 9) == "1")
    digitalWrite(31, HIGH);
  else 
    digitalWrite(31, LOW);    

  // подождем 10мс для выбора адреса
  delay(10);
  
  //запись
  digitalWrite(42, HIGH);
  digitalWrite(44, HIGH);
  delay(60); // задерживаем высокий уровень на 60мс для записи данных
  digitalWrite(44, LOW);
  digitalWrite(42, LOW);
}

void writeChip() {
  nMode = 0;
  int adr, dat;
  adr = 0;
  // открываем файл только для чтения
  File myFile = SD.open("code.hex");
  if (myFile) {
  
    // читаем файл посимвольно до конца:
    while (adr < 2048 && myFile.available()) {
        dat = myFile.read();
        Serial.print((String)adr+" - "+(String)dat+" - ");
        Serial.println(dat, HEX);
        WriteByte(adr, dat);
        adr++;
    }
    // закрываем файл:
    myFile.close();
  } else {
    // если файл не открылся, сообщает об ошибке:
    Serial.println("No file code.hex found!!!");
  }
}

void readChip() {

int r, i, adr = 0;
String sAdr, sData;

// чтение
  digitalWrite(42, LOW);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  adr = 0;
  while (adr < 2048) {
    // сформируем строку адреса
    sAdr = "";
    sData = "";
    for (i = sizeof(adr) * 8 - 1; i >= 0; --i)
    {
       sAdr = sAdr + (String)((adr >> i) & 1);
    }  
    
    // выберем адрес
    if (sAdr.substring(15) == "1")
      digitalWrite(39, HIGH);
    else 
      digitalWrite(39, LOW);
    if (sAdr.substring(14, 15) == "1")
      digitalWrite(38, HIGH);
    else 
      digitalWrite(38, LOW);    
    if (sAdr.substring(13, 14) == "1")
      digitalWrite(37, HIGH);
    else 
      digitalWrite(37, LOW);    
    if (sAdr.substring(12, 13) == "1")
      digitalWrite(36, HIGH);
    else 
      digitalWrite(36, LOW);    
    if (sAdr.substring(11, 12) == "1")
      digitalWrite(35, HIGH);
    else 
      digitalWrite(35, LOW);    
    if (sAdr.substring(10, 11) == "1")
      digitalWrite(34, HIGH);
    else 
      digitalWrite(34, LOW);    
    if (sAdr.substring(9, 10) == "1")
      digitalWrite(33, HIGH);
    else 
      digitalWrite(33, LOW);    
    if (sAdr.substring(8, 9) == "1")
      digitalWrite(32, HIGH);
    else 
      digitalWrite(32, LOW);    
    if (sAdr.substring(7, 8) == "1")
      digitalWrite(43, HIGH);
    else 
      digitalWrite(43, LOW);    
    if (sAdr.substring(6, 7) == "1")
      digitalWrite(41, HIGH);
    else 
      digitalWrite(41, LOW);    
    if (sAdr.substring(5, 6) == "1")
      digitalWrite(40, HIGH);
    else 
      digitalWrite(40, LOW);    
  
    // подождем 10мс для выбора адреса и прочтем данные
    delay(10);
    r = 0;
    if (digitalRead(24) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 0); } 
    else
      sData = "0" + sData; 
    if (digitalRead(25) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 1); } 
    else
      sData = "0" + sData; 
    if (digitalRead(26) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 2); } 
    else
      sData = "0" + sData;
    if (digitalRead(27) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 3); } 
    else
      sData = "0" + sData; 
    if (digitalRead(28) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 4); } 
    else
      sData = "0" + sData; 
    if (digitalRead(29) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 5); } 
    else
      sData = "0" + sData; 
    if (digitalRead(30) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 6); } 
    else
      sData = "0" + sData; 
    if (digitalRead(31) == HIGH){
      sData = "1" + sData;
      r = r + pow(2, 7); } 
    else
      sData = "0" + sData; 
  
    Serial.print(sAdr+" - "); 
    Serial.print(sData+" - ");
    Serial.println(r, HEX);

    adr++; 
  }
  nMode = 0;
}

void setup() {
  nMode = 0;
  Serial.begin(9600);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(53, OUTPUT);
  if (!SD.begin(53)) {
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("start...");
  pinMode(44, OUTPUT);
  digitalWrite(44, LOW);
  pinMode(42, OUTPUT);
  digitalWrite(42, LOW);  
  pinMode(39, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(40, OUTPUT);
  Serial.println("Init...done!");
  Serial.println("Waiting command...");
}
 
void loop() {
  if (digitalRead(4) == LOW && nMode == 0){
    delay(20); // защита от дребезга контактов
    if (digitalRead(4) == LOW && nMode == 0){
      Serial.println("Start writing chip...");
      nMode = 2;  
      writeChip();
      Serial.println("Writing complete!!!");
      delay(5000);
    }
  }

  if (digitalRead(5) == LOW && nMode == 0){
    delay(20); // защита от дребезга контактов
    if (digitalRead(5) == LOW && nMode == 0){
      Serial.println("Start reading chip...");
      nMode = 1;
      readChip();
      Serial.println("Reading complete!!!");
      delay(5000);
    }
  }  
  delay(100);
}
