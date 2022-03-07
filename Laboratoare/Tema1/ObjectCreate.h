#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

namespace ObjectCreate
{

	Mesh* wtf(std::string name, std::string type, glm::vec3 center, float length, glm::vec3 color, bool fill = false);

}

