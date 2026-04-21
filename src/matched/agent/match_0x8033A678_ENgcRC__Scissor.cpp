// 0x8033A678 (56B) ENgcRC::Scissor(TRect<float> *)
// EDLEntry { cmd=11, data=rect_ptr } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

template<class T> class TRect;

class ENgcRenderer {
public:
    void Scissor(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void Scissor(TRect<float>* r);
};

void ENgcRC::Scissor(TRect<float>* r) {
    EDLEntry e;
    e.cmd = 11;
    e.data = r;
    ((ENgcRenderer*)s_renderer)->Scissor(&e);
}
