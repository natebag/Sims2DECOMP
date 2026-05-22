// 0x8034F0F8 shutdown_stream(Stream (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 2f; lbz 0,0x75(31); andi. 9,0,8; bne 2f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; li 4,-904; bl _s8034F0F8_0; lwz 3,0x1c(31); li 4,0; bl _s8034F0F8_1; 0:; lbz 0,0x75(31); andi. 30,0,16; bne 1f; addi 3,31,36; bl _s8034F0F8_2; stw 30,0x0(31); b 2f; 1:; lbz 0,0x75(31); ori 0,0,8; stb 0,0x75(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034F0F8_0();
extern "C" void _s8034F0F8_1();
extern "C" void _s8034F0F8_2();
extern "C" void f_8034F0F8() {}
