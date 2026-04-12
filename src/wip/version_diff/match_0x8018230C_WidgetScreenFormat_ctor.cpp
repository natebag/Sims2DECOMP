// 0x8018230C WidgetScreenFormat::WidgetScreenFormat (28b)
// FLAGS: -fno-schedule-insns -fno-schedule-insns2

struct WidgetScreenFormat {
    int f0;
    int f4;
    int pad[2];  // padding to offset 16
    int f16;
    int pad2[2]; // padding to offset 28
    int f28;
    WidgetScreenFormat();
};

WidgetScreenFormat::WidgetScreenFormat() {
    f16 = 0;
    f28 = 0;
    f4 = 0;
    f0 = 0;
}
