This project is an example of how to build a app wrapper with a command line and 
JSON configuration file option.

## Get the two dependencies 
wget https://github.com/nlohmann/json/releases/download/v3.3.0/json.hpp<br>
wget https://github.com/CLIUtils/CLI11/releases/download/v1.6.1/CLI11.hpp

## For the meantime compile using<br>
c++ -std=c++11 *.cpp -o tap -Wno-logical-op-parentheses

## run using<br>
./tap -f test.json
