#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	void SpawnKrasnieShariki();
	void SpawnJoltieShariki();
	void SpawnNinjago();
	void ArrowGoesPewPew();
	void GenerateBow();
	void InputLives();
	void shurikenBowImpact();
	void shurikenArrowImpact();
	void arrowRedBaloonImpact();
	void arrowYellowBallonImpact();
	void spawnMultyplayer();
	void multyplayerImpact();
	void spawnNulifier();
	void hitNulifier();

protected:
	glm::mat3 modelMatrix;
	float translateX = 1, translateY = 1;
	int scaleX = 1, scaleY = 1;
	float angularStep;
	GLenum cullFace;
	GLenum polygonMode;
	int muxy = 350;
	int I_AM_SPEEEED = 100;
	int roata_morii = 0;
	float arrowUp = 0;
	float powerX = 0;
	float powerY = 0;
	int lives = 3;


};
