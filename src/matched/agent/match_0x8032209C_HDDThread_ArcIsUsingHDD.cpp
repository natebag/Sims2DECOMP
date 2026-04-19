// 0x8032209C (60B) HDDThread::ArcIsUsingHDD(int)
// Same pattern as ArcIsCurrent: pre-seed r3=0, bgt to shared epilogue.

extern int InnerArcUsingHDD(void*);

class HDDThreadUH {
public:
    int ArcIsUsingHDD(int);
};

int HDDThreadUH::ArcIsUsingHDD(int idx) {
    int result = 0;
    if ((unsigned int)idx <= 31) {
        result = InnerArcUsingHDD((char*)this + (idx * 20 + 0x340));
    }
    return result;
}
