// 0x80119088 (60B) cSampleChannel::cSampleChannel(cSamplePatch*)
// Init m_field0 and m_field4 to 0, then SetPatch(patch).

class cSamplePatch;

class cSampleChannel {
public:
    int m_field0;   // +0
    int m_field4;   // +4
    cSampleChannel(cSamplePatch* patch);
    void SetPatch(cSamplePatch* patch);
};

cSampleChannel::cSampleChannel(cSamplePatch* patch)
    : m_field0(0)
    , m_field4(0)
{
    SetPatch(patch);
}
