// FLAGS: -fno-schedule-insns
// 0x802092D8 InteractorModule::Interactor::SetExtents (20 bytes)
// DOL:
//   lwz r0, 4(r4)
//   lwz r9, 0(r4)
//   stw r0, 84(r3)
//   stw r9, 80(r3)
//   blr

struct Pair { int a; int b; };

struct Interactor {
    char pad[80];
    Pair m_p;
    void SetExtents(Pair* p);
};

void Interactor::SetExtents(Pair* p) {
    int b = *(int*)((char*)p + 4);
    int a = *(int*)((char*)p + 0);
    *(int*)((char*)this + 84) = b;
    *(int*)((char*)this + 80) = a;
}
