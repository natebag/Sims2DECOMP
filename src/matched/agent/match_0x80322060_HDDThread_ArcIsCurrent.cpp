// 0x80322060 (60B) HDDThread::ArcIsCurrent(int)
// Bounds check with pre-seeded return 0 (falls into shared epilogue):
//   int r = 0; if (idx <= 31) r = Inner(this + 0x340 + idx*20); return r;

extern int InnerArcCurrent(void*);

class HDDThread {
public:
    int ArcIsCurrent(int);
};

int HDDThread::ArcIsCurrent(int idx) {
    int result = 0;
    if ((unsigned int)idx <= 31) {
        result = InnerArcCurrent((char*)this + (idx * 20 + 0x340));
    }
    return result;
}
