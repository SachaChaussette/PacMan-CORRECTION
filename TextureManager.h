#pragma once

#include "Singleton.h"
#include "CoreMinimal.h"

class TextureManager : public Singleton<TextureManager>
{
	string prefix;
	string extension;


public:
	TextureManager();

private:
	void UpdateShape(RectangleShape& _shape, u_int& _spriteIndex);
public:
	void InitShape(RectangleShape& _shape, Texture& _texture, const string& _path);

	void UpdateSpriteIndex(RectangleShape& _shape,  u_int& _spriteIndex, const u_int& _maxTile, const u_int& _timeToWait);
	void SetTextureRectOnShape(RectangleShape& _shape, const Vector2i& _position, const Vector2i& _size);
	void SetTextureRectOnShape(RectangleShape& _shape, const IntRect& _intRect);
};

