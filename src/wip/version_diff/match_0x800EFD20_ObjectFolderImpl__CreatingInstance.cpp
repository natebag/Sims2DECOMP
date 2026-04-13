typedef unsigned char u8;

void ObjectFolderImpl_CreatingInstance(u8* self, u8* selector) {
    if (*(int*)(selector + 0xA0) != 1) {
        u8* inner = *(u8**)(selector + 0x38);
        if (*(int*)(inner + 0xC0) != 0) {
            u8* vt = *(u8**)self;
            short adj = *(short*)(vt + 0x200);
            void (*func)(u8*, u8*, int) = *(void (**)(u8*, u8*, int))(vt + 0x204);
            func(self + adj, selector, 1);
            *(int*)(selector + 0x68) = *(int*)(selector + 0x68) + 1;
        }
    }
}
