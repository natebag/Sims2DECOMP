// 0x80006B74 debugSetScreenGrabPending (4b)
extern "C" void debugSetScreenGrabPending(char*) {}

// MATCH: 0x80006B78 debugAddSavedInput (4 bytes)
struct AptSavedInputRecord;
extern "C" void debugAddSavedInput(AptSavedInputRecord*, int) {}

// MATCH: 0x80007424 startSoundStream (4 bytes)
extern "C" void startSoundStream(void*, int) {}

// MATCH: 0x80007428 startSound (4 bytes)
extern "C" void startSound(void*, char*) {}

// MATCH: 0x8000742C freeSound (4 bytes)
extern "C" void freeSound(void*) {}
