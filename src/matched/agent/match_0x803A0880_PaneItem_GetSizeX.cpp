// FLAGS: -fno-elide-constructors
// 0x803A0880 PaneItem::GetSizeX (68b)
    char pad[28];
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4();
};

float PaneItem_GetSizeX(PaneBaseX* self) {
    self->V4();
    return *(float*)((char*)self + 20);
}
