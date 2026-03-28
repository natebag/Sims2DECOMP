// 0x800F8560 (120 bytes)
// ObjectModuleImpl::RelationshipAccessed(Neighbor *, Neighbor *, int, bool)

class ObjectModuleImpl { public: void RelationshipAccessed(Neighbor *, Neighbor *, int, bool); };

__attribute__((naked))
void ObjectModuleImpl::RelationshipAccessed(Neighbor *, Neighbor *, int, bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7CBF2B78\n.long 0x2C070000\n.long 0x41820048\n.long 0x816DAC1C\n.long 0x812B0000\n.long 0x800900FC\n.long 0xA86900F8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x816DAC1C\n.long 0x7FE4FB78\n.long 0x812B0000\n.long 0x800900FC\n.long 0xA86900F8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000001\n.long 0x901E0018\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
