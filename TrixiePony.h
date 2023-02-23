#pragma once

#include<MagicBox.h>
#include<Pony.h>
#include<RoundList.h>
#include<TextureStorage.h>
#include<queue>

class TrixiePony : public Pony
{
public:
	int BoxCount;
	int MaxBoxes;
	std::queue<MagicBox *> * Boxes;
	float boxcost;
	float levitatecost;
	bool canlevitate;

	TrixiePony(TextureStorage * ts);
	void GetTextures(TextureStorage * ts);
	void AddBox(MagicBox * mb);
	void RemoveBox(MagicBox * mb);
	MagicBox * RemoveFrontBox();
};