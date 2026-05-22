// 0x80038634 EyeToyClient::Shutdown(void) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 22,0x8(1); stw 0,0x34(1); bl _s80038634_0; lwz 3,-32576(13); bl _s80038634_1; lwz 4,-32532(13); cmpwi 4,0; beq 0f; lis 3,-32692; li 5,1; addi 3,3,-17444; bl _s80038634_2; 0:; li 0,0; li 9,-1; stw 9,-32576(13); lis 22,-32702; stw 0,-32572(13); stw 0,-32532(13); bl _s80038634_3; lis 9,-32702; li 11,0; addi 24,9,15808; addi 23,24,4; 1:; mulli 9,11,12; li 30,0; addi 25,11,1; lwzx 0,23,9; mr 29,9; lwzx 11,24,9; cmpw 30,0; bge 3f; mr 31,11; lis 26,-32692; li 27,0; addi 28,22,15812; 2:; lwz 4,0x4(31); addi 3,26,-17444; li 5,1; addi 30,30,1; bl _s80038634_4; stw 27,0x4(31); addi 31,31,8; lwzx 0,28,29; cmpw 30,0; blt 2b; 3:; mr 11,25; cmpwi 11,4; ble 1b; lwz 0,0x34(1); mtspr 8,0; lmw 22,0x8(1); addi 1,1,48"
extern "C" void _s80038634_0();
extern "C" void _s80038634_1();
extern "C" void _s80038634_2();
extern "C" void _s80038634_3();
extern "C" void _s80038634_4();
extern "C" void f_80038634() {}
