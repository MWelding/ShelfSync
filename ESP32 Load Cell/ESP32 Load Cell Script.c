#include <HX711.h>
#include <Preferences.h>


const int LOADCELL_DOUT_PIN = 32; 
const int LOADCELL_SCK_PIN = 33;  


HX711 scale;


Preferences preferences;
float calibration_factor = 1.0; 


float known_weight = 1000.0; 
void setup() {
  Serial.begin(115200);
  

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  

  preferences.begin("weight_calibration", false);
  calibration_factor = preferences.getFloat("calibration_factor", 1.0);
  preferences.end();

  // Perform a one-time calibration if no calibration exists in NVS
  if (calibration_factor == 1.0) {
    Serial.println("No calibration found. Calibrating...");
    calibrate();
  } else {
    Serial.print("Using saved calibration factor: ");
    Serial.println(calibration_factor);
  }

  // Set the scale to use the calibration factor
  scale.set_scale(calibration_factor);
  scale.tare();  // Zero the scale

  Serial.println("Scale ready to measure weight.");
}

void loop() {
  // Continuously read the weight
  if (scale.is_ready()) {
    long weight = scale.get_units(10);  // Get the average of 10 readings
    Serial.print("Weight: ");
    Serial.print(weight);
    Serial.println(" g");
  } else {
    Serial.println("HX711 not found.");
  }
  
  delay(1000);  // Read every second
}

void calibrate() {
  // The user needs to place a known weight on the scale for calibration.
  Serial.println("Place a known weight (e.g., 1000g) on the scale.");
  delay(5000); // Give the user 5 seconds to place the weight
  
  // Read the raw value for the known weight
  long raw_value = scale.get_units(10);  // Average of 10 readings
  Serial.print("Raw value with weight: ");
  Serial.println(raw_value);

  // Calculate the calibration factor
  calibration_factor = raw_value / known_weight;
  Serial.print("Calculated calibration factor: ");
  Serial.println(calibration_factor);

  // Save the calibration factor to NVS
  preferences.begin("weight_calibration", false);
  preferences.putFloat("calibration_factor", calibration_factor);
  preferences.end();

  // Set the new calibration factor for the scale
  scale.set_scale(calibration_factor);

  Serial.println("Calibration complete.");
}

