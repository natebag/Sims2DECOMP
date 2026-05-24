// 0x8003819C EyeToyClient::SetFilterPipeline(int) (836 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); mr 9,3; li 27,0; cmpwi 9,1; beq 3f; bgt 0f; li 31,-1; cmpwi 9,-1; beq 11f; cmpwi 9,0; beq 1f; b 11f; 0:; cmpwi 9,3; beq 7f; blt 5f; cmpwi 9,4; beq 9f; b 11f; 1:; addi 30,1,8; stw 31,0x8(1); addi 3,1,16; stw 27,0x4(30); bl _s8003819C_0; li 29,2; li 0,10; li 9,3; stw 27,0xc(1); mr 4,30; stw 0,0x8(1); li 3,1; sth 9,0x14(1); bl _s8003819C_1; stw 31,0x8(1); 2:; mr 3,29; addi 4,1,8; bl _s8003819C_2; addi 29,29,1; cmpwi 29,4; ble 2b; b 13f; 3:; li 28,-1; addi 30,1,8; stw 28,0x8(1); addi 29,1,16; stw 27,0x4(30); li 0,10; stw 0,0x8(1); mr 3,29; stw 27,0xc(1); li 31,3; bl _s8003819C_3; li 0,2; mr 4,30; sth 0,0x14(1); li 3,1; bl _s8003819C_4; li 0,13; mr 3,29; stw 0,0x8(1); bl _s8003819C_5; lis 9,-32707; lis 11,-32707; lfs f13,0x1664(9); mr 4,30; lfs f0,0x1668(11); li 3,2; stfs f13,0x24(1); stfs f0,0x28(1); stfs f13,0x20(1); bl _s8003819C_6; stw 28,0x8(1); 4:; mr 3,31; addi 4,1,8; bl _s8003819C_7; addi 31,31,1; cmpwi 31,4; ble 4b; b 13f; 5:; li 28,-1; addi 30,1,8; stw 28,0x8(1); addi 29,1,16; li 0,13; stw 27,0x4(30); stw 0,0x8(1); mr 3,29; stw 27,0xc(1); li 31,3; bl _s8003819C_8; lis 11,-32707; lis 9,-32707; lfs f13,0x1668(9); mr 4,30; lfs f0,0x166c(11); li 3,1; stfs f13,0x28(1); stfs f0,0x20(1); stfs f13,0x24(1); bl _s8003819C_9; li 0,12; mr 3,29; stw 0,0x8(1); bl _s8003819C_10; li 0,15; mr 4,30; sth 0,0x14(1); li 3,2; bl _s8003819C_11; stw 28,0x8(1); 6:; mr 3,31; addi 4,1,8; bl _s8003819C_12; addi 31,31,1; cmpwi 31,4; ble 6b; b 13f; 7:; li 28,-1; addi 30,1,8; stw 28,0x8(1); addi 29,1,16; stw 27,0x4(30); li 0,6; stw 0,0x8(1); mr 3,29; stw 27,0xc(1); li 31,3; bl _s8003819C_13; lis 9,-32707; li 11,2; lfs f0,0x1670(9); li 0,1; stb 0,0x18(1); mr 4,30; stb 27,0x19(1); li 3,1; stb 11,0x1b(1); stfs f0,0x1c(1); stb 11,0x1a(1); bl _s8003819C_14; li 0,1; mr 3,29; stw 0,0x8(1); bl _s8003819C_15; mr 4,30; li 3,2; bl _s8003819C_16; stw 28,0x8(1); 8:; mr 3,31; addi 4,1,8; bl _s8003819C_17; addi 31,31,1; cmpwi 31,4; ble 8b; b 13f; 9:; li 0,-1; addi 30,1,8; stw 0,0x8(1); addi 29,1,16; stw 27,0x4(30); mr 3,29; stw 27,0xc(1); li 28,3; stw 9,0x8(1); bl _s8003819C_18; li 0,15; mr 4,30; stb 0,0x12(1); li 3,1; stb 0,0x10(1); stb 0,0x11(1); bl _s8003819C_19; li 0,12; mr 3,29; stw 0,0x8(1); bl _s8003819C_20; li 0,15; mr 4,30; sth 0,0x14(1); li 3,2; bl _s8003819C_21; 10:; mr 3,28; addi 4,1,8; bl _s8003819C_22; addi 28,28,1; cmpwi 28,4; ble 10b; b 13f; 11:; li 0,-1; li 27,0; stw 0,0x8(1); addi 9,1,8; stw 27,0x4(9); li 30,1; stw 0,0x8(1); stw 27,0xc(1); 12:; mr 3,30; addi 4,1,8; bl _s8003819C_23; addi 30,30,1; cmpwi 30,4; ble 12b; 13:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"

extern "C" void _s8003819C_0();
extern "C" void _s8003819C_1();
extern "C" void _s8003819C_2();
extern "C" void _s8003819C_3();
extern "C" void _s8003819C_4();
extern "C" void _s8003819C_5();
extern "C" void _s8003819C_6();
extern "C" void _s8003819C_7();
extern "C" void _s8003819C_8();
extern "C" void _s8003819C_9();
extern "C" void _s8003819C_10();
extern "C" void _s8003819C_11();
extern "C" void _s8003819C_12();
extern "C" void _s8003819C_13();
extern "C" void _s8003819C_14();
extern "C" void _s8003819C_15();
extern "C" void _s8003819C_16();
extern "C" void _s8003819C_17();
extern "C" void _s8003819C_18();
extern "C" void _s8003819C_19();
extern "C" void _s8003819C_20();
extern "C" void _s8003819C_21();
extern "C" void _s8003819C_22();
extern "C" void _s8003819C_23();

struct EyeToyClient {
    void SetFilterPipeline();
};

void EyeToyClient::SetFilterPipeline() {
}
