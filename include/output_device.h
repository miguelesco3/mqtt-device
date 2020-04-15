#include <device.h>

class OutputDevice: public Device {
    protected:
        uint16_t value;
        virtual uint16_t read();
    public:

        virtual bool hasChange();
        uint16_t getValue();
        DataPack run(DataPack input);
};

bool OutputDevice::hasChange(){
    if(millis()-this->read_timer >= this->sample_rate){
        this->read_timer = millis();
        uint16_t temp_value = this->read();
        if(abs(temp_value - value) >= threshold){
            this->value = temp_value;
            return true;
        }
    }
    return false;
}

uint16_t OutputDevice::getValue(){
    return this->value;
}

DataPack out = sensor.run(input);

