// 0x80352998 Effects::EffectsManager::ForEachEffectInList(Effects::EffectsVisitor (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,0x0(5); mr 30,4; cmpwi 31,0; beq 2f; 0:; lwz 11,0x0(31); mr 4,30; lwz 10,0x8(11); lwz 9,0x144(10); lha 3,0x28(9); lwz 0,0x2c(9); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; li 3,0; b 3f; 1:; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 2:; li 3,1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_80352998() {}
