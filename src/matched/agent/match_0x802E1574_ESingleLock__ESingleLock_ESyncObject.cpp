// 0x802E1574 ESingleLock::ESingleLock(ESyncObject (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,0; stw 4,0x0(31); cmpwi 5,0; stw 0,0x4(31); stw 6,0x8(31); beq 0f; li 4,-1; bl _s802E1574_0; 0:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E1574_0();
extern "C" void f_802E1574() {}
