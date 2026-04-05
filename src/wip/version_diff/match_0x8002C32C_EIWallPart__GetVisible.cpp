// EIWallPart::GetVisible(int)
// Address: 0x8002C32C | Size: 48 bytes

struct EIWallPart {
    char pad[0x5C];
    unsigned int m_visibleFlags;  // word access, not byte
};

int EIWallPart__GetVisible(EIWallPart* self, int which) {
    if (which == 0) {
        return (self->m_visibleFlags >> 7) & 1;
    } else if (which == 1) {
        return self->m_visibleFlags & 1;
    }
    return 0;
}
