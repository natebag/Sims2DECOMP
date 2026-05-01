// 0x8033A620 (88B) ENgcRC::ClipRect(TRect<float> &)
// EDLEntry { cmd=54, pad, 4 floats: left, top, right, bottom } dispatched to renderer.

struct EDLEntryRect {
    char cmd;
    char pad[7];
    float left;
    float top;
    float right;
    float bottom;
    char tail[8];
};

template<class T> class TRect;

class ENgcRenderer {
public:
    void ClipRect(EDLEntryRect* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void ClipRect(TRect<float>& r);
};

template<>
class TRect<float> {
public:
    float left;
    float top;
    float right;
    float bottom;
};

void ENgcRC::ClipRect(TRect<float>& r) {
    EDLEntryRect e;
    e.cmd = 54;
    e.left = r.left;
    e.top = r.top;
    e.right = r.right;
    e.bottom = r.bottom;
    ((ENgcRenderer*)s_renderer)->ClipRect(&e);
}
