// 0x802D8310 EThread::Attach(int) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s802D8310_0; stw 30,0x318(31); mr 3,31; bl _s802D8310_1; stw 3,0x31c(31); mr 3,31; bl _s802D8310_2; lwz 9,0x31c(31); li 0,0; stw 3,0x320(31); stw 0,0x328(31); cmpwi 9,0; stw 0,0x324(31); beq 0f; lis 4,-9253; mr 3,9; ori 4,4,56283; li 5,3072; bl _s802D8310_3; li 0,1; stw 0,0x328(31); 0:; lwz 0,-22760(13); stw 0,0x330(31); lwz 9,-22760(13); cmpwi 9,0; beq 1f; stw 31,0x334(9); b 2f; 1:; stw 31,-22764(13); 2:; li 0,0; stw 0,0x334(31); stw 31,-22760(13); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D8310_0();
extern "C" void _s802D8310_1();
extern "C" void _s802D8310_2();
extern "C" void _s802D8310_3();
extern "C" void f_802D8310() {}
