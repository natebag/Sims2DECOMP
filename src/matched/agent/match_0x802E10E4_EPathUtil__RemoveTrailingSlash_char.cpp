// 0x802E10E4 EPathUtil::RemoveTrailingSlash(char (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpw 31,4; beq 0f; bl _s802E10E4_0; 0:; mr 3,31; bl _s802E10E4_1; lbz 0,0x0(31); cmpwi 0,0; beq 2f; mr 3,31; bl _s802E10E4_2; addi 3,3,-1; lbzx 0,31,3; cmpwi 0,47; bne 2f; cmpwi 3,0; beq 2f; cmpwi 3,2; bne 1f; lbz 0,0x1(31); cmpwi 0,58; bne 1f; lbz 9,0x0(31); addi 0,9,-97; cmplwi 0,25; ble 2f; addi 0,9,-65; cmplwi 0,25; ble 2f; 1:; li 0,0; stbx 0,31,3; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802E10E4_0();
extern "C" void _s802E10E4_1();
extern "C" void _s802E10E4_2();
extern "C" void f_802E10E4() {}
