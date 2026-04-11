extern int VT[];
void del_fn(void *);
void d_UrbzModeNewGameState_UrbzModeNewGameState(char *self, int __in_chrg) {
    *(int **)(self + 24) = VT;
    if (__in_chrg & 1) {
        del_fn(self);
    }
}
