// 0x803CA8CC EAnimNodeDataPos::Destruct(EAnimNodeDataPos*) (16B)
// Set vtable pointer at offset 0 (same pattern as EStorable::Construct)

extern char EAnimNodeDataPos_vtable[16];

struct EAnimNodeDataPos;

void EAnimNodeDataPos_Destruct(EAnimNodeDataPos* p) {
    *(void**)p = (void*)EAnimNodeDataPos_vtable;
}
