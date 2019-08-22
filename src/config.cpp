#include "config.h"
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

using namespace rapidjson;
using namespace std;

#include "Open3D/Open3D.h"
using namespace open3d;

bool Config::LoadFromJson(const string& jsonFilePath) {
	FILE* fp = fopen(jsonFilePath.c_str(), "r");
	char readBuffer[1024*4];
	rapidjson::FileReadStream is(fp, readBuffer, sizeof(readBuffer));
	Document doc;
	doc.ParseStream(is);
	fclose(fp);

    if(doc.HasParseError()) {
		utility::PrintError("Error when parse %s", jsonFilePath.c_str());
		return false;
    }
    for(Value::ConstMemberIterator itr = doc.MemberBegin(); itr != doc.MemberEnd(); ++itr) {
		auto nameStr = itr->name.GetString();
		if(doc[nameStr].IsString()) {
			strValues_[nameStr] = doc[nameStr].GetString();
		} else if(doc[itr->name.GetString()].IsBool()) {
			boolValues_[nameStr] = doc[nameStr].GetBool();
		} else if(doc[itr->name.GetString()].IsInt()) {
			intValues_[nameStr] = doc[nameStr].GetInt();
		} else if(doc[itr->name.GetString()].IsDouble()) {
			doubleValues_[nameStr] = doc[nameStr].GetDouble();
		} else if(doc[itr->name.GetString()].IsArray()) {
			utility::PrintWarning("Find array type %s in json, skip\n", nameStr);
		} else if(doc[itr->name.GetString()].IsObject()) {
			utility::PrintWarning("Find obj type %s in json, skip\n", nameStr);
		} else {
			utility::PrintWarning("Find unknown type %s in json, skip\n", nameStr);
		}
	}
 
    return true;
};

bool Config::GetValue(const string& name, bool& value) {
	auto itr = boolValues_.find(name);
	if(itr == boolValues_.end()) {
		value = false;
		utility::PrintWarning("Can't found config %s return zero value\n", name.c_str());
	} else {
		value = itr->second;
	}
	return true;
};
bool Config::GetValue(const string& name, int& value) {
	auto itr = intValues_.find(name);
	if(itr == intValues_.end()) {
		value = 0;
		utility::PrintWarning("Can't found config %s return zero value\n", name.c_str());
	} else {
		value = itr->second;
	}
	return true;
};
bool Config::GetValue(const string& name, double& value) {
	auto itr = doubleValues_.find(name);
	if(itr == doubleValues_.end()) {
		value = 0;
		utility::PrintWarning("Can't found config %s return zero value\n", name.c_str());
	} else {
		value = itr->second;
	}
	return true;
};
bool Config::GetValue(const string& name, string& value) {
	auto itr = strValues_.find(name);
	if(itr == strValues_.end()) {
		value = "";
		utility::PrintWarning("Can't found config %s return zero value\n", name.c_str());
	} else {
		value = itr->second;
	}
	return true;
};

