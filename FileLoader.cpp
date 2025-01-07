#include "FileLoader.h"

FileLoader::FileLoader()
{
    extension = ".txt";
}

string FileLoader::ReadAll(const string& _path) const
{
    ifstream _stream = ifstream(_path + extension);

    if (!_stream.is_open())
    {
        const string& _filePathName = _path.empty() ? "Unknown" : _path + extension;
        //throw exception("ERROR => Impossible de charger le fichier " + _filePathName);
    }

    string _data, _line;

    while (getline(_stream, _line))
    {
        _data += _line;
      _data += '\n';
    }

    return _data;
}
