
/*
 * NanoやMKRをClassic (UNO)のシールドを使えるようにするための変換基板を使うか否かの選択
 */
#define USE_CONVERTER

/*
 * デバイスの選択
 */

#define USE_DF_ROBOT_DF_PLAYER_MINI


/*
/-+-01-+-001.mp3  東京事変
  |    |
  |    +-002.mp3
  |    |
  |    +-003.mp3
  |
  +-02-+-004.mp3    Sting
  |    |
  |    +-0999.mp3   Police
  |
  +-MP3-+-0005.mp3  Hall and Oats
  |
  +-1.mp3 Shade
  |
  +-2.mp3
  |
  +-3.mp3
*/


#include "detectArduinoHardware.h"

#ifdef USE_CONVERTER
#include "ArduinoShieldConverter.h"
#endif /* USE_CONVERTER */

#include "UnifiedMP3.h"

/* Mega 2560 */
#if CPU_ARCH == AVR_ARCH
  #include <SoftwareSerial.h>
  SoftwareSerial SSerial(10, 11); // RX, TX
  #define COMSerial SSerial
  #define ShowSerial Serial
  #define _SET_SERIALS_
  #define _SOFTWARE_SERIAL_
#endif /* CPU_ARCH == AVR_ARCH */

/* Uno R4 Series */
#if CPU_ARCH==RA4_ARCH
  #define COMSerial Serial1 // 0/RX, 1/TX
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* CPU_ARCH == RA4_ARCH */

/* Nano RP2040 connect */
#if HARDWARE_TYPE==ARDUINO_NANO_RP2040_C
  #define COMSerial Serial1
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* HARDWARE_TYPE==ARDUINO_NANO_RP2040_C */

/* Nano ESP32 */
#if HARDWARE_TYPE==ARDUINO_NANO_ESP32_S3
  #include <SoftwareSerial.h>
  SoftwareSerial SSerial(2, 3); // RX, TX
  #define COMSerial SSerial
  #define ShowSerial Serial
//  #define COMSerial Serial1  // D9/RX, D8/TX
//  #define ShowSerial Serial
  #define _SET_SERIALS_
  #define _SOFTWARE_SERIAL_
#endif /* HARDWARE_TYPE==ARDUINO_NANO_ESP32_S3 */

/* Arduino M0 pro */
#if HARDWARE_TYPE==ARDUINO_M0
  #define COMSerial Serial1 // 0/RX, 1/TX
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* HARDWARE_TYPE==ARDUINO_M0 */

/* Arduino MKR Series */
#if (CPU_TYPE==TYPE_SAMD21G18A) && ( FORM_FACTOR_TYPE==FORM_FACTOR_MKR)
  #define COMSerial Serial1  // 13/RX, 14/TX
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* (CPU_TYPE==TYPE_SAMD21G18A) && ( FORM_FACTOR_TYPE==FORM_FACTOR_MKR) */

/* Nano 33 IoT */
#if HARDWARE_TYPE==ARDUINO_NANO_33_IOT
  #define COMSerial Serial1
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* HARDWARE_TYPE==ARDUINO_NANO_33_IOT */

/* Arduino Giga */
#if (HARDWARE_TYPE==ARDUINO_GIGA_WIFI_MAIN) || (HARDWARE_TYPE==ARDUINO_GIGA_WIFI_SUB)
  #define COMSerial Serial1 // D19/RX, D18/TX
  #define ShowSerial Serial
  #define _SET_SERIALS_
#endif /* (HARDWARE_TYPE==ARDUINO_GIGA_WIFI_MAIN) || (HARDWARE_TYPE==ARDUINO_GIGA_WIFI_SUB) */

#ifndef _SET_SERIALS_
#error "no serail information defined"
#endif /* _SET_SERIALS_ */

#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
#define COMSERIAL_SPEED 9600
DFRobotDFPlayerMini myDFPlayer;
UnifiedMP3 Mp3Player(&myDFPlayer, DF_ROBOT_DFP_PLAYER_MINI);
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */

#define MAX_BUFF_SIZE 256
#define MAX_TEST 4
struct testResultEntity {
  bool result;
  char about[MAX_BUFF_SIZE];
  char comment[MAX_BUFF_SIZE];
} testResult[MAX_TEST];


void printStartMessage(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
  }
  sprintf(message,"Wait for start test No.%d (%s)",testNumber+1, about.c_str());
  ShowSerial.println(message);
}

void waitForStart(void){
  ShowSerial.print("Please press Enter key to start test : ");
  int count =0;
  while (true) {
    if (ShowSerial.available() > 0) {
      char input = ShowSerial.read();
      if (input == '\n') {
        break;
      } else {
        ShowSerial.print(input);
      }
    }
  }
  ShowSerial.println("");
}

