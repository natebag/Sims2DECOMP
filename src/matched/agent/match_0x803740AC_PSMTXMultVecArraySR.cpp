// 0x803740AC PSMTXMultVecArraySR (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE1A30000; .long 0xE1830010; addi 6,6,-1; .long 0xE1638008; .long 0x100D6420; addi 5,5,-4; .long 0xE1438018; .long 0x102D64E0; mtspr 9,6; .long 0xE0630020; .long 0x104B5420; .long 0xE0838028; .long 0xE0C40000; .long 0xE4E48008; .long 0x11000198; .long 0x112301B2; .long 0x1101419E; .long 0x114449FA; 0:; .long 0xE4C40004; .long 0x118241DC; .long 0xE4E48008; .long 0x11AA4A54; .long 0x11000198; .long 0x112301B2; .long 0xF5850004; .long 0x1101419E; .long 0xF5A58008; .long 0x114449FA; bdnz 0b; .long 0x118241DC; .long 0x11AA4A54; .long 0xF5850004; .long 0xF5A58008"
extern "C" int f_803740AC() {}
