// FLAGS: -fno-elide-constructors
int BS_strlen(char *);
void *BS_assign_impl(void *, char *, int);

struct BS_OpAssign {
    void *operator_eq(char *str);
};

void *BS_OpAssign::operator_eq(char *str) {
    int len;
    if (str != 0) {
        len = BS_strlen(str);
    } else {
        len = 0;
    }
    BS_assign_impl(this, str, len);
    return this;
}
