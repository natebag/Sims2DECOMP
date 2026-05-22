// 0x8027EEEC AptActionInterpreter::_FunctionAptActionPush0(AptActionInterpreter (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,-26908(13); mr 29,3; cmpwi 31,0; beq 2f; lwz 0,0x0(31); lwz 9,0xc(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 1:; li 0,0; mr 8,31; stw 0,0xc(31); b 3f; 2:; lwz 3,-23020(13); li 4,16; bl _s8027EEEC_0; mr 30,3; li 4,7; bl _s8027EEEC_1; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; mr 8,30; stw 9,0x8(30); 3:; lwz 9,0x0(29); lis 4,-32704; lwz 10,0x8(29); lis 5,-32704; rlwinm 11,9,2,0,29; addi 4,4,5760; stwx 8,11,10; addi 9,9,1; stw 9,0x0(29); addi 5,5,5812; li 6,138; lwz 9,0x8(8); lha 3,0x8(9); lwz 0,0xc(9); add 3,8,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8027EEEC_0();
extern "C" void _s8027EEEC_1();
extern "C" void f_8027EEEC() {}
