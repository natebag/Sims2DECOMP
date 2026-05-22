// 0x80265C2C PADInit (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); stwu 1,-56(1); stmw 25,0x1c(1); addi 31,3,-16416; lwz 0,-23184(13); cmpwi 0,0; beq 0f; li 3,1; b 3f; 0:; lwz 3,-27656(13); bl _s80265C2C_0; lwz 3,-23140(13); cmplwi 3,0; beq 1f; bl _s80265C2C_1; 1:; lwz 0,-23536(13); li 3,1; stw 3,-23184(13); cmplwi 0,0; beq 2f; bl _s80265C2C_2; addi 25,4,0; addi 26,3,0; li 5,16; bl _s80265C2C_3; lis 5,1; addi 27,5,-1; li 28,0; and 6,4,27; and 4,25,27; and 5,3,28; and 0,26,28; addc 29,4,6; addi 3,26,0; addi 4,25,0; adde 30,0,5; li 5,32; bl _s80265C2C_4; and 4,4,27; and 0,3,28; addc 29,4,29; addi 3,26,0; addi 4,25,0; adde 30,0,30; li 5,48; bl _s80265C2C_5; and 0,4,27; addc 5,0,29; lis 0,-4096; li 4,16383; stw 0,-23172(13); and 0,5,4; lis 3,-32768; sth 0,0x30e0(3); 2:; lis 3,-32768; lhz 0,0x30e0(3); rlwinm 0,0,8,10,23; oris 0,0,19712; stw 0,0x40(31); lhz 0,0x30e0(3); rlwinm 0,0,8,10,23; oris 0,0,19776; stw 0,0x44(31); lhz 0,0x30e0(3); rlwinm 0,0,8,10,23; oris 0,0,19840; stw 0,0x48(31); lhz 0,0x30e0(3); rlwinm 0,0,8,10,23; oris 0,0,19904; stw 0,0x4c(31); bl _s80265C2C_6; lis 3,-32700; addi 3,3,-11624; bl _s80265C2C_7; lis 3,-4096; bl _s80265C2C_8; 3:; lmw 25,0x1c(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s80265C2C_0();
extern "C" void _s80265C2C_1();
extern "C" void _s80265C2C_2();
extern "C" void _s80265C2C_3();
extern "C" void _s80265C2C_4();
extern "C" void _s80265C2C_5();
extern "C" void _s80265C2C_6();
extern "C" void _s80265C2C_7();
extern "C" void _s80265C2C_8();
extern "C" void f_80265C2C() {}
