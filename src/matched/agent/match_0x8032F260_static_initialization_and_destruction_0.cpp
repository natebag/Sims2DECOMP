// 0x8032F260 __static_initialization_and_destruction_0 (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 1f; cmpwi 3,0; beq 0f; lis 3,-32692; addi 3,3,18304; bl _s8032F260_0; lis 11,-32768; lis 9,4194; lwz 0,0xf8(11); ori 9,9,19923; mulhwu 0,0,9; rlwinm 0,0,24,8,31; mulli 0,0,10; stw 0,-22564(13); b 1f; 0:; lis 3,-32692; li 4,2; addi 3,3,18304; bl _s8032F260_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032F260_0();
extern "C" void _s8032F260_1();
extern "C" void f_8032F260() {}
