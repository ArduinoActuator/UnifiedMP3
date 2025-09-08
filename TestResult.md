# 動作確認(簡易版)

## 動作確認結果のまとめ





### 共通機能


|機種名|[Grove - MP3 v4.0][GroveMP3v4]|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|-|
|[Arduino Mega 2560][Mega2560]|▲1|◯|
|[Arduino M0 pro][M0Pro]||◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|◯|
|[Arduino Nano 33 IoT][Nano33IoT]||◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]||◯|
|[Ardino MKR Zero][MKRZero]||◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||

- 1 : ボリュームのUPとDOWNは動作するが，数値によるボリューム設定が動かない

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|

### [Grove - MP3 v4.0][GroveMP3v4]専用機能

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|▲1|
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

- 1 : ボリューム設定が動かない

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|

### [DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]専用機能

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## 準備

SD上に以下のようにmp3ファイルを配置する．

### [DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]の場合

```
/-+-01-+-001.mp3
  |    |
  |    +-002.mp3
  |    |
  |    +-003.mp3
  |
  +-02-+-004.mp3
  |    |
  |    +-0999.mp3
  |
  +-MP3-+-0005.mp3
  |
  +-1.mp3
  |
  +-2.mp3
  |
  +-3.mp3
*/
```


### [Grove - MP3 v4.0][GroveMP3v4]の場合
```
/-+-1-+-1.mp3
  |   |
  |   +-2.mp3
  |   |
  |   +-3.mp3
  +-2---4.mp3
  |
  +-MP3-+-5.mp3
  |
  +-1.mp3
  |
  +-2.mp3
  |
  +-3.mp3
*/
```


## API一覧

```
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue next(void);
mp3FunctionReturnValue previous(void);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue volumeDown(void);
mp3FunctionReturnValue volumeUp(void);
mp3FunctionReturnValue selectStorage(UnifiedMp3PlayerStorage storage);
mp3FunctionReturnValue pause(void);
mp3FunctionReturnValue start(void);
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue playByName(const char* fileName, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue playLargeDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber);
mp3FunctionReturnValue playDirectoryByName(const char* dir, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue loopDirectory(int folderNumber);
mp3FunctionReturnValue playMp3Directory(int fileNumber);
mp3FunctionReturnValue cutInPlay(UnifiedMp3PlayerStorage device, uint32_t index);
mp3FunctionReturnValue setEQ(uint8_t eq);
```

```

typedef enum {
  MP3_FUNCTION_UNSUPPORTED = 1,
  MP3_FUNCTION_SUCCESS,
  MP3_FUNCTION_FAIL,
} mp3FunctionReturnValue;


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
```


## 共通



### テスト(1)

#### テスト対象API
```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue pause(void);
mp3FunctionReturnValue start(void);
```

#### 動作
- ボリュームを15に設定
- SDのrootディレクトリ上のファイル番号1のmp3ファイルを再生
- 10秒待つ
- 一時停止
- 10秒待つ
- 再生再開
- 10秒待つ
- 再生終了

#### テスト結果

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|-|
|[Arduino Mega 2560][Mega2560]|▲1|◯|
|[Arduino M0 pro][M0Pro]||◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|◯|
|[Arduino Nano 33 IoT][Nano33IoT]||◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|◯|
|[Ardino MKR Zero][MKRZero]||◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テスト(2)

#### テスト対象API
```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue next(void);
mp3FunctionReturnValue previous(void);
```

#### 動作
- ボリュームを15に設定
- SDのrootディレクトリ上のファイル番号1のmp3ファイルを再生
- 10秒待つ
- 次の曲を再生
- 10秒待つ
- 次の曲を再生
- 10秒待つ
- 前の曲を再生
- 10秒待つ
- 再生終了

#### テスト結果


|機種名|[Grove - MP3 v4.0][GroveMP3v4]|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|-|
|[Arduino Mega 2560][Mega2560]|▲1|◯|
|[Arduino M0 pro][M0Pro]||◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|◯|
|[Arduino Nano 33 IoT][Nano33IoT]||◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|◯|
|[Ardino MKR Zero][MKRZero]||◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|




