// 0x8012C698 cXPerson::CAST_IMPL() (68B) — Tech #47, vt at +4, slot at 0x308/0x30C

class cXPerson {
public:
    cXPerson* CAST_IMPL();
};

cXPerson* cXPerson::CAST_IMPL() {
    if (this != 0) {
        char* p = (char*)this;
        char* vt = *(char**)(p + 4);
        short adj = *(short*)(vt + 0x308);
        void* fn = *(void**)(vt + 0x30C);
        return ((cXPerson*(*)(void*))fn)(p + adj);
    }
    return 0;
}
