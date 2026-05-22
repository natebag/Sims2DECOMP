// 0x80288A38 AptCharacterTextInst::~AptCharacterTextInst(void) (352 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; lis 9,-32704; lwz 30,0x68(31); lis 11,-32704; lfs f0,0x4bdc(9); li 29,0; addi 11,11,20136; mr 28,4; stw 11,0x14(31); cmpwi 30,0; stfs f0,0x60(31); stw 29,0x24(31); stw 29,0x64(31); beq 0f; mr 3,30; li 4,2; bl _s80288A38_0; lwz 3,-23020(13); mr 4,30; li 5,32; bl _s80288A38_1; stw 29,0x68(31); 0:; lwz 3,0x20(31); cmpwi 3,0; beq 1f; addi 0,13,-27404; cmpw 3,0; beq 1f; lis 9,-32694; li 4,2; lwz 0,-16212(9); mtspr 8,0; blrl; stw 29,0x20(31); 1:; lwz 0,0x74(31); cmpwi 0,0; bge 2f; lwz 4,0x8(31); cmpwi 4,0; beq 2f; lwz 3,-23020(13); li 5,64; bl _s80288A38_2; 2:; lwz 4,0x1c(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288A38_3; 3:; lwz 4,0x18(31); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 4f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s80288A38_4; 4:; lis 9,-32704; lwz 3,0xc(31); addi 9,9,20216; stw 9,0x14(31); cmpwi 3,0; beq 5f; li 4,3; bl _s80288A38_5; 5:; andi. 0,28,1; beq 6f; lwz 3,-23020(13); mr 4,31; li 5,120; bl _s80288A38_6; 6:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80288A38_0();
extern "C" void _s80288A38_1();
extern "C" void _s80288A38_2();
extern "C" void _s80288A38_3();
extern "C" void _s80288A38_4();
extern "C" void _s80288A38_5();
extern "C" void _s80288A38_6();
extern "C" void f_80288A38() {}
