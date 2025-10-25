
#ifndef MESH_LIBRARY
#define MESH_LIBRARY

#include<unordered_map>

class MeshLibrary
{
public:
	MeshLibrary();


public:
	std::unordered_map<std::string, int> m_NameHandleLookup;

};






#endif // MESH_LIBRARY
