#include <settings.h>

class Device {
    public:
        Device(uint16_t device_id, uint8_t type);
        virtual DataPack run(DataPack input);
        DataPack report();
    protected:
        uint16_t device_id;
        uint8_t type;
        uint8_t status;
};

Device::Device(uint16_t device_id, uint8_t type){
    this->device_id = device_id;
    this->type = type;
}

DataPack Device::report() {
    DataPack out;
    out.addData(DEVICE_ID_KEY, this->device_id);
    out.addData(DEVICE_TYPE_KEY, this->type);
    out.addData(DEVICE_STATUS_KEY, this->status);
    return out;
}
