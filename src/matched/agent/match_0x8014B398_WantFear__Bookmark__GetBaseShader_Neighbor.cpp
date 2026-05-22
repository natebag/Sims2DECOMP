// 0x8014B398 WantFear::Bookmark::GetBaseShader(Neighbor (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x4(31); bl _s8014B398_0; mr 30,3; lbz 0,0xa(30); extsb 0,0; cmpwi 0,0; beq 0f; cmpwi 0,4; beq 0f; mr 3,31; bl _s8014B398_1; cmpwi 3,0; beq 0f; lbz 30,0xa(30); lis 9,-32697; lwz 29,0x5eec(9); mr 3,31; extsb 30,30; bl _s8014B398_2; mr 5,3; mr 4,30; mr 3,29; bl _s8014B398_3; b 1f; 0:; lwz 3,0x4(31); bl _s8014B398_4; lwz 0,0xc(3); lis 3,-16260; cmpwi 0,0; ori 3,3,13636; beq 1f; mr 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8014B398_0();
extern "C" void _s8014B398_1();
extern "C" void _s8014B398_2();
extern "C" void _s8014B398_3();
extern "C" void _s8014B398_4();
extern "C" void f_8014B398() {}
