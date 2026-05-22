// 0x80352894 Effects::EffectsManager::RemoveEntryFromList(Effects::EffectsManager::EffectEntry (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,5; mr. 4,4; bne 0f; li 3,0; b 4f; 0:; cmpwi 6,0; beq 1f; lwz 4,0x0(6); b 2f; 1:; mr 3,31; bl _s80352894_0; mr 4,3; 2:; li 0,1; cmpwi 4,0; bne 3f; li 0,0; 3:; cmpwi 0,0; li 3,0; beq 4f; mr 3,31; bl _s80352894_1; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80352894_0();
extern "C" void _s80352894_1();
extern "C" void f_80352894() {}
