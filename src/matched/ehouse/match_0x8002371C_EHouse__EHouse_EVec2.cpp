// 0x8002371C EHouse::EHouse(EVec2 (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 29,4; mr 30,10; mr 28,5; mr 26,8; mr 27,6; mr 25,7; addi 3,31,100; bl _s8002371C_0; li 0,0; addi 9,31,224; stw 0,0xe0(31); lis 11,-32707; stw 0,0x4(9); li 10,1; stw 0,0x8(9); cmpwi 26,0; stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stw 0,0x28(9); lfs f12,0x950(11); stw 0,0x34(9); stfs f12,0x2c(9); stfs f12,0x30(9); stw 30,0x0(31); stw 28,0x54(31); stw 0,0x124(31); stw 0,0x1c(31); stw 0,0x20(31); stw 0,0x2c(31); stw 0,0x28(31); stw 10,0x24(31); lfs f0,0x4(29); stfs f0,0x4c(31); lfs f13,0x0(29); stw 10,0x10(31); stfs f13,0x50(31); stw 0,0x34(31); stfs f12,0x3c(31); stw 0,0x14(31); stw 0,0x38(31); stw 0,0x30(31); beq 0f; li 3,180; bl _s8002371C_1; bl _s8002371C_2; stw 3,0x8(31); b 1f; 0:; stw 26,0x8(31); 1:; cmpwi 25,0; beq 2f; li 3,20; bl _s8002371C_3; mr 4,31; bl _s8002371C_4; stw 3,0x4(31); b 3f; 2:; stw 25,0x4(31); 3:; cmpwi 27,0; bne 4f; mr 3,31; bl _s8002371C_5; mr 4,3; lis 3,-32697; addi 3,3,24012; bl _s8002371C_6; mr 4,3; li 5,0; lis 3,-32696; li 6,0; addi 3,3,32332; bl _s8002371C_7; lwz 9,-26512(13); stw 3,0x1c(31); stw 3,0x30(9); b 5f; 4:; stw 27,0x1c(31); mr 3,27; bl _s8002371C_8; lwz 9,-26512(13); lwz 0,0x1c(31); stw 0,0x30(9); 5:; lwz 11,0x1c(31); cmpwi 11,0; beq 9f; lwz 9,0x54(31); addi 10,9,-1; mr 8,10; cmpwi 10,15; ble 6f; li 10,15; 6:; lis 9,-32702; rlwinm 0,10,3,0,28; addi 9,9,14600; addis 11,11,3; add 0,0,9; mr 10,8; stw 0,-7084(11); ble 7f; li 10,15; 7:; mulli 0,10,12; lwz 11,0x1c(31); lis 9,-32702; addi 9,9,14408; addis 11,11,3; mr 10,8; add 0,0,9; stw 0,-7080(11); ble 8f; li 10,15; 8:; lis 9,-32702; lwz 11,0x1c(31); addi 9,9,14728; rlwinm 0,10,2,0,29; lfsx f0,9,0; addis 11,11,3; lis 3,-32692; stfs f0,-7076(11); addi 3,3,-27556; lwz 9,0x1c(31); lwz 4,0x8(9); bl _s8002371C_9; stw 3,0x20(31); 9:; lwz 10,0x1c(31); lis 11,-32765; addi 11,11,-18804; li 0,0; addis 10,10,3; lis 8,-32707; stw 11,-7464(10); addi 9,31,224; stw 0,0xc(31); mr 3,31; stw 0,0x18(31); stw 0,0xe0(31); lfs f0,0x950(8); stw 0,0x34(9); stw 0,0x4(9); stw 0,0x8(9); stw 0,0xc(9); stw 0,0x10(9); stw 0,0x14(9); stw 0,0x18(9); stw 0,0x1c(9); stw 0,0x20(9); stw 0,0x24(9); stfs f0,0x40(31); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8002371C_0();
extern "C" void _s8002371C_1();
extern "C" void _s8002371C_2();
extern "C" void _s8002371C_3();
extern "C" void _s8002371C_4();
extern "C" void _s8002371C_5();
extern "C" void _s8002371C_6();
extern "C" void _s8002371C_7();
extern "C" void _s8002371C_8();
extern "C" void _s8002371C_9();

struct EHouse {
    void EHouse_EVec2();
};

void EHouse::EHouse_EVec2() {
}
