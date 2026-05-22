// 0x80039CB0 GetSignFromName(unsigned (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 29,3; addi 9,9,23376; li 31,1; addi 30,9,4; 0:; lwz 9,0x0(30); li 3,0; addi 30,30,4; cmpwi 9,0; beq 1f; lwz 3,0x0(9); 1:; mr 4,29; bl _s80039CB0_0; cmpwi 3,0; bne 2f; extsh 3,31; b 3f; 2:; addi 31,31,1; cmpwi 31,12; ble 0b; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80039CB0_0();
extern "C" void f_80039CB0() {}
