// 0x80161AD0 WantFear::Tree::GetNodeById(short) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lha 3,0x28(9); lwz 0,0x2c(9); b 0f; lwz 9,0x4(11); lha 3,0x30(9); lwz 0,0x34(9); b 0f; lwz 9,0x4(11); lha 3,0x38(9); lwz 0,0x3c(9); b 0f; lwz 9,0x4(11); lha 3,0x40(9); lwz 0,0x44(9); b 0f; lwz 9,0x4(11); lha 3,0x48(9); lwz 0,0x4c(9); 0:; add 3,11,3; mtspr 8,0; blrl; b 1f; lwz 9,0x4(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" int f_80161AD0() {}
