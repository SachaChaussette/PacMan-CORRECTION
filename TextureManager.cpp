#include "TextureManager.h"

TextureManager::TextureManager()
{
	prefix = "Assets/Textures/";
	extension = ".png";
}

void TextureManager::InitShape(RectangleShape& _shape, Texture& _texture, const string& _path)
{
	if (_texture.loadFromFile(prefix + _path + extension))
	{
		_shape.setTexture(&_texture);
	}
	else
	{
		cerr << "ERROR => InitShape() Le fichier n'a pas pu être chargé !!!" << endl;
	}
	
}

void TextureManager::UpdateSpriteIndex(RectangleShape& _shape, u_int& _spriteIndex, const u_int& _maxTile, const u_int& _timeToWait)
{
	static u_int _time = 0;

	if (++_time % _timeToWait == 0)
	{
		++_spriteIndex %= _maxTile;
		UpdateShape(_shape, _spriteIndex);
	}
}

void TextureManager::SetTextureRectOnShape(RectangleShape& _shape, const Vector2i& _position, const Vector2i& _size)
{
	_shape.setTextureRect(IntRect(_position, _size));
}
void TextureManager::SetTextureRectOnShape(RectangleShape& _shape, const IntRect& _intRect)
{
	_shape.setTextureRect(_intRect);
}

void TextureManager::UpdateShape(RectangleShape& _shape, u_int& _spriteIndex)
{
	_shape.setTextureRect(IntRect(Vector2i(15 * _spriteIndex, 0), Vector2i(15, 15)));
}
