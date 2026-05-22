// 0x8017610C UI2D::AddEntry(char (360 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x8(3); mr 10,4; mr 4,5; mr 30,6; lwz 9,0x4(31); mr 29,8; stw 9,0x8(3); cmpwi 9,0; beq 0f; li 0,0; stw 0,0x0(9); 0:; lwz 0,0x0(3); cmpwi 0,0; bne 1f; stw 31,0x0(3); stw 0,0x0(31); stw 31,0x4(3); stw 0,0x4(31); b 2f; 1:; lwz 9,0x4(3); li 11,0; stw 31,0x4(9); lwz 0,0x4(3); stw 0,0x0(31); stw 31,0x4(3); stw 11,0x4(31); 2:; stw 10,0x8(31); cmpwi 30,0; stw 7,0x14(31); stw 4,0xc(31); stw 29,0x10(31); beq 3f; mr 3,30; bl _s8017610C_0; li 0,0; stw 30,0x18(31); b 5f; 3:; lis 3,-32692; addi 3,3,-17444; bl _s8017610C_1; cmpwi 3,0; stw 3,0x18(31); beq 4f; stw 30,0x1c(31); b 6f; 4:; li 0,1; 5:; stw 0,0x1c(31); 6:; lwz 3,0x18(31); cmpwi 3,0; beq 8f; lwz 0,0x3c(3); cmpwi 0,2; bne 7f; li 0,1; rlwinm 30,29,0,24,31; stw 0,0x20(31); mr 4,30; bl _s8017610C_2; cmpwi 3,0; stw 3,0x28(31); beq 8f; lwz 3,0x18(31); lwz 0,0x58(3); rlwinm 0,0,30,31,31; cmpwi 0,0; stw 0,0x20(31); bne 8f; mr 4,30; bl _s8017610C_3; mr 4,3; stw 4,0x24(31); cmpwi 4,0; beq 8f; lis 3,-32692; li 5,0; addi 3,3,-17444; li 6,0; bl _s8017610C_4; b 8f; 7:; li 0,0; stw 0,0x20(31); 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8017610C_0();
extern "C" void _s8017610C_1();
extern "C" void _s8017610C_2();
extern "C" void _s8017610C_3();
extern "C" void _s8017610C_4();
extern "C" void f_8017610C() {}
