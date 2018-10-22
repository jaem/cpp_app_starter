//-----------------------------------------------------------------------------
// Copyright (c) 2018 jamjam
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iterator>
#include "app_cfg.hpp"
#include "app.hpp"

// Third party Libraries
// JSON PArser for confgiuration
#include "json.hpp"
using json = nlohmann::json;
// Command lin parser
#include "CLI11.hpp"

//-----------------------------------------------------------------------------
//
// https://github.com/nlohmann/json/blob/develop/test/src/unit-serialization.cpp
// 
// Main 
// 
// 
// 
// 
//-----------------------------------------------------------------------------
/*
 * Main call
 */
int main(int argc, char **argv) {
    CLI::App appArgs{"Example app configuration setup."};

    cfg cfgObj;       // Configuration object
    app_to_run main;  // Main app object

    // Define options, all variables should exist in the config class.
    appArgs.add_option("-p", cfgObj.p, "Parameter");
    appArgs.add_option("-f,--file", cfgObj.setupFile, "Require an existing file")
                       //->required()
                       ->check(CLI::ExistingFile);

    // Parse the command line args
    CLI11_PARSE(appArgs, argc, argv);

    // process config file if it exists
    cfgObj.processJsonConfig();

    // Bail in here with our config object and read config files. Go to work
    return main.run(&cfgObj);

}
