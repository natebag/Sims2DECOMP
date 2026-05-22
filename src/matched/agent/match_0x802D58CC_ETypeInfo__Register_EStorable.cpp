// 0x802D58CC ETypeInfo::Register(EStorable (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,7; mr 29,9; stw 4,0x0(31); mr 3,8; stw 5,0x4(31); stw 6,0x8(31); stw 8,0xc(31); bl _s802D58CC_0; li 0,-1; stw 3,0x10(31); sth 30,0x14(31); cmpw 29,31; sth 0,0x16(31); beq 0f; stw 29,0x18(31); b 1f; 0:; li 0,0; stw 0,0x18(31); 1:; lwz 9,-26840(13); mr 3,31; addi 9,9,1; stw 9,-26840(13); bl _s802D58CC_1; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D58CC_0();
extern "C" void _s802D58CC_1();
extern "C" void f_802D58CC() {}
