// 0x802D803C ENgcSNFile::Seek (68b)

struct ENgcSNFile {
    char pad[0x14];
    int field_0x14;
    char pad2[0x18];
    int field_0x30;
    char pad3[0x8];
    int field_0x3c;
    int Seek(int offset, int origin);
};

int ENgcSNFile::Seek(int offset, int origin) {
    if (origin == 1) {
        offset += field_0x14;
    } else if (origin == 0) {
        field_0x30 = offset;
    } else {
        field_0x30 = field_0x14 + offset;
    }
    field_0x3c = 0;
    return field_0x30;
}
