#include <thread>

#include "Open3D/Open3D.h"
using namespace open3d;

#include "util.h"

namespace util{//ns util

void show(const string& typeName, const string& fileName, const string& trajectoryFileName) {
	if (typeName == "mesh") {
		auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
		if (io::ReadTriangleMesh(fileName, *mesh_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		mesh_ptr->ComputeVertexNormals();
		visualization::DrawGeometries({mesh_ptr}, "Mesh", 1600, 900);
	} else if (typeName == "spin") {
		auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
		if (io::ReadTriangleMesh(fileName, *mesh_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		mesh_ptr->ComputeVertexNormals();
		visualization::DrawGeometriesWithAnimationCallback(
				{mesh_ptr},
				[&](visualization::Visualizer *vis) {
				vis->GetViewControl().Rotate(10, 0);
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
				return false;
				},
				"Spin", 1600, 900);
	} else if (typeName == "slowspin") {
		auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
		if (io::ReadTriangleMesh(fileName, *mesh_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		mesh_ptr->ComputeVertexNormals();
		visualization::DrawGeometriesWithKeyCallbacks(
				{mesh_ptr},
				{{GLFW_KEY_SPACE,
				[&](visualization::Visualizer *vis) {
				vis->GetViewControl().Rotate(10, 0);
				std::this_thread::sleep_for(
						std::chrono::milliseconds(30));
				return false;
				}}},
				"Press Space key to spin", 1600, 900);
	} else if (typeName == "pointcloud") {
		auto cloud_ptr = std::make_shared<geometry::PointCloud>();
		if (io::ReadPointCloud(fileName, *cloud_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		cloud_ptr->NormalizeNormals();
		visualization::DrawGeometries({cloud_ptr}, "PointCloud", 1600, 900);
	} else if (typeName == "rainbow") {
		auto cloud_ptr = std::make_shared<geometry::PointCloud>();
		if (io::ReadPointCloud(fileName, *cloud_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		cloud_ptr->NormalizeNormals();
		cloud_ptr->colors_.resize(cloud_ptr->points_.size());
		double color_index = 0.0;
		double color_index_step = 0.05;

		auto update_colors_func = [&cloud_ptr](double index) {
			auto color_map_ptr = visualization::GetGlobalColorMap();
			for (auto &c : cloud_ptr->colors_) {
				c = color_map_ptr->GetColor(index);
			}
		};
		update_colors_func(1.0);

		visualization::DrawGeometriesWithAnimationCallback(
				{cloud_ptr},
				[&](visualization::Visualizer *vis) {
				color_index += color_index_step;
				if (color_index > 2.0) color_index -= 2.0;
				update_colors_func(fabs(color_index - 1.0));
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				return true;
				},
				"Rainbow", 1600, 900);
	} else if (typeName == "image") {
		auto image_ptr = std::make_shared<geometry::Image>();
		if (io::ReadImage(fileName, *image_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		visualization::DrawGeometries({image_ptr}, "Image", image_ptr->width_,
				image_ptr->height_);
	} else if (typeName == "depth") {
		auto image_ptr = io::CreateImageFromFile(fileName);
		camera::PinholeCameraIntrinsic camera;
		camera.SetIntrinsics(640, 480, 575.0, 575.0, 319.5, 239.5);
		auto pointcloud_ptr =
			geometry::CreatePointCloudFromDepthImage(*image_ptr, camera);
		visualization::DrawGeometries(
				{pointcloud_ptr},
				"geometry::PointCloud from Depth geometry::Image", 1920, 1080);
	} else if (typeName == "editing") {
		auto pcd = io::CreatePointCloudFromFile(fileName);
		visualization::DrawGeometriesWithEditing({pcd}, "Editing", 1920, 1080);
	} else if (typeName == "animation") {
		auto mesh_ptr = std::make_shared<geometry::TriangleMesh>();
		if (io::ReadTriangleMesh(fileName, *mesh_ptr)) {
			utility::PrintWarning("Successfully read %s\n", fileName);
		} else {
			utility::PrintError("Failed to read %s\n\n", fileName);
			return;
		}
		mesh_ptr->ComputeVertexNormals();
		if (trajectoryFileName != "") {
			visualization::DrawGeometriesWithCustomAnimation(
					{mesh_ptr}, "Animation", 1920, 1080);
		} else {
			visualization::DrawGeometriesWithCustomAnimation(
					{mesh_ptr}, "Animation", 1600, 900, 50, 50, trajectoryFileName);
		}
	}
	utility::PrintInfo("End of the test.\n");
	return ;
}

bool loadConfig(const string& configFilePath/*, map<int, int>& config*/) {
	return true;
}

vector<string> splitStr(const string &str, const string &pattern)
{
	vector<string> resVec;

	if ("" == str) {
		return resVec;
	}
	size_t posStart = 0;
	size_t posEnd = str.find(pattern);

	while (posEnd != string::npos)
	{
		resVec.push_back(str.substr(posStart, posEnd));
		posStart = posEnd;
		posEnd = str.find(pattern);
	}
	resVec.push_back(str.substr(posStart, posEnd));

	return resVec;
}

};// eof ns util

