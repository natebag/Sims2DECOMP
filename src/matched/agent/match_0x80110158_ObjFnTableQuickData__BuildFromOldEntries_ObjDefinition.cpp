// 0x80110158 ObjFnTableQuickData::BuildFromOldEntries(ObjDefinition (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x10(31); cmpwi 0,0; bne 0f; li 3,124; bl _s80110158_0; stw 3,0x10(31); 0:; lwz 3,0x10(31); li 4,0; li 5,124; bl _s80110158_1; bl _s80110158_2; lwz 9,0x10(31); sth 3,0x4(9); bl _s80110158_3; lwz 9,0x10(31); sth 3,0x6(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80110158_0();
extern "C" void _s80110158_1();
extern "C" void _s80110158_2();
extern "C" void _s80110158_3();
extern "C" void f_80110158() {}
