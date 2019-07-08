#include <SoftwareSerial.h>
SoftwareSerial mySerial(3, 2);
String reading="{  \"deviceId\" : 2, \"lat\" : 12.983027,  \"lon\" : 80.2594,  \"udmlevel\" : 37,  }";


void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
  setupHttpInit();
 // sendDataToServer(0);
}


  void loop()
{
//  if (Serial.available()>0)
//   switch(Serial.read())
//  {
//    case 'd':
//      StartCall();
//      delay(1000);  
//      break;
//    case 'h':
//      CutCall();
//      break;
//    case 'a':
////      Internet();
//      delay(1000);
//      break;
// }
//  

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}

//void StartCall()
//{
//  mySerial.print("ATD+918451077962;\r");
//
//  delay(1000);
//}
//void CutCall()
//{
//  mySerial.print("ATH\r");
//
//  delay(1000);
//}

//void Internet()
//{
//  mySerial.print("AT+CFUN=1\r");
//  mySerial.print("AT+CPIN?\r");
//  mySerial.print("AT+CSTT="www","",""\r");
//  mySerial.print("AT+CIICR\r");
//  mySerial.print("AT+CIFSR\r");
//  mySerial.print("AT+SAPBR=3,1"Contype","GPRS"\r");
//  mySerial.print("AT+CIPSTART="TCP","exploreembedded.com",80\r");
//  mySerial.print("AT+CIPSEND=63\r");
//
//  delay(1000);
//}

//Serial.println("");
//mySerial.println("\r\n");

void setupHttpInit() {
  
Serial.println("See if the SIM808 is ready");
mySerial.println("AT\r\n");
waitUntilReponse(500);

Serial.println("SIM card inserted and unlocked?");
mySerial.println("AT+CPIN?\r\n");
waitUntilReponse(500);


Serial.println("Is the SIM card registered?");
mySerial.println("AT+CREG?\r\n");
delay(1000);
waitUntilReponse(500);

Serial.println("Is GPRS attached?");
mySerial.println("AT+CGATT?\r\n");
delay(1000);
waitUntilReponse(500);


Serial.println("Check signal strength - should be 9 or higher");
mySerial.println("AT+CSQ\r\n");
delay(1000);
waitUntilReponse(500);

//Serial.println("");
//mySerial.println("\r\n");
delay(1000);
//AT+CSTT / AT+CIICR/ AT+CIFSR


mySerial.println("AT+CSTT\r\n");
delay(1000);


mySerial.println("AT+CIICR\r\n");
delay(1000);


mySerial.println("AT+CIFSR\r\n");
delay(1000);

Serial.println("Set connection type to GPRS");
mySerial.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\" \r\n");
delay(1000);
waitUntilReponse(500);

Serial.println("Set the APN - this will depend on your network/service provider");
mySerial.println("AT+SAPBR=3,1,\"APN\",\"www\"\r\n");
delay(1000);
waitUntilReponse(500);

Serial.println("Enable GPRS - this will take a moment or two");
mySerial.println("AT+SAPBR=1,1\r\n");
delay(1000);
waitUntilReponse(500);

//Serial.println("");
//mySerial.println("\r\n");

Serial.println("Check to see if connection is correct and get your IP address");
mySerial.println("AT+SAPBR=2,1\r\n");
delay(1000);
waitUntilReponse(500);

Serial.println("Enable HTTP mode");
mySerial.println("AT+HTTPINIT\r\n");
delay(1000);
mySerial.println("AT+HTTPINIT\r\n");
delay(1000);
mySerial.println("AT+HTTPINIT\r\n");
delay(1000);
mySerial.println("AT+HTTPINIT\r\n");
delay(1000);
mySerial.println("AT+HTTPINIT\r\n");
delay(1000);
mySerial.println("AT+CMEE?\r\n");
//AT+CMEE=2\r
delay(1000);
waitUntilReponse(500);

String udmstring = udmstring + udmlevelvar;


mySerial.println("at+httppara=\"url\",\"http://snarks.000webhostapp.com/fire.php?deviceId=2&lat=50&lon=60&udmlevel=75\"\r\n");

