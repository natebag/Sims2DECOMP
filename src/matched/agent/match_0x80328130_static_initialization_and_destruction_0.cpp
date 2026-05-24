// 0x80328130 __static_initialization_and_destruction_0 (84 B)
// goto do_dtor forces DOL's beq-to-dtor layout: ctor in fall-through, dtor at branch target.

struct SomeStruct_804C;
extern SomeStruct_804C gStruct_804Cbbc8;

void SomeStruct_ctor_804C(SomeStruct_804C*);
void SomeStruct_dtor_804C(SomeStruct_804C*, int);

void __static_initialization_and_destruction_0(int param1, int param2) {
    if (param2 != 0xFFFF) return;
    if (param1 == 0) goto do_dtor;
    SomeStruct_ctor_804C(&gStruct_804Cbbc8);
    goto done;
do_dtor:
    SomeStruct_dtor_804C(&gStruct_804Cbbc8, 2);
done:;
}
