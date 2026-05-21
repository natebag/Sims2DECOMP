// 0x802C6B7C EFileSystem::FileCreator::TallyBits(int, int, int) const (36B)
//
// Simple 3-arg const method: if a==b return c; if a==0x80000000 return 0;
// else return 0x80000000.
// Pure source-only.

namespace EFileSystem {
class FileCreator {
public:
    int TallyBits(int a, int b, int c) const;
};
}

int EFileSystem::FileCreator::TallyBits(int a, int b, int c) const {
    if (a == b) return c;
    if (a == (int)0x80000000) return 0;
    return (int)0x80000000;
}
