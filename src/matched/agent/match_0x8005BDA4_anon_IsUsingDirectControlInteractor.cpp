// 0x8005BDA4 {anonymous}::IsUsingDirectControlInteractor(int) (100B)

extern void* GetSingleton();
extern void* GetPlayerInteractor(void* mgr, int type, int idx);

namespace {
int IsUsingDirectControlInteractor(int type) {
    void* mgr = GetSingleton();
    void* r1 = GetPlayerInteractor(mgr, type, -1);
    if (r1 == 0) return 0;
    void* mgr2 = GetSingleton();
    void* r2 = GetPlayerInteractor(mgr2, type, 0);
    return r1 == r2;
}
}
