#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

#include "p2Defs.h"

class PhysBody;
struct b2Body;
struct b2RevoluteJoint;
struct b2PrismaticJoint;

struct flipper
{
	//flipper b2 body and physbody
	b2Body* Attacher;
	PhysBody* Pbody;

	//flipper joint
	b2RevoluteJoint* Joint;

	//Rect for blitting purposes
	SDL_Rect Rect;
};

struct kicker {
	PhysBody* anchor;
	PhysBody* body;
	b2PrismaticJoint* joint;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

	bool PrintStaticElements = true;

public:

	p2List<PhysBody*> circles;
	p2List<PhysBody*> world_parts;
	p2List<PhysBody*> sensorsList;


	//Colliders
	PhysBody* Bouncer = nullptr;
	PhysBody*BouncerL = nullptr;
	PhysBody* BouncerCircle = nullptr;
	PhysBody*BouncerLCircle = nullptr;
	PhysBody*BlueBouncer = nullptr;


	//Sensors
		//Upper part
	PhysBody*UpperSenser1;
	PhysBody*UpperSenser2;
	PhysBody*UpperSenser3;
	
	PhysBody*UpperSenser4;

	PhysBody*UpperSmallSenser1;
	PhysBody*UpperSmallSenser2;
	PhysBody*UpperSmallSenser3;

		//Lower part
	PhysBody*LowerBigSensor1;
	PhysBody*LowerBigSensor2;
	PhysBody*LowerBigSensor3;
	
	PhysBody*LowerSmallSenser1;
	PhysBody*LowerSmallSenser2;

	PhysBody*LowerSmallSenser3;
	PhysBody*LowerSmallSenser4;
	PhysBody*LowerSmallSenser5;
	
	//HighWay Sensors
	PhysBody*Highway1;
	PhysBody*Highway2;
	PhysBody*Highway3;
	PhysBody*Highway4;
	PhysBody*Highway5;
	PhysBody*Highway6;
	PhysBody*Highway7;
	PhysBody*Highway8;
	PhysBody*Highway9;
	PhysBody*Highway10;
	PhysBody*Highway11;
	PhysBody*Highway12;
	PhysBody*Highway13;
	PhysBody*Highway14;
	PhysBody*Highway15;


	//EssentialSensors
	PhysBody*KickerPathSensor;
	PhysBody*pitSensor;
	PhysBody*QuadXpointsSensor;
	PhysBody*DoubleXpointsSensor;
	PhysBody*LockBallSensors;


	//Textures
	SDL_Texture* Ball;
	SDL_Texture* StaticScene;
	SDL_Texture* ScoreBoard;
	SDL_Texture* BouncerTR;
	SDL_Texture* BouncerCIR;
	SDL_Texture* BlueBouncerLight;
	SDL_Texture* spriteSheet;
	SDL_Texture* launchertext;
	
	//lights
	SDL_Texture*BigBlueLight;
	SDL_Texture*BigBlueTriLightH;
	SDL_Texture*LittleBlueLight;


	
	SDL_Texture*PostScoreTex;

	//flippers

	flipper rightFlipper;
	SDL_Rect rightFlipperRect;

	flipper leftFlipper;
	SDL_Rect leftFlipperRect;

	flipper rightUpFlipper;
	SDL_Rect rightUpFlipperRect;

	flipper leftUpFlipper;
	SDL_Rect leftUpFlipperRect;

	flipper InvisibleFlipper;
	SDL_Rect invisibleFlipperRect;


	//kicker
	kicker launcher;
	SDL_Rect launcherRect;

	//FX
	uint HitBall;
	uint BouncerSound;
	uint BlueUpperSenser1;
	uint SmallLightOn;
	uint BallInPitFX;
	uint FlipperUp;
	uint FlipperDown;
	uint KickerFX;
	uint MidleLightFX;
	uint OneMoreChance;
	uint Highway;
	uint ShortCut;
	uint GasGas;
	uint LockBall;

	//Collisions bools
	bool BlitBouncer=false;
	bool BlitBouncerL =false;
	bool BlitBouncerCircle = false;
	bool BlitBouncerLCircle = false;
	bool BlitBlueBouncer = false;

	//Sensors bools
		//Upper Light Sensors Bools
	bool sensor_BlueUpperSenser1=false;
	bool sensor_BlueUpperSenser2 = false;
	bool sensor_BlueUpperSenser3 = false;

	bool sensor_BlueUpperSenser4 = false;

	bool sensor_UpperSmallSenser1 = false;
	bool sensor_UpperSmallSenser2 = false;
	bool sensor_UpperSmallSenser3 = false;

		//Lower Light Sensors Bools
	bool sensor_LowerBigSensor1 = false;

	bool sensor_LowerBigSensor2 = false;
	bool sensor_LowerBigSensor3 = false;

	bool sensor_LowerSmallSenser1 = false;
	bool sensor_LowerSmallSenser2 = false;

	bool sensor_LowerSmallSenser3=false;
	bool sensor_LowerSmallSenser4=false;
	bool sensor_LowerSmallSenser5=false;
	//Highway Ligtd

	bool sensor_Highway1 = false;
	bool sensor_Highway2 = false;
	bool sensor_Highway3 = false;
	bool sensor_Highway4 = false;
	bool sensor_Highway5 = false;
	bool sensor_Highway6 = false;
	bool sensor_Highway7 = false;
	bool sensor_Highway8 = false;
	bool sensor_Highway9 = false;
	bool sensor_Highway10 = false;
	bool sensor_Highway11 = false;
	bool sensor_Highway12 = false;
	bool sensor_Highway13 = false;
	bool sensor_Highway14 = false;
	bool sensor_Highway15 = false;


	//Essntial Sensors bool
	bool PitSensorForBall = false;
	bool EndMatch = false;
	bool FlipperKickerup = false;
	bool QuadPoints = false;
	bool DoubleXpoints = false;
	bool sensor_LockBallSensors = false;

	//numOfBalls
	int BallsNum = 4;

	//startingPoint
	iPoint StartingPoint;
	

	//Parameters
	float WALL_RESTITUTION = 0.3;
	float BOUNCER_RESTI = 1.2;
	float flipperMaxTorque = 28.0;


	//UI
	int			score;
	int			high_score;
	int			ScoreMultiply = 1;

	void AddScore(int multiply, int Addscore);
	void AddBonusScore(int multiply, int bonus);
	void SetBoolstoFalse();

	SDL_Rect YellowScoreRect;
	SDL_Rect OrangeScoreRect;
	SDL_Texture* YellowScoreText = nullptr;
	SDL_Texture* OrangeScoreText = nullptr;

	int OrangeFont;
	int YellowFont;

	void DrawScore();

	
	SDL_Texture* Shortcut = nullptr;

	SDL_Texture* x4Text = nullptr;

	SDL_Texture* freegassText = nullptr;

	SDL_Texture* canadaText = nullptr;

	bool toBlit = false;

	bool canada = false;
	bool x4 = false;
	bool freegass = false;
	bool shortcutbool = false;

};
