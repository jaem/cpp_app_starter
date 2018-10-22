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
#include <fstream>

#include "app_cfg.hpp"

// Our config files will be small. This is not a performant section of
// code. We are looking for a simple PERL Slurp tro std::string
// https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
// std::ifstream t(cfgObj.setupFile);
// std::stringstream buffer;
// buffer << t.rdbuf();
// Went with this exampe from JSON GH.

int cfg::processJsonConfig() {

    // Read the file and create stream into JSON object
    std::ifstream inStream(this->setupFile); // Read the file
    inStream >> this->configFromFile; // Stream into a JSON object

    // https://stackoverflow.com/questions/45934851/c-nlohmann-json-how-to-iterate-find-a-nested-object

    // Level 1 Keys
    for (json::iterator it = this->configFromFile.begin(); it != this->configFromFile.end(); ++it) {
      std::cout << it.key() << " : " << it.value() << "CFG :" << it.value().size() <<"\n";

      if (it.value().is_structured()) {
      	// Level 2
        for (json::iterator itSub = it.value().begin(); itSub != it.value().end(); ++itSub) {
          std::cout << "-------" << itSub.key() << " : " << itSub.value() << "  -- " << itSub.value().is_structured() <<"\n";
        }
      }

    }

    // Level 1 Keys, direct acces example. You can test for null 
    for (json::iterator it = this->configFromFile.begin(); it != this->configFromFile.end(); ++it) {
      std::cout << "Direct Access : " << this->configFromFile[it.key()]["debug"] << "\n";
      std::cout << "Direct Access : " << this->configFromFile[it.key()]["debugd"] << "\n";
    }

    // 
    std::cout << "\n\n" << this->configFromFile << "\n\n" << this->configFromFile.size() << "\n";

    std::cout << "Direct Access : " << this->configFromFile["widget"]["debugd"] << "\n";

    return 0;
}

