/* EString2::operator=(char *) - 0x802D4698 (64 bytes) */

struct EString2 {
    char *m_str;

    void MakeCopy(char *);
    void Deallocate(char *);
    EString2 &op_assign(char *src);
};

EString2 &EString2::op_assign(char *src)
{
    char *old = m_str;
    MakeCopy(src);
    Deallocate(old);
    return *this;
}
