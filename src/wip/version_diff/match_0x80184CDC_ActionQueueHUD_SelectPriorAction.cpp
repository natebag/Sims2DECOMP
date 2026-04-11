/* 0x80184CDC (100 bytes)
   ActionQueueHUD::SelectPriorAction(void) */

typedef signed char s8;
typedef unsigned char u8;

typedef unsigned int u32;

struct ActionQueueItem {
    u32 field_0;
    u32 field_4;
    u8 field_8;
    u8 field_9;
    u8 field_a;
    u8 field_b;
    u32 field_c;
    u8 enabled;      // 0xAD - offset 173 from item start
    u8 pad[3];
    u32 field_14;
};

struct ActionQueueHUD {
    u32 field_0;
    u8 pad[789];
    s8 selectedIndex;  // 0x319 = 793
    
    void SelectAction(s8 index);
    void SelectPriorAction();
};

void ActionQueueHUD::SelectPriorAction() {
    for (s8 i = selectedIndex - 1; i >= 0; i--) {
        ActionQueueItem* item = (ActionQueueItem*)((char*)this + 156 + (int)i * 20);
        if (item->enabled) {
            SelectAction(i);
            return;
        }
    }
}
