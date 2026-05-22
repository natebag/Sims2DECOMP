// 0x800922F4 MUStatesSaveNewGame::Draw(ERC (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0x1c(3); addi 9,9,-9; cmplwi 9,2; bgt 0f; lwz 11,0x8(3); lwz 10,0x98(11); lwz 9,0x80(10); lha 3,0x30(9); lwz 0,0x34(9); add 3,10,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_800922F4() {}
