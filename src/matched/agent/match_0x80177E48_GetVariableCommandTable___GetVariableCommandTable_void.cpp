// 0x80177E48 GetVariableCommandTable::~GetVariableCommandTable(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; lis 9,-32698; lwz 0,0x0(30); addi 9,9,26096; mr 29,4; stw 9,0xc(30); cmpwi 0,0; lwz 11,0x8(30); beq 0f; lwz 9,0x4(30); stw 11,0x4(9); lwz 11,0x8(30); lwz 0,0x4(30); stw 0,0x0(11); lwz 11,0x0(30); 0:; lwz 31,0x4(11); cmpwi 11,0; beq 1f; lwz 9,0x10(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; mr. 11,31; bne 0b; andi. 0,29,1; beq 2f; mr 3,30; bl _s80177E48_0; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80177E48_0();
extern "C" void f_80177E48() {}
