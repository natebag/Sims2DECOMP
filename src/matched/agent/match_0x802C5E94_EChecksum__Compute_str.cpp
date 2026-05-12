// 0x802C5E94 (76B) EChecksum::Compute(char*)
// CRC32 for null-terminated strings. Table = EChecksum::m_table at 0x8043E928 (256 words).
// unsigned char c for null checks (lbz+cmpwi no extsb); (signed char)c for table index (extsb).
// Scheduler: extsb r9 before lbzu r10 (data dep); cmpwi r10 deferred past lwzx.

extern unsigned int EChecksum__m_table[256];

struct EChecksum_Cmp {
    static unsigned int Compute(char* str);
};

unsigned int EChecksum_Cmp::Compute(char* str) {
    unsigned char c = (unsigned char)*str;
    unsigned int crc = 0xFFFFFFFF;
    if (!c) goto done;
    do {
        unsigned int idx = (crc & 0xFF) ^ (unsigned int)(signed char)c;
        crc = (crc >> 8) ^ EChecksum__m_table[idx];
        c = (unsigned char)*++str;
    } while (c);
done:
    return ~crc;
}
