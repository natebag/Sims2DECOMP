// audio_bridge.cpp — Minimal Win32 audio playback for Sims 2 PC port
// Uses waveOut API for basic PCM playback. Not production quality —
// just enough to hear sound effects and confirm the audio pipeline works.

#include "audio_bridge.h"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>

#pragma comment(lib, "winmm.lib")

#define MAX_VOICES 16

struct AudioVoice {
    HWAVEOUT hWaveOut;
    WAVEHDR  waveHdr;
    int      active;
};

static AudioVoice g_voices[MAX_VOICES];
static int g_audioInit = 0;

int audio_init(void) {
    memset(g_voices, 0, sizeof(g_voices));
    g_audioInit = 1;
    printf("[AUDIO] Win32 waveOut audio initialized (%d voices)\n", MAX_VOICES);
    return 1;
}

void audio_shutdown(void) {
    for (int i = 0; i < MAX_VOICES; i++) {
        if (g_voices[i].active) {
            waveOutReset(g_voices[i].hWaveOut);
            waveOutUnprepareHeader(g_voices[i].hWaveOut, &g_voices[i].waveHdr, sizeof(WAVEHDR));
            waveOutClose(g_voices[i].hWaveOut);
            g_voices[i].active = 0;
        }
    }
    g_audioInit = 0;
}

static int find_free_voice(void) {
    for (int i = 0; i < MAX_VOICES; i++) {
        if (!g_voices[i].active) return i;
        // Check if a voice has finished playing
        if (g_voices[i].waveHdr.dwFlags & WHDR_DONE) {
            waveOutUnprepareHeader(g_voices[i].hWaveOut, &g_voices[i].waveHdr, sizeof(WAVEHDR));
            waveOutClose(g_voices[i].hWaveOut);
            g_voices[i].active = 0;
            return i;
        }
    }
    return -1;
}

int audio_play_sample(const void* data, int dataSize, int sampleRate, int channels) {
    if (!g_audioInit || !data || dataSize <= 0) return -1;

    int slot = find_free_voice();
    if (slot < 0) return -1;

    AudioVoice* v = &g_voices[slot];

    WAVEFORMATEX wfx = {};
    wfx.wFormatTag = WAVE_FORMAT_PCM;
    wfx.nChannels = (WORD)channels;
    wfx.nSamplesPerSec = (DWORD)sampleRate;
    wfx.wBitsPerSample = 16;
    wfx.nBlockAlign = wfx.nChannels * wfx.wBitsPerSample / 8;
    wfx.nAvgBytesPerSec = wfx.nSamplesPerSec * wfx.nBlockAlign;

    MMRESULT result = waveOutOpen(&v->hWaveOut, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);
    if (result != MMSYSERR_NOERROR) {
        return -1;
    }

    memset(&v->waveHdr, 0, sizeof(WAVEHDR));
    v->waveHdr.lpData = (LPSTR)data;
    v->waveHdr.dwBufferLength = (DWORD)dataSize;

    waveOutPrepareHeader(v->hWaveOut, &v->waveHdr, sizeof(WAVEHDR));
    waveOutWrite(v->hWaveOut, &v->waveHdr, sizeof(WAVEHDR));
    v->active = 1;

    return slot;
}

void audio_stop_voice(int voiceHandle) {
    if (voiceHandle < 0 || voiceHandle >= MAX_VOICES) return;
    AudioVoice* v = &g_voices[voiceHandle];
    if (!v->active) return;

    waveOutReset(v->hWaveOut);
    waveOutUnprepareHeader(v->hWaveOut, &v->waveHdr, sizeof(WAVEHDR));
    waveOutClose(v->hWaveOut);
    v->active = 0;
}

void audio_set_volume(float volume) {
    // waveOut volume: 0x0000 to 0xFFFF per channel
    DWORD vol = (DWORD)(volume * 0xFFFF);
    if (vol > 0xFFFF) vol = 0xFFFF;
    DWORD stereoVol = (vol << 16) | vol;
    waveOutSetVolume(NULL, stereoVol);
}

#else
// Non-Windows fallback
int audio_init(void) { return 0; }
void audio_shutdown(void) {}
int audio_play_sample(const void* data, int dataSize, int sampleRate, int channels) { return -1; }
void audio_stop_voice(int voiceHandle) {}
void audio_set_volume(float volume) {}
#endif // _WIN32
