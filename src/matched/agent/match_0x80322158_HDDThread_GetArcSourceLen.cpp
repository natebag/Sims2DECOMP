// 0x80322158 (60B) HDDThread::GetArcSourceLen(int)
// Same pattern as ArcIsCurrent: pre-seed r3=0, bgt to shared epilogue.

extern int InnerGetArcSourceLen(void*);

class HDDThreadSL {
public:
    int GetArcSourceLen(int);
};

int HDDThreadSL::GetArcSourceLen(int idx) {
    int result = 0;
    if ((unsigned int)idx <= 31) {
        result = InnerGetArcSourceLen((char*)this + (idx * 20 + 0x340));
    }
    return result;
}
