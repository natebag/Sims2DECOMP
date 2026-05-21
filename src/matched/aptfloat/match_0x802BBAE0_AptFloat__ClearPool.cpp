// 0x802BBAE0 (132B) AptFloat::ClearPool(void)

extern "C" char* AptFloat__spFirstFree;  // SDA r13-26912

class AptFloat {
public:
    static void ClearPool();
};

void AptFloat::ClearPool() {
    char* head = AptFloat__spFirstFree;
    while (head != 0) {
        char* p = AptFloat__spFirstFree;
        char* vt = *(char**)((char*)p + 8);
        char* next = *(char**)((char*)p + 12);
        short adj1 = *(short*)(vt + 96);
        void* fn1 = *(void**)(vt + 100);
        ((void (*)(void*))fn1)(p + adj1);

        char* p2 = AptFloat__spFirstFree;
        if (p2 != 0) {
            char* vt2 = *(char**)((char*)p2 + 8);
            short adj2 = *(short*)(vt2 + 120);
            void* fn2 = *(void**)(vt2 + 124);
            ((void (*)(void*, int))fn2)(p2 + adj2, 3);
        }

        AptFloat__spFirstFree = next;
        head = next;
    }
}
