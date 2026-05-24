/* EString2::Convert(double) @ 0x802D4130 (36 bytes) */
/* Canonical class layout from include/types/EString.h */

class EString2 {
public:
    unsigned short* m_buffer;
    void Convert(float val);
    void Convert(double val);
};

void EString2::Convert(double val) {
    Convert((float)val);
}
