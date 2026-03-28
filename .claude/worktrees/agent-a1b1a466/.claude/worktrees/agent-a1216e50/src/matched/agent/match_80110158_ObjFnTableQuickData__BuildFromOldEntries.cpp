// 0x80110158 (104 bytes)
// ObjFnTableQuickData::BuildFromOldEntries(ObjDefinition *)

class ObjFnTableQuickData { public: void BuildFromOldEntries(ObjDefinition *); };

__attribute__((naked))
void ObjFnTableQuickData::BuildFromOldEntries(ObjDefinition *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0010\n.long 0x2C000000\n.long 0x40820010\n.long 0x3860007C\n.long 0x481C1035\n.long 0x907F0010\n.long 0x807F0010\n.long 0x38800000\n.long 0x38A0007C\n.long 0x48133455\n.long 0x4BFC9489\n.long 0x813F0010\n.long 0xB0690004\n.long 0x4BFC9485\n.long 0x813F0010\n.long 0xB0690006\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
