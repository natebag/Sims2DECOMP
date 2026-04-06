// FLAGS: -fno-elide-constructors
// 0x803A0828 PaneItem::GetSize (68b)
    char pad[28];
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4();
};

void* PaneItem_GetSize(PaneBase* self) {
    self->V4();
    return (char*)self + 20;
}
