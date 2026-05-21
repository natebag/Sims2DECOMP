// 0x80239F10 (64B) EmitterGeomProcessCB(void *)

extern "C" char* g_pRC;  // SDA r13-28384
extern float kEmitterGeomConst[3];  // 0x803DF8C8

void EmitterGeomProcessCB(void* unused) {
    char* p = g_pRC;
    char* vt = *(char**)(p + 112);
    short adj = *(short*)(vt + 600);
    void* fn = *(void**)(vt + 604);
    ((void (*)(void*, float))fn)(p + adj, kEmitterGeomConst[0]);
}
