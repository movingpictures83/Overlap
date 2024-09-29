#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "OverlapPlugin.h"

void OverlapPlugin::input(std::string file) {
 inputfile = file;
readParameterFile(file);
}

void OverlapPlugin::run() {}

void OverlapPlugin::output(std::string file) {
 std::string outputfile = file;
myCommand += "overlap -i";
myCommand += " ";
addRequiredParameterNoFlag("window");
addRequiredParameter("-cols", "cols");
myCommand += " >& "+outputfile + " ";
 system(myCommand.c_str());
}

PluginProxy<OverlapPlugin> OverlapPluginProxy = PluginProxy<OverlapPlugin>("Overlap", PluginManager::getInstance());
