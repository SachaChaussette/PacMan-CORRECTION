#pragma once

#include "Singleton.h"
#include "CoreMinimal.h"

class TextureManager : public Singleton<TextureManager>
{
	string prefix;
	string extension;

public:
	TextureManager();
public:
	
	void InitShape(RectangleShape& _shape, Texture& _texture, const string& _path);
};

