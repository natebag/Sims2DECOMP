extern int VT[];
void del_fn(void *);
void d_PreGameCasPlayer2State_PreGameCasPlayer2State(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
