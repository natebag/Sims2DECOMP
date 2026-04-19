// 0x80010D70 (60B) AptViewer::RepeatClear(int a, int b)
// Member function (this unused). Zero 3 static 4x4 int arrays at [b][a].
// Byte offset = b*16 + a*4 (distributed shifts). Stores: count=0, rate=22, button=0.

extern "C" {
    extern int AptViewer_repeatButton[4][4];  // 0x80423610
    extern int AptViewer_repeatRate[4][4];    // 0x80423630
    extern int AptViewer_repeatCount[4][4];   // 0x80423650
}

class AptViewer {
public:
    void RepeatClear(int a, int b);
};

void AptViewer::RepeatClear(int a, int b) {
    AptViewer_repeatCount[a][b] = 0;
    AptViewer_repeatRate[a][b] = 22;
    AptViewer_repeatButton[a][b] = 0;
}
