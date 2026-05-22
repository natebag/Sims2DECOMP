// 0x8034F22C stream_free(Stream (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 0,0x74(31); andis. 9,0,32; bne 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 0f; li 4,-904; bl _s8034F22C_0; lwz 3,0x1c(31); li 4,-904; bl _s8034F22C_1; 0:; lwz 0,0x74(31); oris 0,0,32; stw 0,0x74(31); 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8034F22C_0();
extern "C" void _s8034F22C_1();
extern "C" void f_8034F22C() {}
