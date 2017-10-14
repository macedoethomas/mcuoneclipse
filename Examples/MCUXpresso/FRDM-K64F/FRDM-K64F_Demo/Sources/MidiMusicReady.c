/*
 * MidiMusicMidiReady.c
 *
 *  Created on: 01.01.2015
 *      Author: Erich Styger
 */

#include "Platform.h"
#if PL_HAS_MIDI
#include "Midi.h"
#include "MidiMusic.h"
#include "MidiMusicReady.h"

#define NOF_TRACKS                  2  /* this music has two tracks */
#define NOF_TICKS_PER_QUARTER_NOTE  0x180 /* see http://www.ccarh.org/courses/253/assignment/midifile/ */

uint32_t MMReady_GetTempoUS(void) {
  return 120000; /*???*/
}

int MMReady_GetOffset(void) {
  return -(12+3);
}

static const MIDI_MusicLine track0[] =
{
/* beat,ticks, event,          note,              value */
  {0,  0, MIDI_BANK,      0, 0},
  {0,  0, MIDI_PATCH,     MIDI_INSTR_Default, 0},
  {0,  0, MIDI_PAN,       64, 0},
  {0,  0, MIDI_VOLUME,    127, 0},
  {0,  0, MIDI_NOTE_ON ,  MIDI_NOTE_Fh6, 127},
  {0, 64, MIDI_NOTE_OFF,  MIDI_NOTE_Fh6, 100},
  {0, 96, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {0,160, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {0,192, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {0,256, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {0,288, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {0,352, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {1,  0, MIDI_NOTE_ON ,  MIDI_NOTE_Fh5, 127},
  {1, 64, MIDI_NOTE_OFF,  MIDI_NOTE_Fh5, 100},
  {1, 96, MIDI_NOTE_ON ,  MIDI_NOTE_G5 , 127},
  {1,160, MIDI_NOTE_OFF,  MIDI_NOTE_G5 , 100},
  {1,192, MIDI_NOTE_ON ,  MIDI_NOTE_G5 , 127},
  {1,256, MIDI_NOTE_OFF,  MIDI_NOTE_G5 , 100},
  {1,288, MIDI_NOTE_ON ,  MIDI_NOTE_G5 , 127},
  {1,352, MIDI_NOTE_OFF,  MIDI_NOTE_G5 , 100},
  {2,  0, MIDI_NOTE_ON ,  MIDI_NOTE_Fh4, 127},
  {2, 64, MIDI_NOTE_OFF,  MIDI_NOTE_Fh4, 100},
  {2, 96, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {2,160, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {2,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {2,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {2,288, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {2,352, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {3,192, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {3,256, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {3,288, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {3,352, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {4,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {4, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {4, 96, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {4,160, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {4,288, MIDI_NOTE_ON ,  MIDI_NOTE_E6 , 127},
  {4,352, MIDI_NOTE_OFF,  MIDI_NOTE_E6 , 100},
  {5, 96, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {5,160, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {5,192, MIDI_NOTE_ON ,  MIDI_NOTE_E6 , 127},
  {5,256, MIDI_NOTE_OFF,  MIDI_NOTE_E6 , 100},
  {6,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G6 , 127},
  {6, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G6 , 100},
  {6, 96, MIDI_NOTE_ON ,  MIDI_NOTE_A6 , 127},
  {6,160, MIDI_NOTE_OFF,  MIDI_NOTE_A6 , 100},
  {6,192, MIDI_NOTE_ON ,  MIDI_NOTE_E6 , 127},
  {6,256, MIDI_NOTE_OFF,  MIDI_NOTE_E6 , 100},
  {6,288, MIDI_NOTE_ON ,  MIDI_NOTE_E6 , 127},
  {6,352, MIDI_NOTE_OFF,  MIDI_NOTE_E6 , 100},
  {7,  0, MIDI_NOTE_ON ,  MIDI_NOTE_E6 , 127},
  {7, 64, MIDI_NOTE_OFF,  MIDI_NOTE_E6 , 100},
  {7,192, MIDI_NOTE_ON ,  MIDI_NOTE_D6 , 127},
  {7,256, MIDI_NOTE_OFF,  MIDI_NOTE_D6 , 100},
  {7,288, MIDI_NOTE_ON ,  MIDI_NOTE_C6 , 127},
  {7,352, MIDI_NOTE_OFF,  MIDI_NOTE_C6 , 100},
  {8, 96, MIDI_NOTE_ON ,  MIDI_NOTE_Ch6, 127},
  {8,160, MIDI_NOTE_OFF,  MIDI_NOTE_Ch6, 100},
  {8,288, MIDI_NOTE_ON ,  MIDI_NOTE_G5 , 127},
  {8,352, MIDI_NOTE_OFF,  MIDI_NOTE_G5 , 100},
  {9, 96, MIDI_NOTE_ON ,  MIDI_NOTE_Ch6, 127},
  {9,160, MIDI_NOTE_OFF,  MIDI_NOTE_Ch6, 100},
  {9,192, MIDI_NOTE_ON ,  MIDI_NOTE_G5 , 127},
  {9,256, MIDI_NOTE_OFF,  MIDI_NOTE_G5 , 100},
  {10,  0, MIDI_NOTE_ON,   MIDI_NOTE_Ch6, 127},
  {10, 64, MIDI_NOTE_OFF,  MIDI_NOTE_Ch6, 100},
  {10,192, MIDI_NOTE_ON ,  MIDI_NOTE_D6 , 127},
  {10,256, MIDI_NOTE_OFF,  MIDI_NOTE_D6 , 100},
  {10,288, MIDI_NOTE_ON ,  MIDI_NOTE_D6 , 127},
  {10,352, MIDI_NOTE_OFF,  MIDI_NOTE_D6 , 100},
  {11,  0, MIDI_NOTE_ON ,  MIDI_NOTE_D6 , 127},
  {11,256, MIDI_NOTE_OFF,  MIDI_NOTE_D6 , 100},
  {11,256, MIDI_END_OF_TRACK, 0,  0}
};

static const MIDI_MusicLine track1[] =
{
/* beat,ticks, event,          note,              value */
  {0,  0, MIDI_BANK,      0, 0},
  {0,  0, MIDI_PATCH ,    MIDI_INSTR_Default, 0},
  {0,  0, MIDI_PAN,       64,                  0},
  {0,  0, MIDI_VOLUME,    127,                 0},
  {3,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {3,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {3,288, MIDI_NOTE_ON ,  MIDI_NOTE_A4 , 127},
  {3,352, MIDI_NOTE_OFF,  MIDI_NOTE_A4 , 100},
  {4,  0, MIDI_NOTE_ON ,  MIDI_NOTE_B4 , 127},
  {4, 64, MIDI_NOTE_OFF,  MIDI_NOTE_B4 , 100},
  {4, 96, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {4,160, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {4,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {4,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {4,288, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {4,352, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {5,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {5, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {5, 96, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {5,160, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {5,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {5,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {5,288, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {5,352, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {6,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {6, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {6, 96, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {6,160, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {6,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {6,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {6,288, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {6,352, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {7,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {7, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {7, 96, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {7,160, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {7,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {7,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {7,288, MIDI_NOTE_ON ,  MIDI_NOTE_C5 , 127},
  {7,352, MIDI_NOTE_OFF,  MIDI_NOTE_C5 , 100},
  {8,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {8, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {8, 96, MIDI_NOTE_ON ,  MIDI_NOTE_Ah4, 127},
  {8,160, MIDI_NOTE_OFF,  MIDI_NOTE_Ah4, 100},
  {8,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {8,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {8,288, MIDI_NOTE_ON ,  MIDI_NOTE_Ah4, 127},
  {8,352, MIDI_NOTE_OFF,  MIDI_NOTE_Ah4, 100},
  {9,  0, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {9, 64, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {9, 96, MIDI_NOTE_ON ,  MIDI_NOTE_Ah4, 127},
  {9,160, MIDI_NOTE_OFF,  MIDI_NOTE_Ah4, 100},
  {9,192, MIDI_NOTE_ON ,  MIDI_NOTE_G4 , 127},
  {9,256, MIDI_NOTE_OFF,  MIDI_NOTE_G4 , 100},
  {9,288, MIDI_NOTE_ON ,  MIDI_NOTE_Ah4, 127},
  {9,352, MIDI_NOTE_OFF,  MIDI_NOTE_Ah4, 100},
  {10,  0, MIDI_NOTE_ON,  MIDI_NOTE_G4,  127},
  {10, 64, MIDI_NOTE_OFF, MIDI_NOTE_G4,  100},
  {10, 96, MIDI_NOTE_ON , MIDI_NOTE_B4,  127},
  {10,160, MIDI_NOTE_OFF, MIDI_NOTE_B4,  100},
  {10,192, MIDI_NOTE_ON , MIDI_NOTE_G4,  127},
  {10,256, MIDI_NOTE_OFF, MIDI_NOTE_G4,  100},
  {10,288, MIDI_NOTE_ON , MIDI_NOTE_B4,  127},
  {10,352, MIDI_NOTE_OFF, MIDI_NOTE_B4,  100},
  {11,  0, MIDI_NOTE_ON , MIDI_NOTE_G4,  127},
  {11,256, MIDI_NOTE_OFF, MIDI_NOTE_G4,  100},
  {11,256, MIDI_END_OF_TRACK, 0,  0}
};

uint8_t MMReady_NofTracks(void) {
  return NOF_TRACKS;
}

uint8_t MMReady_GetMidiMusicInfo(MIDI_MusicTrack *tracks, uint8_t nofTracks) {
  if (nofTracks<NOF_TRACKS) {
    return ERR_OVERFLOW; /* not enough tracks available */
  }
  tracks[0].lines = &track0[0];
  tracks[0].nofLines = sizeof(track0)/sizeof(track0[0]);
  tracks[0].currLine = 0;
  tracks[0].nofTicksPerQuarterNote = NOF_TICKS_PER_QUARTER_NOTE;
  tracks[1].lines = &track1[0];
  tracks[1].nofLines = sizeof(track1)/sizeof(track1[0]);
  tracks[1].currLine = 0;
  tracks[1].nofTicksPerQuarterNote = NOF_TICKS_PER_QUARTER_NOTE;
  return ERR_OK;
}

#endif /* PL_HAS_MIDI */
