// 0x802C4440 StringPool::GetString(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; li 29,0; bl _s802C4440_0; lis 9,-32694; mr 28,3; addi 31,9,-11332; mr 26,31; addi 27,31,708; 0:; lwzx 3,29,26; lhz 0,0x2(3); cmpw 0,28; bne 1f; addi 3,3,8; mr 4,30; bl _s802C4440_1; cmpwi 3,0; bne 1f; mr 3,31; b 2f; 1:; addi 31,31,4; addi 29,29,4; cmpw 31,27; ble 0b; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802C4440_0();
extern "C" void _s802C4440_1();
extern "C" void f_802C4440() {}
