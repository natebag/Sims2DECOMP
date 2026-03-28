/* TrackDataReader::JumpToEnd(void) - 0x8011643C - 32 bytes */

struct ERSoundTrackData {
    char _pad[0x14];
    int m_sizeHi;
    int m_sizeLo;
};

struct TrackDataReader {
    ERSoundTrackData* data;
    int offset;

    void JumpToEnd(void);
};

void TrackDataReader::JumpToEnd(void) {
    offset = ((data->m_sizeLo - data->m_sizeHi) >> 2) - 1;
}
