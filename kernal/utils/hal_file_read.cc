#include "hal_file_read.h"
using namespace kernal;

bool hal_file_read::read_whole(const char* file, std::string& buffer) {

    buffer.clear();
    if (nullptr == file) {
        return false;
    }

    FILE* _file_handle = ::fopen(file, "r");
    if (nullptr == _file_handle) {
        return false;
    }

    ::fseek(_file_handle, 0, SEEK_END);
    int _file_size = ::ftell(_file_handle);
    ::fseek(_file_handle, 0, SEEK_SET);
    buffer.resize(_file_size);
    int _read_size = ::fread(&(buffer[0]), sizeof(char), _file_size, _file_handle);
    ::fclose(_file_handle);

    return _read_size == _file_size;
}
