// 0x802F6608 ERC::BeginCommand(int, (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 29,0x1c(31); stw 30,0x1c(31); cmpwi 29,1; bne 0f; cmpwi 30,1; beq 0f; lwz 9,0x70(31); lha 3,0x2c8(9); lwz 0,0x2cc(9); add 3,31,3; mtspr 8,0; blrl; 0:; cmpwi 30,2; bne 1f; cmpwi 29,2; beq 1f; lwz 9,0x70(31); lha 3,0x2c0(9); lwz 0,0x2c4(9); add 3,31,3; mtspr 8,0; blrl; 1:; lbz 9,0x18(31); addi 9,9,1; stb 9,0x18(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_802F6608() {}
