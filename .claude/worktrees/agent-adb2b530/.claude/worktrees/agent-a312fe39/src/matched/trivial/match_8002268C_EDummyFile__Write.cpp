// 0x8002268C (8 bytes)
class EDummyFile {
public:
    int Write(int p1, int p2);
};

int EDummyFile::Write(int p1, int p2) {
    return p2;
}
