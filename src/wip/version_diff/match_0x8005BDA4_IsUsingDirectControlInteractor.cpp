// VERSION_DIFF: code layout — boolean idiom generates larger code
/* {anonymous}::IsUsingDirectControlInteractor(int) at 0x8005BDA4 (100B) */
// FLAGS: -fno-elide-constructors

extern void *getDCI_obj(void);
extern void *checkDCI(void *, int, int);

int IsUsingDirectControlInteractor_anon(int type) {
    void *obj = getDCI_obj();
    int r1 = (int)checkDCI(obj, type, -1);
    if (r1 == 0) return 0;
    obj = getDCI_obj();
    int r2 = (int)checkDCI(obj, type, 0);
    return (r1 | r2) != 0;
}
