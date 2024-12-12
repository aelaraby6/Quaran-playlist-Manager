#ifndef AUDIO_H
#define AUDIO_H

#include <string>
#include <iostream>

using namespace std;

class Audio {
private:
    string name;
    string path;
    string type;

public:
    Audio(const string& name, const string& path, const string& type);

    string getName() const;
    string getPath() const;
    string getType() const;
    void setName(const string& name);
    void setPath(const string& path);
    void setType(const string& type);
    bool operator==(const Audio& other) const;
    void print() const;
    friend ostream& operator<<(ostream& os, const Audio& audio);
};

#endif
