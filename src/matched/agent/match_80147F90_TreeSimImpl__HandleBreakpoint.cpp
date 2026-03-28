// 0x80147F90 (72 bytes)
// TreeSimImpl::HandleBreakpoint(StackElem *, BehaviorNode *)

class TreeSimImpl { public: void HandleBreakpoint(StackElem *, BehaviorNode *); };

__attribute__((naked))
void TreeSimImpl::HandleBreakpoint(StackElem *, BehaviorNode *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7C9F2379\n.long 0x41820010\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x480011C9\n.long 0x7FC3F378\n.long 0x7FE4FB78\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