### テスト(3)

#### テスト対象API
```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue volumeDown(void);
mp3FunctionReturnValue volumeUp(void);
```

#### 動作
- ボリュームを15に設定
- SDのrootディレクトリ上のファイル番号1のmp3ファイルを再生
- ボリュームUPして5秒待つを10回繰り返し
- ボリュームDOWNして5秒待つを10回繰り返し
- 再生終了


#### テスト結果

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|-|
|[Arduino Mega 2560][Mega2560]|▲1|◯|
|[Arduino M0 pro][M0Pro]||◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|◯|
|[Arduino Nano 33 IoT][Nano33IoT]||◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|◯|
|[Ardino MKR Zero][MKRZero]||◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テスト(4-1) : [Grove - MP3 v4.0][GroveMP3v4]の場合

#### テスト対象API
```
mp3FunctionReturnValue playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue volume(uint8_t volume);
```

#### 動作
- SDのrootディレクトリ1番にある4番のファイルを再生
- ボリュームを10に設定
- 10秒待つ
- SDのrootディレクトリ1番にある5番のファイルを再生
- 10秒待つ
- 再生終了


#### テスト結果

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|▲1|
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テスト(4-2) : [DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]の場合

#### テスト対象API
```
mp3FunctionReturnValue playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue volume(uint8_t volume);
```

#### 動作
- ボリュームを15に設定
- SDのrootディレクトリ1番にある1番のファイルを再生
- 10秒待つ
- SDのrootディレクトリ1番にある2番のファイルを再生
- 10秒待つ
- SDのrootディレクトリ2番にある4番のファイルを再生
- 10秒待つ
- 再生終了

#### テスト結果

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## [Grove - MP3 v4.0][GroveMP3v4]専用機能


### テスト(1)

#### テスト対象API
```
mp3FunctionReturnValue playDirectoryByName(const char* dir, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
```

#### 動作

- SDのディレクトリ1番にある4番のファイルを再生
- ボリュームを10に設定
- 10秒待つ
- 再生終了


#### テスト結果

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|▲1|
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



### テスト(2)

#### テスト対象API
```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue cutInPlay(UnifiedMp3PlayerStorage device, uint32_t index);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
```

#### 動作

- SDのrootディレクトリにある1番のファイルを再生
- ボリュームを10に設定
- 20秒待つ
- SDのrootディレクトリにある2番のファイルをcut-inで再生
- 6分待ち (cut-inで再生した曲が終わり，元の曲の再生に戻るのを確認)
- 再生終了


#### テスト結果

|機種名|[Grove - MP3 v4.0][GroveMP3v4]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|▲1|
|[Arduino M0 pro][M0Pro]||
|[Arduino UNO R4 Minima][UnoR4Minima]|▲1|
|[Arduino Nano 33 IoT][Nano33IoT]||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|▲1|
|[Ardino MKR Zero][MKRZero]||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

- 1 : ベンダ提供デバイスドライバの挙動が怪しく，特にボリューム設定がうまくいかない場合が多い

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


## [DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]専用機能


### テスト(1)

#### テスト対象API
```
mp3FunctionReturnValue playLargeDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
```

#### 動作
- ボリュームを20に設定
- SDのディレクトリ("02")にある"0999.mp3"を再生
- 10秒待つ
- 再生終了


#### テスト結果

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|




### テスト(2)

#### テスト対象API
```
mp3FunctionReturnValue playMp3Directory(int fileNumber);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
```

#### 動作
- ボリュームを20に設定
- SDのMP3ディレクトリにある"0005.mp3"を再生
- 10秒待つ
- 再生終了


#### テスト結果

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|



### テスト(3)

#### テスト対象API
```
mp3FunctionReturnValue loopDirectory(int folderNumber);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
```

#### 動作
- ボリュームを20に設定
- SDのディレクトリ"02"をループ再生
- 10分待つ (全曲再生が終わり，1曲目に戻ることを確認)
- 再生終了


#### テスト結果

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|


### テスト(4)

