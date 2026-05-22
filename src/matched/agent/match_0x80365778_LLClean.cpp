// 0x80365778 LLClean (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80365778_0; lwz 0,0x88(30); stw 0,0x90(30); mr. 31,0; beq 1f; 0:; lwz 9,0x90(30); mr 4,31; mr 3,30; lwz 0,0x0(9); stw 0,0x90(30); bl _s80365778_1; lwz 3,-25844(13); mr 4,31; bl _s80365778_2; lwz 31,0x90(30); cmpwi 31,0; bne 0b; 1:; mr 3,30; bl _s80365778_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80365778_0();
extern "C" void _s80365778_1();
extern "C" void _s80365778_2();
extern "C" void _s80365778_3();
extern "C" void f_80365778() {}
