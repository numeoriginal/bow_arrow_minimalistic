#include "Tema1.h"

#include <vector>
#include <iostream>
#include <time.h>
#include <Core/Engine.h>
#include "Transform2D.h"
#include "ObjectCreate.h"


using namespace std;

Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}
bool fil;
glm::vec3 curner = glm::vec3(100, 100, 0);
glm::vec3 curner1 = glm::vec3(150, 100, 0);
vector <int>fromHell;
vector <float>fromHell_Yellow;
vector <int> from_down_town;
vector <int> rnd;
vector <int> rnd_yellow;
vector <int> rnd_shurik;
vector <glm::vec2> shuriks;
vector <glm::vec2> rBaloons;
vector <glm::vec2> yBaloons;
vector <glm::vec2> impactedShuriks;
vector <bool> impactedReds;
vector <bool> impactedYellows;

int bowX, bowY;
int arrowX, arrowY;
int coef = 0, coef1 = 0, coef2 = 0;
int tY = 100, tXbow = 100, txarrow = 100;
float upWeGo = 0;
float scaleBarX = 1, scaleBarY = 1, power = 0;
float angler, angler1, columbine = 0;
float counter = 0;
bool pewpew = false;
bool reload = false;
int tyArrow = 100;
int initX = 100, initY = 100;
int b1 = 0, b2 = 0;
int timer = 0;
int score = 0;
int multyplayer = 0;
int mSpeed = 0, multyX = 0, multyY = 0;
bool mImpact = false;
int multyTimer = 0;
int SCORE_COEF = 1;
int mipi = 300, mSpeed1 = 0, multyX1 = 0, multyY1 = 0;
bool mImpact1 = false;
int pipi = 50;

