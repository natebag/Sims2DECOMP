// 0x801AD3E8 (112 bytes)
// E2ETarget::UpdateSaturation(char *, char *)

class E2ETarget { public: void UpdateSaturation(char *, char *); };

__attribute__((naked))
void E2ETarget::UpdateSaturation(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CA32B78\n.long 0x4813182D\n.long 0x3D20803F\n.long 0xC009F918\n.long 0xFC010000\n.long 0x4C620B82\n.long 0x41830018\n.long 0x3D20803F\n.long 0xC009F91C\n.long 0xFC010000\n.long 0x4C620382\n.long 0x40830008\n.long 0xFC200090\n.long 0x4BE8BF15\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x38A00000\n.long 0x4BFFFB89\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
