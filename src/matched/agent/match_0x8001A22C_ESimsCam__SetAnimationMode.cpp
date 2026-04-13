// 0x8001A22C ESimsCam::SetAnimationMode (32b)
typedef unsigned int uint;

struct ESimsCam {
    char _pad1[0x478];
    uint m_animDirty;
    char _pad2[216];
    uint m_animMode;
    uint m_animObj1;
    uint m_animObj2;
};

void ESimsCam__SetAnimationMode(ESimsCam *self, uint mode, uint obj1, uint obj2, int update) {
    self->m_animMode = mode;
    self->m_animObj1 = obj1;
    self->m_animObj2 = obj2;
    if (update) {
        self->m_animDirty = 1;
    }
}
