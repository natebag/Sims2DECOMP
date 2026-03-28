/* operator<(char *, BString &) - 0x8009C330 (64 bytes) */

struct BString {
    int compare(char *, unsigned int) const;
};

int operator_lt_charptr_BString(char *lhs, BString &rhs)
{
    int r = rhs.compare(lhs, 0);
    return r > 0;
}
