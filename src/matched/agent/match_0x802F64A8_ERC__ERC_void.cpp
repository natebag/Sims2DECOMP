// 0x802F64A8 ERC::ERC(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-21944; addi 3,31,108; stw 9,0x70(31); bl _s802F64A8_0; li 0,0; li 11,255; stb 0,0x18(31); addi 9,31,48; stw 0,0x20(31); li 0,4; mtspr 9,0; 0:; stw 11,0x0(9); addi 9,9,-4; bdnz 0b; li 0,0; mr 3,31; stw 0,0x58(31); stw 0,0x34(31); stw 0,0x38(31); stw 0,0x3c(31); stw 0,0x40(31); stw 0,0x54(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802F64A8_0();
extern "C" void f_802F64A8() {}
