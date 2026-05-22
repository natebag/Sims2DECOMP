// 0x8021BC44 InteractorModule::PlacementObject::InitializeGridObject(cXMTObjectImpl (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr. 31,4; bne 0f; li 3,0; b 1f; 0:; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x4(31); lwz 3,-21432(13); lwz 4,0x0(9); bl _s8021BC44_0; li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8021BC44_0();
extern "C" void f_8021BC44() {}
