// 0x800AB300 Behavior::Behavior (20b)

extern int Behavior_vtable[];

struct Behavior {
    int* m_vt;
    Behavior();
};

Behavior::Behavior() {
    *(int**)this = Behavior_vtable;
}
