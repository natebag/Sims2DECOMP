// 0x80330D78 (8B) ENgcMemoryCard::CloseForIO(char *, unsigned int)
// Trivial stub returning 1.

class ENgcMemoryCard {
public:
    int CloseForIO(char* path, unsigned int mode);
};

int ENgcMemoryCard::CloseForIO(char*, unsigned int) { return 1; }