#### テスト対象API
```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
mp3FunctionReturnValue volume(uint8_t volume);
mp3FunctionReturnValue stop(void);
mp3FunctionReturnValue setEQ(uint8_t eq);
```

#### 動作
- ボリュームを20に設定
- SDのrootディレクトリにある1番のファイルを再生
- 30秒待つ
- イコライザの設定を1(Pop)に設定
- 10秒待つ
- イコライザの設定を2(Rock)に設定
- 10秒待つ
- イコライザの設定を3(Jazz)に設定
- 10秒待つ
- イコライザの設定を4(Classic)に設定
- 10秒待つ
- イコライザの設定を5(Bass)に設定
- 10秒待つ
- 再生終了


#### テスト結果

|機種名|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|-|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|▲|一部の機能が動作しない|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|





## テスト環境


|ソフトウェア/Arduinoファミリ|モジュール名|開発元|バージョン|
|---|---|---|---|
|Arduino IDE|－|Arduino|2.3.2|
|AVR|Arduino AVR Boards|Arduino|1.8.6|
|ESP32|Arduino ESP32 Boards|Arduino|2.0.18|
|Giga|Arduino Mbed OS Giga Boards|Arduino|4.3.1|
|Nano|Arduino Mbed OS Nano Boards|Arduino|4.3.1|
|M0|Arduino SAMD Boards (32bits ARM Cortex-M0+)|Arduino|1.8.14|
|UnoR4|Arduino Uno R4 Boards|Arduino|1.4.1|

### コンパイルテスト

|Arduino機種|コンパイル結果|
|---|---|
|[Arduino Nano ESP32][NanoESP32]|✕|
|[Arduino Mega 2560][Mega2560]|◯|
|[Arduino M0 pro][M0Pro]|◯|
|[Arduino UNO R4 Minima][UnoR4Minima]|◯|
|[Arduino Nano 33 IoT][Nano33IoT]|◯|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|◯|
|[Ardino MKR Zero][MKRZero]|◯|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]||

|内容|意味|
|---|---|
|◯|コンパイル成功|
|△|条件付き|
|✕|コンパイルできない|
|-|原理的に互換性がない|
|未|未検証|
<!-- テンプレート


### テスト結果


|機種名|[Grove LED 赤 Arduino用][GroveRedLED]|[Grove - Circular LED][GroveCircularLED]|[Grove - LED Bar][GroveLEDBar]|[RGBフルカラーLED 5mm OSTA5131A カソードコモン][OSTA5131A]|[チェーン接続可能 Grove RGB LED][GroveChainableRGB_Led]|[Grove RGB LED スティック][Grove_RGB_LEDスティック]|
|---|---|---|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|||||||
|[Arduino Mega 2560][Mega2560]|||||||
|[Arduino M0 pro][M0Pro]|||||||
|[Arduino UNO R4 WiFi][UnoR4WiFi]|||||||
|[Arduino UNO R4 Minima][UnoR4Minima]|||||||
|[Arduino Nano 33 IoT][Nano33IoT]|||||||
|[Arduino Giga R1 Wifi][GigaR1WiFi]|||||||
|[Arduino MKR WiFi 1010][MKRWiFi1010]|||||||
|[Ardino MKR Zero][MKRZero]|||||||
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|||||||


|内容|意味|
|---|---|
|◯|動作する|
|△|動作電圧の変換等を行えば動作する|
|✕|動作しない|
|-|原理的に互換性がない|
|未|未検証|
 -->



<!-- MP3プレーヤ -->

|名称|コントローラ|電圧(V)|
|---|---|---|
|[Grove - MP3 v2.0][GroveMP3v2]|KT403A|5|
|[Grove - MP3 v3.0][GroveMP3v3]|WT2003S-20SS|3.3/5|
|[Grove - MP3 v4.0][GroveMP3v4]|WT2605CX|5|
|[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]|DFROBOT LISP3|3.3/5|

