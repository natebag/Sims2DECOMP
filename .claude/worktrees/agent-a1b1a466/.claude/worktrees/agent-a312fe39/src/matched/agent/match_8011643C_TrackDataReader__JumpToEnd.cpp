// 0x8011643C (32 bytes)
struct ERSoundTrackData {
    char _pad[0x14];
    int* m_commands;
    int* m_commandsEnd;
};

class TrackDataReader {
public:
    ERSoundTrackData* m_data;
    int m_pos;

    void JumpToEnd();
};

void TrackDataReader::JumpToEnd() {
    register ERSoundTrackData* data __asm__("r11") = m_data;
    __asm__ __volatile__("" : "+r"(data));
    register int* start __asm__("r0") = data->m_commands;
    register int* end __asm__("r9") = data->m_commandsEnd;
    __asm__ __volatile__("" : "+r"(start), "+r"(end));
    m_pos = (end - start) - 1;
}
