#include <input_device.h>

class TSensor: public input_device {
private:
    uint8_t pin;
public:
IrSensor(uint16_t device_id, uint16_t threshold, long sample_time):input_device(device_id,threshold,sample_time){};
    bool init(uint8_t pin);
    uint16_t read();
};

uint8_t TSensor::init(uint8_t pin){
    this->pin=pin
    this->read_timer=millis();

}

uint16_t TSensor::read(){
    return digitalRead(this->pin);
}

