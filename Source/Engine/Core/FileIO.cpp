#include "FileIO.h"

namespace hop
{
	std::string getFilePath()
	{
		return std::filesystem::current_path().string();
	}
}
