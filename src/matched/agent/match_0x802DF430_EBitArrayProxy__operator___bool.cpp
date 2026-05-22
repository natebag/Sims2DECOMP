// 0x802DF430 EBitArrayProxy::operator&=(bool) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 30,0x4(3); mr 29,4; lwz 31,0x0(3); mr 4,30; mr 3,31; bl _s802DF430_0; cmpwi 3,0; li 5,1; bne 0f; li 5,0; 0:; cmpwi 29,0; li 0,1; bne 1f; li 0,0; 1:; mr 3,31; mr 4,30; and 5,5,0; bl _s802DF430_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802DF430_0();
extern "C" void _s802DF430_1();
extern "C" void f_802DF430() {}
