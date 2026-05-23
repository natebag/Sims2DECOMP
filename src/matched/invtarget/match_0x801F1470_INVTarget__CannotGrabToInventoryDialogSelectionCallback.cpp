typedef unsigned char u8;

u8* closeDialog(void);
u8* getObject(u8*, int, int);
void processGrab(u8*);

void INVTarget_CannotGrabToInventoryDialogSelectionCallback(u8* self, int selection) {
    if (selection != 0) return;
    u8* base = closeDialog();
    u8* obj = getObject(base, *(int*)(self + 0x84), 2);
    if (obj != 0) {
        processGrab(obj);
    }
}
