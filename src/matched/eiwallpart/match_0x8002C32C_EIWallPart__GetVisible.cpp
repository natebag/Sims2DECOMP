// EIWallPart::GetVisible(int)
// Address: 0x8002C32C | Size: 48 bytes
// FLAGS: -fno-elide-constructors

struct EIWallPart {
    char pad[0x5C];
    unsigned int m_visibleFlags;
};

int EIWallPart__GetVisible(EIWallPart* self, int which) {
    if (which == 0) {
        return (int)(self->m_visibleFlags & 1U);
    } else if (which == 1) {
        return (int)((self->m_visibleFlags >> 1) & 1U);
    }
    return 0;
}
