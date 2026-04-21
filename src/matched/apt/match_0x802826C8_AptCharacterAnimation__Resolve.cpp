// 0x802826C8 (104B) AptCharacterAnimation::Resolve(void*, AptConstFile*, void*)

struct AptConstFile;

struct AptCharacterAnimation {
    void Fixup(void* a, AptConstFile* b, void* c);
    void Resolve(void* a, AptConstFile* b, void* c);
};

void AptCharacterAnimation::Resolve(void* a, AptConstFile* b, void* c) {
    int* p = (int*)((char*)b + 28);
    int val = *p;
    if (val != 0) {
        *p = (int)b + val;
    }
    *(int*)((char*)this + 48) = 0;
    Fixup(a, b, c);
    val = *p;
    if (val != 0) {
        *p = val - (int)b;
    }
}