void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);
	glm::vec3 cornerK = glm::vec3(0, 0, 0);
	glm::vec3 corner = glm::vec3(100, 100, 0);
	glm::vec3 corner1 = glm::vec3(150, 100, 0);
	float squareSide = 100;
	
	
	// initialize sx and sy (the scale factors)
	scaleX = 1;
	scaleY = 1;
	
	cullFace = GL_BACK;
	polygonMode = GL_FILL;

	// Load a mesh from file into GPU memory
	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}
	
	// Create a mesh box using custom data
	Mesh *tryf = ObjectCreate::wtf("1try", "sajeata", corner1, squareSide, glm::vec3(0, 0, 0));
	AddMeshToList(tryf);

	Mesh* pff = ObjectCreate::wtf("da", "arc", corner, squareSide + 50.0f, glm::vec3(0, 0, 0));
	AddMeshToList(pff);

	Mesh* kek = ObjectCreate::wtf("nu", "shuriken", cornerK, squareSide / 2.0f, glm::vec3(0, 0, 0));
	AddMeshToList(kek);

	Mesh* pupl = ObjectCreate::wtf("yes", "balon", corner, squareSide / 2.5f, glm::vec3(1.2, 0, 0));
	AddMeshToList(pupl);

	Mesh* pupl1 = ObjectCreate::wtf("galb?n", "balon", corner, squareSide / 2.5f, glm::vec3(1, 1, 0));
	AddMeshToList(pupl1);

	Mesh* mops = ObjectCreate::wtf("scaler", "power", cornerK, squareSide / 2.5f, glm::vec3(1, 1, 0));
	AddMeshToList(mops);

	Mesh* socks = ObjectCreate::wtf("waller", "jizni", cornerK, squareSide / 4.8f, glm::vec3(1, 0, 0));
	AddMeshToList(socks);

	Mesh* bonuScore = ObjectCreate::wtf("multy", "balon", corner, squareSide / 4.f, glm::vec3(1, 0, 1));
	AddMeshToList(bonuScore);

	Mesh* NOScore = ObjectCreate::wtf("minus", "balon", corner, squareSide / 4.f, glm::vec3(1.5, 1.5, 1.5));
	AddMeshToList(NOScore);

	for (int i = 0; i < 10; i++)
	{
		fromHell.push_back(-70);
		fromHell_Yellow.push_back(-120);
		from_down_town.push_back(1400);
		rnd.push_back(0);
		rnd_yellow.push_back(rand() % 200);
		rnd_shurik.push_back(rand() % 100);

		shuriks.push_back(glm::vec2(0, 0));
		rBaloons.push_back(glm::vec2(0, 0));
		yBaloons.push_back(glm::vec2(0, 0));

		impactedShuriks.push_back(glm::vec2(false));
		impactedReds.push_back(false);
		impactedYellows.push_back(false);
	}

}
void Tema1::SpawnKrasnieShariki() {

	for (int i = 0; i < fromHell.size(); i++)
	{
		if (fromHell.at(i) >= 720)
		{
			fromHell.at(i) = -70;
			if (i < 4)
			{
				coef1 = 100;
			}
			else
			{
				coef1 = 180;
			}
			rnd.at(i) = rand() % coef1;
		}
		if (impactedReds.at(i) == true)
		{

			fromHell.at(i) = -100;
			if (i < 4)
			{
				coef1 = 100;
			}
			else
			{
				coef1 = 180;
			}
			rnd.at(i) = rand() % coef1;
			impactedReds.at(i) = false;
			score += SCORE_COEF;
			cout << "Score: " <<score << endl;
		}


		
	}
	
	glm::mat3 baloonRedMatrix1 = glm::mat3(1);
	rBaloons.at(0).x = 100 + 525;
	rBaloons.at(0).y = 100 + fromHell.at(0) + rnd.at(0);
	baloonRedMatrix1 *= Transform2D::Translate(525, fromHell.at(0) + rnd.at(0)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix1);

	glm::mat3 baloonRedMatrix2 = glm::mat3(1);
	rBaloons.at(1).x = 100 + 625;
	rBaloons.at(1).y = 100 + fromHell.at(1) + rnd.at(1);
	baloonRedMatrix2 *= Transform2D::Translate(625, fromHell.at(1) + rnd.at(1)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix2);

	glm::mat3 baloonRedMatrix3 = glm::mat3(1);
	rBaloons.at(2).x = 100 + 715;
	rBaloons.at(2).y = 100 + fromHell.at(2) + rnd.at(2);
	baloonRedMatrix3 *= Transform2D::Translate(715, fromHell.at(2) + rnd.at(2)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix3);

	glm::mat3 baloonRedMatrix4 = glm::mat3(1);
	rBaloons.at(3).x = 100 + 800;
	rBaloons.at(3).y = 100 + fromHell.at(3) + rnd.at(3);
	baloonRedMatrix4 *= Transform2D::Translate(800, fromHell.at(3) + rnd.at(3)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix4);

	glm::mat3 baloonRedMatrix5 = glm::mat3(1);
	rBaloons.at(4).x = 100 + 960;
	rBaloons.at(4).y = 100 + fromHell.at(4) + rnd.at(4);
	baloonRedMatrix5 *= Transform2D::Translate(960, fromHell.at(4) - rnd.at(4)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix5);

	glm::mat3 baloonRedMatrix6 = glm::mat3(1);
	rBaloons.at(5).x = 100 + 1030;
	rBaloons.at(5).y = 100 + fromHell.at(5) + rnd.at(5);
	baloonRedMatrix6 *= Transform2D::Translate(1030, fromHell.at(5) + rnd.at(5)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix6);

	glm::mat3 baloonRedMatrix7 = glm::mat3(1);
	rBaloons.at(6).x = 100 + 1120;
	rBaloons.at(6).y = 100 + fromHell.at(6);
	baloonRedMatrix7 *= Transform2D::Translate(1120, fromHell.at(6)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["yes"], shaders["VertexColor"], baloonRedMatrix7);
};
void Tema1::SpawnJoltieShariki() {

	
	for (int i = 0; i < fromHell_Yellow.size(); i++)
	{
		if (fromHell_Yellow.at(i) >= 720)
		{
			fromHell_Yellow.at(i) = -100;
			if (i > 3)
			{
				coef = 100;
			}
			else
			{
				coef = 170;
			}
			rnd_yellow.at(i) = rand() % coef;
			
		}
		
		if (impactedYellows.at(i) == true)
		{

			fromHell_Yellow.at(i) = -180;
			if (i < 2)
			{
				coef = 100;
			}
			else
			{
				coef = 180;
			}
			rnd_yellow.at(i) = rand() % coef;
			impactedYellows.at(i) = false;

			if (score > 0)
			{
				score -= 1;
				cout << "Score: " << score << endl;
			}
			
		}

	}

	yBaloons.at(0).x = 100 + 475;
	yBaloons.at(0).y = 100 + fromHell_Yellow.at(0) - rnd_yellow.at(0);
	glm::mat3 baloonMatrix1 = glm::mat3(1);
	baloonMatrix1 *= Transform2D::Translate(475, fromHell_Yellow.at(0) - rnd_yellow.at(0)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["galb?n"], shaders["VertexColor"], baloonMatrix1);

	yBaloons.at(1).x = 100 + 655;
	yBaloons.at(1).y = 100 + fromHell_Yellow.at(1) + rnd_yellow.at(1);
	glm::mat3 baloonMatrix2 = glm::mat3(1);
	baloonMatrix2 *= Transform2D::Translate(655, fromHell_Yellow.at(1) + rnd_yellow.at(1)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["galb?n"], shaders["VertexColor"], baloonMatrix2);

	yBaloons.at(2).x = 100 + 935;
	yBaloons.at(2).y = 100 + fromHell_Yellow.at(2);
	glm::mat3 baloonMatrix3 = glm::mat3(1);
	baloonMatrix3 *= Transform2D::Translate(935, fromHell_Yellow.at(2)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["galb?n"], shaders["VertexColor"], baloonMatrix3);
	
	yBaloons.at(3).x = 100 + 1140;
	yBaloons.at(3).y = 100 + fromHell_Yellow.at(3) + rnd_yellow.at(3);
	glm::mat3 baloonMatrix4 = glm::mat3(1);
	baloonMatrix4 *= Transform2D::Translate(1140, fromHell_Yellow.at(3) + rnd_yellow.at(3)) * Transform2D::Scale(scaleX, scaleY + 0.2);
	RenderMesh2D(meshes["galb?n"], shaders["VertexColor"], baloonMatrix4);
};
void Tema1::SpawnNinjago() {

	
	
	for (int i = 0; i < rnd_shurik.size(); i++)
	{
		if (impactedShuriks.at(i).x == true)
		{
			impactedShuriks.at(i).x = false;
			if (impactedShuriks.at(i).y == false)
			{
				lives--;
			}	
			from_down_town.at(i) = 1800;
			if (i > 3)
			{
				rnd_shurik.at(i) = rand() % 80;
			}
			else
			{
				rnd_shurik.at(i) = rand() % 200;
			}	
		}
		if (i <= 5)
		{
			if (impactedShuriks.at(i).y == true)
			{
				from_down_town.at(i) = 1800;

				if (i > 3)
				{
					rnd_shurik.at(i) = rand() % 80;
				}
				else
				{
					rnd_shurik.at(i) = rand() % 200;
				}
				impactedShuriks.at(i).y = false;
				score += SCORE_COEF;
				cout << "Score: " << score << endl;
				timer = 200;
			}
		}
		
		if (from_down_town.at(i) < -200)
		{
			from_down_town.at(i) = 1600;

			if (i > 3)
			{
				coef2 = 80;
			}
			else
			{
				coef2 = 150;
			}
			rnd_shurik.at(i) = rand() % coef2;
		}	
	}

		shuriks.at(0).x = from_down_town.at(0);
		shuriks.at(0).y = -70;
		glm::mat3 NinjaMatrix0 = glm::mat3(1);
		NinjaMatrix0 *= Transform2D::Translate(from_down_town.at(0), -70) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix0);

		shuriks.at(1).x = from_down_town.at(1) + rnd_shurik.at(1);
		shuriks.at(1).y = 100;
		glm::mat3 NinjaMatrix1 = glm::mat3(1);
		NinjaMatrix1 *= Transform2D::Translate(from_down_town.at(1) + rnd_shurik.at(1), 100) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix1);
	
		shuriks.at(2).x = from_down_town.at(2) + rnd_shurik.at(2);
		shuriks.at(2).y = 190;
		glm::mat3 NinjaMatrix2 = glm::mat3(1);
		NinjaMatrix2 *= Transform2D::Translate(from_down_town.at(2) + rnd_shurik.at(2), 190) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix2);


		shuriks.at(3).x = from_down_town.at(3) - rnd_shurik.at(3);
		shuriks.at(3).y = 300;
		glm::mat3 NinjaMatrix3 = glm::mat3(1);
		NinjaMatrix3 *= Transform2D::Translate(from_down_town.at(3) - rnd_shurik.at(3), 300) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix3);


		shuriks.at(4).x = from_down_town.at(4) - rnd_shurik.at(4);
		shuriks.at(4).y = 550;
		glm::mat3 NinjaMatrix5 = glm::mat3(1);
		NinjaMatrix5 *= Transform2D::Translate(from_down_town.at(4) - rnd_shurik.at(4), 550) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix5);

		shuriks.at(5).x = from_down_town.at(5) + rnd_shurik.at(5);
		shuriks.at(5).y = 640;
		glm::mat3 NinjaMatrix6 = glm::mat3(1);
		NinjaMatrix6 *= Transform2D::Translate(from_down_town.at(5) + rnd_shurik.at(5), 640) * Transform2D::Rotate(roata_morii);
		RenderMesh2D(meshes["nu"], shaders["VertexColor"], NinjaMatrix6);


};
void Tema1::ArrowGoesPewPew() {

	glm::mat3 ArrowMatrix = glm::mat3(1);
	glm::ivec2 resolutionA = window->GetResolution();
	float angl;
	
	
	// render an object using colors from vertex
	if (powerX > resolutionA.x || powerY > resolutionA.y || timer == 200)
	{
		scaleBarX = 1;
		txarrow = initX;
		tyArrow = initY;
		power = 0;
		powerX = 0;
		powerY = 0;
		pewpew = false;
		timer = 0;
	}

	if (pewpew == true)
	{
	
		timer++;
		arrowX = 150 + (100 / 1.4f) * cos(columbine) + powerX;
		arrowY = 100 + (100 / 1.4f) * sin(columbine) + powerY;
	

		ArrowMatrix *= Transform2D::Translate(powerX, powerY);
		ArrowMatrix *= Transform2D::Translate(txarrow, tyArrow);
		ArrowMatrix *= Transform2D::Rotate(columbine);
		ArrowMatrix *= Transform2D::Translate(-txarrow, -tyArrow);

	
	}
	else 
	{
	
			powerY = upWeGo;
			angl = angler;
			ArrowMatrix = glm::mat3(1);
			ArrowMatrix *= Transform2D::Translate(0, upWeGo);
			ArrowMatrix *= Transform2D::Translate(txarrow, tyArrow);
			ArrowMatrix *= Transform2D::Rotate(angl);
			ArrowMatrix *= Transform2D::Translate(-txarrow, -tyArrow);	
		
	}
	
	RenderMesh2D(meshes["1try"], shaders["VertexColor"], ArrowMatrix);

}
void Tema1::GenerateBow() {

	bowY = 100 + upWeGo;
	bowX = 100;

	glm::mat3 BowMatrix = glm::mat3(1);

	BowMatrix *= Transform2D::Translate(0, upWeGo);
	BowMatrix *= Transform2D::Translate(tXbow, tY);
	BowMatrix *= Transform2D::Rotate(angler);
	BowMatrix *= Transform2D::Translate(-tXbow, -tY);
	RenderMesh2D(meshes["da"], shaders["VertexColor"], BowMatrix);

};
void Tema1::InputLives() {

	if (lives <= 0)
	{
		cout << "Game Over Loser" << endl;
		cout << "Final score: " << score << endl;
		window->Close();
	}

	// I blessed u with 3 lives
	if (lives >= 1)
	{
		glm::mat3 lifeMatrix1 = glm::mat3(1);
		lifeMatrix1 *= Transform2D::Translate(20, 700) * Transform2D::Scale(1, 1.4f);
		RenderMesh2D(meshes["waller"], shaders["VertexColor"], lifeMatrix1);
	}
	
	if (lives >= 2 )
	{
		glm::mat3 lifeMatrix2 = glm::mat3(1);
		lifeMatrix2 *= Transform2D::Translate(45, 700) * Transform2D::Scale(1, 1.4f);
		RenderMesh2D(meshes["waller"], shaders["VertexColor"], lifeMatrix2);
	}

	if (lives >= 3)
	{
		glm::mat3 lifeMatrix3 = glm::mat3(1);
		lifeMatrix3 *= Transform2D::Translate(70, 700) * Transform2D::Scale(1, 1.4f);
		RenderMesh2D(meshes["waller"], shaders["VertexColor"], lifeMatrix3);
	}
	
}
void Tema1::shurikenArrowImpact()
{
	float arrowRad = 0;
	float radiusShuriken = (100 / 1.8f);

	float dx1, dy1, distance1;

	for (int i = 0; i < shuriks.size(); i++)
	{
		if (shuriks.at(i).x > 0 && shuriks.at(i).y > 0)
		{
			dx1 = arrowX - shuriks.at(i).x;
			dy1 = arrowY - shuriks.at(i).y;

			distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

			if (distance1 < arrowRad + radiusShuriken)
			{
				impactedShuriks.at(i).y = true;

			}
		}
		
	}


}
void Tema1::arrowRedBaloonImpact()
{
	float arrowRad = 0;
	float rBaloon = (100 / 2.2f);

	float dx1, dy1, distance1;

	for (int i = 0; i < rBaloons.size(); i++)
	{
		if (rBaloons.at(i).x >0 && rBaloons.at(i).y > 0)
		{
			dx1 = arrowX - rBaloons.at(i).x;
			dy1 = arrowY - rBaloons.at(i).y;

			distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

			if (distance1 < arrowRad + rBaloon)
			{
				impactedReds.at(i) = true;
			}
		}	
	}
}
void Tema1::arrowYellowBallonImpact()
{
	float arrowRad = 0;
	float yBaloon = (100 / 2.2f);

	float dx1, dy1, distance1;

	for (int i = 0; i < yBaloons.size(); i++)
	{
		if (yBaloons.at(i).x > 0 && yBaloons.at(i).y > 0)
		{
			dx1 = arrowX - yBaloons.at(i).x;
			dy1 = arrowY - yBaloons.at(i).y;

			distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

			if (distance1 < arrowRad + yBaloon)
			{

				impactedYellows.at(i) = true;

			}
		}
	}

}
void Tema1::spawnMultyplayer()
{
	
	if (mSpeed > 720)
	{
		mSpeed = -150;

		pipi = rand() % 800;
	}
	if (mImpact == true)
	{
		
		mSpeed = -50;
		pipi = rand() % 800;
		multyTimer += 150;
		SCORE_COEF += 1;
		cout << "Score x" << SCORE_COEF << " active." << endl;
		mImpact = false;
	}

	multyX = 400 + pipi;
	multyY = 100 + mSpeed;

	glm::mat3 multyplyMatrix = glm::mat3(1);
	multyplyMatrix *= Transform2D::Translate(multyX, mSpeed) ;
	RenderMesh2D(meshes["multy"], shaders["VertexColor"], multyplyMatrix);

}
void Tema1::multyplayerImpact()
{
	float arrowRad = 0;
	float multyR = (100 / 1.8f);

	float dx1, dy1, distance1;
	if (multyX > 0 && multyY > 0)
	{
		dx1 = arrowX - multyX;
		dy1 = arrowY - multyY;

		distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

		if (distance1 < arrowRad + multyR)
		{
			mImpact = true;
		}
	}
	
}
void Tema1::spawnNulifier()
{
	if (mSpeed1 > 720)
	{
		mSpeed1 = 50;

		mipi = rand() % 800;
	}
	if (mImpact1 == true)
	{

		mSpeed1 = -150;
		mipi = rand() % 800;
		multyTimer = 0;
		SCORE_COEF = 1;
		cout << "Multyplier nulified." << endl;
		mImpact1 = false;
	}

	multyX1 = 400 + mipi;
	multyY1 = 100 + mSpeed1;

	glm::mat3 multyplyMatrix1 = glm::mat3(1);
	multyplyMatrix1 *= Transform2D::Translate(multyX1, mSpeed1);
	RenderMesh2D(meshes["minus"], shaders["VertexColor"], multyplyMatrix1);
}
void Tema1::hitNulifier()
{
	float arrowRad = 0;
	float multyR = (100 / 1.8f);

	float dx1, dy1, distance1;
	if (multyX1 > 0 && multyY1 > 0)
	{
		dx1 = arrowX - multyX1;
		dy1 = arrowY - multyY1;

		distance1 = sqrt(dx1 * dx1 + dy1 * dy1);

		if (distance1 < arrowRad + multyR)
		{
			mImpact1 = true;
		}
	}


}
void Tema1::shurikenBowImpact()
{
	float radiusBow = (100 / 2.4f);
	float radiusShuriken = (100 / 1.9f);

	
	float dx, dy, distance;

	for (int i = 0; i < shuriks.size(); i++)
	{
		dx = bowX - shuriks.at(i).x;
		dy = bowY - shuriks.at(i).y;
		distance = sqrt(dx * dx + dy * dy);

		if (distance < radiusBow + radiusShuriken)
		{
			impactedShuriks.at(i).x = true;
		}
	}


}
;

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0.4, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
	glLineWidth(3);
	glPointSize(5);
	glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

	if (multyTimer > 0)
	{
		multyTimer--;
	} else if (multyTimer == 0){

		SCORE_COEF = 1;
	}
	

	InputLives(); // lifes ^_^

	ArrowGoesPewPew(); // draw sajeata
	
	GenerateBow(); // draw arcu

	// bara de tragere
	glm::mat3 scalerMatrix = glm::mat3(1);
	scalerMatrix *= Transform2D::Scale(scaleBarX, scaleBarY);
	RenderMesh2D(meshes["scaler"], shaders["VertexColor"], scalerMatrix);

	SpawnNinjago(); // draw ninjagos 
	for (int i = 0; i < from_down_town.size(); i++)
	{
		// viteza miscare shuriken
		from_down_town.at(i) -= deltaTimeSeconds * (I_AM_SPEEEED * 1.8f); // SPEEEEEEEED
	}

	roata_morii += deltaTimeSeconds * 60;

	SpawnKrasnieShariki(); // draw baloons
	for (int i = 0; i < fromHell.size(); i++)
	{
		// viteza zbor baloani rosi
		fromHell.at(i) += deltaTimeSeconds * (I_AM_SPEEEED * 1.65f); // speed
	}
	
	SpawnJoltieShariki(); // draw baloons galb?n
	for (int i  = 0; i  < fromHell_Yellow.size(); i ++)
	{
		// viteza zbor baloani galbene
		fromHell_Yellow.at(i) += deltaTimeSeconds * (I_AM_SPEEEED * 1.45f); // speed
	}
	

	if (pewpew == true)
	{
		// viteza tragere sajeata
		powerX += deltaTimeSeconds * (power + I_AM_SPEEEED) * cos(columbine) ;
		powerY += deltaTimeSeconds * (power + I_AM_SPEEEED) * sin(columbine) ;
	}
	
	mSpeed += deltaTimeSeconds * (I_AM_SPEEEED * 3.f);
	mSpeed1 += deltaTimeSeconds * (I_AM_SPEEEED * 3.f);

	shurikenBowImpact();
	shurikenArrowImpact();
	arrowRedBaloonImpact();
	arrowYellowBallonImpact();
	spawnMultyplayer();
	multyplayerImpact();
	spawnNulifier();
	hitNulifier();

}

void Tema1::FrameEnd()
{

}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	// miscare arc sus jos
	if (window->KeyHold(GLFW_KEY_W)) {
		upWeGo += muxy * deltaTime;
		
	}
	if (window->KeyHold(GLFW_KEY_S)) {
		upWeGo -= muxy * deltaTime;

	}

	// bow draw power
	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT) && pewpew == false)
	{
		if (counter < 60)
		{
			scaleBarX += deltaTime * 8;
			power = scaleBarX * 220;
			counter++;
		}
		
	}

}

void Tema1::OnKeyPress(int key, int mods)
{
	// increase speed a.k.a difficulty
	if (key == GLFW_KEY_Q ) {
		I_AM_SPEEEED += 15;
	}
	if (key == GLFW_KEY_E) {
		I_AM_SPEEEED -= 15;
	}
	if (key == GLFW_KEY_R)
	{
		timer = 200;
	}
}

void Tema1::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// calculare unghi centru arc - pozitie cursor
	glm::ivec2 resolution = window->GetResolution();
	angler = atan((resolution.y - mouseY - upWeGo - 100) / (mouseX - curner.x));
	
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event



}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
	if (button == 1 && pewpew == false)
	{
		columbine = angler;
		counter = 0;
		pewpew = true;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}
