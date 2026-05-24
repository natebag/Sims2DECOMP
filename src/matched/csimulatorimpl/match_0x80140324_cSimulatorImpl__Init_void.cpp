// 0x80140324 cSimulatorImpl::Init(void) (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 11,0; addi 10,31,20; li 8,0; 0:; add 9,11,11; addi 0,11,1; extsh 11,0; sthx 8,10,9; cmpwi 11,47; ble 0b; li 9,3500; li 0,0; li 8,6; li 7,1997; stw 9,0x84(31); li 11,2; li 10,15; li 30,1; sth 8,0x22(31); li 29,4; sth 7,0x24(31); sth 11,0x34(31); sth 10,0x16(31); lwz 9,0x0(31); sth 0,0x1e(31); stw 0,0x8c(31); stw 0,0x88(31); stw 0,0x9c(31); stw 0,0x178(31); stw 0,0x7c(31); stw 0,0x74(31); stw 0,0x78(31); sth 30,0x14(31); lwz 0,0x194(9); lha 3,0x190(9); mtspr 8,0; add 3,31,3; blrl; li 10,-1; sth 3,0x1c(31); sth 10,0x38(31); lis 9,-32692; li 11,255; lwz 0,-17472(9); sth 30,0x36(31); sth 29,0x2c(31); sth 11,0x68(31); sth 10,0x62(31); sth 0,0x32(31); bl _s80140324_0; lwz 9,0x0(31); li 4,0; stw 3,0x90(31); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,31,3; blrl; li 0,3; li 3,24; sth 0,0x3c(31); bl _s80140324_1; bl _s80140324_2; stw 3,0x174(31); sth 29,-31828(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80140324_0();
extern "C" void _s80140324_1();
extern "C" void _s80140324_2();

struct cSimulatorImpl {
    void Init();
};

void cSimulatorImpl::Init() {
}
