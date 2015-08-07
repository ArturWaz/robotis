
set(dynamixel_source_files asynchronousPacketReader.h asynchronousPacketReader.cpp MX28.cpp MX28.h  MX12W.h _base_communicationV1.h _base_communicationV1.cpp)

add_library(robotis ${dynamixel_source_files})

