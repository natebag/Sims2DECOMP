// 0x8013D6AC Path::InitPath(RoutingParams (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr 0,4; lis 3,-32696; stw 0,0x0(31); addi 3,3,26792; bl _s8013D6AC_0; lwz 0,0x4(31); addi 10,31,36; lwz 9,0x14(31); lwz 11,0x24(31); stw 0,0x8(31); stw 9,0x18(31); lwz 0,0x4(10); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(10); li 0,0; li 9,-1; stw 0,0x38(31); stw 9,0x68(31); mr 3,31; stw 0,0x34(31); stw 0,0x6c(31); bl _s8013D6AC_1; cmpwi 3,0; beq 2f; li 0,1; stw 0,0x34(31); 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8013D6AC_0();
extern "C" void _s8013D6AC_1();
extern "C" void f_8013D6AC() {}
