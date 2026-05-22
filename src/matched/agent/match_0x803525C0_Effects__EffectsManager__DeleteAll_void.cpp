// 0x803525C0 Effects::EffectsManager::DeleteAll(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lwz 0,0x4(31); cmpwi 0,0; stw 0,0x8(1); beq 1f; 0:; lwz 9,0x8(1); addi 5,31,4; addi 6,1,8; mr 3,31; lwz 30,0x0(9); lwz 29,0x8(9); mr 4,30; bl _s803525C0_0; mr 4,30; mr 3,31; bl _s803525C0_1; cmpwi 29,0; stw 29,0x8(1); bne 0b; 1:; li 3,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s803525C0_0();
extern "C" void _s803525C0_1();
extern "C" void f_803525C0() {}
