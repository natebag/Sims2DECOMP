/* Behavior::Behavior(void) at 0x800AB300 (20B) */

extern int Behavior_vtable[];

struct Behavior {
    int* m_vtable;

    Behavior(void);
};

Behavior::Behavior(void) {
    m_vtable = Behavior_vtable;
}
