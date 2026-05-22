// 0x80239F10 EmitterGeomProcessCB(void (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 10,-28384(13); lis 9,-32704; lfs f1,-1848(9); lwz 11,0x70(10); lha 3,0x258(11); lwz 0,0x25c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void f_80239F10() {}
