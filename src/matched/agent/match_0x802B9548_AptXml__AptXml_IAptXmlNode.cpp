// 0x802B9548 AptXml::AptXml(IAptXmlNode (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 5,4; li 4,33; bl _s802B9548_0; lis 9,-32703; mr 3,30; addi 9,9,31032; stw 9,0x8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802B9548_0();
extern "C" void f_802B9548() {}
