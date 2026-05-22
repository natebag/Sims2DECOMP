// 0x8012B6D8 (124B) cXPersonImpl::Turn(int)

extern "C" void Turn__12cXObjectImplFi(void*, int);
extern "C" float getPersonDirection__10SAnimator2();

class cXPersonImpl {
public:
    void* m_0;
    void* m_4;
    void Turn(int dir);
};

void cXPersonImpl::Turn(int dir) {
    Turn__12cXObjectImplFi(m_0, dir);

    char* obj1 = (char*)m_4;
    char* vt1 = *(char**)(obj1 + 4);
    short adj1 = *(short*)(vt1 + 392);
    void* (*fn1)(void*) = *(void* (**)(void*))(vt1 + 396);
    if (fn1(obj1 + adj1) == 0) return;

    char* obj2 = (char*)m_4;
    char* vt2 = *(char**)(obj2 + 4);
    void* fn2 = *(void**)(vt2 + 396);
    short adj2 = *(short*)(vt2 + 392);
    void* result = ((void* (*)(void*))fn2)(obj2 + adj2);

    float f = getPersonDirection__10SAnimator2();
    *(float*)((char*)result + 48) = f;
}
