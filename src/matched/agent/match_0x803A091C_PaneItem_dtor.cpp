// FLAGS: -fno-elide-constructors
// 0x803A091C PaneItem::~PaneItem (84b)
void paneitem_cleanup(void*);
void paneitem_parent_dtor(void*);
void paneitem_delete(void*);

void PaneItem_dtor(char* self, int mode) {
    *(int*)(self + 28) = (int)PaneItem_vtable;
    paneitem_cleanup(self);
    paneitem_parent_dtor(self);
    if (mode & 1) {
        paneitem_delete(self);
    }
}
