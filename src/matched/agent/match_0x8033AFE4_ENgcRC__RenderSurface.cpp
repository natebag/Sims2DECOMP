// 0x8033AFE4 (60B) ENgcRC::RenderSurface(ERenderSurface *, int)
// 2-byte-header EDLEntry { cmd=45, arg2 byte, pad[2], int data=ptr }.

class ERenderSurface;

struct EDLEntry2 {
    char cmd;
    char arg2;
    char pad[2];
    void* data;
};

class ENgcRenderer {
public:
    void RenderSurface(EDLEntry2* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void RenderSurface(ERenderSurface* surf, int arg2);
};

void ENgcRC::RenderSurface(ERenderSurface* surf, int arg2) {
    EDLEntry2 e;
    e.cmd = 45;
    e.arg2 = (char)arg2;
    e.data = surf;
    ((ENgcRenderer*)s_renderer)->RenderSurface(&e);
}
