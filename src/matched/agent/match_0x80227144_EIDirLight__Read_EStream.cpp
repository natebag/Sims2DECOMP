// 0x80227144 EIDirLight::Read(EStream (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s80227144_0; lis 9,-32688; lhz 0,-13378(9); cmpwi 0,0; bne 0f; mr 3,31; addi 4,30,172; bl _s80227144_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80227144_0();
extern "C" void _s80227144_1();
extern "C" void f_80227144() {}
