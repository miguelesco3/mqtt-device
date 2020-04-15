#include <input_device.h>
#include <DHT.h>

#define DHTTYPE DHT22
DHT dht(pin, DHTTYPE);

class DHTsensor: public InputDevice {
private:
    uint8_t pin;
public:
    DHTsensor(uint16_t device_id, uint16_t threshold, long sample_time): InputDevice(device_id, threshold, sample_rate) {};
    bool init(uint8_t pin);
    uint16_t read();
    uint16_t readhum();
};

bool DHTsensor::init(uint8_t pin){
    this->pin = pin;
    this->read_timer = millis();
}

uint16_t DHTsensor::read(){
    float t = dht.readTemperature();
        return (t);
}
uint16_t DHTsensor::readhum(){
    float h = dht.readHumidity();
        return (h);
}
