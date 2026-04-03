extern int VT_QuickDataSoundInfo_QuickDataSoundInfo[];
void del_QuickDataSoundInfo_QuickDataSoundInfo(void *);
void dtor_QuickDataSoundInfo_QuickDataSoundInfo(char *self, int __in_chrg) {
    *(int **)self = VT_QuickDataSoundInfo_QuickDataSoundInfo;
    if (__in_chrg & 1) {
        del_QuickDataSoundInfo_QuickDataSoundInfo(self);
    }
}
