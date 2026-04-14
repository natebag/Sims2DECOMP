// 0x8039D7F8 Camera_ctor (76b)
// Family: vtable ctor + conditional call (16 members)
// Pattern: stmw r30, load fields, call, load vtable addr, call, restore this, call, lmw r30

extern void Func1(int, int);        // 0x8039D788
extern void Func2(int, int);        // 0x803276AC
extern void Func3(void*);           // 0x8039D7E4
extern int VTable[];

struct Camera {
    int field0;
    int field4;
};

void Camera_ctor(Camera* self) {
    Func1(self->field0, self->field4);
    Func2((int)VTable, self->field0);
    Func3(self);
}
