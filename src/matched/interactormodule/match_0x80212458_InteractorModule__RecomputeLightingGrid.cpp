// 0x80212458 (92B) InteractorModule::RecomputeLightingGrid(cXObject *)

class cXObject;
extern "C" void helper_0x80024E04(void* obj);
extern char gInteractorTargetStatic[];  // 0x80475E94

class InteractorModule {
public:
    static void RecomputeLightingGrid(cXObject* obj);
};

void InteractorModule::RecomputeLightingGrid(cXObject* obj) {
    void* target = *(void**)gInteractorTargetStatic;
    if (obj != 0) {
        char* vt = *(char**)((char*)obj + 4);
        short adj = *(short*)(vt + 1056);
        void* fn = *(void**)(vt + 1060);
        int r = ((int (*)(void*))fn)((char*)obj + adj);
        if (r != 1) return;
    }
    helper_0x80024E04(target);
}
