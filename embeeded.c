#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

ESP8266WebServer server(80);

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, OUTPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Wire.begin(D2, D1);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" TRASH COLLECTOR ");
  lcd.setCursor(0, 1);
  lcd.print(" BOAT INITIALIZING ");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    lcd.setCursor(0, 0);
    lcd.print("Connecting to WiFi");
  }
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(1500);

  server.on("/", []() {
    String page = "<html><head><title>Trash Collector Boat</title></head>";
    page += "<body><center><h1>Trash Collector Boat Control</h1><br><br>";
    page += "<button onclick=\"sendCommand('forward')\">Forward</button>";
    page += "<button onclick=\"sendCommand('backward')\">Backward</button>";
    page += "<button onclick=\"sendCommand('left')\">Left</button>";
    page += "<button onclick=\"sendCommand('right')\">Right</button>";
    page += "<button onclick=\"sendCommand('stop')\">Stop</button>";
    page += "<script>";
    page += "function sendCommand(command) { var xhttp = new XMLHttpRequest();";
    page += "xhttp.open('GET', '/' + command, true); xhttp.send(); }</script>";
    page += "</center></body></html>";
    server.send(200, "text/html", page);
  });

  server.on("/forward", []() { controlMotors('F'); server.send(200, "text/plain", "Forward"); });
  server.on("/backward", []() { controlMotors('B'); server.send(200, "text/plain", "Backward"); });
  server.on("/left", []() { controlMotors('L'); server.send(200, "text/plain", "Left"); });
  server.on("/right", []() { controlMotors('R'); server.send(200, "text/plain", "Right"); });
  server.on("/stop", []() { controlMotors('S'); server.send(200, "text/plain", "Stop"); });

  server.begin();
}

void controlMotors(char command) {
  // Implement motor control logic based on the command
}

void loop() {
  server.handleClient();
}
