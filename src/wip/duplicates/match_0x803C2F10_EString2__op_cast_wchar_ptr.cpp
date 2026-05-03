// FLAGS: -fno-elide-constructors-only
/* EString2::operator unsigned wchar_t *() const @ 0x803C2F10 (8 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_Cast { wchar_t_u *m_str; operator wchar_t_u*() const; };

EString2_Cast::operator wchar_t_u*() const {
    return m_str;
}
