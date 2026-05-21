// 0x801EB580 (100B) GOLTarget::IsMapGoalUnlocked(int, int, int)

extern "C" char* Globs__pNeighborhood;  // SDA r13-21476

class GOLTarget {
public:
    int IsMapGoalUnlocked(int a, int b, int c);
};

int GOLTarget::IsMapGoalUnlocked(int a, int b, int c) {
    char* nb = Globs__pNeighborhood;
    char* vt1 = *(char**)nb;
    short adj1 = *(short*)(vt1 + 288);
    void* fn1 = *(void**)(vt1 + 292);
    char* this1 = nb + adj1;
    void* obj = ((void* (*)(void*, int))fn1)(this1, 1);

    char* vt2 = *(char**)obj;
    short adj2 = *(short*)(vt2 + 328);
    void* fn2 = *(void**)(vt2 + 332);
    char* this2 = (char*)obj + adj2;
    int result = ((int (*)(void*))fn2)(this2);

    if (result == 0) return 0;
    return 1;
}
