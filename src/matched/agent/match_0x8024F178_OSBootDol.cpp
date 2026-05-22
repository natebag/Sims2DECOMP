// 0x8024F178 __OSBootDol (412 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stw 31,0x3c(1); stw 30,0x38(1); stw 29,0x34(1); mr 31,3; mr 29,4; mr 30,5; addi 3,1,24; addi 4,1,20; bl _s8024F178_0; mr 5,31; crxor 6,6,6; addi 3,1,28; addi 4,13,-27904; bl _s8024F178_1; cmplwi 30,0; li 31,0; beq 4f; mr 3,30; b 0f; 0:; b 1f; 1:; b 3f; 2:; addi 3,3,4; addi 31,31,1; 3:; lwz 0,0x0(3); cmplwi 0,0; bne 2b; 4:; addi 0,31,2; rlwinm 3,0,2,0,29; li 4,1; bl _s8024F178_2; addi 0,1,28; stw 0,0x0(3); addi 5,30,4; addi 6,3,4; b 5f; 5:; addi 8,31,1; cmpwi 8,1; addi 4,8,-1; ble 9f; rlwinm 0,4,29,3,31; cmplwi 0,0; mtspr 9,0; beq 7f; b 6f; 6:; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; bdnz 6b; andi. 4,4,7; beq 9f; 7:; mtspr 9,4; b 8f; 8:; lwz 0,-4(5); addi 5,5,4; stw 0,0x0(6); addi 6,6,4; bdnz 8b; 9:; lwz 5,0x18(1); mr 9,3; lwz 6,0x14(1); mr 4,29; li 3,-1; li 7,0; bl _s8024F178_3; lwz 0,0x44(1); lwz 31,0x3c(1); lwz 30,0x38(1); lwz 29,0x34(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8024F178_0();
extern "C" void _s8024F178_1();
extern "C" void _s8024F178_2();
extern "C" void _s8024F178_3();
extern "C" void f_8024F178() {}
