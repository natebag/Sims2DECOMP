int __cntlzw(int val);
int __cntlzw(int val) {
    int result;
    asm("cntlzw %0, %1" : "=r"(result) : "r"(val));
    return result;
}
