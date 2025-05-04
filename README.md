# Unified MP3

このHardware Abstraction Layerは，Arduinoにシリアル接続するさまざまなMP3プレーヤの
APIを統一するためのものです．

[SeedStudio][SeedStudio]はコントローラチップが異なるMP3プレーヤを発売しているが，
世代としてversion2からversion4まで，[Grove Serial MP3 Playerライブラリ][GroveSerialMP3PlayerLib]
で対応している．

このライブラリと，[DFRobot社のArduino用MP3プレーヤ][DFRobotDFPlayerMini]用のライブラリ
([DFPlayer - A Mini MP3 Player For Arduino][DFRobotDFPlayerMiniLib])の2種類に対応している．


## 動作確認済みデバイス
現状，動作確認できているのは，以下の[SeedStudio][SeedStudio]のプレーヤのみ
- [Grove - MP3 v4.0][GroveMP3v4]


## 使い方

```UnifiedMP3_config.h```の中の```#undef```を活かすことで，
不要なライブラリを取り込まないようにすることができる．

以下の設定例は，[Grove - MP3 v4.0][GroveMP3v4]だけを活かして，それ以外の
ライブラリを取り込まないようにするものである．

```C:UnifiedMP3_config.h
#undef USE_KT403A_PLAYER
#undef USE_WT2003S_PLAYER
//#undef USE_WT2605C_PLAYER
#undef USE_DF_ROBOT_DF_PLAYER_MINI
```


<!-- 以下は，外部リンクの定義 
- Adafruit Unified Sensor Driver - [https://github.com/adafruit/Adafruit_Sensor][AdafruitUSD]
-->

<!-- Grove Serial MP3 Playerライブラリ -->
[GroveSerialMP3PlayerLib]:https://github.com/Seeed-Studio/Seeed_Serial_MP3_Player
<!-- Grove - MP3 v2.0 -->
[GroveMP3v2]:https://wiki.seeedstudio.com/Grove-MP3_v2.0/
<!-- Grove - MP3 v3.0 -->
[GroveMP3v3]:https://wiki.seeedstudio.com/Grove-MP3-v3/
<!-- Grove - MP3 v4.0 -->
[GroveMP3v4]:https://wiki.seeedstudio.com/grove_mp3_v4/
<!-- DFPlayer - A Mini MP3 Player For Arduino -->
[DFRobotDFPlayerMiniLib]:https://github.com/DFRobot/DFRobotDFPlayerMini
<!-- DFPlayer - A Mini MP3 Player -->
[DFRobotDFPlayerMini]:https://www.dfrobot.com/product-1121.html


<!-- 以下は，外部リンクの定義 -->
[GroveBarometerSensorBMP180]:http://wiki.seeedstudio.com/Grove-Barometer_Sensor-BMP180/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[AdafruitUSD]:https://github.com/adafruit/Adafruit_Sensor
[shield]:https://www.seeedstudio.com/Base-Shield-V2-p-1378.html
[M0Pro]:https://store.arduino.cc/usa/arduino-m0-pro
[Due]:https://store.arduino.cc/usa/arduino-due
[Uno]:https://store.arduino.cc/usa/arduino-uno-rev3
[UnoWiFi]:https://store.arduino.cc/usa/arduino-uno-wifi-rev2
[Mega]:https://store.arduino.cc/usa/arduino-mega-2560-rev3
[LeonardoEth]:https://store.arduino.cc/usa/arduino-leonardo-eth
[ProMini]:https://www.sparkfun.com/products/11114
[ESPrDev]:https://www.switch-science.com/catalog/2652/
[ESPrDevShield]:https://www.switch-science.com/catalog/2811/
[ESPrOne]:https://www.switch-science.com/catalog/2620/
[ESPrOne32]:https://www.switch-science.com/catalog/3555/
[Grove]:https://www.seeedstudio.io/category/Grove-c-1003.html
[SeedStudio]:https://www.seeedstudio.io/
[Arduino]:http://https://www.arduino.cc/
[Sparkfun]:https://www.sparkfun.com/
[SwitchScience]:https://www.switch-science.com/
[AusExGrove3AxisDigitalAccelerometer1_5g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-1.5g/
[AusExGrove3AxisDigitalAccelerometer16g]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Accelerometer-16g/
[AusExGrove3AxisDigitalGyro]:http://wiki.seeedstudio.com/Grove-3-Axis_Digital_Gyro/
[AusExGroveI2cTouchSensor]:http://wiki.seeedstudio.com/Grove-I2C_Touch_Sensor/
[AusExGroveAnalog1AxisGyro]:http://wiki.seeedstudio.com/Grove-Single_Axis_Analog_Gyro/
[AusExGroveAnalogCurrentSensor]:http://wiki.seeedstudio.com/Grove-Electricity_Sensor/
[AusExGroveAnalogTemperatureSensor]:http://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
[AusExGroveGsr]:http://wiki.seeedstudio.com/Grove-GSR_Sensor/
[AusExGroveRotaryAngleSensor]:http://wiki.seeedstudio.com/Grove-Rotary_Angle_Sensor/
[AusExGroveSimpleLight]:http://wiki.seeedstudio.com/Grove-Light_Sensor/
[AusExGroveSimpleMoisture]:http://wiki.seeedstudio.com/Grove-Moisture_Sensor/
[AusExGroveSimpleSound]:http://wiki.seeedstudio.com/Grove-Loudness_Sensor/
[AusExDigitalSwitch]:http://wiki.seeedstudio.com/Grove-Switch-P/
[AusExGroveDustSensor]:http://wiki.seeedstudio.com/Grove-Dust_Sensor/
[AusExGroveInfraredDistanceSensor]:http://wiki.seeedstudio.com/Grove-IR_Distance_Interrupter_v1.2/
[AusExGroveInfraredReflectiveSensor]:http://wiki.seeedstudio.com/Grove-Infrared_Reflective_Sensor/
[AusExGroveTouchSensor]:http://wiki.seeedstudio.com/Grove-Touch_Sensor/
[AusExGroveUltrasonicRanger]:http://wiki.seeedstudio.com/Grove-Ultrasonic_Ranger/
[AusExGroveWaterSensor]:http://wiki.seeedstudio.com/Grove-Water_Sensor/
[AusExGrovePirSensor]:http://wiki.seeedstudio.com/Grove-PIR_Motion_Sensor/


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
