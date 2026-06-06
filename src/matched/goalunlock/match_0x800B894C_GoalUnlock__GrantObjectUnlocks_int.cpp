// 0x800B894C GoalUnlock::GrantObjectUnlocks(int) (288 B)

struct GoalUnlockVtable {
    char pad0[0x18]; short countOff; int (*count)(void*, int);
    char pad1[8];
    short canOff; int (*can)(void*, int, int);
    short grantOff; void (*grant)(void*, int, int);
};
struct GoalUnlock { GoalUnlockVtable* vtable; void GrantObjectUnlocks(int value); };
struct UnlockInfo { int guid; short unlock; short pad; };
extern UnlockInfo s_objectUnlocks[];
struct EThread { int IsCallingThread(); };
extern EThread* g_someThread;
struct H2DTarget { void SpawnRewardMomentDialog(int, int); };
extern char _gd[];

void GoalUnlock::GrantObjectUnlocks(int value) {
    int div = value / 100;
    GoalUnlock* self = this;
    int selected = -1;
    int i = 0;
    int threshold = (short)div;
    while (i < vtable->count((char*)self + vtable->countOff, 5)) {
        UnlockInfo* info = &s_objectUnlocks[i];
        if (info->unlock != 0 && threshold >= info->unlock) {
            if (vtable->can((char*)self + vtable->canOff, 5, i) == 0) {
                selected = i;
                vtable->grant((char*)self + vtable->grantOff, 5, selected);
            }
        }
        i = (short)(i + 1);
    }
    if (g_someThread->IsCallingThread() != 0 && selected != -1) {
        H2DTarget* h = *(H2DTarget**)(_gd + 0x48);
        if (h != 0) {
            h->SpawnRewardMomentDialog(5, selected);
        }
    }
}
