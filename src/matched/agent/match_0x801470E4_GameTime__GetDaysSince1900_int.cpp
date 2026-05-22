// 0x801470E4 GameTime::GetDaysSince1900(int, (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 29,4; cmpwi 28,1899; ble 0f; addi 0,29,-1; cmplwi 0,11; ble 1f; 0:; li 3,0; b 4f; 1:; li 31,1; addi 30,5,-1; cmpw 31,29; addi 27,28,-1900; bge 3f; 2:; mr 4,31; mr 3,28; bl _s801470E4_0; addi 31,31,1; add 30,30,3; cmpw 31,29; blt 2b; 3:; mulli 3,27,360; add 3,30,3; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s801470E4_0();
extern "C" void f_801470E4() {}
