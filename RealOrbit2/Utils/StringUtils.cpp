
#include "StringUtils.h"
#include <sstream>
#include <fstream>

namespace Utils
{
    // created by chatgpt:
    std::vector<std::string> SplitString(const std::string& str, const std::string& delimiter)
    {
        std::vector<std::string> parts;
        size_t start = 0;
        size_t end;

        while ((end = str.find(delimiter, start)) != std::string::npos)
        {
            parts.push_back(str.substr(start, end - start));
            start = end + delimiter.length();
        }

        parts.push_back(str.substr(start)); // last part
        return parts;
    }

    // // test with these lines:
    // auto splitted = Utils::SplitString("asd dsa qwe dsa ert", "dsa");
    // auto splitted2 = Utils::SplitString("asd dsa qwe dsa ert", " dsa qwe ");
    // auto splitted3 = Utils::SplitString("asd dsa qwe dsa ert", " ");
    // auto splitted4 = Utils::SplitString("asd dsa qwe dsa ert", "\t");


    std::vector<std::string> ReadFileWithoutComments(const std::string& filePath, const std::string& commentSeparator)
    {
        std::vector<std::string> result;
        std::ifstream file(filePath);
        std::string line;

        while (std::getline(file, line))
        {
            auto splitted = Utils::SplitString(line, commentSeparator);
            if (splitted[0].size() > 0) { result.push_back(splitted[0]); }
        }
        file.close();

        return result;
    }






}




