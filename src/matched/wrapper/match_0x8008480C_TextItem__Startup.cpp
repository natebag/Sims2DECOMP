// 0x8008480C TextItem::Startup (88b)

struct SubObj { char pad[52]; float size; };

extern void TextBaseItem_Startup(void*);
extern void SetStyle(void*, int);
extern void InitSubObj(SubObj*);
extern char g_defaultStyle[4];
extern char g_defaultSize[4];

struct TextItem {
    int pad0;
    int flags;
    char pad1[24];
    SubObj subObj;
};

void TextItem_Startup(TextItem* self) {
    TextBaseItem_Startup(self);
    SetStyle(self, *(int*)g_defaultStyle);
    SubObj* sub = &self->subObj;
    sub->size = *(float*)g_defaultSize;
    InitSubObj(sub);
    self->flags |= 2;
}
