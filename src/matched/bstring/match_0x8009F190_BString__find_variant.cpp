int BS_strlen(char *);
int BS_find_impl(void *, char *, int, int);

struct BS_FindCP {
    int find(char *str, int startIdx);
};

int BS_FindCP::find(char *str, int startIdx) {
    int len;
    if (str != 0) {
        len = BS_strlen(str);
    } else {
        len = 0;
    }
    return BS_find_impl(this, str, startIdx, len);
}
