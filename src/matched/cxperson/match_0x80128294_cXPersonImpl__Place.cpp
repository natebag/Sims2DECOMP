// 0x80128294 (76B) cXPersonImpl::Place(FTilePt&, int, cXObject*, int)

class cXObject;
class FTilePt;

extern "C" void func_0x800DE3C4(void*);

class cXPersonImpl {
public:
    void* m_0;
    void* m_4;
    void Place(FTilePt& tp, int p2, cXObject* obj, int p4);
};

void cXPersonImpl::Place(FTilePt& tp, int p2, cXObject* obj, int p4) {
    func_0x800DE3C4(m_0);
    char* sub = (char*)m_4;
    char* vt = *(char**)(sub + 4);
    short adj = *(short*)(vt + 424);
    void* (*fn)(void*) = *(void* (**)(void*))(vt + 428);
    fn(sub + adj);
}
