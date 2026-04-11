// 0x8014ABA0 (40 bytes)
// Bookmark::Bookmark(unsigned short p2, short p3, void* p4, unsigned short p5)
// WANT_FEAR MATCH

struct Bookmark {
    unsigned short f0;    // offset 0
    unsigned short f2;    // offset 2  
    void* f4;             // offset 4
    unsigned short f8;    // offset 8
    
    Bookmark(unsigned short p2, short p3, void* p4, unsigned short p5);
};

Bookmark::Bookmark(unsigned short p2, short p3, void* p4, unsigned short p5) {
    f0 = p2;
    f2 = 0;
    f8 = p5;
    f4 = p4;
    // Check flag at offset 29 of p4 - early return if bit 1 not set
    if ((((char*)p4)[29] & 2) == 0) {
        return;
    }
    f2 = (unsigned short)p3;
}
