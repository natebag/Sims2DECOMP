// 0x802C8C9C EHashTable::Remove(HTIteratorPtrType (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 5,4; mr 9,3; lwz 11,0xc(5); lwz 0,0xc(9); divwu 4,11,0; mullw 4,4,0; subf 4,4,11; bl _s802C8C9C_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s802C8C9C_0();
extern "C" void f_802C8C9C() {}
