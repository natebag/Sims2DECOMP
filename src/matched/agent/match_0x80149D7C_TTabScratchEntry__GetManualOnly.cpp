// 0x80149D7C TTabScratchEntry::GetManualOnly (20b)

struct TTabScratchEntry {
    char _pad[0x114];
    short m_attenuation;
};

int TTabScratchEntry__GetManualOnly(TTabScratchEntry *self) {
    return self->m_attenuation > 99;
}
