
#include "TableReader.h"
#include "StringUtils.h"

namespace TableReader
{
	std::unordered_map<std::string, std::vector<double>> ReadTable(const std::string& filePath)
	{
		std::vector<std::string> fileContent = Utils::ReadFileWithoutComments(filePath, "//");
		int n = fileContent.size() - 1;

		std::vector<std::string> headerItems = Utils::SplitString(fileContent[0], "\t");
		std::unordered_map<std::string, std::vector<double>> result;
		for (std::string headerItem : headerItems)
		{
			result[headerItem] = std::vector<double>(n);
		}

		for (int i = 1; i < fileContent.size(); i++)
		{
			std::vector<std::string> splitted = Utils::SplitString(fileContent[i], "\t");
			for (int j = 0; j < headerItems.size(); j++)
			{
				result[headerItems[j]][i - 1] = stod(splitted[j]);
			}
		}

		return result;
	}

}
