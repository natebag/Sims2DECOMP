// 0x8003FD34 EGlobal::GetNewUIString(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr. 29,5; beq 1f; lwz 3,0xe8(4); lis 4,-32707; addi 4,4,10156; bl _s8003FD34_0; lis 9,-32697; mr 30,3; addi 28,9,24012; mr 5,29; lwz 3,0xe8(28); mr 4,30; bl _s8003FD34_1; mr. 3,3; bne 0f; lwz 3,0xe8(28); lis 5,-32707; mr 4,30; addi 5,5,10172; bl _s8003FD34_2; mr. 3,3; beq 1f; 0:; lwz 0,0x0(3); b 2f; 1:; lwz 0,-24988(13); 2:; stw 0,0x0(31); mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8003FD34_0();
extern "C" void _s8003FD34_1();
extern "C" void _s8003FD34_2();
extern "C" void f_8003FD34() {}
