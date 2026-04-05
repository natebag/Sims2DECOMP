typedef unsigned char u8;
void del_tdr(void*);
void d_TrackDataReader(u8* self, int __in_chrg) {
    *(int*)self = 0;
    if (__in_chrg & 1) {
        del_tdr(self);
    }
}
