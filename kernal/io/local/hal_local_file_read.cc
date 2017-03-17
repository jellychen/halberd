#include "hal_local_file_read.h"
using namespace kernal;
using namespace io;

hal_local_file_read::hal_local_file_read() {
}

hal_local_file_read::~hal_local_file_read() {
}

std::shared_ptr<hal_package_data> hal_local_file_read::read(const char* name) {
    if (nullptr == name) {
        return std::shared_ptr<hal_package_data>();
    }

    FILE* _file_handle = ::fopen(name, "r");
    if (nullptr == _file_handle) {
        return std::shared_ptr<hal_package_data>();
    }
    ::fseek(_file_handle, 0, SEEK_END);
    int _file_size = ::ftell(_file_handle);
    ::fseek(_file_handle, 0, SEEK_SET);
    std::shared_ptr<hal_package_data> data(new hal_package_data());
    data->resize((uint32_t)_file_size);
    uint8_t* raw_buffer = data->raw_buffer();
    ::fread((void*)raw_buffer, sizeof(char), _file_size, _file_handle);
    ::fclose(_file_handle);

    return data;
}
