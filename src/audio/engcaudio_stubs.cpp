// engcaudio_stubs.cpp - Stub implementations for Engcaudio
// Auto-generated from symbols.json - 29 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x805041CC | 112 bytes
ENgcAudio::ENgcAudio(void) { }

// 0x8050423C | 92 bytes
ENgcAudio::~ENgcAudio(void) { }

// 0x80504310 | 260 bytes
void ENgcAudio::InitAudio(void) { }

// 0x80504414 | 4 bytes
void ENgcAudio::AudioAlarmHandler(OSAlarm *, OSContext *) { }

// 0x80504418 | 104 bytes
void ENgcAudio::Shutdown(void) { }

// 0x80504480 | 1152 bytes
void ENgcAudio::PlayMusic(EPMDesc &) { }

// 0x80504900 | 8 bytes
void ENgcAudio::GetIndexFromVoice(EVoice *) { }

// 0x80504908 | 8 bytes
void ENgcAudio::GetVoiceFromIndex(unsigned char) { }

// 0x80504910 | 784 bytes
void ENgcAudio::Update(void) { }

// 0x80504C20 | 204 bytes
void ENgcAudio::StopMusic(void) { }

// 0x80504CEC | 112 bytes
void ENgcAudio::PauseMusic(void) { }

// 0x80504D5C | 112 bytes
void ENgcAudio::ResumeMusic(void) { }

// 0x80504DCC | 192 bytes
void ENgcAudio::SetMusicVolume(float) { }

// 0x80504E8C | 8 bytes
void ENgcAudio::GetMusicVolume(void) { }

// 0x80504E94 | 196 bytes
void ENgcAudio::SetMusicPan(float) { }

// 0x80504F58 | 8 bytes
void ENgcAudio::GetMusicPan(void) { }

// 0x80504F60 | 92 bytes
void ENgcAudio::IsPlayingMusic(void) { }

// 0x80504FF8 | 64 bytes
void ENgcAudio::AudioAllocVoice(void) { }

// 0x80505038 | 72 bytes
void ENgcAudio::FreeVoice(EVoice *) { }

// 0x80505080 | 412 bytes
void ENgcAudio::AudioBindVoice(EVoice *, unsigned int) { }

// 0x8050521C | 232 bytes
void ENgcAudio::UnbindVoice(EVoice *) { }

// 0x80505304 | 144 bytes
void ENgcAudio::GetVoiceState(EVoice *, EVoiceDesc &) { }

// 0x80505394 | 304 bytes
void ENgcAudio::SetVoiceState(EVoice *, EVoiceDesc &) { }

// 0x805054C4 | 108 bytes
void ENgcAudio::SetSpeakerVolumes(EVoice *, int *, unsigned int) { }

// 0x80505530 | 8 bytes
void ENgcAudio::IsPausedDueToDiscError(void) { }

// 0x80505538 | 8 bytes
void ENgcAudio::SetDiscErrorCallback(void (*)(bool)) { }

// 0x80505668 | 4 bytes
void ENgcAudio::Flush(bool) { }

// 0x8050566C | 4 bytes
void ENgcAudio::AddEvent(EA_EVENT, EMsgQueue &, unsigned int) { }

// 0x80505670 | 4 bytes
void ENgcAudio::RemoveEvent(EA_EVENT, EMsgQueue &, unsigned int) { }
