/* __static_initialization_and_destruction_0 at 0x80175428 (84B) */

struct SomeStruct_8048;
extern SomeStruct_8048 gStruct_80487870;

void SomeStruct_ctor_8048(SomeStruct_8048*);
void SomeStruct_dtor_8048(SomeStruct_8048*, int);

void __static_initialization_and_destruction_0(int param1, int param2) {
    if (param2 != 0xFFFF) return;
    if (param1 == 0) {
        SomeStruct_ctor_8048(&gStruct_80487870);
    } else {
        SomeStruct_dtor_8048(&gStruct_80487870, 2);
    }
}
