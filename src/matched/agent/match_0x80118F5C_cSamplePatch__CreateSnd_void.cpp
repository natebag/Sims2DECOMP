// 0x80118F5C cSamplePatch::CreateSnd(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 4,0x8(31); cmpwi 4,0; beq 0f; lwz 10,-24136(13); lfs f1,0x14(31); lwz 11,0x0(10); lwz 9,0x0(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; lwz 9,-24136(13); lwz 5,0x10(31); lwz 11,0x0(9); xori 5,5,2; subfic 0,5,0; adde 5,0,5; lwz 4,0xc(31); lwz 9,0x0(11); lfs f1,0x14(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; 1:; stw 3,0x18(31); li 3,0; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_80118F5C() {}
