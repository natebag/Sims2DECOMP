
int stricmp_internal(char *, char *);

struct EString {
    char* m_str;

    int CompareNoCase(char* other) const;
};

int EString::CompareNoCase(char* other) const {
    char* s = m_str;
    if (*s != 0)
        goto this_nonempty;
    if (other == 0)
        goto both_empty;
    if (*other != 0)
        goto return_neg1;
both_empty:
    return 0;
return_neg1:
    return -1;
this_nonempty:
    if (other == 0)
        goto return_pos1;
    if (*other != 0)
        goto do_compare;
return_pos1:
    return 1;
do_compare:
    return stricmp_internal(s, other);
}
