#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, std::string> umap
    {
    {"1", "Hello"},
    {"2", "World"},
    {"3", "Hello"},
    {"4", "unordered_map"}
    };
    std::cout << umap.at("1") << std::endl;
    std::cout << umap["2"] << std::endl;
    auto range = umap.equal_range("3");
    for (auto i = range.first; i != range.second; i++)
    {
        std::cout << i->first << " => " << i->second << std::endl;
    }

    return 0;
}