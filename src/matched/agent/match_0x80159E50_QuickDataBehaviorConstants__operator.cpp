// 0x80159E50 QuickDataBehaviorConstants::operator (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lis 9,-32696; mr 31,3; lwz 11,0x6928(9); addi 10,9,26920; li 0,0; cmplw 31,11; blt 0f; lwz 0,0xc(10); lwz 9,0x8(10); mullw 0,0,9; add 0,11,0; subfc 0,0,31; subfe 0,0,0; neg 0,0; 0:; cmpwi 0,0; beq 1f; cmpwi 31,0; beq 2f; lis 0,17733; ori 0,0,21062; stw 0,0x0(31); lwz 9,0x4(10); stw 9,0x4(31); stw 31,0x4(10); b 2f; 1:; bl _s80159E50_0; mr 4,31; bl _s80159E50_1; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80159E50_0();
extern "C" void _s80159E50_1();
extern "C" void f_80159E50() {}
