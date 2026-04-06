// 0x802D859C (48b)
extern int someFunc(void);
int wrapper() {
    return someFunc() != 0;
}
