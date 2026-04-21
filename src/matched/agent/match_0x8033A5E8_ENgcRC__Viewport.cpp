// 0x8033A5E8 (56B) ENgcRC::Viewport(EViewport *)
// EDLEntry { cmd=9, data=viewport_ptr } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

class EViewport;

class ENgcRenderer {
public:
    void Viewport(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void Viewport(EViewport* viewport);
};

void ENgcRC::Viewport(EViewport* viewport) {
    EDLEntry e;
    e.cmd = 9;
    e.data = viewport;
    ((ENgcRenderer*)s_renderer)->Viewport(&e);
}
