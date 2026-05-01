// 0x8033A958 (104B) ENgcRC::RectListRot(int, float *, EVec4 &, float)
// Twin of RectList: cmd=59 instead of 58.

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
    void RectListRot(EDLEntryRectList* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void RectListRot(int count, float* p, EVec4& color, float z);
};

void ENgcRC::RectListRot(int count, float* p, EVec4& color, float z) {
    if (count == 0) return;
    EDLEntryRectList e;
    e.cmd = 59;
    e.count = (short)count;
    e.data = p;
    e.colorX = color.x;
    e.colorY = color.y;
    e.colorZ = color.z;
    e.colorW = color.w;
    e.z = z;
    ((ENgcRenderer*)s_renderer)->RectListRot(&e);
}
