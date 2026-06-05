// 0x80232D80 ERLevel::AllocAndLoadLevel(EFile &) (120 B)

struct ERLevel;
struct EFileVtable { char pad[0x18]; short off; void (*read)(void*, void*, int); };
struct EFile { char pad[0x28]; EFileVtable* vtable; };
extern EFile& operator>>(EFile& file, ERLevel*& level);

ERLevel* ERLevel_AllocAndLoadLevel(EFile& file) {
    int a;
    ERLevel* level;
    int b;
    EFileVtable* vt = file.vtable;
    vt->read((char*)&file + vt->off, &a, 4);
    operator>>(file, level);
    vt = file.vtable;
    vt->read((char*)&file + vt->off, &b, 4);
    return level;
}
