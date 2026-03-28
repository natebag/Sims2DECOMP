// 0x8032B9F0 (4 bytes)
typedef void OSAlarm;
typedef void OSContext;
class ENgcAudio {
public:
    static void AudioAlarmHandler(OSAlarm*, OSContext*);
};
void ENgcAudio::AudioAlarmHandler(OSAlarm*, OSContext*) {}
