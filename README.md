This project is an example of how to build a app wrapper with a command line and 
JSON configuration file option.

## Get the two dependicies
wget https://github.com/nlohmann/json/releases/download/v3.3.0/json.hpp
wget https://github.com/CLIUtils/CLI11/releases/download/v1.6.1/CLI11.hpp

## For the meantime compile using
c++ -std=c++11 *.cpp -o tap -Wno-logical-op-parentheses

## run using
./tap -f test.json
