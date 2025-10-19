#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'.', '0', '=', '/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

String currentNumber = "";
double num1 = 0;
double num2 = 0;
char operation = ' ';
bool resultCalculated = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    if (isdigit(customKey) || customKey == '.') {
      if (resultCalculated) {
        currentNumber = "";
        resultCalculated = false;
        lcd.clear();
        lcd.setCursor(0, 0);
      }
      currentNumber += customKey;
      lcd.print(customKey);
    } else if (customKey == '+' || customKey == '-' || customKey == '*' || customKey == '/') {
      if (currentNumber != "") {
        num1 = currentNumber.toDouble();
        currentNumber = "";
        operation = customKey;
        lcd.setCursor(0, 1);
        lcd.print(num1);
        lcd.print(operation);
      }
    } else if (customKey == '=') {
      if (currentNumber != "" && operation != ' ') {
        num2 = currentNumber.toDouble();
        double result = 0;
        switch (operation) {
          case '+':
            result = num1 + num2;
            break;
          case '-':
            result = num1 - num2;
            break;
          case '*':
            result = num1 * num2;
            break;
          case '/':
            if (num2 != 0) {
              result = num1 / num2;
            } else {
              lcd.clear();
              lcd.print("Error: Div by 0");
              delay(2000);
              lcd.clear();
              currentNumber = "";
              num1 = 0;
              num2 = 0;
              operation = ' ';
              return;
            }
            break;
        }
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(num1);
        lcd.print(operation);
        lcd.print(num2);
        lcd.print("=");
        lcd.print(result);
        currentNumber = String(result);
        num1 = result;
        num2 = 0;
        operation = ' ';
        resultCalculated = true;
      }
    }
  }
}
