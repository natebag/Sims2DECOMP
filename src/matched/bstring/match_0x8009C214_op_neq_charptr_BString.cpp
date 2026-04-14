/* operator!=(char *, BString &) - 0x8009C214 (64 bytes) */

struct BString {
    int compare(char *, unsigned int) const;
};

int operator_neq_charptr_BString(char *lhs, BString &rhs)
{
    int r = rhs.compare(lhs, 0);
    return r != 0;
}
