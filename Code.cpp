// INSTALL RF24 LIBRARY FROM ARDUINO IDE
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define NRF24L01+ Pins
#define CE_PIN 9  
#define CSN_PIN 10 

// Initialize RF24 module
RF24 radio(CE_PIN, CSN_PIN);

// Total number of channels (0 to 124) but 125 so it goes max!
const int num_channels = 125;
int current_channel = 0;

void setup() {
    Serial.begin(115200);

    if (!radio.begin()) {
        Serial.println("NRF24 Module Not Detected! Check your wiring and follow the diagram!");
        while (1); // Stop if module is not found
    }

    Serial.println("NRF24+ module connected!");
    
    // Configure radio for maximum disruption
    radio.setAutoAck(false);             // Disable auto-acknowledge
    radio.stopListening();               // Transmit mode
    radio.setRetries(0, 0);              // No retries
    radio.setPALevel(RF24_PA_HIGH);      // High power mode
    radio.setDataRate(RF24_2MBPS);       // Fastest data rate
    radio.setCRCLength(RF24_CRC_DISABLED); // Disable CRC for speed

    Serial.println("Jammer Ready!");
}

void loop() {
    // Set the channel
    radio.setChannel(current_channel);

    // Print the current channel to the serial monitor
    Serial.print("Jamming on Channel: ");
    Serial.println(current_channel);

    // Sending data
    uint8_t jamData[32] = {0};  // Empty data packet (max size: 32 bytes)
    radio.write(jamData, sizeof(jamData));

    // Hop to the next channel
    current_channel++;
    if (current_channel >= num_channels) {
        current_channel = 0;  // Restart from the first channel
    }

    delay(5); // Adjust speed of channel hopping, 5 is default!
}
