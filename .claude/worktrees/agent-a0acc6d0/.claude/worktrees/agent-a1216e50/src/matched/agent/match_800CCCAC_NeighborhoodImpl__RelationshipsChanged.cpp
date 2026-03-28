// 0x800CCCAC (84 bytes)
// NeighborhoodImpl::RelationshipsChanged(Neighbor *)

class NeighborhoodImpl { public: void RelationshipsChanged(Neighbor *); };

__attribute__((naked))
void NeighborhoodImpl::RelationshipsChanged(Neighbor *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x3BE00001\n.long 0x93E40024\n.long 0xA88400EA\n.long 0x81230000\n.long 0xA8090120\n.long 0x81290124\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x41820008\n.long 0x93E30020\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
