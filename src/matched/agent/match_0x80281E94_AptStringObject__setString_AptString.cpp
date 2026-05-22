// 0x80281E94 AptStringObject::setString(AptString (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 9,0x8(30); lis 4,-32704; lis 5,-32704; addi 4,4,5528; lha 3,0x8(9); addi 5,5,5412; lwz 0,0xc(9); li 6,335; add 3,30,3; mtspr 8,0; blrl; stw 30,0x24(29); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void f_80281E94() {}
