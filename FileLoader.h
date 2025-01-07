#pragma once

#include "CoreMinimal.h"
#include "Singleton.h"

class FileLoader : public Singleton<FileLoader>
{
	string extension;

public:
	FileLoader();

public:
	string ReadAll(const string& _path) const;

};