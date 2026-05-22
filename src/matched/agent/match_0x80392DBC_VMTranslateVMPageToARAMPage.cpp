// 0x80392DBC __VMTranslateVMPageToARAMPage (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); rlwinm 0,3,22,17,29; lwz 4,-21852(13); lwzx 0,4,0; rlwinm. 0,0,0,1,31; beq 0f; mr 3,0; b 1f; 0:; bl _s80392DBC_0; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s80392DBC_0();
extern "C" void f_80392DBC() {}
