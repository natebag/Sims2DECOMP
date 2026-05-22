// 0x802A9F9C AptNativeHash::Lookup(EAStringC (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lwz 9,0x0(31); lhz 0,0x6(9); cmpwi 0,0; bne 0f; mr 3,31; bl _s802A9F9C_0; 0:; lwz 9,0x0(31); lwz 0,0x4(30); lhz 29,0x6(9); cmpwi 0,0; beq 1f; mr 3,30; mr 4,31; bl _s802A9F9C_1; mr. 3,3; beq 1f; lwz 3,0x4(3); b 10f; 1:; cmpwi 29,1689; bne 5f; lis 9,-32694; lwz 3,0x0(31); lwz 4,-10852(9); lhz 11,0x2(3); lhz 0,0x2(4); cmpw 11,0; beq 2f; li 3,0; b 4f; 2:; cmpw 3,4; bne 3f; li 3,1; b 4f; 3:; addi 3,3,8; addi 4,4,8; bl _s802A9F9C_2; subfic 0,3,0; adde 3,0,3; 4:; cmpwi 3,0; beq 5f; lwz 3,0xc(30); b 10f; 5:; cmpwi 29,27581; bne 9f; lis 9,-32694; lwz 3,0x0(31); lwz 4,-11332(9); lhz 11,0x2(3); lhz 0,0x2(4); cmpw 11,0; beq 6f; li 3,0; b 8f; 6:; cmpw 3,4; bne 7f; li 3,1; b 8f; 7:; addi 3,3,8; addi 4,4,8; bl _s802A9F9C_3; subfic 0,3,0; adde 3,0,3; 8:; cmpwi 3,0; beq 9f; lwz 3,0x8(30); b 10f; 9:; li 3,0; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802A9F9C_0();
extern "C" void _s802A9F9C_1();
extern "C" void _s802A9F9C_2();
extern "C" void _s802A9F9C_3();
extern "C" void f_802A9F9C() {}