<!-- Grove - MP3 v2.0 -->
[GroveMP3v2]:https://wiki.seeedstudio.com/Grove-MP3_v2.0/
<!-- Grove - MP3 v3.0 -->
[GroveMP3v3]:https://wiki.seeedstudio.com/Grove-MP3-v3/
<!-- Grove - MP3 v4.0 -->
[GroveMP3v4]:https://wiki.seeedstudio.com/grove_mp3_v4/
<!-- DFPlayer - A Mini MP3 Player -->
[DFRobotDFPlayerMini]:https://www.dfrobot.com/product-1121.html

<!-- SoftwareSerial Library -->
[SoftwareSerial]:https://docs.arduino.cc/learn/built-in-libraries/software-serial/

<!-- ESP SoftwareSerial Library -->
[EspSoftwareSerial]:https://docs.arduino.cc/libraries/espsoftwareserial/



<!-- Arduino 本体 -->

|機種名|コア|MCU|動作電圧|
|---|---|---|---|
|[Arduino Nano ESP32][NanoESP32]|Xtensa LX6|ESP32-S3|3.3V|
|[Arduino Mega 2560][Mega2560]|AVR|ATmega2560|5V|
|[Arduino M0 pro][M0Pro]|ARM Cortex-M0+|ATSAMD21G18|3.3V|
|[Arduino UNO R4 WiFi][UnoR4WiFi]|ARM Cortex-M4|RA4M1|5V|
|[Arduino UNO R4 Minima][UnoR4Minima]|ARM Cortex-M4|RA4M1|5V|
|[Arduino Nano 33 IoT][Nano33IoT]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Giga R1 Wifi][GigaR1WiFi]|ARM Cortex-M7|STM32H747XI|3.3V|
|[Arduino MKR WiFi 1010][MKRWiFi1010]|ARM Cortex-M0+|SAMD21|3.3V|
|[Ardino MKR Zero][MKRZero]|ARM Cortex-M0+|SAMD21|3.3V|
|[Arduino Nano RP2040 Connect][NanoRP2040Connect]|ARM Cortex-M0+|Raspberry Pi RP2040|3.3V|

<!-- Arduino Nano ESP32 -->
[NanoESP32]:https://docs.arduino.cc/hardware/nano-esp32/
<!--Arduino Mega 2560-->
[Mega2560]:https://docs.arduino.cc/hardware/mega-2560/
<!--Arduino M0 pro-->
[M0Pro]:https://docs.arduino.cc/retired/boards/arduino-m0-pro/
<!--Arduino UNO R4 WiFi-->
[UnoR4WiFi]:https://docs.arduino.cc/hardware/uno-r4-wifi/
<!--Arduino UNO R4 Minima-->
[UnoR4Minima]:https://docs.arduino.cc/hardware/uno-r4-minima/
<!--Arduino Nano 33 IoT-->
[Nano33IoT]:https://docs.arduino.cc/hardware/nano-33-iot/
<!--Arduino Giga R1 Wifi-->
[GigaR1WiFi]:https://docs.arduino.cc/hardware/giga-r1-wifi/
<!--Arduino MKR WiFi 1010-->
[MKRWiFi1010]:https://docs.arduino.cc/hardware/mkr-wifi-1010/
<!--Ardino MKR Zero-->
[MKRZero]:https://docs.arduino.cc/hardware/mkr-zero/
<!--Arduino Nano RP2040 Connect-->
[NanoRP2040Connect]:https://docs.arduino.cc/hardware/nano-rp2040-connect/




<!--- コメント
[Adafruit Unified Sensor Driver][AdafruitUSD]
[Groveシールド][shield]
[Arduino M0 Pro][M0Pro]
[Arduino Due][Due]
[Arduino Uno R3][Uno]
[Arduino Mega2560 R3][Mega]
[Arduino Leonardo Ethernet][LeonardoEth]
[Arduino Pro mini 328 - 3.3V/8MHz][ProMini]
[ESpr one][ESPrOne]
[ESPr one 32][ESPrOne32]
[Grove][Grove]
[Seed Studio][SeedStudio]
[Arduino][Arduino]
[Sparkfun][Sparkfun]
[スイッチサイエンス][SwitchScience]
--->
