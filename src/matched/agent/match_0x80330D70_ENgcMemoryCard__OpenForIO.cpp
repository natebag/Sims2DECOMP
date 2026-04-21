// 0x80330D70 (8B) ENgcMemoryCard::OpenForIO(char *, unsigned int)
// Trivial stub returning 1.

class ENgcMemoryCard {
public:
    int OpenForIO(char* path, unsigned int mode);
};

int ENgcMemoryCard::OpenForIO(char*, unsigned int) { return 1; }
