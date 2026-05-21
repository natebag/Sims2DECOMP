// 0x800BAB9C (92B) cGZMusic::~cGZMusic(void)
// Twin of cGZSnd dtor — different vt + cleanup helper

extern char cGZMusic_vt[];  // 0x804670E0
extern "C" void helper_cGZMusic_reset(void* this_);          // 0x800BB19C
extern "C" void helper_cGZSndSys_removeMusic(void* mgr, void* this_);  // 0x800B90F8
extern "C" char* _gzSndSys;
extern "C" void* MainHeap();
extern "C" void helper_EAHeap_Free(void* heap, void* p);

class cGZMusic {
public:
    void dtor(short deleting_flag);
};

void cGZMusic::dtor(short deleting_flag) {
    *(char**)this = cGZMusic_vt;
    helper_cGZMusic_reset(this);
    helper_cGZSndSys_removeMusic(_gzSndSys, this);
    if (deleting_flag & 1) {
        helper_EAHeap_Free(MainHeap(), this);
    }
}
