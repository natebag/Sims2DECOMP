// 0x80119050 (56B) cSamplePatch::CreateChannel(void)
// Allocate 8B cSampleChannel via __builtin_new and ctor with this as patch arg.

class cSamplePatch;

class cSampleChannel {
public:
    char _pad[8];
    cSampleChannel(cSamplePatch* patch);
};

class cSamplePatch {
public:
    cSampleChannel* CreateChannel();
};

cSampleChannel* cSamplePatch::CreateChannel()
{
    return new cSampleChannel(this);
}
