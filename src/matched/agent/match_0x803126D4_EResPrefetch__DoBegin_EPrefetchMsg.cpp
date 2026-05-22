// 0x803126D4 EResPrefetch::DoBegin(EPrefetchMsg (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x3fc(31); cmpwi 0,0; beq 0f; lis 3,-32692; lis 5,-32702; addi 5,5,1284; li 6,238; addi 3,3,-17464; mr 4,31; bl _s803126D4_0; lwz 3,0xc(30); stw 3,0x3dc(31); lwz 0,0x4(30); mr 4,0; stw 0,0x3e0(31); bl _s803126D4_1; mr 0,3; lwz 4,0x3e0(31); lwz 3,0x3dc(31); stw 0,0x3e4(31); stw 0,0x3ec(31); bl _s803126D4_2; lwz 0,0x3f8(31); lis 9,-32702; lfs f0,0x558(9); li 11,1; divwu 10,3,0; stw 3,0x3e8(31); stw 11,0x414(31); stfs f0,0x410(31); mullw 0,10,0; stw 10,0x3f0(31); subf 3,0,3; stw 3,0x3f4(31); 0:; mr 3,30; bl _s803126D4_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803126D4_0();
extern "C" void _s803126D4_1();
extern "C" void _s803126D4_2();
extern "C" void _s803126D4_3();
extern "C" void f_803126D4() {}
