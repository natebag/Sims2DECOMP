// 0x803654E0 LLDestroyNode (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; bl _s803654E0_0; lwz 9,0x94(30); cmpwi 9,0; beq 0f; lwz 0,0x8(31); cmpwi 0,0; beq 0f; lwz 0,0xc(31); rlwinm. 11,0,2,30,31; bne 0f; addi 3,31,8; mtspr 8,9; blrl; 0:; lwz 0,0xc(31); cmpwi 0,0; blt 1f; lwz 3,-25844(13); mr 4,31; bl _s803654E0_1; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803654E0_0();
extern "C" void _s803654E0_1();
extern "C" void f_803654E0() {}
