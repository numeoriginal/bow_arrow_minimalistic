#include "ObjectCreate.h"

#include <Core/Engine.h>
#include <iostream>
#include <Math.h>

using namespace std;

Mesh* ObjectCreate::wtf(std::string name, std::string type, glm::vec3 center, float length, glm::vec3 color, bool fill)
{
	glm::vec3 mid = center;
	Mesh* square = new Mesh(name);
	string bow = "arc";
	string arrow = "sajeata";
	string balon = "balon";
	string powerBar = "power";
	string life = "jizni";
	string huiken = "shuriken";
	string multiplayer = "m";

	if (type == bow)
	{
	
		vector<VertexFormat> vertices =
		{
			// base
			VertexFormat(mid,glm::vec3(1,1,1)),
			VertexFormat(mid + glm::vec3(0,-(length / 1.75),0),glm::vec3(1,1,1)), //1
			VertexFormat(mid + glm::vec3(0,(length / 1.75),0),glm::vec3(1,1,1)), //20

		};

		for (float i = 4.71f; i < 7.90f; i += 0.05)
		{
			vertices.push_back(VertexFormat(mid + glm::vec3((length / 1.75) * cos(i), (length / 1.75) * sin(i), 0), color));
			
		}
		vector<unsigned short> indices;
	
		for (int i = 0; i < vertices.size(); i++)
		{
			indices.push_back(i);
		}
		square->SetDrawMode(GL_LINE_STRIP);
		square->InitFromData(vertices, indices);
		return square;

	}
	 else if (type == arrow)
	{
		

		vector<VertexFormat> vertices =
		{
			// base
			VertexFormat(mid,color),
			VertexFormat(mid + glm::vec3(-(length / 2),-(length / 52),0),color), // 1
			VertexFormat(mid + glm::vec3(length / 2,-(length / 52),0),color), // 2
			VertexFormat(mid + glm::vec3(length / 2,length / 52,0),color), // 3
			VertexFormat(mid + glm::vec3(-(length / 2),length / 52,0),color), // 4
			// tip
			VertexFormat(mid + glm::vec3((length / 1.4),0,0),color), // 5
			VertexFormat(mid + glm::vec3((length / 2),length / 13,0),color), // 6
			VertexFormat(mid + glm::vec3((length / 2),-(length / 13),0),color), //7
		};
		vector<unsigned short> indices = {
			1,2,3,
			3,4,1,
			6,7,5
		};

			square->InitFromData(vertices, indices);
		return square;
	}
	else if (type == balon)
	{
		vector<VertexFormat>vertices;

		for (float i = 0; i < 6.28f; i += 0.0005)
		{
			vertices.push_back(VertexFormat(mid + glm::vec3((length / 1.2) * cos(i), (length / 1.2) * sin(i), 0), color));


		}
		vertices.push_back(VertexFormat(mid, color));

		vector<unsigned short> indices;

		for (int i = 0; i < vertices.size(); i+= 2)
		{
			//indices.push_back(vertices.size());
			indices.push_back(i);
			indices.push_back(vertices.size() - 1);
			indices.push_back(i + 1);
			
		}
		vertices.push_back(VertexFormat(mid + glm::vec3(0,-(length / 1.3),0), color));
		vertices.push_back(VertexFormat(mid + glm::vec3(-15, -length, 0), color));
		vertices.push_back(VertexFormat(mid + glm::vec3(15, -length , 0), color));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		vertices.push_back(VertexFormat(mid + glm::vec3(0, -(length + 0), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-7, -(length + 6), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-14, -(length + 8), 0), glm::vec3(0, 0, 0)));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		vertices.push_back(VertexFormat(mid + glm::vec3(8, -(length + 6), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(14, -(length + 8), 0), glm::vec3(0, 0, 0)));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		
		vertices.push_back(VertexFormat(mid + glm::vec3(14, -(length + 8), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-10, -(length + 14), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-14, -(length + 18), 0), glm::vec3(0, 0, 0)));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		vertices.push_back(VertexFormat(mid + glm::vec3(-14, -(length + 18), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(10, -(length + 20), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(14, -(length + 24), 0), glm::vec3(0, 0, 0)));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		vertices.push_back(VertexFormat(mid + glm::vec3(14, -(length + 24), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-8, -(length + 26), 0), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(mid + glm::vec3(-12, -(length + 30), 0), glm::vec3(0, 0, 0)));

		indices.push_back(vertices.size() - 1);
		indices.push_back(vertices.size() - 2);
		indices.push_back(vertices.size() - 3);

		square->SetDrawMode(GL_TRIANGLES);

		square->InitFromData(vertices, indices);
		return square;
	}
	 else if (type == huiken)
	{
		// base

		vector<VertexFormat> vertices =
		{
			// base
			VertexFormat(mid,glm::vec3(1,1,1)),
			VertexFormat(mid + glm::vec3(-(length / 2),0,0),color), // 1
			VertexFormat(mid + glm::vec3(-(length / 2),-(length / 2),0),color), // 2

			VertexFormat(mid + glm::vec3((length / 2),0,0),color), // 3
			VertexFormat(mid + glm::vec3((length / 2),(length / 2),0),color), // 4

			VertexFormat(mid + glm::vec3(0,(length / 2),0),color), // 5
			VertexFormat(mid + glm::vec3(-(length / 2),(length / 2),0),color), // 6

			VertexFormat(mid + glm::vec3(0,-(length / 2),0),color), // 7
			VertexFormat(mid + glm::vec3((length / 2),-(length / 2),0),color), // 8

		};
			vector<unsigned short> indices = {

				0,1,2,
				0,3,4,
				0,5,6,
				0,7,8 
		};

		square->InitFromData(vertices, indices);
		return square;

	}
	 else if (type == powerBar)
	{
		
	vector<VertexFormat> vertices =
	{
		// base
		VertexFormat(mid,color),
		VertexFormat(mid + glm::vec3(-(length / 2),-(length / 4),0),color), // 1
		VertexFormat(mid + glm::vec3(length / 2,-(length / 4),0),color), // 2
		VertexFormat(mid + glm::vec3(length / 2,length / 4,0),color), // 3
		VertexFormat(mid + glm::vec3(-(length / 2),length / 4,0),color), // 4
		
	};
	vector<unsigned short> indices = {
		1,2,3,
		3,4,1,
	};

		square->InitFromData(vertices, indices);
		return square;

	}
	 else if (type == life)
	{
		vector<VertexFormat> vertices =
		{
			// base
			VertexFormat(mid,color),
			VertexFormat(mid + glm::vec3(-(length / 2), 0, 0),color), // 1
			VertexFormat(mid + glm::vec3( (length / 2), 0, 0),color), // 2
			VertexFormat(mid + glm::vec3( 0,-(length / 2), 0),color), // 3
			VertexFormat(mid + glm::vec3( 0, (length / 2), 0),color), // 4

		};

		vector<unsigned short> indices = {
			1,2,3,
			1,2,4,
		};

		square->InitFromData(vertices, indices);
		return square;

	}


}