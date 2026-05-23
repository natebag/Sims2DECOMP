// 0x80250AB0 Config24MB (128B) — Dolphin SDK OSMemory.o
// ASMPROC_inject_before: before="blr" replace="rfi" lines="li 7,0; lis 4,0; addi 4,4,2; lis 3,-32768; addi 3,3,511; lis 6,256; addi 6,6,2; lis 5,-32512; addi 5,5,255; isync; mtdbatu 0,7; mtdbatl 0,4; mtdbatu 0,3; isync; mtibatu 0,7; mtibatl 0,4; mtibatu 0,3; isync; mtdbatu 2,7; mtdbatl 2,6; mtdbatu 2,5; isync; mtibatu 2,7; mtibatl 2,6; mtibatu 2,5; isync; mfmsr 3; ori 3,3,48; mtsrr1 3; mflr 3; mtsrr0 3"
extern "C" void Config24MB() {}