void checkTestResult(String about, uint8_t testNumber){
  char message[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE ; i++ ){
    message[i]=0;
    testResult[testNumber].about[i]=0;
    testResult[testNumber].comment[i]=0;
  }
  sprintf(message,"Please input the failure of test No.%d (%s), if the test is succeeded, press Enter : ",testNumber+1, about.c_str());
  sprintf(testResult[testNumber].about,"%s", about.c_str());
  testResult[testNumber].result = true;
  ShowSerial.print(message);
  int count =0;
  while (true) {
    if (ShowSerial.available() > 0) {
      char input = ShowSerial.read();
      if ((input != -1) && (input != '\n')) {
        testResult[testNumber].comment[count]=input;
        testResult[testNumber].result = false;
        count++;
        ShowSerial.print(input);
      }
      if ((count == MAX_BUFF_SIZE-2) || (input == '\n')) break;
    }
  }
  ShowSerial.println("");
}

void sumTestResult(void){
  int count = 0;
  ShowSerial.println("======== summary of tests ========");
  for (int i=0 ; i<MAX_TEST ; i++ ) {
    char message[MAX_BUFF_SIZE];
    for (int i=0; i<MAX_BUFF_SIZE; i++) {
      message[i]=0;
    }
    if (testResult[i].result) {
      sprintf(message,"Test result of test No.%d (%s) : Success.",i+1, testResult[i].about);
    } else {
      count++;
      sprintf(message,"Test result of test No.%d (%s) : %s",i+1, testResult[i].about, testResult[i].comment);
    }
    ShowSerial.println(message);
  }
  ShowSerial.println("");
  char finalMessage[MAX_BUFF_SIZE];
  for (int i=0; i<MAX_BUFF_SIZE; i++) {
    finalMessage[i]=0;
  }
  sprintf(finalMessage, "Test result : all(%d) , success(%d) , fail(%d)", MAX_TEST, MAX_TEST-count, count);
  ShowSerial.println(finalMessage);
  ShowSerial.println("");
}

enum functionList {
  FUNCTION_STOP = 0,
  FUNCTION_NEXT,
  FUNCTION_PREVIOUS,
  FUNCTION_VOLUME,
  FUNCTION_VOLUME_DOWN,
  FUNCTION_VOLUME_UP,
  FUNCTION_SELECT_STORAGE,
  FUNCTION_PAUSE,
  FUNCTION_START,
  FUNCTION_PLAY_BY_INDEX,
  FUNCTION_PLAY_BY_NAME,
  FUNCTION_PLAY_DIR_BY_NUMBER,
  FUNCTION_PLAY_LARGE_DIR_BY_NUMBER,
  FUNCTION_PLAY_DIR_BY_NAME,
  FUNCTION_LOOP_DIR,
  FUNCTION_PLAY_MP3_DIR,
  FUNCTION_CUT_IN_PLAY,
  FUNCTION_SET_EQ
};

String functionName[FUNCTION_SET_EQ+1] = {
  "stop()",
  "next()",
  "previous()",
  "volume()",
  "volumeDown()",
  "volumeUp()",
  "selectStorage()",
  "pause()",
  "start()",
  "playByIndex()",
  "playByName()",
  "playDirectoryByNumber()",
  "playLargeDirectoryByNumber()",
  "playDirectoryByName()",
  "loopDirectory()",
  "playMp3Directory()",
  "cutInPlay()",
  "setEQ()"
};

void checkReturnValue(mp3FunctionReturnValue val, uint8_t funcType) {
  char buff[MAX_BUFF_SIZE];
  memset(buff,0,MAX_BUFF_SIZE);
  if (val == MP3_FUNCTION_UNSUPPORTED) {
    ShowSerial.println("");
    sprintf(buff,"executed function \"%s\" is unsupported.",functionName[funcType].c_str());
    ShowSerial.println(buff);
    return;
  }
  if (val == MP3_FUNCTION_FAIL) {
    ShowSerial.println("");
    sprintf(buff,"executed function \"%s\" is failed.",functionName[funcType].c_str());
    ShowSerial.println(buff);
    return;
  }
}

void test1() {
  String about = "test1";
  printStartMessage(about, 0);
  // テスト内容の説明
  ShowSerial.println("=== action ==="); // playLargeDirectoryByNumber() dfplayer only
  ShowSerial.println("play file num 999 of dir num 2");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("stop");

  ShowSerial.println("");
  waitForStart();
  ShowSerial.println("start : test1");

  mp3FunctionReturnValue value;

  ShowSerial.println("set volume : 20");
  value = Mp3Player.volume(20);
  checkReturnValue(value,FUNCTION_VOLUME);
  ShowSerial.println("play file num 999 of dir num 2");
  value = Mp3Player.playLargeDirectoryByNumber(2,999);
  checkReturnValue(value,FUNCTION_PLAY_LARGE_DIR_BY_NUMBER);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("stop");
  value = Mp3Player.stop();
  checkReturnValue(value,FUNCTION_STOP);

  checkTestResult(about, 0);
  ShowSerial.println("");
  ShowSerial.println("");
}


