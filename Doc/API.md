# API

```
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

## クラスオブジェクトの作成と初期化

MP3プレーヤーとArduino間は，シリアルで通信するデバイスばかりなので，ハードウェアシリアルが2つ以上あるArduinoの機種以外は
ソフトウェアシリアルを利用して，MP3プレーヤーとArduino本体間を接続する必要がある．


一般的に，ハードウェアシリアルはArduinoのコンソールとして利用するので，MP3プレーヤーとの接続は，ソフトウェアシリアルを使う場合が
多くなる．以下の事例では，ソフトウェアシリアルを使うという前提で説明する．


[DFPlayer - A Mini MP3 Player (DFROBOT LISP3)][DFRobotDFPlayerMini]と
Arduino MegaやMega2560の組合せで利用する場合，使えるピン番号に制限があるため，
[Software serialライブラリ][SoftwareSerial]の説明を参照して，
利用するピン番号を決める必要がある．

```
Mega and Mega 2560 boards support change interrupts, so only the following can be used for RX: 10, 11, 12, 13, 14, 15, 50, 51, 52, 53, A8 (62), A9 (63), A10 (64), A11 (65), A12 (66), A13 (67), A14 (68), A15 (69). Not all pins on the Leonardo and Micro boards support change interrupts, so only the following can be used for RX: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
```

また，ESP32を搭載した機種を用いる場合は，ソフトウェアシリアルのライブラリとして，[EspSoftwareSerialライブラリ][EspSoftwareSerial]を
利用する必要がある．


なお，初期化の手順としては，
各デバイスのデバイスドライバを利用して，プレーヤーのクラスオブジェクトを作成し，
そのオブジェクトを利用して，本APIのクラスオブジェクトを生成する．

### [Grove - MP3 v2.0 (KT403A)][GroveMP3v2]の場合

#### グローバル定義
```
SoftwareSerial kt403aSerial(2, 3); // RX, TX

KT403A<HardwareSerial> kt403a_player;

UnifiedMP3( &kt403a_player, KT403A_PLAYER);
```

#### ``setup()``内で実行
```
kt403aSerial.begin(9600);
kt403a_player.init(kt403aSerial);

```


### [Grove - MP3 v3.0 (|WT2003S-20SS)][GroveMP3v3]の場合

#### グローバル定義
```
SoftwareSerial wt2003sSerial(2, 3); // RX, TX

KT403A<HardwareSerial> wt2003s_player;

UnifiedMP3( &wt2003s_player, WT2003S_PLAYER);
```

#### ``setup()``内で実行
```
wt2003sSerial.begin(9600);
wt2003s_player.init(wt2003sSerial);
```


### [Grove - MP3 v4.0 (WT2605CX)][GroveMP3v4]の場合

#### グローバル定義
```
SoftwareSerial wt2605cSerial(2, 3); // RX, TX

WT2605C<SoftwareSerial> wt2605c_player;

UnifiedMP3 wt2605c(&wt2605c_player, WT2605C_PLAYER);
```

#### ``setup()``内で実行
```
wt2605cSerial.begin(115200);
wt2605c_player.init(wt2605cSerial);
```

### [DFPlayer - A Mini MP3 Player (DFROBOT LISP3)][DFRobotDFPlayerMini]の場合

#### グローバル定義
```
SoftwareSerial dfpSerial(/*rx =*/4, /*tx =*/5);

DFRobotDFPlayerMini myDFPlayer;

