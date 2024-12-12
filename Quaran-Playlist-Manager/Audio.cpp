#include "Audio.h"

Audio::Audio(const string& name, const string& path, const string& type)
    : name(name), path(path), type(type) {}

string Audio::getName() const {
    return name;
}

string Audio::getPath() const {
    return path;
}

string Audio::getType() const {
    return type;
}

void Audio::setName(const string& name) {
    this->name = name;
}

void Audio::setPath(const string& path) {
    this->path = path;
}

void Audio::setType(const string& type) {
    this->type = type;
}

bool Audio::operator==(const Audio& other) const {
    return name == other.name && path == other.path && type == other.type;
}

void Audio::print() const {
    cout << "Audio Name: " << name << endl;
    cout << "Audio Path: " << path << endl;
    cout << "Audio Type: " << type << endl;
}

ostream& operator<<(ostream& print, const Audio& audio) {
    print << "Audio Name: " << audio.name << ", Path: " << audio.path << ", Type: " << audio.type;
    return print;
}
