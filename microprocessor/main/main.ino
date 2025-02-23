#include <LoRa.h>

#include "LoRaHandler.h"

void setup() {
    if (!initLoRa()) {
        while (1); // Halt if LoRa initialization fails
    }
    
    // Example: Change frequency after initialization
    delay(3000);
    // setLoRaFrequency(868E6); // Change to 868 MHz
}

void loop() {
    sendLoRaMessage("Hello, LoRa!");
    delay(2000);
}