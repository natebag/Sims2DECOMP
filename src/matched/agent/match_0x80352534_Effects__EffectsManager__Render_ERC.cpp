// 0x80352534 Effects::EffectsManager::Render(ERC (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,0x0(3); mr 30,4; cmpwi 0,0; beq 3f; lwz 31,0x4(3); cmpwi 31,0; beq 3f; 0:; lwz 9,0x0(31); li 10,1; lwz 11,0x8(9); lwz 0,0x140(11); andi. 9,0,2048; bne 1f; li 10,0; 1:; cmpwi 10,0; beq 2f; lwz 9,0x144(11); mr 4,30; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80352534() {}
