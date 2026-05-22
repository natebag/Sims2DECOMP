// 0x8034C880 ENgcSFXStreamer::Update(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s8034C880_0; lis 9,-32690; addi 9,9,-19244; mr 31,9; addi 30,31,4148; 0:; lwz 0,0x24(31); cmpwi 0,0; beq 1f; lwz 3,0x0(31); cmpwi 3,0; beq 1f; lwz 0,0x40(31); andis. 9,0,8192; bne 1f; cmpwi 0,0; bge 1f; andis. 9,0,16384; bne 1f; lwz 0,0x1b2(3); lwz 9,0x28(31); rlwinm 0,0,31,1,31; cmplw 0,9; bge 1f; li 4,7; bl _s8034C880_1; lwz 0,0x40(31); lwz 3,0x0(31); rlwinm 0,0,0,1,31; stw 0,0x40(31); bl _s8034C880_2; 1:; addi 31,31,68; cmplw 31,30; ble 0b; bl _s8034C880_3; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034C880_0();
extern "C" void _s8034C880_1();
extern "C" void _s8034C880_2();
extern "C" void _s8034C880_3();
extern "C" void f_8034C880() {}
