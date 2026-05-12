// FLAGS: -fno-schedule-insns
// 0x802C5E44 (80B) EChecksum::Compute(void*, int)
// CRC32 with explicit size. Table = EChecksum::m_table at 0x8043E928 (256 words).
// No extsb — byte loaded with lbz (unsigned), XOR is unsigned.
// Counter: count = size-1, cmpwi count before addi count,-1 (scheduler hoist).
// do-while count-- != 0: GCC hoist cmpwi early for CR latency.
// beq size==0 goto done (same not-r3 end as char* variant).
// lbz r0,0(r8) + addi r8,r8,1 (separate load+incr, not lbzu).

extern unsigned int EChecksum__m_table[256];

struct EChecksum_Cmp2 {
    static unsigned int Compute(void* data, int size);
};

unsigned int EChecksum_Cmp2::Compute(void* data, int size) {
    char* ptr = (char*)data;
    int count = size - 1;
    unsigned int crc = 0xFFFFFFFF;
    if (size == 0) goto done;
    do {
        unsigned int idx = (crc & 0xFF) ^ (unsigned char)*ptr;
        crc = (crc >> 8) ^ EChecksum__m_table[idx];
        ptr++;
    } while (count-- != 0);
done:
    return ~crc;
}
