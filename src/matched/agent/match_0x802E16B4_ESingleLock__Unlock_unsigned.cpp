// 0x802E16B4 ESingleLock::Unlock(unsigned (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x4(31); cmpwi 0,0; beq 0f; lwz 11,0x0(31); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; xori 3,3,1; stw 3,0x4(31); 0:; lwz 3,0x4(31); xori 3,3,1; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802E16B4() {}
