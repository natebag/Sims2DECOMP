// 0x80128134 (128B) cXPersonImpl::Skipping3D()
// Tech #47 triple MI-vcall: 2x same slot vt+392/396 + 1x vt+160/164 on result

class cXPersonImpl {
public:
    int m_0;
    void* m_4;
    void Skipping3D();
};

void cXPersonImpl::Skipping3D() {
    char* obj = (char*)m_4;
    char* vt = *(char**)(obj + 4);
    short adj = *(short*)(vt + 392);
    void* (*fn)(void*) = *(void* (**)(void*))(vt + 396);
    if (fn(obj + adj) == 0) return;

    char* obj2 = (char*)m_4;
    char* vt2 = *(char**)(obj2 + 4);
    void* fn2 = *(void**)(vt2 + 396);
    short adj2 = *(short*)(vt2 + 392);
    void* r2 = ((void* (*)(void*))fn2)(obj2 + adj2);

    char* vt3 = *(char**)r2;
    short adj3 = *(short*)(vt3 + 160);
    void (*fn3)(void*) = *(void (**)(void*))(vt3 + 164);
    fn3((char*)r2 + adj3);
}
