/* EString::operator=(char *) - 0x802D2BE4 (64 bytes) */

struct EString {
    char *m_str;

    void MakeCopy(char *);
    void Deallocate(char *);
    EString &op_assign(char *src);
};

EString &EString::op_assign(char *src)
{
    char *old = m_str;
    MakeCopy(src);
    Deallocate(old);
    return *this;
}
