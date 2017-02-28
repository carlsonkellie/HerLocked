// Include BLE files.
#include <SPI.h>
#include <boards.h>
#include <RBL_nRF8001.h>

// Define output pin
#define LED_PIN 2

void setup()
{
  // Enable serial debug.
  Serial.begin(9600);
  Serial.println("Arduino EasyBLE example started");
  Serial.println("Serial rate set to 9600");

  // Enable output.
  pinMode(LED_PIN, OUTPUT);

  // Turn off LED.
  digitalWrite(LED_PIN, LOW);

  // Initialize BLE library.
  ble_begin();

  // Set a custom BLE name.
  ble_set_name("ble_led");

  Serial.println("ble_begin done!");
}

// This function is called continuously, after setup() completes.
void loop()
{
  // If there's any input...
  while (ble_available())
  {
    // Read input.
    int c = ble_read();
    Serial.println("Got input:");
    if (c != 0)
    {
      // Non-zero input means "turn on LED".
      Serial.println("Led: on");
      digitalWrite(LED_PIN, HIGH);
    }
    else
    {
      // Input value zero means "turn off LED".
      Serial.println("Led: off");
      digitalWrite(LED_PIN, LOW);
    }
  }

  // Process BLE events.
  ble_do_events();
}
