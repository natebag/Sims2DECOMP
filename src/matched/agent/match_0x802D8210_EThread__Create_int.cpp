// 0x802D8210 EThread::Create(int, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; mr 4,5; mr 5,6; bl _s802D8210_0; cmpwi 3,0; beq 4f; lwz 6,0x320(31); lis 4,-32722; lwz 0,0x31c(31); addi 4,4,-32040; mr 7,6; mr 8,30; add 6,0,6; mr 3,31; mr 5,31; li 9,1; bl _s802D8210_1; cmpwi 3,0; li 0,1; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 3f; lwz 0,-22760(13); stw 0,0x330(31); lwz 9,-22760(13); cmpwi 9,0; beq 1f; stw 31,0x334(9); b 2f; 1:; stw 31,-22764(13); 2:; li 0,0; li 3,1; stw 0,0x334(31); stw 31,-22760(13); stw 31,0x318(31); b 5f; 3:; mr 3,31; bl _s802D8210_2; 4:; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802D8210_0();
extern "C" void _s802D8210_1();
extern "C" void _s802D8210_2();
extern "C" void f_802D8210() {}
