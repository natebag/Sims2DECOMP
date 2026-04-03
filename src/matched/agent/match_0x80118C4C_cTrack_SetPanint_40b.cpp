void *inner_fn(void *, int, int);
void *w_cTrack_SetPanint(void *self, int arg) {
    return inner_fn(self, 10, arg);
}
