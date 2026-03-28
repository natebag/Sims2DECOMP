// 0x801AD378 (112 bytes)
// E2ETarget::UpdateHue(char *, char *)

class E2ETarget { public: void UpdateHue(char *, char *); };

__attribute__((naked))
void E2ETarget::UpdateHue(char *, char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7CA32B78\n.long 0x4813189D\n.long 0x3D20803F\n.long 0xC009F910\n.long 0xFC010000\n.long 0x4C620B82\n.long 0x41830018\n.long 0x3D20803F\n.long 0xC009F914\n.long 0xFC010000\n.long 0x4C620382\n.long 0x40830008\n.long 0xFC200090\n.long 0x4BE8BFF1\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x38A00000\n.long 0x4BFFFBF9\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
