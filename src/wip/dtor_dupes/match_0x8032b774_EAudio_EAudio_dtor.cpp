extern int VT_EAudio_EAudio[];
void del_EAudio_EAudio(void *);
void dtor_EAudio_EAudio(char *self, int __in_chrg) {
    *(int **)self = VT_EAudio_EAudio;
    if (__in_chrg & 1) {
        del_EAudio_EAudio(self);
    }
}
