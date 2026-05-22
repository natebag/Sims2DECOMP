// 0x802ABB58 AptSound::objectMemberLookup(AptValue (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); cmpwi 4,0; beq 0f; lwz 3,0x0(5); lhz 4,0x2(3); addi 3,3,8; bl _s802ABB58_0; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 9f; lwz 31,0x4(3); cmpwi 31,2; beq 5f; bgt 2f; cmpwi 31,1; beq 3f; b 9f; 2:; cmpwi 31,3; beq 7f; b 9f; 3:; lwz 28,-27096(13); cmpwi 28,0; bne 4f; lwz 3,-23016(13); li 4,40; bl _s802ABB58_1; mr 30,3; lis 29,-32725; addi 29,29,-18000; li 4,9; bl _s802ABB58_2; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802ABB58_3; stb 28,0x20(30); lis 11,-32704; addi 11,11,16488; lwz 9,0x0(30); lwz 0,0x20(30); lis 4,-32703; stw 29,0x24(30); rlwimi 9,31,8,18,23; rlwinm 0,0,0,10,7; stw 11,0x8(30); stw 0,0x20(30); lis 5,-32703; stw 30,-27096(13); addi 4,4,-7480; stw 9,0x0(30); addi 5,5,-7564; li 6,141; lha 3,0x8(11); lwz 0,0xc(11); add 3,30,3; mtspr 8,0; blrl; 4:; lwz 3,-27096(13); b 10f; 5:; lwz 31,-27092(13); cmpwi 31,0; bne 6f; lwz 3,-23016(13); li 4,40; bl _s802ABB58_4; mr 30,3; lis 29,-32725; addi 29,29,-17684; li 4,9; bl _s802ABB58_5; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802ABB58_6; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-27092(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,-7480; addi 5,5,-7564; li 6,146; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 6:; lwz 3,-27092(13); b 10f; 7:; lwz 31,-27088(13); cmpwi 31,0; bne 8f; lwz 3,-23016(13); li 4,40; bl _s802ABB58_7; mr 30,3; lis 29,-32725; addi 29,29,-17584; li 4,9; bl _s802ABB58_8; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802ABB58_9; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-27088(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,-7480; addi 5,5,-7564; li 6,151; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 8:; lwz 3,-27088(13); b 10f; 9:; li 3,0; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802ABB58_0();
extern "C" void _s802ABB58_1();
extern "C" void _s802ABB58_2();
extern "C" void _s802ABB58_3();
extern "C" void _s802ABB58_4();
extern "C" void _s802ABB58_5();
extern "C" void _s802ABB58_6();
extern "C" void _s802ABB58_7();
extern "C" void _s802ABB58_8();
extern "C" void _s802ABB58_9();
extern "C" void f_802ABB58() {}
