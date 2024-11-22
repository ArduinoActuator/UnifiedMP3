#ifndef __UNIFIED_MP3_H__
#define __UNIFIED_MP3_H__

#define USE_KT403A_PLAYER
#define USE_WT2003S_PLAYER
#define USE_WT2605C_PLAYER
#define USE_DF_ROBOT_DF_PLAYER_MINI

#include "UnifiedMP3_config.h"

//#include "config.h"

#ifdef USE_KT403A_PLAYER  // Grove - MP3 v2.0  https://wiki.seeedstudio.com/Grove-MP3_v2.0/
#include "KT403A_Player.h"
#endif /* USE_KT403A_PLAYER */

#ifdef USE_WT2003S_PLAYER  // Grove - MP3 v3.0  https://wiki.seeedstudio.com/Grove-MP3-v3/
#include "WT2003S_Player.h"
#endif /* USE_WT2003S_PLAYER */

#ifdef USE_WT2605C_PLAYER  // Grove - MP3 v4.0  https://wiki.seeedstudio.com/grove_mp3_v4/
#include "WT2605C_Player.h"
#endif /* USE_WT2605C_PLAYER */

#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
#include "DFRobotDFPlayerMini.h"
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */

#include <SoftwareSerial.h>

#define UNIFIED_MP3_UNSUPPORTED -1
#define UNIFIED_MP3_SUCCESS      1
#define UNIFIED_MP3_FAIL         0


typedef enum {
  KT403A_PLAYER = 1,
  WT2003S_PLAYER,
  WT2605C_PLAYER,
  DF_ROBOT_DFP_PLAYER_MINI
} UnifiedMp3PlayerType;

typedef enum {
  SD_STORAGE = 1,
  SPI_STORAGE,
  UDISK_STORAGE
} UnifiedMp3PlayerStorage;

typedef enum {
    MP3_MODE_CYCLE        = 0,
    MP3_MODE_SINGLE_CYCLE,
    MP3_MODE_DIR_CYCLE,
    MP3_MODE_RANDOM,
    MP3_MODE_SINGLE_SHOT
} UnifiedMp3PlayerMode;

class UnifiedMP3 {
public:
#ifdef USE_KT403A_PLAYER
  UnifiedMP3(KT403A<SoftwareSerial> * kt403a, UnifiedMp3PlayerType type);
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
  UnifiedMP3(WT2003S<SoftwareSerial> * wt2003s, UnifiedMp3PlayerType type);
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  UnifiedMP3(WT2605C<SoftwareSerial> * wt2605c, UnifiedMp3PlayerType type);
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  UnifiedMP3(DFRobotDFPlayerMini *dfr_player_mini, UnifiedMp3PlayerType type);
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  int stop(void);
  int next(void);
  int previous(void);
  int volume(uint8_t volume);
  int volumeDown(void);
  int volumeUp(void);
  int selectStorage(UnifiedMp3PlayerStorage storage);
  int pause(void);
  int start(void);
  int playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
  int playByName(const char* fileName, UnifiedMp3PlayerMode mode);
  int playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
  int playDirectoryByName(const char* dir, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
  int loopDirectory(int folderNumber);
  int playMp3Directory(int fileNumber);
  int cutInPlay(UnifiedMp3PlayerStorage device, uint32_t index);
  int setEQ(uint8_t eq);

private:
  int setMode(UnifiedMp3PlayerMode mode);
#if defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER)
  UnifiedMp3PlayerStorage _storage_type;
#endif /* USE_WT2003S_PLAYER || USE_WT2605C_PLAYER */
  UnifiedMp3PlayerType _type;
#ifdef USE_KT403A_PLAYER
  KT403A<SoftwareSerial> * _kt403a;
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
  WT2003S<SoftwareSerial> * _wt2003s;
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  WT2605C<SoftwareSerial> * _wt2605c;
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  DFRobotDFPlayerMini * _dfr_player_mini;
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
};

#endif /* __UNIFIED_MP3_H__ */

#if defined(USE_KT403A_PLAYER) || defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER)
#endif /* USE_KT403A_PLAYER || USE_WT2003S_PLAYER || USE_WT2605C_PLAYER */


#ifdef USE_KT403A_PLAYER
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
