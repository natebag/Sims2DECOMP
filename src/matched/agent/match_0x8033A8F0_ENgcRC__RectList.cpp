// 0x8033A8F0 (104B) ENgcRC::RectList(int, float *, EVec4 &, float)
// EDLEntry { cmd=58, count(short), data*, color(EVec4), z(float) } dispatched to renderer.

struct EDLEntryRectList {
    char  cmd;
    char  pad;
    short count;
    float* data;
    float colorX;
    float colorY;
    float colorZ;
    float colorW;
    float z;
    char  tail[12];
};

class EVec4 {
public:
    float x, y, z, w;
};

class ENgcRenderer {
public:
    void RectList(EDLEntryRectList* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void RectList(int count, float* p, EVec4& color, float z);
};

void ENgcRC::RectList(int count, float* p, EVec4& color, float z) {
    if (count == 0) return;
    EDLEntryRectList e;
    e.cmd = 58;
    e.count = (short)count;
    e.data = p;
    e.colorX = color.x;
    e.colorY = color.y;
    e.colorZ = color.z;
    e.colorW = color.w;
    e.z = z;
    ((ENgcRenderer*)s_renderer)->RectList(&e);
}
