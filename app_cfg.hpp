#ifndef APP_CFG_H
#define APP_CFG_H

#include "json.hpp"
using json = nlohmann::json;

/*
Class to hold all global program configuration
*/
class cfg {
public:
	int p;
    std::string setupFile;
    json configFromFile;

    int processJsonConfig ();
};

#endif
