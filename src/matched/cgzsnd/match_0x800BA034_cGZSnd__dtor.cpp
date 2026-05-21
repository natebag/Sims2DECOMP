// 0x800BA034 (92B) cGZSnd::~cGZSnd(void)

extern char cGZSnd_vt[];  // 0x80467188
extern "C" void helper_cGZSnd_reset(void* this_);            // 0x800BA8F4
extern "C" void helper_cGZSndSys_removeSnd(void* mgr, void* this_);  // 0x800B90A8
extern "C" char* _gzSndSys;  // SDA r13-24468
extern "C" void* MainHeap();                                  // 0x802CFF00
extern "C" void helper_EAHeap_Free(void* heap, void* p);     // 0x802D0D78

class cGZSnd {
public:
    void dtor(short deleting_flag);
};

void cGZSnd::dtor(short deleting_flag) {
    *(char**)this = cGZSnd_vt;
    helper_cGZSnd_reset(this);
    helper_cGZSndSys_removeSnd(_gzSndSys, this);
    if (deleting_flag & 1) {
        helper_EAHeap_Free(MainHeap(), this);
    }
}