UnifiedMP3 dfplayer(&myDFPlayer, DF_ROBOT_DFP_PLAYER_MINI);
```


#### ``setup()``内で実行
```
  dfpSerial.begin(9600);
  if (!myDFPlayer.begin(dfpSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
```



## 再生停止
音楽再生を停止する．

```
mp3FunctionReturnValue stop(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 次の曲を再生
現在再生中の音楽/音声の次の音楽/音声を再生する．
再生している音楽/音声が格納されているストレージのファイルシステムにおける各ファイルの番号順に従って次の曲が選ばれる．

```
mp3FunctionReturnValue next(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 直前の曲を再生
現在再生中の音楽/音声の前の音楽/音声を再生する．
再生している音楽/音声が格納されているストレージのファイルシステムにおける各ファイルの番号順に従って次の曲が選ばれる．

```
mp3FunctionReturnValue previous(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生開始
音楽/音声の再生を開始
```
mp3FunctionReturnValue start(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生一時停止
音楽/音声の再生を一時停止
```
mp3FunctionReturnValue pause(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)



## ボリューム設定
ボリューム(音量)を引数の値に設定する．

```
mp3FunctionReturnValue volume(uint8_t volume);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)


## ボリュームダウン
音量を1段階下げる

```
mp3FunctionReturnValue volumeDown(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)


## ボリュームアップ
音量を1段階上げる

```
mp3FunctionReturnValue volumeUp(void);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## ストレージの選択

MP3プレーヤーの機種のうち，[Grove - MP3 v3.0][GroveMP3v3]と[Grove - MP3 v4.0][GroveMP3v4]はいろいろな種類の外部ストレージが接続できる．．その場合に，
どの種類のストレージを利用するかを選択する．

```
mp3FunctionReturnValue selectStorage(UnifiedMp3PlayerStorage storage);
```
引数は以下の``enum``から選択する．
```
typedef enum {
  SD_STORAGE = 1,
  SPI_STORAGE,
  UDISK_STORAGE
} UnifiedMp3PlayerStorage;
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生する音楽/音声の選択を番号で行う
音楽/音声ファイルを選択するのに，ストレージのファイルシステムの管理番号で行う．

```
mp3FunctionReturnValue playByIndex(uint32_t index, UnifiedMp3PlayerMode mode);
```

引数として，下の``enum``の値を用いて，再生方法を指定するが，ランダム再生や，1曲を繰り返すなどを選択できる．
```
typedef enum {
    MP3_MODE_CYCLE        = 0,
    MP3_MODE_SINGLE_CYCLE,
    MP3_MODE_DIR_CYCLE,
    MP3_MODE_RANDOM,
    MP3_MODE_SINGLE_SHOT
} UnifiedMp3PlayerMode;
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生する音楽/音声の選択をファイル名で行う
[Grove - MP3 v3.0][GroveMP3v3]と[Grove - MP3 v4.0][GroveMP3v4]限定の機能で，音楽/音声ファイルをファイル名で選択する．
ただし，手持ちの装置では動作しない．

```
mp3FunctionReturnValue playByName(const char* fileName, UnifiedMp3PlayerMode mode);
```

引数として，下の``enum``の値を用いて，再生方法を指定するが，ランダム再生や，1曲を繰り返すなどを選択できる．
```
typedef enum {
    MP3_MODE_CYCLE        = 0,
    MP3_MODE_SINGLE_CYCLE,
    MP3_MODE_DIR_CYCLE,
    MP3_MODE_RANDOM,
    MP3_MODE_SINGLE_SHOT
} UnifiedMp3PlayerMode;
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生する音楽/音声の選択をディレクトリの番号で行う
音楽/音声ファイルを選択するのに，ファイルが格納されているディレクトリとファイルの，ストレージにおけるファイルシステムの管理番号で行う．
[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]の場合，ファイルの番号は1から255の値にする必要がある．
```
mp3FunctionReturnValue playDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
```

引数として，下の``enum``の値を用いて，再生方法を指定するが，ランダム再生や，1曲を繰り返すなどを選択できる．
```
typedef enum {
    MP3_MODE_CYCLE        = 0,
    MP3_MODE_SINGLE_CYCLE,
    MP3_MODE_DIR_CYCLE,
    MP3_MODE_RANDOM,
    MP3_MODE_SINGLE_SHOT
} UnifiedMp3PlayerMode;
```

なお，[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]でこの機能を使う場合，ディレクトリの番号を引数で``1``と指定する場合，実際のファイルシステム上のディレクトリ名は「``01``」
になっている必要があり，ファイルの指定を``2``とする場合，実際のファイルシステム上のファイル名は「``01/002.mp3``」に
なっていなければならない．

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)


## 再生する音楽/音声の選択をディレクトリの番号で行う(その2)
[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]専用の機能で，1つのディレクトリに多量(255以上)のmp3ファイルが
存在する場合に利用する機能．そのかわりに，ディレクトリの番号は1から10の間にする必要がある．

```
mp3FunctionReturnValue playLargeDirectoryByNumber(uint8_t folderNumber, uint32_t fileNumber);
```

ディレクトリの番号を引数で``1``と指定する場合，実際のファイルシステム上のディレクトリ名は「``01``」
になっている必要があり，ファイルの指定を``2``とする場合，実際のファイルシステム上のファイル名は「``01/0002.mp3``」に
なっていなければならない．

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## 再生する音楽/音声の選択をディレクトリの名前で行う
[Grove - MP3 v3.0][GroveMP3v3]と[Grove - MP3 v4.0][GroveMP3v4]限定の機能で音楽/音声ファイルを選択するのに，ファイルが格納されているディレクトリとファイルの名前で行う．

```
mp3FunctionReturnValue playDirectoryByName(const char* fileNumber, uint32_t dirNumber, UnifiedMp3PlayerMode mode);
```

引数として，下の``enum``の値を用いて，再生方法を指定するが，ランダム再生や，1曲を繰り返すなどを選択できる．
```
typedef enum {
    MP3_MODE_CYCLE        = 0,
    MP3_MODE_SINGLE_CYCLE,
    MP3_MODE_DIR_CYCLE,
    MP3_MODE_RANDOM,
    MP3_MODE_SINGLE_SHOT
} UnifiedMp3PlayerMode;
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

本来，下のようなAPIになるはずだが，Seeed Studio提供のデバイスドライバに誤りがあり，
ファイル番号とディレクトリ名を逆にして装置に送っているため，番号とディレクトリ名が逆になってしまう．

```
mp3FunctionReturnValue playDirectoryByName(const char* dir, uint32_t fileNumber, UnifiedMp3PlayerMode mode);
```

## あるディレクトリに格納されている音楽/音声を繰り返し再生する．
[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]で，ディレクトリの指定方法はファイルシステムにおける対象ディレクトリの管理番号を指定する．
```
mp3FunctionReturnValue loopDirectory(int folderNumber);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

この機能も，実際のファイルシステムのディレクトリ名は「数字二桁(01とか02)」にする必要がある．

## MP3ディレクトリ内の音楽/音声を特定のファイルを再生
[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]では，ストレージ内の「MP3」ディレクトリ内の特定の曲を再生する機能がある．
このAPIはそれに対応している．
ファイルの指定は，ファイルシステムの管理番号で行う．
```
mp3FunctionReturnValue playMp3Directory(int fileNumber);
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

引数(``fileNumber``)の値として``5``を指定する場合，実際のファイルシステム上のファイル名は「``0005.mp3``(数字4桁)」になっている必要がある．

## カットイン再生
[Grove - MP3 v3.0][GroveMP3v3]と[Grove - MP3 v4.0][GroveMP3v4]にはカットイン再生の機能がある．
カットイン再生する対象ファイルの指定は，ストレージ種類とファイルシステムの管理番号で行う．
```
mp3FunctionReturnValue cutInPlay(UnifiedMp3PlayerStorage device, uint32_t index);
```
ストレージ種類の選択は以下の``enum``の値を用いる．

```
typedef enum {
  SD_STORAGE = 1,
  SPI_STORAGE,
  UDISK_STORAGE
} UnifiedMp3PlayerStorage;
```

- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)

## イコライザの設定
[Grove - MP3 v2.0][GroveMP3v2]と[DFPlayer - A Mini MP3 Player][DFRobotDFPlayerMini]には，イコライザの機能があるため，それを利用するインターフェイス．

```
mp3FunctionReturnValue setEQ(uint8_t eq);
```

引数の値とイコライザの効果の対応関係は以下表の通り．
|値|効果|
|---|---|
|0|NORMAL|
|1|POP|
|2|ROCK|
|3|JAZZ|
|4|CLASSIC|
|5|BASS|


- 返り値 : MP3_FUNCTION_SUCCESS(成功), MP3_FUNCTION_FAIL(失敗), MP3_FUNCTION_UNSUPPORTED(未サポート)


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