mySerial.println("at+httpaction=0");


















//mySerial.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\" \r\n");
Serial.println("Set HTTP profile identifier");
mySerial.println("AT+HTTPPARA=\"CID\",1 \r\n");
delay(1000);
waitUntilReponse(500);

Serial.println("Put in the URL of the PHP webpage where you will post ");
mySerial.println("AT+HTTPPARA=\"URL\",\"http://snarks.000webhostapp.com/fire.php\"");
delay(1000);
waitUntilReponse(500);

mySerial.println("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
//("AT+HTTPPARA=\"CONTENT\",\"application/json\"");
delay(1000);
waitUntilReponse(500);

Serial.println("Tell the SIM808 how much data you'll send (18 bytes here) and how long to wait for a time-out (10,000 ms here)");
mySerial.println("AT+HTTPDATA="+String(reading.length()) + ",60000");

//("AT+HTTPDATA=" + String(reading.length()) + ",100000");
//delay(1000);
//waitUntilReponse(500);
mySerial.println(reading);
//Serial.println("Key in the data you want to send after you get the DOWNLOAD prompt.");
//mySerial.println("{\"deviceId\": 11, \"lat\": 333, \"lon\": 444, \"udmlevel\":777}\r\n\"");
//
////{"location_id": 238, "fill_percent": 90}
//
//delay(1000);
//waitUntilReponse(500);

//Serial.println("Post the data - wait a second for the response");
mySerial.println("AT+HTTPACTION=0\r\n");
//delay(1000);
//waitUntilReponse(500);

//Serial.println(" Read the response - www.posttestserver.com will give you a  URL where you can confirm that it's working");
mySerial.println("AT+HTTPREAD\r\n");
//delay(1000);
//waitUntilReponse(500);
//mySerial.println("AT+HTTPREAD\r\n");
//Serial.println("");
//mySerial.println("\r\n");

//Serial.println("Close the HTTP connection");
//mySerial.println("AT+HTTPTERM \r\n");
//delay(1000);
//waitUntilReponse(500);
//
//Serial.println("Disconnect the GPRS");
//mySerial.println("AT+SAPBR=0,1\r\n");
//delay(1000);
//waitUntilReponse(500);

//
//mySerial.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\"\r\n");
//delay(1000);
//waitUntilReponse(500);
//mySerial.println("AT+SAPBR=3,1,\"APN\",\"www\"\r\n");
//delay(1000);
//waitUntilReponse(500);
//mySerial.println("AT+SAPBR=1,1\r\n");
//delay(3000);
//waitUntilReponse(500);
//mySerial.println("AT+HTTPINIT\r\n");
//delay(300);
//waitUntilReponse(500);
}
//void sendDataToServer(int deviceId) {
//int latitude,longitude;
//mySerial.println("AT+HTTPINIT=?\r\n");
//delay(300);
//waitUntilReponse(500);
//mySerial.println("AT+HTTPPARA=\"CID\",1\r\n");
//delay(300);
//waitUntilReponse(500);
//mySerial.write("AT+HTTPPARA=\"URL\",\"http://snarks.000webhostapp.com/fire.php?deviceId=0&lat=555&lon=777&udmlevel=236\"\r\n");
//waitUntilReponse(500);
//mySerial.print(deviceId);
//mySerial.write("&lat=");
//mySerial.print(latitude,9);
//mySerial.write("&lon=");
//mySerial.print(longitude,9);
//mySerial.write(":80\"\r\n");
//delay(500);
//waitUntilReponse(500);
//mySerial.write("AT+HTTPACTION=0\r\n");
//delay(3000);
//waitUntilReponse(500);
//mySerial.write("AT+HTTPDATA=40,10000\r\n");
//delay(500);
//waitUntilReponse(500);
//}
void waitUntilReponse(int delayMs)
{
// Delay in ms
while (mySerial.available() < 0) { delay(delayMs); } while (mySerial.available() > 0) {
Serial.write(mySerial.read());
}

}
