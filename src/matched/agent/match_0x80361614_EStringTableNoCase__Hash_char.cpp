// 0x80361614 EStringTableNoCase::Hash(char (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 11,0x0(4); li 10,0; cmpwi 11,0; beq 2f; 0:; extsb 9,11; addi 0,9,-97; cmplwi 0,25; bgt 1f; addi 0,9,-32; extsb 9,0; 1:; rlwinm 0,10,2,0,29; lbzu 11,0x1(4); add 0,0,10; add 10,0,9; cmpwi 11,0; bne 0b; 2:; lwz 3,0x10(3); and 3,10,3"
extern "C" int f_80361614() {}