void test2() {
  String about = "test2";
  printStartMessage(about, 1);
  // テスト内容の説明
  ShowSerial.println("=== action ==="); // playMp3Directory() dfplayer only
  ShowSerial.println("play num 5 of mp3 dir");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("stop");

  ShowSerial.println("");
  waitForStart();
  ShowSerial.println("start : test2");

  mp3FunctionReturnValue value;

  ShowSerial.println("set volume : 20");
  value = Mp3Player.volume(20);
  checkReturnValue(value,FUNCTION_VOLUME);
  ShowSerial.println("play file num 5 of MP3 dir");
  value = Mp3Player.playMp3Directory(5);
  checkReturnValue(value,FUNCTION_PLAY_MP3_DIR);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("stop");
  value = Mp3Player.stop();
  checkReturnValue(value,FUNCTION_STOP);

  checkTestResult(about, 1);
  ShowSerial.println("");
  ShowSerial.println("");
}

void test3() {
  String about = "test3";
  printStartMessage(about, 2);
  // テスト内容の説明

  ShowSerial.println("=== 8th action ==="); // loopDirectory() dfplayer only
  ShowSerial.println("loop play dir num 2");
  ShowSerial.println("wait 10 min");
  ShowSerial.println("stop");
  ShowSerial.println("");
  waitForStart();
  ShowSerial.println("start : test3");

  mp3FunctionReturnValue value;

  ShowSerial.println("set volume : 20");
  value = Mp3Player.volume(20);
  checkReturnValue(value,FUNCTION_VOLUME);
  ShowSerial.println("loop play dir num 2");
  value = Mp3Player.loopDirectory(2);
  checkReturnValue(value,FUNCTION_LOOP_DIR);
  ShowSerial.println("wait 10 min");
  delay(600000);
  ShowSerial.println("stop");
  value = Mp3Player.stop();
  checkReturnValue(value,FUNCTION_STOP);

  checkTestResult(about, 2);
  ShowSerial.println("");
  ShowSerial.println("");
}

void test4() {
  String about = "test4";
  printStartMessage(about, 3);
  // テスト内容の説明
  ShowSerial.println("=== action ==="); // setEQ() dfplayer only , EQ0/1/2/3/4/5    Normal/Pop/Rock/Jazz/Classic/Bass
  ShowSerial.println("play num 1 of root directory");
  ShowSerial.println("wait 30 sec");
  ShowSerial.println("setEQ(1) Pop");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("setEQ(2) Rock");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("setEQ(3) Jazz");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("setEQ(4) Classic");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("setEQ(5) Bass");
  ShowSerial.println("wait 10 sec");
  ShowSerial.println("stop");
  ShowSerial.println("");
  waitForStart();
  ShowSerial.println("start : test4");

  mp3FunctionReturnValue value;


  ShowSerial.println("set volume : 20");
  value = Mp3Player.volume(20);
  checkReturnValue(value,FUNCTION_VOLUME);
  ShowSerial.println("play num 1 of root directory");
  value = Mp3Player.playByIndex(1,MP3_MODE_SINGLE_SHOT);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 30 sec");
  delay(30000);
  ShowSerial.println("setEQ(1) Pop");
  value = Mp3Player.setEQ(1);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("setEQ(2) Rock");
  value = Mp3Player.setEQ(2);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("setEQ(3) Jazz");
  value = Mp3Player.setEQ(3);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("setEQ(4) Classic");
  value = Mp3Player.setEQ(4);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("setEQ(5) Bass");
  value = Mp3Player.setEQ(5);
  checkReturnValue(value,FUNCTION_PLAY_BY_INDEX);
  ShowSerial.println("wait 10 sec");
  delay(10000);
  ShowSerial.println("stop");
  value = Mp3Player.stop();
  checkReturnValue(value,FUNCTION_STOP);


  checkTestResult(about, 3);
  ShowSerial.println("");
  ShowSerial.println("");
}

void setup() {
  COMSerial.begin(COMSERIAL_SPEED);
  ShowSerial.begin(9600);

  if (SERIAL_RESET) {
    while (!ShowSerial) {
      ; // wait for serial port to connect. Needed for native USB
    }
  } else {
    delay(3000);
  }

  ShowSerial.println("");
  ShowSerial.println("");
  ShowSerial.println("MP3 player device driver test.");
  ShowSerial.println("");

#ifdef USE_WT2605C_PLAYER
  wt2605c_player.init(COMSerial);
#endif /* USE_WT2605C_PLAYER */

#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
  ShowSerial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(COMSerial, /*isACK = */true, /*doReset = */true)) {  //Use serial to communicate with mp3.
    ShowSerial.println(F("Unable to begin:"));
    ShowSerial.println(F("1.Please recheck the connection!"));
    ShowSerial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  ShowSerial.println(F("DFPlayer Mini online."));
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */

  mp3FunctionReturnValue value = Mp3Player.stop();
  checkReturnValue(value,FUNCTION_STOP);

  test1();
  test2();
  test3();
  test4();
  sumTestResult();

}

void loop() {
  // put your main code here, to run repeatedly:

}

#ifdef USE_WT2605C_PLAYER
#endif /* USE_WT2605C_PLAYER */

#ifdef USE_DF_ROBOT_DF_PLAYER_MINI
#endif /* USE_DF_ROBOT_DF_PLAYER_MINI */
