// 0x80385A88 DummyLen (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); li 30,1; stw 29,0x1c(1); li 29,0; bl _s80385A88_0; stw 3,-25328(13); lis 3,16838; addi 31,3,20077; lwz 0,-25328(13); mullw 3,0,31; addi 0,3,12345; stw 0,-25328(13); lwz 0,-25328(13); rlwinm 3,0,16,27,31; addi 3,3,1; b 2f; 0:; bl _s80385A88_1; slw 0,3,30; addi 30,30,1; cmplwi 30,16; ble 1f; li 30,1; 1:; stw 0,-25328(13); addi 29,29,1; lwz 0,-25328(13); mullw 3,0,31; addi 0,3,12345; stw 0,-25328(13); lwz 0,-25328(13); rlwinm 3,0,16,27,31; addi 3,3,1; 2:; cmpwi 3,4; bge 3f; cmplwi 29,10; blt 0b; 3:; cmpwi 3,4; bge 4f; li 3,4; 4:; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80385A88_0();
extern "C" void _s80385A88_1();
extern "C" void f_80385A88() {}
