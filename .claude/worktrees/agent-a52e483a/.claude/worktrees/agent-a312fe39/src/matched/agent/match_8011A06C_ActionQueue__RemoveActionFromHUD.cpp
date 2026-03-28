// 0x8011A06C (124 bytes)
// ActionQueue::RemoveActionFromHUD(int)

class ActionQueue { public: void RemoveActionFromHUD(int); };

__attribute__((naked))
void ActionQueue::RemoveActionFromHUD(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x880302B0\n.long 0x2C000000\n.long 0x40820058\n.long 0x800302AC\n.long 0x812302A8\n.long 0x7C090050\n.long 0x7C040000\n.long 0x40800044\n.long 0x3C00CCCC\n.long 0x7D292214\n.long 0x6000CCCD\n.long 0x3D608047\n.long 0x7C090016\n.long 0x816B5BCC\n.long 0x2C0B0000\n.long 0x5400E8FE\n.long 0x1C00000A\n.long 0x7D204850\n.long 0x1D290044\n.long 0x7CA34A14\n.long 0x41820010\n.long 0x888302B1\n.long 0x7D635B78\n.long 0x4809EDF5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
