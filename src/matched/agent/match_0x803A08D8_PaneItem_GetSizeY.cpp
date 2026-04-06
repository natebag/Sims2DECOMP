// FLAGS: -fno-elide-constructors
// 0x803A08D8 PaneItem::GetSizeY (68b)
    char pad[28];
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4();
};

float PaneItem_GetSizeY(PaneBaseY* self) {
    self->V4();
    return *(float*)((char*)self + 24);
}
