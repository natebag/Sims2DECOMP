/* Neighborhood::CreateInstance(void) - 0x800CC6D0 (40 bytes) */

struct NeighborhoodImpl {
    char m_data[0xCC];
    NeighborhoodImpl(void);
};

void *operator new(unsigned int size);

struct Neighborhood {
    static NeighborhoodImpl *CreateInstance(void);
};

NeighborhoodImpl *Neighborhood::CreateInstance(void) {
    return new NeighborhoodImpl();
}
