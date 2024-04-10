# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/application/Espressif/frameworks/esp-idf-v5.0.4/components/bootloader/subproject"
  "D:/espidf-iot-project/build/bootloader"
  "D:/espidf-iot-project/build/bootloader-prefix"
  "D:/espidf-iot-project/build/bootloader-prefix/tmp"
  "D:/espidf-iot-project/build/bootloader-prefix/src/bootloader-stamp"
  "D:/espidf-iot-project/build/bootloader-prefix/src"
  "D:/espidf-iot-project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/espidf-iot-project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/espidf-iot-project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
