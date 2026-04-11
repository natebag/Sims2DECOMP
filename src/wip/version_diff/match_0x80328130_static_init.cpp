/* __static_initialization_and_destruction_0 at 0x80328130 (84B) */

struct SomeStruct_804C;
extern SomeStruct_804C gStruct_804Cbbc8;

void SomeStruct_ctor_804C(SomeStruct_804C*);
void SomeStruct_dtor_804C(SomeStruct_804C*, int);

void __static_initialization_and_destruction_0(int param1, int param2) {
    if (param2 != 0xFFFF) return;
    if (param1 == 0) {
        SomeStruct_ctor_804C(&gStruct_804Cbbc8);
    } else {
        SomeStruct_dtor_804C(&gStruct_804Cbbc8, 2);
    }
}
