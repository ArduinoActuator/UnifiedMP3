#include "UnifiedMP3.h"

#ifdef USE_KT403A_PLAYER
UnifiedMP3::UnifiedMP3(KT403A<SoftwareSerial> * kt403a, UnifiedMp3PlayerType type):
  _kt403a(kt403a),
  _type(type)
{
}
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
UnifiedMP3::UnifiedMP3(WT2003S<SoftwareSerial> * wt2003s, UnifiedMp3PlayerType type):
  _wt2003s(wt2003s),
  _type(type)
{
  _storage_type = SD_STORAGE;
}
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
UnifiedMP3::UnifiedMP3(WT2605C<SoftwareSerial> * wt2605c, UnifiedMp3PlayerType type):
  _wt2605c(wt2605c),
  _type(type)
{
  _storage_type = SD_STORAGE;
}
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
UnifiedMP3::UnifiedMP3(DFRobotDFPlayerMini *dfr_player_mini, UnifiedMp3PlayerType type):
  _dfr_player_mini(dfr_player_mini),
  _type(type)
{
}
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */

int UnifiedMP3::stop(void) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->stop();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->stop();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->stop();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->stop();
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::next(void) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->next();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->next();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->next();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->next();
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::previous(void) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->previous();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->previous();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->previous();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->previous();
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::volume(uint8_t vol) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->volume(vol);
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->volume(vol);
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->volume(vol);
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->volume(vol);
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::volumeDown(void) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->volumeDown();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->volumeDown();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->volumeDown();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->volumeDown();
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::volumeUp(void) {
  switch(_type) {
#ifdef USE_KT403A_PLAYER
    case KT403A_PLAYER: {
      uint8_t result = _kt403a->volumeUp();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
    case WT2003S_PLAYER: {
      uint8_t result = _wt2003s->volumeUp();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
    case WT2605C_PLAYER: {
      uint8_t result = _wt2605c->volumeUp();
      if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
    case DF_ROBOT_DFP_PLAYER_MINI: {
      _dfr_player_mini->volumeUp();
      return UNIFIED_MP3_SUCCESS;
    }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::selectStorage(UnifiedMp3PlayerStorage storage) {
#if defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER)
  if ((_type == WT2003S_PLAYER) || (_type == WT2605C_PLAYER)) {
    _storage_type = storage;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER || USE_WT2605C_PLAYER */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::pause(void) {
#ifdef USE_KT403A_PLAYER
  if (_type == KT403A_PLAYER) {
    uint8_t result = _kt403a->pause();
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
  if (_type == WT2003S_PLAYER) {
    _wt2003s->pause_or_play();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  if (_type == WT2605C_PLAYER) {
    _wt2605c->pause_or_play();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  if (_type == DF_ROBOT_DFP_PLAYER_MINI) {
    _dfr_player_mini->pause();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::start(void) {
#ifdef USE_KT403A_PLAYER
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
  if (_type == WT2003S_PLAYER) {
    _wt2003s->pause_or_play();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  if (_type == WT2605C_PLAYER) {
    _wt2605c->pause_or_play();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  if (_type == DF_ROBOT_DFP_PLAYER_MINI) {
    _dfr_player_mini->start();
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::setMode(UnifiedMp3PlayerMode mode) {
#ifdef USE_WT2003S_PLAYER
  uint8_t result;
  switch(mode) {
    case MP3_MODE_SINGLE_SHOT: {
      result = _wt2003s->playMode(SINGLE_SHOT);
      break;
    }
    case MP3_MODE_SINGLE_CYCLE: {
      result = _wt2003s->playMode(SINGLE_CYCLE);
      break;
    }
    case MP3_MODE_CYCLE: {
      result = _wt2003s->playMode(CYCLE);
      break;
    }
    case MP3_MODE_RANDOM: {
      result = _wt2003s->playMode(RANDOM);
      break;
    }
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
  return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  uint8_t wt2605c_result;
  switch(mode) {
    case MP3_MODE_SINGLE_SHOT: {
      wt2605c_result = _wt2605c->playMode(SINGLE_SHOT);
      break;
    }
    case MP3_MODE_SINGLE_CYCLE: {
      wt2605c_result = _wt2605c->playMode(SINGLE_CYCLE);
      break;
    }
    case MP3_MODE_CYCLE: {
      wt2605c_result = _wt2605c->playMode(CYCLE);
      break;
    }
    case MP3_MODE_RANDOM: {
      wt2605c_result = _wt2605c->playMode(RANDOM);
      break;
    }
    case MP3_MODE_DIR_CYCLE: {
      wt2605c_result = _wt2605c->playMode(DIR_CYCLE);
      break;
    }
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
  if (wt2605c_result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
  return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2605C_PLAYER */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::playByIndex(uint32_t index, UnifiedMp3PlayerMode mode) {
#if defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER)
  if ((_type == WT2003S_PLAYER) || (_type == WT2605C_PLAYER)) {
    switch(_storage_type) {
      case SD_STORAGE: {
#ifdef USE_WT2003S_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2003s->playSDRootSong(index);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2605c->playSDRootSong(index);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        //Serial.println("set success********");
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2605C_PLAYER */
      }
      case UDISK_STORAGE: {
#ifdef USE_WT2003S_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2003s->playUDiskRootSong(index);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2605c->playUDiskRootSong(index);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2605C_PLAYER */
      }
      case SPI_STORAGE: {
        uint16_t fileIndex = (uint16_t)index;
#ifdef USE_WT2003S_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2003s->playSPIFlashSong(fileIndex);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
        int modeResult = setMode(mode);
        if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
        uint8_t result;
        result = _wt2605c->playSPIFlashSong(fileIndex);
        if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
        return UNIFIED_MP3_SUCCESS;
#endif /* USE_WT2605C_PLAYER */
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER || USE_WT2605C_PLAYER */
#ifdef USE_KT403A_PLAYER
  if (_type == KT403A_PLAYER) {
    uint16_t fileIndex = (uint16_t)index;
    uint8_t result;
    switch(mode) {
      case MP3_MODE_SINGLE_SHOT: {
        result = _kt403a->playSongMP3(fileIndex);
        break;
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  if (_type == DF_ROBOT_DFP_PLAYER_MINI) {
    int fileIndex = (int)index;
    uint8_t result;
    switch(mode) {
      case MP3_MODE_SINGLE_SHOT: {
        //result = _dfr_player_mini->play(fileIndex);
        _dfr_player_mini->play(fileIndex);
        break;
      }
      case MP3_MODE_SINGLE_CYCLE: {
        //result = _dfr_player_mini->loop(fileIndex);
        _dfr_player_mini->loop(fileIndex);
        break;
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    //if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
}


int UnifiedMP3::playByName(const char* fileName, UnifiedMp3PlayerMode mode){
#ifdef USE_WT2003S_PLAYER
  if (_type == WT2003S_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    uint8_t result;
    switch(_storage_type) {
      case SD_STORAGE: {
        result = _wt2003s->playSDSong(fileName);
      }
      case UDISK_STORAGE: {
        result = _wt2003s->playUDiskSong(fileName);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  if (_type == WT2605C_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    uint8_t result;
    switch(_storage_type) {
      case SD_STORAGE: {
        result = _wt2605c->playSDSong(fileName);
      }
      case UDISK_STORAGE: {
        result = _wt2605c->playUDiskSong(fileName);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2605C_PLAYER */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode){
#ifdef USE_KT403A_PLAYER
  if (_type == KT403A_PLAYER) {
    uint8_t fileIndexNumber = (uint8_t)fileNumber;
    int kt403a_result;
    switch(mode) {
      case MP3_MODE_SINGLE_SHOT: {
        kt403a_result = _kt403a->playSongSpecify(folderNumber, fileIndexNumber);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (kt403a_result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_WT2003S_PLAYER
  if (_type == WT2003S_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    String dirName = String(folderNumber, DEC);
    int len = dirName.length() + 1;
    char result[len];
    dirName.toCharArray(result, len);
    uint8_t wt2003s_result;
    switch(_storage_type) {
      case SD_STORAGE: {
        uint16_t index = (uint16_t) fileNumber;
        wt2003s_result = _wt2003s->playSDDirectorySong(result, index);
      }
      case UDISK_STORAGE: {
        wt2003s_result = _wt2003s->playUDiskDirectorySong(result, fileNumber);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (wt2003s_result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  if (_type == WT2605C_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    String dirName = String(folderNumber, DEC);
    int len = dirName.length() + 1;
    char result[len];
    dirName.toCharArray(result, len);
    uint8_t wt2605c_result;
    switch(_storage_type) {
      case SD_STORAGE: {
        uint16_t index = (uint16_t) fileNumber;
        wt2605c_result = _wt2605c->playSDDirectorySong(result, index);
      }
      case UDISK_STORAGE: {
        wt2605c_result = _wt2605c->playUDiskDirectorySong(result, fileNumber);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (wt2605c_result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2605C_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  if (_type == DF_ROBOT_DFP_PLAYER_MINI) {
    if (mode != MP3_MODE_SINGLE_SHOT) return UNIFIED_MP3_UNSUPPORTED;
    uint16_t fileIndexNumber = (uint16_t)fileNumber;
    _dfr_player_mini->playLargeFolder(folderNumber, fileIndexNumber);
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::playDirectoryByName(const char* dirName, uint32_t fileNumber, UnifiedMp3PlayerMode mode){
#ifdef USE_WT2003S_PLAYER
  if (_type == WT2003S_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    uint8_t result;
    switch(_storage_type) {
      case SD_STORAGE: {
        uint16_t index = (uint16_t) fileNumber;
        result = _wt2003s->playSDDirectorySong(dirName, index);
      }
      case UDISK_STORAGE: {
        result = _wt2003s->playUDiskDirectorySong(dirName, fileNumber);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  if (_type == WT2605C_PLAYER) {
    int modeResult = setMode(mode);
    if (UNIFIED_MP3_SUCCESS != modeResult) return modeResult;
    uint8_t wt2605c_result;
    switch(_storage_type) {
      case SD_STORAGE: {
        uint16_t index = (uint16_t) fileNumber;
        wt2605c_result = _wt2605c->playSDDirectorySong(dirName, index);
      }
      case UDISK_STORAGE: {
        wt2605c_result = _wt2605c->playUDiskDirectorySong(dirName, fileNumber);
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (wt2605c_result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_WT2605C_PLAYER */
  return UNIFIED_MP3_UNSUPPORTED;
}

int UnifiedMP3::loopDirectory(int folderNumber) {
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  _dfr_player_mini->loopFolder(folderNumber);
  return UNIFIED_MP3_SUCCESS;
#else /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
}

int UnifiedMP3::playMp3Directory(int fileNumber) {
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  _dfr_player_mini->playMp3Folder(fileNumber);
  return UNIFIED_MP3_SUCCESS;
#else /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
}

int UnifiedMP3::cutInPlay(UnifiedMp3PlayerStorage device, uint32_t index){
#if defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER)
  uint8_t result;
#ifdef USE_WT2003S_PLAYER
  switch(device) {
    case SD_STORAGE: {
      result = _wt2003s->cutInPlay(SD, index);
      break;
    }
    case SPI_STORAGE: {
      result = _wt2003s->cutInPlay(SPIFLASH, index);
      break;
    }
    case UDISK_STORAGE: {
      result = _wt2003s->cutInPlay(UDISK, index);
      break;
    }
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
#endif /* USE_WT2003S_PLAYER */
#ifdef USE_WT2605C_PLAYER
  switch(device) {
    case SD_STORAGE: {
      result = _wt2605c->cutInPlay(SD, index);
      break;
    }
    case SPI_STORAGE: {
      result = _wt2605c->cutInPlay(SPIFLASH, index);
      break;
    }
    case UDISK_STORAGE: {
      result = _wt2605c->cutInPlay(UDISK, index);
      break;
    }
    default: {
      return UNIFIED_MP3_UNSUPPORTED;
    }
  }
#endif /* USE_WT2605C_PLAYER */
  if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
  return UNIFIED_MP3_SUCCESS;
#else /* defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER) */
  return UNIFIED_MP3_UNSUPPORTED;
#endif /* defined(USE_WT2003S_PLAYER) || defined(USE_WT2605C_PLAYER) */
}

int UnifiedMP3::setEQ(uint8_t eq) {
#ifdef USE_KT403A_PLAYER
  if (_type==KT403A_PLAYER) {
    uint8_t result;
    switch(eq) {
      case 0x00: {
        result = _kt403a->setEqualizer(NORMAL);
        break;
      }
      case 0x01: {
        result = _kt403a->setEqualizer(POP);
        break;
      }
      case 0x02: {
        result = _kt403a->setEqualizer(ROCK);
        break;
      }
      case 0x03: {
        result = _kt403a->setEqualizer(JAZZ);
        break;
      }
      case 0x04: {
        result = _kt403a->setEqualizer(CLASSIC);
        break;
      }
      case 0x05: {
        result = _kt403a->setEqualizer(BASS);
        break;
      }
      default: {
        return UNIFIED_MP3_UNSUPPORTED;
      }
    }
    if (result = (uint8_t) -1) return UNIFIED_MP3_FAIL;
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_KT403A_PLAYER */
#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  if (_type==DF_ROBOT_DFP_PLAYER_MINI) {
    _dfr_player_mini->EQ(eq);
    return UNIFIED_MP3_SUCCESS;
  }
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
  return UNIFIED_MP3_UNSUPPORTED;
}
