// 0x800D3D70 (8 bytes)
class NghResFile {
public:
    int IsLittleEndian();
};

int NghResFile::IsLittleEndian() {
    return 1;
}
