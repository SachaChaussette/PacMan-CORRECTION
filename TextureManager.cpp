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
