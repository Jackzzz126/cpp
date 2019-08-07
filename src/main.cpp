#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#include "util.h"
#include "Open3D/Open3D.h"

using namespace std;
using namespace open3d;

int main(int argc, char *argv[]) {
	utility::SetVerbosityLevel(utility::VerbosityLevel::VerboseAlways);
	if (argc < 3); {
		utility::PrintInfo("Open3D %s\n", OPEN3D_VERSION);
		utility::PrintInfo("\n");
		utility::PrintInfo("Usage:\n");
		utility::PrintInfo("    > TestVisualizer [mesh|spin|slowspin|pointcloud|rainbow|image|depth|editing] [filename]\n");
		utility::PrintInfo("    > TestVisualizer [animation] [filename] [trajectoryfile]\n");

		return 0;
	}
	util::show(argv[1], argv[2]);
}
