// 0x8018230C WidgetScreenFormat::WidgetScreenFormat (28b)

struct WidgetScreenFormat {
    int f0;     // offset 0
    int f4;     // offset 4
    int f8;     // offset 8
    int f12;    // offset 12
    int f16;    // offset 16
    int f20;    // offset 20
    int f24;    // offset 24
    int f28;    // offset 28
    WidgetScreenFormat();
};

WidgetScreenFormat::WidgetScreenFormat() {
    WidgetScreenFormat* p = this;
    *(volatile int*)&p->f16 = 0;
    *(volatile int*)&p->f28 = 0;
    *(volatile int*)&p->f4 = 0;
    *(volatile int*)&p->f0 = 0;
}
