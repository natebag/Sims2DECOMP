// 0x80147960 (92 bytes)
// TreeSimImpl::GetCurrentNode(short *, short *)

class TreeSimImpl { public: void GetCurrentNode(short *, short *); };

__attribute__((naked))
void TreeSimImpl::GetCurrentNode(short *, short *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x81630000\n.long 0x7C9D2378\n.long 0x7CBC2B78\n.long 0x812B0018\n.long 0x8009004C\n.long 0xA8690048\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x7C7E1B78\n.long 0x48001781\n.long 0xB07D0000\n.long 0xA01E0002\n.long 0xB01C0000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
