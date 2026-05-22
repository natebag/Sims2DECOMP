// 0x80286C48 _isIndex(char (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s80286C48_0; cmpwi 3,0; beq 0f; li 3,1; b 1f; 0:; lbz 3,0x0(31); xori 3,3,48; subfic 0,3,0; adde 3,0,3; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80286C48_0();
extern "C" void f_80286C48() {}
