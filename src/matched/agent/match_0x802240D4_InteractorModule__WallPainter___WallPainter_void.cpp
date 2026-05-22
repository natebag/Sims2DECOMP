// 0x802240D4 InteractorModule::WallPainter::~WallPainter(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; lis 11,-32698; mr 31,3; addi 9,9,-30600; addi 11,11,-10560; stw 9,0x5c(31); stw 11,0xbc(31); addi 10,31,156; lwz 9,0x9c(31); mr 30,4; lwz 0,0x4(10); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(10); cmpwi 3,0; beq 3f; lwz 0,0xc(10); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s802240D4_0; b 3f; 2:; bl _s802240D4_1; 3:; lis 9,-32697; andi. 0,30,1; addi 9,9,-32144; stw 9,0x5c(31); beq 4f; mr 3,31; bl _s802240D4_2; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802240D4_0();
extern "C" void _s802240D4_1();
extern "C" void _s802240D4_2();
extern "C" void f_802240D4() {}
