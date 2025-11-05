
#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <vector>
#include <string>


namespace Utils
{

	std::vector<std::string> SplitString(const std::string& str, const std::string& separator = "\t");

	std::vector<std::string> ReadFileWithoutComments(const std::string& filePath, const std::string& commentSeparator = "//");


}

#endif // STRING_UTILS_H
