class EChecksum {
public:
    static unsigned int Compute(char*);
};

class ECheatLookup {
public:
    static unsigned int hash(char*);
};

unsigned int ECheatLookup::hash(char* text)
{
    return EChecksum::Compute(text);
}
