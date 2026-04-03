// 0x80022684 (8 bytes)
class EDummyFile {
public:
    int Read(int p1, int p2);
};

int EDummyFile::Read(int p1, int p2) {
    return p2;
}
