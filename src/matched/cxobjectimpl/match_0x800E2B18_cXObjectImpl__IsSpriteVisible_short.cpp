// 0x800E2B18 (88B) cXObjectImpl::IsSpriteVisible(short)
// Range-check + sparse-array probe predicate. Leaf function, no stack frame.

struct ContainerStruct {
    char _pad0_127[128];
    short m_first;
};

struct cXObjectImpl {
    char _pad0_15[16];
    short* m_array;
    short m_count;
    char _pad22_135[136 - 22];
    ContainerStruct* m_container;

    int IsSpriteVisible(short spriteIdx);
};

int cXObjectImpl::IsSpriteVisible(short spriteIdx) {
    short count = m_count;
    if (count == 0) {
        return 1;
    }
    short first = m_container->m_first;
    if (spriteIdx < first || spriteIdx >= first + count) {
        return 1;
    }
    short val = m_array[spriteIdx - first];
    if (val != 0) {
        return 1;
    }
    return 0;
}
