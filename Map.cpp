#pragma warning( disable : 4482 )

#include<Map.h>
#include<Game.h>

#include<MagicStar.h>

#include<ALLdecors.h>
#include<ALLobjects.h>
#include<ALLNPCs.h>

Map::Map()
{
	timeStep = 1.0f / 60.0f;
	velocityIterations = 8;
	positionIterations = 16;

	b2Vec2 gravity(0.0f, -10.0f);
	world = new b2World(gravity);
}

Map * Map::LoadMap(int level, TextureStorage * ts, SoundStorage * ss, SaveState * savestate, bool skillsloaded)
{
	Map * map = new Map();
	if (Game::player) map->player = (Game::player);
	else
	{
		Game::player = new Player(ts);
		map->player = Game::player;
	}
	map->player->SetEnergyToMax();

	switch (level)
	{
	case 1:
		{
			map->level = 1;
			map->CanBeTrixie = false;
			map->CanBeRD = true;
			map->CanBeAJ = false;
			map->boxlayer = 6;
			map->mslayer = 5000;

			map->player->ConstructBody(map->world, b2Vec2(5.0f, 80.0f));
			map->player->CurrentPony = map->player->RD;
			map->Actors.insert(std::pair<int, Actor*>(1, map->player));

			for (int i = TextureStorage::Zombie_left_01; i <= TextureStorage::Zombie_right_16; ++i)  // pre-load sprites for zombie
			{
				ts->LoadTexture((TextureStorage::TexName)i);
			}

			savestate->characters = 2;
			savestate->playerchar = 2;
			savestate->playerstate = 1;
			map->player->SetState(1);  // SetState(savestate->playerstate);
			savestate->level = level;
			savestate->playerpos = b2Vec2(5.0f, 80.0f);
			savestate->screenpos = b2Vec2(2.0f, 88.0f);

			if (skillsloaded) map->SkillsFromState(savestate);
			else
			{
				// set default skills both to player and savestate
				savestate->runcost = 1.0f;
				savestate->runspeed = 2.5f;
				savestate->canbuck = false;
				savestate->flycost = 1.2f;
				savestate->flyspeed = 2.0f;
				savestate->candash = false;
				savestate->boxcost = 50.0f;
				savestate->levitcost = 1.0f;
				savestate->canlevitate = false;
				savestate->maxboxes = 1;

				map->SkillsFromState(savestate);
			}

			StaticDecorPrototype * dt = new StaticDecorPrototype(ts, TextureStorage::Cloud1, b2Vec2(3.0f, 80.75f));
			map->Actors.insert(std::pair<int, Actor*>(2, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud2, b2Vec2(7.0f, 78.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud3, b2Vec2(2.0f, 75.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud2, b2Vec2(5.5f, 72.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud1, b2Vec2(8.0f, 70.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud4, b2Vec2(9.5f, 69.5f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud3, b2Vec2(4.0f, 65.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud2, b2Vec2(7.5f, 60.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::Cloud1, b2Vec2(3.0f, 55.0f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			SleepBubble * sb = new SleepBubble(ts, b2Vec2(5.7f, 82.3f));
			map->Actors.insert(std::pair<int, Actor*>(-53, sb));

			GroundBox2 * gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(4.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-60, gb2));

			//AnimationTest * at = new AnimationTest(ts->Device);
			//at->position = b2Vec2(7.0f, 7.0f);
			//map->Actors.insert(std::pair<int, Actor*>(-59, at));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(24.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-59, gb2));

			BigTree * bt = new BigTree(ts);
			bt->ConstructBody(map->world, b2Vec2(0.0f, 7.5));
			map->Actors.insert(std::pair<int, Actor*>(-58, bt));

			Grass1 * gr = new Grass1(ts, b2Vec2(-6.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-57, gr));

			Grass2 * gr2 = new Grass2(ts, b2Vec2(4.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-56, gr2));
			//gr = new Grass1(ts, b2Vec2(4.0f, 2.75f));
			//map->Actors.insert(std::pair<int, Actor*>(-56, gr));

			gr = new Grass1(ts, b2Vec2(14.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-55, gr));

			dt = new StaticDecorPrototype(ts, TextureStorage::Text_Jump, b2Vec2(15.5f, 4.5f));
			map->Actors.insert(std::pair<int, Actor*>(-54, dt));

			GroundBox1 * gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(24.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-52, gb1));

			gr = new Grass1(ts, b2Vec2(19.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-52, gr));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(29.0f, 2.2f));
			map->Actors.insert(std::pair<int, Actor*>(-51, gb1));

			gr = new Grass1(ts, b2Vec2(24.0f, 4.95f));
			map->Actors.insert(std::pair<int, Actor*>(-50, gr));

			dt = new StaticDecorPrototype(ts, TextureStorage::Text_Savepoint, b2Vec2(26.5f, 6.5f));
			map->Actors.insert(std::pair<int, Actor*>(-49, dt));

			SavePointTA * spta = new SavePointTA(ts);
			spta->enabled = true;
			spta->actorpos = b2Vec2(28.0f, 5.95f);
			spta->ConstructBody(map->world, b2Vec2(29.0f, 5.7f), b2Vec2(0.5f, 1.0f));
			map->Triggers.push_back(spta);
			map->Actors.insert(std::pair<int, Actor*>(-54, spta));

			Water1 * w = new Water1(ts);
			w->ConstructBody(map->world, b2Vec2(44.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-47, w));

			w = new Water1(ts);
			w->ConstructBody(map->world, b2Vec2(54.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-46, w));

			Lantern1 * lan = new Lantern1(ts);
			lan->ConstructBody(map->world, b2Vec2(39.0f, 4.75f));
			map->Actors.insert(std::pair<int, Actor*>(-45, lan));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(35.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-44, gb1));

			dt = new StaticDecorPrototype(ts, TextureStorage::Lamppost1, b2Vec2(39.0f, 5.25f));
			map->Actors.insert(std::pair<int, Actor*>(-43, dt));

			gr = new Grass1(ts, b2Vec2(30.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-42, gr));

			b2RevoluteJointDef rjd;
			rjd.bodyA = gb1->body;
			rjd.bodyB = lan->body;
			rjd.enableMotor = false;
			rjd.localAnchorA = b2Vec2(4.2f, 3.68f);
			rjd.localAnchorB = b2Vec2(0.0f, 0.35f);
			map->world->CreateJoint(&rjd);

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(49.0f, -2.5f));
			map->Actors.insert(std::pair<int, Actor*>(-41, gb2));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(64.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-40, gb1));

			gr = new Grass1(ts, b2Vec2(59.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-39, gr));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(69.0f, 2.0f));
			map->Actors.insert(std::pair<int, Actor*>(-38, gb1));

			gr = new Grass1(ts, b2Vec2(64.0f, 4.75f));
			map->Actors.insert(std::pair<int, Actor*>(-37, gr));

			Platform1 * pl = new Platform1(ts);
			pl->ConstructBody(map->world, b2Vec2(41.5f, 3.25f));
			map->Actors.insert(std::pair<int, Actor*>(-36, pl));

			BrokenPlatform1 * bpl = new BrokenPlatform1(ts);
			bpl->ConstructBody(map->world, b2Vec2(45.9f, 3.25f));
			map->Actors.insert(std::pair<int, Actor*>(-35, bpl));

			dt = new StaticDecorPrototype(ts, TextureStorage::Text_Swim, b2Vec2(45.9f, 5.5f));
			map->Actors.insert(std::pair<int, Actor*>(-34, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(42.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-34, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(47.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-33, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(55.5f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-32, dt));

			BrokenPlatform2 * bpl2 = new BrokenPlatform2(ts);
			bpl2->ConstructBody(map->world, b2Vec2(56.5f, 3.05f));
			map->Actors.insert(std::pair<int, Actor*>(-31, bpl2));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(79.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-30, gb2));

			gr = new Grass1(ts, b2Vec2(69.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-29, gr));

			gr = new Grass1(ts, b2Vec2(79.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-28, gr));

			dt = new StaticDecorPrototype(ts, TextureStorage::Building01, b2Vec2(73.47f, 7.0f));
			map->Actors.insert(std::pair<int, Actor*>(-28, dt));

			// floor
			b2BodyDef def;
			b2PolygonShape shape;
			def.position = b2Vec2(76.75f, 4.4f);
			b2Body * body = map->world->CreateBody(&def);
			b2Vec2 * points = new b2Vec2[4];
			points[0] = b2Vec2(-2.3f, 0.1f);
			points[1] = b2Vec2(-2.5f, -0.1f);
			points[2] = b2Vec2(2.2f, -0.1f);
			points[3] = b2Vec2(2.2f, 0.1f);
			shape.Set(points, 4);
			body->CreateFixture(&shape, 0.0f);

			// roof
			def.position = b2Vec2(76.4f, 6.45f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(2.2f, 0.35f);
			body->CreateFixture(&shape, 0.0f);

			// railing
			def.position = b2Vec2(78.92f, 4.7f);
			body = map->world->CreateBody(&def);
			points[0] = b2Vec2(0.0f, 0.2f);
			points[1] = b2Vec2(-0.1f, -0.2f);
			points[2] = b2Vec2(0.05f, -0.2f);
			points[3] = b2Vec2(0.05f, 0.2f);
			shape.Set(points, 4);
			delete points;
			body->CreateFixture(&shape, 0.0f);

			PutZombieTA * pzta = new PutZombieTA(ts, b2Vec2(75.0f, 3.0f), 100.0f, 102.0f, -29);
			pzta->enabled = true;
			pzta->resetme = true;
			pzta->ConstructBody(map->world, b2Vec2(76.75f, 5.0f));
			map->Triggers.push_back(pzta);

			// wall for zombie
			FakeObjectBox * fob = new FakeObjectBox(b2Vec2(0.1f, 0.9f));
			fob->ConstructBody(map->world, b2Vec2(78.1f, 3.5f));
			map->Actors.insert(std::pair<int, Actor*>(-60, fob));
			ObjectAndDef oad;
			oad.pos = b2Vec2(78.1f, 3.5f);
			oad.object = fob;
			savestate->objects->push_back(oad);

			DeleteBodyTA * dbta = new DeleteBodyTA(ts);
			dbta->enabled = true;
			dbta->resetme = true;
			dbta->todelete = fob;
			dbta->ConstructBody(map->world, b2Vec2(83.5f, 4.0f), b2Vec2(0.5f, 1.5f));
			map->Triggers.push_back(dbta);

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(89.0f, -1.5f));
			map->Actors.insert(std::pair<int, Actor*>(-27, gb2));

			gr = new Grass1(ts, b2Vec2(89.0f, 1.25f));
			map->Actors.insert(std::pair<int, Actor*>(-26, gr));

			w = new Water1(ts);
			w->ConstructBody(map->world, b2Vec2(101.0f, -4.0f));
			map->Actors.insert(std::pair<int, Actor*>(-25, w));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(94.0f, -2.5f));
			map->Actors.insert(std::pair<int, Actor*>(-24, gb1));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(101.0f, -7.5f));
			map->Actors.insert(std::pair<int, Actor*>(-23, gb1));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(108.0f, -2.5f));
			map->Actors.insert(std::pair<int, Actor*>(-22, gb1));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(113.0f, -1.2f));
			map->Actors.insert(std::pair<int, Actor*>(-21, gb2));

			gr = new Grass1(ts, b2Vec2(103.0f, 1.55f));
			map->Actors.insert(std::pair<int, Actor*>(-20, gr));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Building03, b2Vec2(114.0f, 6.5f));
			map->Actors.insert(std::pair<int, Actor*>(-18, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Building02, b2Vec2(117.3f, 6.5f));
			map->Actors.insert(std::pair<int, Actor*>(-19, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Building04, b2Vec2(122.0f, 6.3f));
			map->Actors.insert(std::pair<int, Actor*>(-17, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Town_Hall, b2Vec2(128.0f, 13.8f));
			map->Actors.insert(std::pair<int, Actor*>(-16, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Building02, b2Vec2(134.8f, 6.5f));
			map->Actors.insert(std::pair<int, Actor*>(-19, dt));

			dt = new StaticDecorPrototype(ts, TextureStorage::TexName::Building05, b2Vec2(137.0f, 7.0f));
			map->Actors.insert(std::pair<int, Actor*>(-19, dt));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(118.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-15, gb2));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(138.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-14, gb2));

			gr = new Grass1(ts, b2Vec2(108.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-13, gr));

			gr = new Grass1(ts, b2Vec2(118.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-12, gr));

			gr = new Grass1(ts, b2Vec2(128.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-11, gr));

			gr = new Grass1(ts, b2Vec2(138.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-10, gr));

			LevelExitTA * leta = new LevelExitTA(ts);
			leta->enabled = true;
			leta->actorpos = b2Vec2(131.0f, 3.78f);
			leta->ConstructBody(map->world, b2Vec2(132.0f, 4.0f), b2Vec2(1.0f, 1.5f));
			map->Triggers.push_back(leta);
			map->Actors.insert(std::pair<int, Actor*>(-9, leta));

			Stars1 * st = new Stars1(ts, b2Vec2(-7.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-100, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 90.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 90.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 80.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 80.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 70.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 70.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 60.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 60.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 50.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 50.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 40.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 40.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 30.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 30.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-99, st));

			st = new Stars1(ts, b2Vec2(8.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-98, st));

			st = new Stars1(ts, b2Vec2(8.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-97, st));

			st = new Stars1(ts, b2Vec2(23.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-96, st));

			st = new Stars1(ts, b2Vec2(23.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-95, st));

			st = new Stars1(ts, b2Vec2(38.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-94, st));

			st = new Stars1(ts, b2Vec2(38.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-93, st));

			st = new Stars1(ts, b2Vec2(53.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-92, st));

			st = new Stars1(ts, b2Vec2(53.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-91, st));

			st = new Stars1(ts, b2Vec2(68.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-90, st));

			st = new Stars1(ts, b2Vec2(68.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-89, st));

			st = new Stars1(ts, b2Vec2(83.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-88, st));

			st = new Stars1(ts, b2Vec2(83.0f, 2.0f));
			map->Actors.insert(std::pair<int, Actor*>(-87, st));

			st = new Stars1(ts, b2Vec2(98.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-86, st));

			st = new Stars1(ts, b2Vec2(98.0f, 2.0f));
			map->Actors.insert(std::pair<int, Actor*>(-85, st));

			st = new Stars1(ts, b2Vec2(113.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-84, st));

			st = new Stars1(ts, b2Vec2(128.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-83, st));

			Moon * m = new Moon(ts, b2Vec2(3.0f, 47.95f));
			m->coefY = 0.8f;
			map->Actors.insert(std::pair<int, Actor*>(-80, m));

			break;  // <-- !!!
		}
	case 2:
		{
			map->level = 2;
			map->CanBeTrixie = false;
			map->CanBeRD = false;
			map->CanBeAJ = true;
			map->boxlayer = 50;
			map->mslayer = 5000;

			map->Actors.insert(std::pair<int, Actor*>(1, map->player));
			map->player->ConstructBody(map->world, b2Vec2(6.5f, 5.5f));
			map->player->CurrentPony = map->player->AJ;

			for (int i = TextureStorage::Zombie_left_01; i <= TextureStorage::Zombie_right_16; ++i)  // pre-load sprites for zombie
			{
				ts->LoadTexture((TextureStorage::TexName)i);
			}

			savestate->characters = 1;
			savestate->playerchar = 1;
			savestate->playerstate = 0;
			map->player->SetState(0);
			savestate->level = level;
			savestate->playerpos = b2Vec2(6.5f, 5.5f);
			savestate->screenpos = b2Vec2(-1.0f, 10.0f);

			if (skillsloaded) map->SkillsFromState(savestate);
			else
			{
				savestate->runcost = 1.0f;
				savestate->runspeed = 2.5f;
				savestate->canbuck = false;
				savestate->flycost = 1.2f;
				savestate->flyspeed = 2.0f;
				savestate->candash = false;
				savestate->boxcost = 50.0f;
				savestate->levitcost = 1.0f;
				savestate->canlevitate = false;
				savestate->maxboxes = 1;

				map->SkillsFromState(savestate);
			}

			GroundBox2 * gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(4.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(-16.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			Grass1 * gr = new Grass1(ts, b2Vec2(-10.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(7.4f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(24.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gr = new Grass1(ts, b2Vec2(17.4f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(27.4f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			StaticDecorPrototype * sdp = new StaticDecorPrototype(ts, TextureStorage::Farmhouse, b2Vec2(-1.0f, 10.7f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence3, b2Vec2(-8.3f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence1, b2Vec2(-5.75f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence2, b2Vec2(-3.1f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			// Parasprite test
			Parasprite * pp = new Parasprite(ts, b2Vec2(10.0f, 4.0f), 0.5f, 0.5f, b2Vec2(20.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-1, pp));

			// main floor
			b2BodyDef def;
			b2PolygonShape shape;
			def.position = b2Vec2(5.0f, 5.0f);
			b2Body * body = map->world->CreateBody(&def);
			shape.SetAsBox(2.5f, 0.2f);
			//b2Vec2 * points = new b2Vec2[4];
			//points[0] = b2Vec2(-2.3f, 0.1f);
			//points[1] = b2Vec2(-2.5f, -0.1f);
			//points[2] = b2Vec2(2.2f, -0.1f);
			//points[3] = b2Vec2(2.2f, 0.1f);
			//shape.Set(points, 4);
			body->CreateFixture(&shape, 0.0f);

			// top step
			def.position = b2Vec2(0.25f, 5.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.25f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			// more steps
			def.position = b2Vec2(0.4f, 4.3f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(0.8f, 4.02f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(1.15f, 3.75f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(1.47f, 3.45f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(1.8f, 3.20f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(2.1f, 3.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(2.45f, 2.75f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			// left wall
			def.position = b2Vec2(0.0f, 5.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.1f, 2.5f);
			body->CreateFixture(&shape, 0.0f);

			// right wall
			def.position = b2Vec2(7.6f, 6.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.1f, 2.0f);
			body->CreateFixture(&shape, 0.0f);

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence3, b2Vec2(8.0f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence1, b2Vec2(10.6f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence2, b2Vec2(13.25f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence1, b2Vec2(15.85f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence2, b2Vec2(18.45f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::HayBale1, b2Vec2(12.8f, 3.55f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::ChickenCoop, b2Vec2(15.0f, 5.2f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(21.0f, 3.3f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			def.position = b2Vec2(21.25f, 2.9f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.4f);
			body->CreateFixture(&shape, 0.0f);

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(39.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gr = new Grass1(ts, b2Vec2(29.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(39.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			// apple trees
			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(25.0f, 7.1f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_01, b2Vec2(23.0f, 7.0f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_02, b2Vec2(26.5f, 6.7f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(54.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_Shift, b2Vec2(33.0f, 5.5f));
			map->Actors.insert(std::pair<int, Actor*>(-4, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_08, b2Vec2(30.0f, 8.2f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			ParallaxDecorPrototype * pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(30.4f, 8.1f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(30.8f, 7.6f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_04, b2Vec2(31.2f, 8.4f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_10, b2Vec2(31.5f, 8.7f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(32.2f, 8.4f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_05, b2Vec2(32.7f, 7.8f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(33.1f, 7.8f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_09, b2Vec2(33.6f, 8.4f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_04, b2Vec2(34.2f, 8.3f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(35.0f, 8.7f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(35.2f, 8.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(35.5f, 7.5f));
			pdp->coefX = 0.1f;
			map->Actors.insert(std::pair<int, Actor*>(-9, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(36.0f, 8.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(36.6f, 8.7f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_08, b2Vec2(37.0f, 8.2f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(37.3f, 8.1f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_09, b2Vec2(37.6f, 8.2f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(37.9f, 7.5f));
			pdp->coefX = 0.1f;
			map->Actors.insert(std::pair<int, Actor*>(-9, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(38.2f, 8.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(38.7f, 8.7f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_01, b2Vec2(39.2f, 8.0f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(39.7f, 8.1f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_09, b2Vec2(40.1f, 8.3f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(40.5f, 7.5f));
			pdp->coefX = 0.1f;
			map->Actors.insert(std::pair<int, Actor*>(-9, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(40.8f, 8.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(41.5f, 8.7f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_02, b2Vec2(41.8f, 7.7f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(42.2f, 8.2f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			// GroundBox1 apple trees
			sdp = new StaticDecorPrototype(ts, TextureStorage::Fence1, b2Vec2(49.4f, 5.3f));
			map->Actors.insert(std::pair<int, Actor*>(-9, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(52.0f, 5.5f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			def.position = b2Vec2(52.25f, 5.1f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.2f, 0.4f);
			body->CreateFixture(&shape, 0.0f);

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_01, b2Vec2(44.0f, 9.2f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(44.4f, 9.3f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(44.8f, 9.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_05, b2Vec2(45.2f, 8.5f));
			pdp->coefX = 0.1f;
			map->Actors.insert(std::pair<int, Actor*>(-9, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_09, b2Vec2(45.7f, 9.1f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(46.1f, 9.2f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_02, b2Vec2(46.5f, 8.7f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_09, b2Vec2(46.9f, 9.3f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_06, b2Vec2(47.3f, 9.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_07, b2Vec2(47.9f, 8.5f));
			pdp->coefX = 0.1f;
			map->Actors.insert(std::pair<int, Actor*>(-9, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_05, b2Vec2(48.5f, 9.0f));
			pdp->coefX = 0.05f;
			map->Actors.insert(std::pair<int, Actor*>(-8, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_04, b2Vec2(48.8f, 9.3f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_08, b2Vec2(48.5f, 9.3f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::AppleTree_03, b2Vec2(49.4f, 9.2f));
			pdp->coefX = 0.02f;
			map->Actors.insert(std::pair<int, Actor*>(-7, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_01, b2Vec2(49.8f, 9.1f));
			map->Actors.insert(std::pair<int, Actor*>(2, sdp));

			GroundBox1 * gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(49.0f, 2.2f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb1));

			gr = new Grass1(ts, b2Vec2(44.0f, 4.95f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			sdp = new StaticDecorPrototype(ts, TextureStorage::AppleTree_01, b2Vec2(57.0f, 8.0f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Shed, b2Vec2(61.0f, 6.5f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			PutZombieTA * pzta = new PutZombieTA(ts, b2Vec2(64.2f, 4.0f), 75.0f, 88.0f, 2);
			pzta->enabled = true;
			pzta->resetme = true;
			pzta->ConstructBody(map->world, b2Vec2(68.2f, 5.0f), b2Vec2(0.5f, 1.5f));
			map->Triggers.push_back(pzta);

			gr = new Grass1(ts, b2Vec2(54.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(69.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb1));

			gr = new Grass1(ts, b2Vec2(64.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(79.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gr = new Grass1(ts, b2Vec2(69.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(79.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(99.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gr = new Grass1(ts, b2Vec2(89.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(99.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(119.0f, 1.0f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gb2));

			gr = new Grass1(ts, b2Vec2(109.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			gr = new Grass1(ts, b2Vec2(119.0f, 3.75f));
			map->Actors.insert(std::pair<int, Actor*>(-5, gr));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building02, b2Vec2(95.0f, 7.4f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building04, b2Vec2(99.0f, 7.3f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building05, b2Vec2(97.3f, 7.9f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Town_Hall, b2Vec2(105.0f, 14.8f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::RD_idle_left, b2Vec2(108.5f, 4.7f));
			map->Actors.insert(std::pair<int, Actor*>(-5, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building02, b2Vec2(109.0f, 7.5f));
			map->Actors.insert(std::pair<int, Actor*>(-7, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building05, b2Vec2(114.0f, 9.5f));
			map->Actors.insert(std::pair<int, Actor*>(-6, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::TexName::Building04, b2Vec2(113.5f, 7.3f));
			map->Actors.insert(std::pair<int, Actor*>(-5, sdp));





			/*
			//PulleyPlatform * pp1 = new PulleyPlatform(ts, 6.0f);
			//pp1->ConstructBody(map->world, b2Vec2(30.0f, -0.4f));
			//map->Actors.insert(std::pair<int, Actor*>(-16, pp1));

			//oad.object = pp1;
			//oad.pos = b2Vec2(30.0f, -0.4f);
			//savestate->objects->push_back(oad);

			//// <bounding> (++important)
			//b2BodyDef def;
			//def.position = b2Vec2(29.1f, 1.75f);
			//b2Body * body = map->world->CreateBody(&def);
			//b2PolygonShape shape;
			//shape.SetAsBox(0.1f, 2.25f);
			//b2FixtureDef fixtureDef;
			//fixtureDef.shape = &shape;
			//fixtureDef.filter.groupIndex = -1;  // groupIndex pro playera
			//fixtureDef.filter.categoryBits = 0x0002;
			//fixtureDef.filter.maskBits = 0xFFFF;
			//body->CreateFixture(&fixtureDef);
			////body->CreateFixture(&shape, 0.0f);

			//def.position = b2Vec2(30.9f, 1.75f);
			//body = map->world->CreateBody(&def);
			//body->CreateFixture(&fixtureDef);
			////body->CreateFixture(&shape, 0.0f);
			//// </bounding>

			//PulleyPlatform * pp2 = new PulleyPlatform(ts, 6.0f);
			//pp2->ConstructBody(map->world, b2Vec2(34.6f, 3.4f));
			//map->Actors.insert(std::pair<int, Actor*>(-15, pp2));

			//oad.object = pp2;
			//oad.pos = b2Vec2(34.6f, 3.4f);
			//savestate->objects->push_back(oad);

			//// <bounding>
			//def.position = b2Vec2(33.7f, 1.75f);
			//body = map->world->CreateBody(&def);
			//body->CreateFixture(&fixtureDef);
			////body->CreateFixture(&shape, 0.0f);

			//def.position = b2Vec2(35.5f, 1.75f);
			//body = map->world->CreateBody(&def);
			//body->CreateFixture(&fixtureDef);
			////body->CreateFixture(&shape, 0.0f);
			//// </bounding>

			//b2PulleyJointDef pjd;
			//pjd.bodyA = pp1->body;
			//pjd.bodyB = pp2->body;
			//pjd.groundAnchorA = b2Vec2(30.0f, 9.6f);  // length 10
			//pjd.groundAnchorB = b2Vec2(33.0f, 9.6f);  // length 6.2
			//pjd.lengthA = 10.0f;
			//pjd.lengthB = 6.2f;
			//pjd.localAnchorA = b2Vec2(0.0f, 0.0f);
			//pjd.localAnchorB = b2Vec2(0.0f, 0.0f);
			//pjd.ratio = 1.0f;

			//map->world->CreateJoint(&pjd);
			//PulleyJointDefWrapper * pjdw = new PulleyJointDefWrapper();
			//pjdw->pjd = pjd;
			//pjdw->object1 = pp1;
			//pjdw->object2 = pp2;
			//savestate->joints->push_back(pjdw);
			//// bounding bodies!!

			//Platform1 * plat = new Platform1(ts);
			//plat->ConstructBody(map->world, b2Vec2(32.3f, 3.4f));
			//map->Actors.insert(std::pair<int, Actor*>(-14, plat));

			//sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(32.05f, 3.4f));
			//map->Actors.insert(std::pair<int, Actor*>(-12, sdp));

			//def.position = b2Vec2(32.3f, 0.9f);
			//body = map->world->CreateBody(&def);
			//shape.SetAsBox(0.2f, 2.4f);
			//body->CreateFixture(&shape, 0.0f);

			//sdp = new StaticDecorPrototype(ts, TextureStorage::Scaffolding02, b2Vec2(28.3f, 6.5f));
			//map->Actors.insert(std::pair<int, Actor*>(-47, sdp));
			*/

			LevelExitTA * leta = new LevelExitTA(ts);
			leta->enabled = true;
			leta->actorpos = b2Vec2(107.95f, 4.8f);
			leta->ConstructBody(map->world, b2Vec2(108.6f, 4.0f), b2Vec2(0.5f, 1.5f));
			map->Triggers.push_back(leta);
			map->Actors.insert(std::pair<int, Actor*>(-2, leta));

			Stars1 * st = new Stars1(ts, b2Vec2(-10.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(-10.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(5.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(5.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(20.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(20.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(35.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(35.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(50.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(50.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(65.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(65.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(80.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(80.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(95.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(95.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(110.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(110.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(125.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			st = new Stars1(ts, b2Vec2(125.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, st));

			Moon * m = new Moon(ts, b2Vec2(7.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-9, m));


			break;
		}
	case 3:
		{
			map->level = 3;
			map->CanBeTrixie = true;
			map->CanBeRD = true;
			map->CanBeAJ = true;
			map->boxlayer = 20;
			map->mslayer = 5000;

			ts->LoadTexture(TextureStorage::BigTree2);
			ts->LoadTexture(TextureStorage::Platform2);
			ts->LoadTexture(TextureStorage::Ramp_left);
			ts->LoadTexture(TextureStorage::WaterWheel);
			ts->LoadTexture(TextureStorage::Mill);
			ts->LoadTexture(TextureStorage::BallPillar);
			ts->LoadTexture(TextureStorage::Mountains);
			ts->LoadTexture(TextureStorage::Text_Savepoint);

			map->Actors.insert(std::pair<int, Actor*>(1, map->player));
			map->player->ConstructBody(map->world, b2Vec2(-5.0f, 3.0f));
			map->player->CurrentPony = map->player->AJ;

			savestate->characters = 7;
			savestate->playerchar = 1;
			savestate->playerstate = 1;
			map->player->SetState(1);
			savestate->level = level;
			savestate->playerpos = b2Vec2(-5.0f, 3.0f);
			savestate->screenpos = b2Vec2(-10.0f, 8.0f);

			if (skillsloaded) map->SkillsFromState(savestate);
			else
			{
				// set default skills both to player and savestate
				savestate->runcost = 1.0f;
				savestate->runspeed = 3.0f;
				savestate->canbuck = true;
				savestate->flycost = 1.0f;
				savestate->flyspeed = 2.0f;
				savestate->candash = false;
				savestate->boxcost = 50.0f;
				savestate->levitcost = 1.0f;
				savestate->canlevitate = true;
				savestate->maxboxes = 3;

				map->SkillsFromState(savestate);
			}

			GroundBox1 * gb1 = new GroundBox1(ts);					// groundbox2 je moná moc, staèil by groundbox1
			gb1->ConstructBody(map->world, b2Vec2(-15.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-60, gb1));

			GroundBox2 * gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(0.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(10, gb2));

			//gr = new Grass1(ts, b2Vec2(-30.0f, 2.75f));
			//map->Actors.insert(std::pair<int, Actor*>(-59, gr));

			// fence
			StaticDecorPrototype * sdp = new StaticDecorPrototype(ts, TextureStorage::Palisade, b2Vec2(2.0f, 5.0f));
			map->Actors.insert(std::pair<int, Actor*>(-63, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Palisade, b2Vec2(4.5f, 5.0f));
			map->Actors.insert(std::pair<int, Actor*>(-62, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Palisade, b2Vec2(7.0f, 5.0f));
			map->Actors.insert(std::pair<int, Actor*>(-61, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::GatePassage, b2Vec2(1.68f, 5.0f));
			map->Actors.insert(std::pair<int, Actor*>(-59, sdp));

			Grass1 * gr = new Grass1(ts, b2Vec2(-20.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-58, gr));

			gr = new Grass1(ts, b2Vec2(-10.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-57, gr));

			gr = new Grass1(ts, b2Vec2(0.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-56, gr));

			BigTree * bt = new BigTree(ts);
			bt->ConstructBody(map->world, b2Vec2(-9.0f, 7.5f));
			map->Actors.insert(std::pair<int, Actor*>(-55, bt));

			Gate1 * gg = new Gate1(ts);
			gg->ConstructBody(map->world, b2Vec2(2.0f, 5.0f));
			map->Actors.insert(std::pair<int, Actor*>(-51, gg));

			ObjectAndDef oad;
			oad.object = gg;
			oad.pos = b2Vec2(2.0f, 5.0f);
			savestate->objects->push_back(oad);

			PulleyPlatform * pp = new PulleyPlatform(ts, 2.4f);
			pp->ConstructBody(map->world, b2Vec2(5.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-54, pp));

			oad.object = pp;
			oad.pos = b2Vec2(5.0f, 2.75f);
			savestate->objects->push_back(oad);

			b2PulleyJointDef pjd;
			pjd.bodyA = gg->body;
			pjd.bodyB = pp->body;
			pjd.groundAnchorA = b2Vec2(2.0f, 10.0f);  // length 5
			pjd.groundAnchorB = b2Vec2(5.0f, 7.75f);  // length 5
			pjd.lengthA = 5.0f;
			pjd.lengthB = 5.0f;
			pjd.localAnchorA = b2Vec2(0.0f, 0.0f);
			pjd.localAnchorB = b2Vec2(0.0f, 0.0f);
			pjd.ratio = 12.0f;

			map->world->CreateJoint(&pjd);
			PulleyJointDefWrapper * pjdw = new PulleyJointDefWrapper();
			pjdw->pjd = pjd;
			pjdw->object1 = gg;
			pjdw->object2 = pp;
			savestate->joints->push_back(pjdw);

			// <bounding>
			b2BodyDef def;
			//def.position = b2Vec2(-2.4f, 5.5f);
			def.position = b2Vec2(1.6f, 5.5f);
			b2Body * body = map->world->CreateBody(&def);
			b2PolygonShape shape;
			shape.SetAsBox(0.1f, 3.0f);
			b2FixtureDef fixtureDef;
			fixtureDef.shape = &shape;
			fixtureDef.filter.groupIndex = -1;  // groupIndex pro playera
			fixtureDef.filter.categoryBits = 0x0002;
			fixtureDef.filter.maskBits = 0xFFFF;
			body->CreateFixture(&fixtureDef);

			//def.position = b2Vec2(-1.6f, 5.5f);
			def.position = b2Vec2(2.4f, 5.5f);
			body = map->world->CreateBody(&def);
			body->CreateFixture(&fixtureDef);
			// </bounding>

			RampLeft * rl = new RampLeft(ts);
			//rl->ConstructBody(map->world, b2Vec2(-1.08f, 2.26f));
			rl->ConstructBody(map->world, b2Vec2(2.92f, 2.26f));
			map->Actors.insert(std::pair<int, Actor*>(-53, rl));

			RampRight * rr = new RampRight(ts);
			rr->ConstructBody(map->world, b2Vec2(7.08f, 2.26f));
			map->Actors.insert(std::pair<int, Actor*>(-52, rr));

			rl = new RampLeft(ts);
			rl->ConstructBody(map->world, b2Vec2(8.7f, 3.1f));
			map->Actors.insert(std::pair<int, Actor*>(-47, rl));

			Platform1 * pl = new Platform1(ts);
			pl->ConstructBody(map->world, b2Vec2(11.5f, 3.5f));
			map->Actors.insert(std::pair<int, Actor*>(-46, pl));

			LevitText * ltxt = new LevitText(ts, b2Vec2(9.5f, 6.0f));
			map->Actors.insert(std::pair<int, Actor*>(-49, ltxt));

			EnableLevitTA * elta = new EnableLevitTA(ts);
			elta->enabled = true;
			elta->text = ltxt;
			elta->ConstructBody(map->world, b2Vec2(11.5f, 4.3f));
			map->Triggers.push_back(elta);
			map->Actors.insert(std::pair<int, Actor*>(-48, elta));

			pl = new Platform1(ts);
			pl->ConstructBody(map->world, b2Vec2(14.5f, 3.5f));
			map->Actors.insert(std::pair<int, Actor*>(-45, pl));

			sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(9.8f, 4.0f));
			map->Actors.insert(std::pair<int, Actor*>(11, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(15.6f, 4.0f));
			map->Actors.insert(std::pair<int, Actor*>(12, sdp));

			Water1 * wat = new Water1(ts);
			wat->ConstructBody(map->world, b2Vec2(15.0f, 0.5f));
			map->Actors.insert(std::pair<int, Actor*>(2, wat));

			wat = new Water1(ts);
			wat->ConstructBody(map->world, b2Vec2(25.0f, 0.5f));
			map->Actors.insert(std::pair<int, Actor*>(3, wat));

			WaterWheel * ww = new WaterWheel(ts);
			ww->ConstructBody(map->world, b2Vec2(20.0f, 4.0f));
			map->Actors.insert(std::pair<int, Actor*>(13, ww));

			b2RevoluteJointDef rjd;
			rjd.bodyA = gb2->body;
			rjd.bodyB = ww->body;
			rjd.enableMotor = true;
			rjd.localAnchorA = b2Vec2(20.0f, 4.0f);
			rjd.localAnchorB = b2Vec2(0.0f, 0.0f);
			rjd.maxMotorTorque = 10000.0f;
			rjd.motorSpeed = -1.0f;
			map->world->CreateJoint(&rjd);

			Platform2 * pl2 = new Platform2(ts);
			pl2->ConstructBody(map->world, b2Vec2(21.7f, 8.25f));
			map->Actors.insert(std::pair<int, Actor*>(-44, pl2));

			SavePointTA * spta = new SavePointTA(ts);
			spta->enabled = true;
			spta->actorpos = b2Vec2(21.5f, 9.6f);
			spta->ConstructBody(map->world, b2Vec2(22.0f, 9.0f), b2Vec2(0.4f, 0.4f));
			map->Triggers.push_back(spta);
			map->Actors.insert(std::pair<int, Actor*>(-43, spta));

			//sdp = new StaticDecorPrototype(ts, TextureStorage::BallPillar, b2Vec2(21.5f, 9.6f));
			//map->Actors.insert(std::pair<int, Actor*>(-43, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_Savepoint, b2Vec2(19.0f, 10.4f));
			map->Actors.insert(std::pair<int, Actor*>(-81, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::VertPlank, b2Vec2(19.75f, 4.0f));
			map->Actors.insert(std::pair<int, Actor*>(14, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Platform1, b2Vec2(20.75f, 4.25f));
			map->Actors.insert(std::pair<int, Actor*>(-42, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Mill, b2Vec2(22.4f, 11.95f));
			map->Actors.insert(std::pair<int, Actor*>(-41, sdp));

			// neviditelná zeï
			def.position = b2Vec2(24.0f, 6.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(0.5f, 1.5f);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(35.4f, 6.0f);
			body = map->world->CreateBody(&def);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(23.7f, 12.0f);
			body = map->world->CreateBody(&def);
			body->CreateFixture(&shape, 0.0f);

			def.position = b2Vec2(34.2f, 12.0f);
			body = map->world->CreateBody(&def);
			body->CreateFixture(&shape, 0.0f);

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(33.5f, 2.0f));
			map->Actors.insert(std::pair<int, Actor*>(15, gb2));

			gb1 = new GroundBox1(ts);
			gb1->ConstructBody(map->world, b2Vec2(48.5f, 2.0f));
			map->Actors.insert(std::pair<int, Actor*>(-37, gb1));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(57.0f, 7.0f));
			map->Actors.insert(std::pair<int, Actor*>(-39, gb2));

			// strop v mill
			def.position = b2Vec2(29.0f, 10.0f);
			body = map->world->CreateBody(&def);
			shape.SetAsBox(5.8f, 0.1f);
			body->CreateFixture(&shape, 0.0f);

			// podlaha v mill
			def.position = b2Vec2(30.1f, 8.25f);
			body = map->world->CreateBody(&def);
			b2Vec2 vertices[4];
			vertices[0].Set(-7.0f, 0.1f);
			vertices[1].Set(-7.2f, -0.1f);
			vertices[2].Set(7.2f, -0.1f);
			vertices[3].Set(7.0f, 0.1f);
			shape.Set(vertices, 4);
			body->CreateFixture(&shape, 0.0f);

			//pl2 = new Platform2(ts);			// NE! zùstane naalokovaná pamì! vytvoøit jen b2Body
			//pl2->ConstructBody(map->world, b2Vec2(24.5f, 8.25f));
			////map->Actors.insert(std::pair<int, Actor*>(-39, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(27.5f, 8.25f));
			////map->Actors.insert(std::pair<int, Actor*>(-38, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(30.5f, 8.25f));
			////map->Actors.insert(std::pair<int, Actor*>(-37, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(33.5f, 8.25f));
			////map->Actors.insert(std::pair<int, Actor*>(-36, pl2));

			pl2 = new Platform2(ts);
			pl2->ConstructBody(map->world, b2Vec2(35.7f, 8.25f));
			map->Actors.insert(std::pair<int, Actor*>(-38, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(24.7f, 10.0f));
			////map->Actors.insert(std::pair<int, Actor*>(-34, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(27.7f, 10.0f));
			////map->Actors.insert(std::pair<int, Actor*>(-33, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(30.7f, 10.0f));
			////map->Actors.insert(std::pair<int, Actor*>(-32, pl2));

			//pl2 = new Platform2(ts);
			//pl2->ConstructBody(map->world, b2Vec2(33.2f, 10.0f));
			////map->Actors.insert(std::pair<int, Actor*>(-31, pl2));

			PlaySoundTA * psta = new PlaySoundTA(ts, ss, SoundStorage::SoundName::ZombieGrowl_1);
			psta->enabled = true;
			psta->resetme = true;
			psta->ConstructBody(map->world, b2Vec2(29.5f, 8.85f), b2Vec2(0.5f, 0.5f));
			map->Triggers.push_back(psta);

			PutZombieTA * pzta = new PutZombieTA(ts, b2Vec2(21.7f, 8.9f), 36.5f, 46.3f, 20);
			pzta->enabled = true;
			pzta->resetme = true;
			pzta->ConstructBody(map->world, b2Vec2(30.5f, 8.85f), b2Vec2(0.5f, 0.5f));
			map->Triggers.push_back(pzta);

			gr = new Grass1(ts, b2Vec2(35.5f, 4.75f));
			map->Actors.insert(std::pair<int, Actor*>(-34, gr));

			gr = new Grass1(ts, b2Vec2(45.5f, 4.75f));
			map->Actors.insert(std::pair<int, Actor*>(-33, gr));

			gr = new Grass1(ts, b2Vec2(47.0f, 9.75f));
			map->Actors.insert(std::pair<int, Actor*>(-36, gr));

			gr = new Grass1(ts, b2Vec2(57.0f, 9.75f));
			map->Actors.insert(std::pair<int, Actor*>(-35, gr));

			sdp = new StaticDecorPrototype(ts, TextureStorage::BigTree2, b2Vec2(38.0f, 18.5f));
			map->Actors.insert(std::pair<int, Actor*>(-40, sdp));

			// <ROPE>
			// 1
			RopeSegment * rs = new RopeSegment(ts);
			rs->ConstructBody(map->world, b2Vec2(43.5f, 13.2f));
			map->Actors.insert(std::pair<int, Actor*>(-32, rs));
			oad.pos = b2Vec2(43.5f, 13.2f);
			oad.object = rs;
			savestate->objects->push_back(oad);

			//b2RevoluteJointDef rjd;
			rjd.bodyA = gb2->body;
			rjd.bodyB = rs->body;
			rjd.enableLimit = false;
			rjd.enableMotor = false;
			rjd.localAnchorA = b2Vec2(-13.5f, 6.6f);
			rjd.localAnchorB = b2Vec2(0.0f, 0.45f);
			map->world->CreateJoint(&rjd);

			RevoluteJointDefWrapper * rjdw = new RevoluteJointDefWrapper();
			rjdw->rjd = rjd;
			rjdw->object1 = gb2;
			rjdw->object2 = rs;
			savestate->joints->push_back(rjdw);
			RopeSegment * rsa = rs;

			// 2
			rs = new RopeSegment(ts);
			rs->ConstructBody(map->world, b2Vec2(43.5f, 12.3f));
			map->Actors.insert(std::pair<int, Actor*>(-31, rs));
			oad.pos = b2Vec2(43.5f, 12.3f);
			oad.object = rs;
			savestate->objects->push_back(oad);

			rjd.bodyA = rsa->body;
			rjd.bodyB = rs->body;
			rjd.localAnchorA = b2Vec2(0.0f, -0.45f);
			rjd.localAnchorB = b2Vec2(0.0f, 0.45f);
			map->world->CreateJoint(&rjd);

			rjdw = new RevoluteJointDefWrapper();
			rjdw->rjd = rjd;
			rjdw->object1 = rsa;
			rjdw->object2 = rs;
			savestate->joints->push_back(rjdw);
			rsa = rs;

			// 3
			rs = new RopeSegment(ts);
			rs->ConstructBody(map->world, b2Vec2(43.5f, 11.4f));
			map->Actors.insert(std::pair<int, Actor*>(-30, rs));
			oad.pos = b2Vec2(43.5f, 11.4f);
			oad.object = rs;
			savestate->objects->push_back(oad);

			rjd.bodyA = rsa->body;
			rjd.bodyB = rs->body;
			rjd.localAnchorA = b2Vec2(0.0f, -0.45f);
			rjd.localAnchorB = b2Vec2(0.0f, 0.45f);
			map->world->CreateJoint(&rjd);

			rjdw = new RevoluteJointDefWrapper();
			rjdw->rjd = rjd;
			rjdw->object1 = rsa;
			rjdw->object2 = rs;
			savestate->joints->push_back(rjdw);

			// platform
			RopePlatform * rp = new RopePlatform(ts);
			rp->ConstructBody(map->world, b2Vec2(43.5f, 9.9f));
			map->Actors.insert(std::pair<int, Actor*>(-29, rp));
			oad.pos = b2Vec2(43.5f, 9.9f);
			oad.object = rp;
			savestate->objects->push_back(oad);

			rjd.bodyA = rs->body;
			rjd.bodyB = rp->body;
			rjd.localAnchorA = b2Vec2(0.0f, -0.45f);
			rjd.localAnchorB = b2Vec2(0.0f, 1.1f);
			map->world->CreateJoint(&rjd);

			rjdw = new RevoluteJointDefWrapper();
			rjdw->rjd = rjd;
			rjdw->object1 = rs;
			rjdw->object2 = rp;
			savestate->joints->push_back(rjdw);
			//</ROPE>


			//RopePlatform * rp = new RopePlatform(ts);
			//rp->ConstructBody(map->world, b2Vec2(43.5f, 11.0f));
			//map->Actors.insert(std::pair<int, Actor*>(-32, rp));
			//ObjectAndDef oad;
			//oad.object = rp;
			//oad.pos = b2Vec2(43.5f, 11.0f);
			//savestate->objects->push_back(oad);

			//rjd.bodyA = gb2->body;
			//rjd.bodyB = rp->body;
			//rjd.enableLimit = false;
			//rjd.enableMotor = true;
			//rjd.maxMotorTorque = -5.0f;
			//rjd.motorSpeed = 0.0f;
			//rjd.localAnchorA = b2Vec2(-13.5f, 6.6f);
			//rjd.localAnchorB = b2Vec2(0.0f, 2.6f);
			//map->world->CreateJoint(&rjd);

			//RevoluteJointDefWrapper * rjdw = new RevoluteJointDefWrapper();
			//rjdw->rjd = rjd;
			//rjdw->object1 = gb2;
			//rjdw->object2 = rp;
			//savestate->joints->push_back(rjdw);

			IncMaxBoxesTA * imbta = new IncMaxBoxesTA(ts);
			imbta->enabled = true;
			imbta->ConstructBody(map->world, b2Vec2(49.0f, 10.3f));
			map->Triggers.push_back(imbta);
			map->Actors.insert(std::pair<int, Actor*>(-80, imbta));

			LevelExitTA * leta = new LevelExitTA(ts);
			leta->enabled = true;
			leta->actorpos = b2Vec2(54.25f, 10.78f);
			leta->ConstructBody(map->world, b2Vec2(55.0f, 11.5f), b2Vec2(0.5f, 2.0f));
			map->Triggers.push_back(leta);
			map->Actors.insert(std::pair<int, Actor*>(-79, leta));

			//sdp = new StaticDecorPrototype(ts, TextureStorage::StarPillar, b2Vec2(54.2f, 10.78f));
			//map->Actors.insert(std::pair<int, Actor*>(-84, sdp));

			//Stars1 * st = new Stars1(ts, b2Vec2(-37.0f, 20.0f));
			//map->Actors.insert(std::pair<int, Actor*>(-100, st));

			//st = new Stars1(ts, b2Vec2(-37.0f, 10.0f));
			//map->Actors.insert(std::pair<int, Actor*>(-99, st));

			Stars1 * st = new Stars1(ts, b2Vec2(-22.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-98, st));

			st = new Stars1(ts, b2Vec2(-22.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-97, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-96, st));

			st = new Stars1(ts, b2Vec2(-7.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-95, st));

			st = new Stars1(ts, b2Vec2(8.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-94, st));

			st = new Stars1(ts, b2Vec2(8.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-93, st));

			st = new Stars1(ts, b2Vec2(23.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-92, st));

			st = new Stars1(ts, b2Vec2(23.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-91, st));

			st = new Stars1(ts, b2Vec2(38.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-90, st));

			st = new Stars1(ts, b2Vec2(38.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-89, st));

			st = new Stars1(ts, b2Vec2(53.0f, 20.0f));
			map->Actors.insert(std::pair<int, Actor*>(-88, st));

			st = new Stars1(ts, b2Vec2(53.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-87, st));

			Mountains * m = new Mountains(ts, b2Vec2(9.0f, 8.0f));
			map->Actors.insert(std::pair<int, Actor*>(-86, m));

			m = new Mountains(ts, b2Vec2(8.0f, 7.0));
			map->Actors.insert(std::pair<int, Actor*>(-85, m));

			m = new Mountains(ts, b2Vec2(20.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-84, m));

			m = new Mountains(ts, b2Vec2(18.0f, 9.0f));
			map->Actors.insert(std::pair<int, Actor*>(-83, m));

			m = new Mountains(ts, b2Vec2(30.0f, 10.0f));
			map->Actors.insert(std::pair<int, Actor*>(-82, m));


			break;
		}

	case 4:
		{
			map->level = 4;
			map->CanBeTrixie = true;
			map->CanBeRD = false;
			map->CanBeAJ = false;
			map->boxlayer = 50;
			map->mslayer = 5000;

			ts->LoadTexture(TextureStorage::Seth1);
			ts->LoadTexture(TextureStorage::Seth2);
			//ts->LoadTexture(TextureStorage::Seth3);
			ts->LoadTexture(TextureStorage::Seth3_1);
			ts->LoadTexture(TextureStorage::Seth3_2);
			ts->LoadTexture(TextureStorage::Seth3_3);
			ts->LoadTexture(TextureStorage::Gray);
			ts->LoadTexture(TextureStorage::Text_End1);
			ts->LoadTexture(TextureStorage::Text_End2);
			ts->LoadTexture(TextureStorage::Text_End3);

			map->Actors.insert(std::pair<int, Actor*>(1, map->player));
			map->player->ConstructBody(map->world, b2Vec2(3.0f, 3.0f));
			map->player->CurrentPony = map->player->Trixie;

			savestate->characters = 7;
			savestate->playerchar = 1;
			savestate->playerstate = 1;
			map->player->SetState(1);
			savestate->level = level;
			savestate->playerpos = b2Vec2(5.0f, 3.0f);
			savestate->screenpos = b2Vec2(0.0f, 8.0f);

			if (skillsloaded) map->SkillsFromState(savestate);
			else
			{
				// set default skills both to player and savestate
				savestate->runcost = 1.0f;
				savestate->runspeed = 3.0f;
				savestate->canbuck = true;
				savestate->flycost = 1.0f;
				savestate->flyspeed = 2.0f;
				savestate->candash = false;
				savestate->boxcost = 50.0f;
				savestate->levitcost = 1.0f;
				savestate->canlevitate = true;
				savestate->maxboxes = 3;

				map->SkillsFromState(savestate);
			}

			GroundBox2 * gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(0.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-20, gb2));

			Grass1 * gr = new Grass1(ts, b2Vec2(-10.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-19, gr));

			gr = new Grass1(ts, b2Vec2(0.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-18, gr));

			PlaySoundTA * psta = new PlaySoundTA(ts, ss, SoundStorage::SoundName::InceptionSound);
			psta->enabled = true;
			psta->ConstructBody(map->world, b2Vec2(9.0f, 5.0f), b2Vec2(0.5f, 2.0f));
			map->Triggers.push_back(psta);

			BigTree * bt = new BigTree(ts);
			bt->ConstructBody(map->world, b2Vec2(1.0f, 7.5f));
			map->Actors.insert(std::pair<int, Actor*>(-17, bt));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(20.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-16, gb2));

			gr = new Grass1(ts, b2Vec2(10.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-15, gr));

			gr = new Grass1(ts, b2Vec2(20.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-14, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(40.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-13, gb2));

			gr = new Grass1(ts, b2Vec2(30.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-12, gr));

			gr = new Grass1(ts, b2Vec2(40.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-11, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(60.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, gb2));

			gr = new Grass1(ts, b2Vec2(50.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-9, gr));

			gr = new Grass1(ts, b2Vec2(60.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-8, gr));

			gb2 = new GroundBox2(ts);
			gb2->ConstructBody(map->world, b2Vec2(80.0f, 0.0f));
			map->Actors.insert(std::pair<int, Actor*>(-10, gb2));

			gr = new Grass1(ts, b2Vec2(70.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-9, gr));

			gr = new Grass1(ts, b2Vec2(80.0f, 2.75f));
			map->Actors.insert(std::pair<int, Actor*>(-8, gr));

			StaticDecorPrototype * sdp = new StaticDecorPrototype(ts, TextureStorage::Gray, b2Vec2(14.9f, 8.0f));
			map->Actors.insert(std::pair<int, Actor*>(-40, sdp));

			ParallaxDecorPrototype * pdp = new ParallaxDecorPrototype(ts, TextureStorage::Seth2);
			pdp->startpos = b2Vec2(15.5f, 6.9f);
			pdp->coefX = 0.1f;
			pdp->coefY = 0.2f;
			map->Actors.insert(std::pair<int, Actor*>(-39, pdp));

			pdp = new ParallaxDecorPrototype(ts, TextureStorage::Seth2);
			pdp->startpos = b2Vec2(18.8f, 6.9f);
			pdp->coefX = 0.1f;
			pdp->coefY = 0.2f;
			map->Actors.insert(std::pair<int, Actor*>(-38, pdp));

			SethPupil * sp = new SethPupil(ts, b2Vec2(15.9f, 6.3f));
			map->Actors.insert(std::pair<int, Actor*>(-37, sp));

			sp = new SethPupil(ts, b2Vec2(19.2f, 6.3f));
			map->Actors.insert(std::pair<int, Actor*>(-36, sp));

			//pdp = new ParallaxDecorPrototype(ts, TextureStorage::Seth3);
			//pdp->startpos = b2Vec2(15.9f, 6.3f);
			//pdp->coefX = 0.12f;
			//pdp->coefY = 0.28f;
			//map->Actors.insert(std::pair<int, Actor*>(-37, pdp));

			//pdp = new ParallaxDecorPrototype(ts, TextureStorage::Seth3);
			//pdp->startpos = b2Vec2(19.2f, 6.3f);
			//pdp->coefX = 0.12f;
			//pdp->coefY = 0.28f;
			//map->Actors.insert(std::pair<int, Actor*>(-36, pdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Seth1, b2Vec2(13.0f, 11.5f));
			map->Actors.insert(std::pair<int, Actor*>(-35, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_End1, b2Vec2(25.0f, 6.0f));
			map->Actors.insert(std::pair<int, Actor*>(-34, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_End2, b2Vec2(33.0f, 8.0f));
			map->Actors.insert(std::pair<int, Actor*>(-33, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_End3, b2Vec2(44.0f, 5.5f));
			map->Actors.insert(std::pair<int, Actor*>(-32, sdp));

			sdp = new StaticDecorPrototype(ts, TextureStorage::Text_End4, b2Vec2(54.0f, 6.0f));
			map->Actors.insert(std::pair<int, Actor*>(-32, sdp));

			bt = new BigTree(ts);
			bt->ConstructBody(map->world, b2Vec2(66.0f, 7.5f));
			map->Actors.insert(std::pair<int, Actor*>(-31, bt));

			Stars1 * st = new Stars1(ts, b2Vec2(-7.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-50, st));

			st = new Stars1(ts, b2Vec2(8.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-48, st));

			st = new Stars1(ts, b2Vec2(23.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-46, st));

			st = new Stars1(ts, b2Vec2(38.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-44, st));

			st = new Stars1(ts, b2Vec2(53.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-42, st));

			st = new Stars1(ts, b2Vec2(68.0f, 12.0f));
			map->Actors.insert(std::pair<int, Actor*>(-41, st));

			break;
		}
		// ...
	}

	return map;
}

void Map::Step()
{
	world->Step(timeStep, velocityIterations, positionIterations);
}

void Map::GetSaveState(SaveState * savestate)
{
	savestate->Reset();
	savestate->level = level;
	savestate->screenpos = b2Vec2(Game::PositionX, Game::PositionY);
	if (CanBeAJ) savestate->characters |= 0x01;
	if (CanBeRD) savestate->characters |= 0x02;
	if (CanBeTrixie) savestate->characters |= 0x04;
	if (player->CurrentPony == player->AJ) savestate->playerchar = 1;
	if (player->CurrentPony == player->RD) savestate->playerchar = 2;
	if (player->CurrentPony == player->Trixie) savestate->playerchar = 3;

	// skills
	SkillsToState(savestate);

	// zatim jenom pokus
	//left je 0, right je 1
	Movement m = player->playerKA->Actual->mv;
	if (m == Movement::BuckL || m == Movement::IdleL || m == Movement::JumpL || m == Movement::RunL
		|| m == Movement::WalkL || m == Movement::FallL || m == Movement::FlyL || m == Movement::DashL)
		savestate->playerstate = 0;
	else savestate->playerstate = 1;

	savestate->playerpos = player->body->GetPosition();

	// Triggers se musí procházet pøed Actors
	std::vector<std::vector<TriggerArea *>::iterator> toremove;
	for (std::vector<TriggerArea *>::iterator it = Triggers.begin(); it != Triggers.end(); ++it)
	{
		TriggerArea * ta = (*it);
		if (ta->deleteme)
		{
			if (ta->body)
			{
				world->DestroyBody(ta->body);
				ta->body = NULL;
			}
			if (ta->isinactors) RemovePtrFromActors(ta);
			toremove.push_back(it);
		}
	}
	for (std::vector<std::vector<TriggerArea *>::iterator>::iterator ait = toremove.begin(); ait != toremove.end(); ait++)
	{
		std::vector<TriggerArea *>::iterator it = (*ait);
		TriggerArea * ta = (*it);
		Triggers.erase(it);
		delete ta;
	}

	for (std::multimap<int, Actor*>::iterator it = Actors.begin(); it != Actors.end(); ++it)
	{
		Actor * a = (*it).second;
		if (a == player) continue;
		Parasprite * pp = dynamic_cast<Parasprite *>(a);
		if (pp)
		{
			ObjectAndDef oad;
			oad.object = pp;
			savestate->objects->push_back(oad);
			continue;
		}
		Object * o = dynamic_cast<Object *>(a);
		if (o == NULL) continue;
		if (o->body == NULL) continue;

		if (o->reconstruct)
		{
			//zapsat data z o do savestate
			ObjectAndDef oad;
			oad.object = o;
			oad.pos = o->body->GetPosition();
			oad.vel = o->body->GetLinearVelocity();
			savestate->objects->push_back(oad);
		}
	}

	b2Joint * j = world->GetJointList();
	while (j)
	{
		switch (j->GetType()) // pokud je to gear joint tak budu kontrolovat jeho jointy, ne objekty
		{
		case b2JointType::e_revoluteJoint:
			{
				b2RevoluteJoint * rjp = dynamic_cast<b2RevoluteJoint *>(j);
				Object * o1 = (Object *)rjp->GetBodyA()->GetUserData();
				Object * o2 = (Object *)rjp->GetBodyB()->GetUserData();
				if (o1->reconstruct || o2->reconstruct)
				{
					RevoluteJointDefWrapper * rjdw = new RevoluteJointDefWrapper(rjp);
					savestate->joints->push_back(rjdw);
				}
				break;
			}
		case b2JointType::e_distanceJoint:
			{
				b2DistanceJoint * djp = dynamic_cast<b2DistanceJoint *>(j);
				Object * o1 = (Object *)djp->GetBodyA()->GetUserData();
				Object * o2 = (Object *)djp->GetBodyB()->GetUserData();
				if (o1->reconstruct || o2->reconstruct)
				{
					DistanceJointDefWrapper * djdw = new DistanceJointDefWrapper(djp);
					savestate->joints->push_back(djdw);
				}
				break;
			}
		case b2JointType::e_pulleyJoint:
			{
				b2PulleyJoint * pjp = dynamic_cast<b2PulleyJoint *>(j);
				Object * o1 = (Object *)pjp->GetBodyA()->GetUserData();
				Object * o2 = (Object *)pjp->GetBodyB()->GetUserData();
				if (o1->reconstruct || o2->reconstruct)  // tohle je moná zbyteènı, pulley by se mìl vdy rekonstruovat
				{
					PulleyJointDefWrapper * pjdw = new PulleyJointDefWrapper(pjp);
					savestate->joints->push_back(pjdw);
				}
				break;
			}
		}
		
		j = j->GetNext();
	}
}

void Map::ResetToSavestate(SaveState * savestate)
{
	if (player->Trixie)
	{
		while (player->Trixie->BoxCount > 0)
		{
			MagicBox * mb = player->Trixie->RemoveFrontBox();
			DeleteActor(mb);
		}
	}
	DestroyAllBodies(false);

	CanBeAJ = CanBeRD = CanBeTrixie = false;
	if ((savestate->characters & 0x01) == 1) CanBeAJ = true;
	if ((savestate->characters & 0x02) == 2) CanBeRD = true;
	if ((savestate->characters & 0x04) == 4) CanBeTrixie = true;

	if (savestate->playerchar == 1) player->CurrentPony = player->AJ;
	if (savestate->playerchar == 2) player->CurrentPony = player->RD;
	if (savestate->playerchar == 3) player->CurrentPony = player->Trixie;
	level = savestate->level;

	player->ConstructBody(world, savestate->playerpos);
	player->SetState(savestate->playerstate);
	player->SetEnergyToMax();

	// skills
	SkillsFromState(savestate);

	// reconstruct bodies
	for (std::vector<ObjectAndDef>::iterator it = savestate->objects->begin(); it != savestate->objects->end(); it++)
	{
		ObjectAndDef oad = *it;
		if ((oad.object) && (oad.object->reconstruct)) oad.object->ConstructBody(world, oad.pos);
	}

	// znova vytvoøit jointy
	for (std::vector<JointDefWrapper *>::iterator it = savestate->joints->begin(); it != savestate->joints->end(); it++)
	{
		JointDefWrapper * jdwp = (*it);
		switch (jdwp->type)
		{
		case b2JointType::e_revoluteJoint:
			{
				RevoluteJointDefWrapper * rjdw = (RevoluteJointDefWrapper *)jdwp;
				b2RevoluteJointDef rjd = rjdw->ToDef();  // kontrolovat jestli bodies existujou?
				world->CreateJoint(&rjd);
				break;
			}
		case b2JointType::e_distanceJoint:
			{
				DistanceJointDefWrapper * djdw = (DistanceJointDefWrapper *)jdwp;
				b2DistanceJointDef djd = djdw->ToDef();
				world->CreateJoint(&djd);
				break;
			}
		case b2JointType::e_pulleyJoint:
			{
				PulleyJointDefWrapper * pjdw = (PulleyJointDefWrapper *)jdwp;
				b2PulleyJointDef pjd = pjdw->ToDef();
				world->CreateJoint(&pjd);
				break;
			}
		}
	}

	std::vector<std::multimap<int, Actor*>::iterator> toremove;
	for (std::multimap<int, Actor*>::iterator it = Actors.begin(); it != Actors.end(); ++it)  // najít bezprizorní actory
	{
		Actor * a = (*it).second;
		Parasprite * pp = dynamic_cast<Parasprite *>(a);  // Parasprite nemá body
		if (pp) continue;
		Object * o = dynamic_cast<Object *>(a);
		if (o)
		{
			if (o->body == NULL)
			{
				delete o;
				(*it).second = NULL;
				toremove.push_back(it);
			}
		}
	}

	// smazat bezprizorní actory
	for (std::vector<std::multimap<int, Actor*>::iterator>::iterator it = toremove.begin(); it != toremove.end(); it++)
	{
		std::multimap<int, Actor*>::iterator ait = (*it);
		Actors.erase(ait);
		// ne delete, u se volalo v cyklu nahoøe
	}

	// reset triggers kterı mají resetme == true
	for (std::vector<TriggerArea *>::iterator it = Triggers.begin(); it != Triggers.end(); it++)
	{
		TriggerArea * ta = (*it);
		if (ta->resetme)
		{
			PowerUpTA * pu = dynamic_cast<PowerUpTA *>(ta);
			if (pu && pu->text) pu->text->SetVisited(false);
			ta->enabled = true;
			ta->deleteme = false;
		}
	}
}

void Map::SkillsToState(SaveState * savestate)
{
	savestate->runcost = player->AJ->runcost;
	savestate->runspeed = player->AJ->runspeed;
	savestate->canbuck = player->AJ->canbuck;
	savestate->flycost = player->RD->flycost;
	savestate->flyspeed = player->RD->flyspeed;
	savestate->candash = player->RD->candash;
	savestate->boxcost = player->Trixie->boxcost;
	savestate->maxboxes = player->Trixie->MaxBoxes;
	savestate->levitcost = player->Trixie->levitatecost;
	savestate->canlevitate = player->Trixie->canlevitate;
}

void Map::SkillsFromState(SaveState * savestate)
{
	player->AJ->runcost = savestate->runcost;
	player->AJ->runspeed = savestate->runspeed;
	player->AJ->canbuck = savestate->canbuck;
	player->RD->flycost = savestate->flycost;
	player->RD->flyspeed = savestate->flyspeed;
	player->RD->candash = savestate->candash;
	player->Trixie->boxcost = savestate->boxcost;
	player->Trixie->MaxBoxes = savestate->maxboxes;
	player->Trixie->levitatecost = savestate->levitcost;
	player->Trixie->canlevitate = savestate->canlevitate;
}

void Map::DestroyAllBodies(bool all)
{
	for (std::multimap<int, Actor*>::iterator it = Actors.begin(); it != Actors.end(); ++it)
	{
		Actor * a = (*it).second;
		Object * o = dynamic_cast<Object *>(a);
		if ((o) && (o->body))
		{
			if ((all) || (o->reconstruct))
			{
				if (world) world->DestroyBody(o->body);
				o->body = NULL;
			}
		}
	}
}

void Map::DestroyBody(Object * o)
{
	if (o)
	{
		if ((world) && (o->body)) world->DestroyBody(o->body);
		o->body = NULL;
	}
}

void Map::DestroyBody(b2Body * b)
{
	if ((world) && (b)) world->DestroyBody(b);
}

void Map::DeleteAllActors()
{
	for (std::multimap<int, Actor*>::iterator it = Actors.begin(); it != Actors.end(); ++it)
	{
		Actor * a = (*it).second;
		Object * o = dynamic_cast<Object *>(a);
		if ((o) && (o->body))
		{
			if (world) world->DestroyBody(o->body);
			o->body = NULL;
		}
		delete a;
	}
	Actors.clear();
}

void Map::ResetTextures(TextureStorage * ts)
{
	for (std::multimap<int, Actor *>::iterator it = Actors.begin(); it != Actors.end(); it++)
	{
		Actor * a = it->second;
#ifdef _DEBUG  // kdy debug tak se textury pro triggers naètou v spodním for-cyklu
		TriggerArea * tap = dynamic_cast<TriggerArea *>(a);
		if (tap) continue;
#endif
		a->GetTextures(ts);
	}
#ifdef _DEBUG
	for (std::vector<TriggerArea *>::iterator it = Triggers.begin(); it != Triggers.end(); it++)
	{
		TriggerArea * ta = (*it);
		ta->GetTextures(ts);
	}
#endif
}

void Map::DeleteActor(Actor * a)
{
	if (a == NULL) return;
	for (std::multimap<int, Actor *>::iterator it = Actors.begin(); it != Actors.end(); it++)
	{
		if (a == (*it).second)
		{
			Object * o = dynamic_cast<Object *>(a);
			if ((o) && (o->body))
			{
				if (world) world->DestroyBody(o->body);
				o->body = NULL;
			}
			delete a;
			Actors.erase(it);
			break;
		}
	}
}

void Map::DeleteActor(std::multimap<int, Actor*>::iterator it)
{
	Actor * a = (*it).second;
	if (a)
	{
		Object * o = dynamic_cast<Object *>(a);
		if ((o) && (o->body))
		{
			if (world) world->DestroyBody(o->body);
			o->body = NULL;
		}
		delete a;
	}
	Actors.erase(it);
}

void Map::RemovePtrFromActors(Actor * a)
{
	if (a == NULL) return;
	for (std::multimap<int, Actor *>::iterator it = Actors.begin(); it != Actors.end(); it++)
	{
		if (a == (*it).second)
		{
			Actors.erase(it);
			break;
		}
	}
}

MagicBox * Map::PutBox(TextureStorage * ts, b2Vec2 pos)
{
	MagicBox * box = new MagicBox(ts);
	Actors.insert(std::pair<int, Actor*>(boxlayer, box));
	box->ConstructBody(world, pos);
	return box;
}

//@deprecated
//void Map::DestroyBox(MagicBox * mb)
//{
//	if (world) world->DestroyBody(mb->body);
//	mb->body = NULL;
//	for (std::map<int, Actor *>::iterator it = Actors.begin(); it != Actors.end(); it++)
//	{
//		Actor * a = (*it).second;
//		if (a == mb)
//		{
//			delete a;
//			Actors.erase(it);
//			break;
//		}
//	}
//}

int Map::PutMagicStar(TextureStorage * ts, b2Vec2 pos)
{
	MagicStar * ms = new MagicStar(ts, pos);
	Actors.insert(std::pair<int, Actor*>(mslayer, ms));
	int r = mslayer;
	++mslayer;
	return r;
}

void Map::PutZombie(TextureStorage * ts, b2Vec2 pos, float LeftBound, float RightBound, int l)
{
	Zombie * z = new Zombie(ts);
	z->Lbound = LeftBound;
	z->Rbound = RightBound;
	z->ConstructBody(world, pos);
	Actors.insert(std::pair<int, Actor*>(l, z));
}

// does not delete Player!
Map::~Map()
{
	delete world;
	world = NULL;

	for (std::multimap<int, Actor*>::iterator it = Actors.begin(); it != Actors.end(); ++it)
	{
		Actor * a = (*it).second;
		
		Object * o = dynamic_cast<Object *>(a);
		if ((o) && (o->body))
		{ o->body = NULL; }

		Player * pl = dynamic_cast<Player *>(a);
		if (pl) continue;

		TriggerArea * ta = dynamic_cast<TriggerArea *>(a);
		if (ta) continue;  // TriggerAreas se maou v posledním cyklu, jinak bysme nìkterı mazali dvakrát

		delete a;
	}
	Actors.clear();

	if (player->Trixie)  // vyprázdnit boxes
	{
		while (player->Trixie->BoxCount > 0) player->Trixie->RemoveFrontBox();
	}

	for (std::vector<TriggerArea *>::iterator it = Triggers.begin(); it != Triggers.end(); it++)
	{
		TriggerArea * ta = (*it);
		delete ta;
	}
	Triggers.clear();
}