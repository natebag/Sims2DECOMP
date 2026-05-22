// 0x80091764 MUStatesFormat::Draw(ERC (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x20(3); cmpwi 0,1; bne 0f; lwz 11,0x8(3); lwz 10,0x98(11); lwz 9,0x80(10); lha 3,0x30(9); lwz 0,0x34(9); add 3,10,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80091764() {}
