
#ifndef TABLE_READER_H
#define TABLE_READER_H

#include <unordered_map>
#include <string>
#include <vector>

namespace TableReader
{
	std::unordered_map<std::string, std::vector<double>> ReadTable(const std::string& filePath);

}




#endif // TABLE_READER_H
