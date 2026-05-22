// 0x8039BC6C __VMBASERestoreExceptionHandlers (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,-21520(13); cmpwi 0,1; bne 0f; lis 3,-32710; lis 5,-32768; lwz 0,-17896(3); addi 3,5,768; li 4,4; stw 0,0x300(5); bl _s8039BC6C_0; sync; lis 6,-32768; addi 3,6,768; li 0,0; isync; icbi 3,0; lis 4,-32710; addi 3,6,1024; addi 5,4,-17472; li 4,4; lwz 0,0x0(5); stw 0,0x400(6); bl _s8039BC6C_1; sync; lis 3,-32768; addi 3,3,1024; li 0,0; isync; icbi 3,0; 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039BC6C_0();
extern "C" void _s8039BC6C_1();
extern "C" void f_8039BC6C() {}
