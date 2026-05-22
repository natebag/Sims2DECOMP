// 0x802FFCF0 EWindow::SetRenderSurface(ERenderSurface (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stw 31,0x1c(1); stw 0,0x24(1); mr 31,3; mr 11,4; lwz 0,0x90(31); cmpw 0,11; bne 0f; lwz 0,0x94(31); cmpw 0,5; beq 3f; 0:; stw 11,0x90(31); cmpwi 11,0; stw 5,0x94(31); beq 1f; lwz 9,0x20(11); addi 4,1,8; lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; lwz 3,-26392(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; addi 3,1,8; bl _s802FFCF0_0; 2:; mr 3,31; addi 4,1,8; bl _s802FFCF0_1; 3:; lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32"
extern "C" void _s802FFCF0_0();
extern "C" void _s802FFCF0_1();
extern "C" void f_802FFCF0() {}
