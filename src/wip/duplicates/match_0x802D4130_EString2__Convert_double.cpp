/* EString2::Convert(double) @ 0x802D4130 (36 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CvD {
    wchar_t_u *m_str;
    void Convert(double d);
    void Convert(float f);
};

void EString2_CvD::Convert(double d) {
    Convert((float)d);
}
