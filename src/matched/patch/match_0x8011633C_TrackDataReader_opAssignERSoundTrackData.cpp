/* TrackDataReader::operator=(ERSoundTrackData *) - 0x8011633C - 20 bytes */
/* mr r9, r3; li r0, 0; stw r4, 0(r9); stw r0, 4(r9); blr */

class ERSoundTrackData;

class TrackDataReader {
public:
    ERSoundTrackData* m_trackData;
    int m_index;

    TrackDataReader& operator=(ERSoundTrackData *);
};

TrackDataReader& TrackDataReader::operator=(ERSoundTrackData *data) {
    m_trackData = data;
    m_index = 0;
    return *this;
}
