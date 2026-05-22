// 0x8039B2F4 __VMBASEInvalidatePageTable (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); stw 31,0xc(1); bl _s8039B2F4_0; lis 4,1; li 6,0; cmplwi 4,0; mr 31,3; addi 4,4,7; li 5,0; rlwinm 4,4,29,3,31; ble 3f; rlwinm. 0,4,29,3,31; mtspr 9,0; beq 1f; 0:; lwz 3,-21536(13); addi 0,6,4; stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; lwz 3,-21536(13); stwx 5,3,0; addi 0,6,12; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,6; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,0; bdnz 0b; andi. 4,4,7; beq 3f; 1:; mtspr 9,4; 2:; lwz 3,-21536(13); addi 0,6,4; stwx 5,3,6; addi 6,6,8; lwz 3,-21536(13); stwx 5,3,0; bdnz 2b; 3:; lwz 3,-21536(13); lis 4,1; bl _s8039B2F4_1; bl _s8039B2F4_2; mr 3,31; bl _s8039B2F4_3; lwz 0,0x14(1); lwz 31,0xc(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8039B2F4_0();
extern "C" void _s8039B2F4_1();
extern "C" void _s8039B2F4_2();
extern "C" void _s8039B2F4_3();
extern "C" void f_8039B2F4() {}
