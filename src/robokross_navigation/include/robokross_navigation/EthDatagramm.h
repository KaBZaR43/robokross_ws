#ifndef ETH_DATAGRAMM_H
#define ETH_DATAGRAMM_H
#include <stdint.h>
#pragma pack(push, 1)// выравнивание структур данных по 1 байту

typedef enum {
    SYS_MODE_ROVER = 0,        //режим ровера
    SYS_MODE_BASE_SVIN,        //режим усреднения координат
    SYS_MODE_BASE_FIXED,       //Режим Базы с фиксированными координатами
    SYS_MODE_ASK_CONNECTIONS,  //Режим регистрации роверов
} ModuleMode;                //Режимы работы модуля

struct SystemStatus  //Статус работы модуля
{
  uint8_t gnssModuleStatus : 1;   //обмен с ГНСС в порядке - 1
  uint8_t radioModuleStatus : 1;  //обмен с радиомодулем в порядке - 1
  uint8_t ethModuleStatus : 1;    //Обмен с модулем Ethernet в порядке - 1
  uint8_t gnssCfgSeted : 1;       //конфигурация ГНСС установлена      - 1
  uint8_t ethExchange : 1;        //флаг наличия обмена по Ethernet
  uint8_t uartExchange : 1;       //флаг наличия обмена по Uart
  uint8_t imuExchange : 1;        //флаг наличия обмена с  БЧЭ
  uint8_t radioExchange : 1;      //флаг наличия обмена по Радиоканалу
};

struct SystemConfig  //конфигурация модуля
{
  uint8_t wrkMode;           //Режим работы описан в ModuleMode
  uint8_t baseId;            //идентификатор при работе в качестве БАЗЫ (Не меняется)
  uint8_t roverId;           //идентификатор при работе в качестве Ровера (присваивается БАЗОЙ)
  float varParam1;           //параметр конфигурации: для ровера - частота обмена в герцах,
                             //для фиксированной базы - координата широты,
                             //для SVIN базы - время усреднения
  float varParam2;           //параметр конфигурации: для ровера - не используется
                             //для фиксированой базы - координата долготы
                             //для SVIN базы трансляция RTCM (если не ноль)
  float varParam3;           //параметр конфигурации: для ровера - не используется
                             //для фиксированой базы - координата высоты
                             //для SVIN базы - не используется
  uint8_t searchInBaseMode;  //Поиск роверов для обратной связи во время работы в режиме базовой станции
  uint8_t resetGnss;         //флаг ресета гнсс 0 - нет, 1 - софтресет, 2 - полный ресет
  uint8_t configCrc;         //контрольная сумма поправок для сохранения в памяти
};

typedef enum
{
  INVALID = 0, // нет решения (не подключена антенна или антенна не ловит)
  SINGLE_POINT = 1,//обычное решение ГНСС
  PSEUDORANGE_DIFF = 2, //псевдо дифференциальный режим (переход в режим RTK должен смениться на FLOAT или FIXED)
  FIXED = 4,//режим RTK гарантированная точность менее 5 см
  FLOAT = 5,//режим RTK с плавающей погрешностью обычно менее 10 см
  INPUT_FIXED = 7, // выход RTK на режим, должен смениться на FLOAT или FIXED
} RoverStatusSol;

typedef struct
{
  uint16_t year;          // UTC-год
  uint8_t month;          // UTC-месяц
  uint8_t day;            // UTC-день
  uint8_t hour;           // UTC-час
  uint8_t minute;         // UTC-минута
  uint8_t second;         // UTC-секунда
  uint8_t statusSolution;        // статус решения гнсс RoverStatusSol
  uint8_t headingStatus;  // статус выставки по гнсс (начальный угол)
  uint8_t GPS_SIU;        // Количество спутников в решении GPS
  uint8_t BDS_SIU;        // Количество спутников в решении Beidou
  uint8_t GLO_SIU;        // Количество спутников в решении GLONASS
  uint8_t GAL_SIU;         // Количество спутников в решении Galileo
  float baseline[3];       // вектор расстояние до базы в проекциях : 0 - северная 1 - вертикальная 2 - восточная
  float baselineDev[3];    // СКО расстояния до базы
  float heading;           // курс относительно севера
  float pitch;             // тангаж относительно плоскости горизонта
  float roll;              // крен относительно плоскости горизонта
  float speed;             // линейная скорость движения
  float speedHeading;         // курс скорости относительно севера
  uint8_t speedSolStat;  // 0 - valid, 1 - invalid
  float velocity[3];       // вектор скорости движения в проекциях : 0 - северная, 1 - вертикальная, 2 - восточная
  float velocityDev[3];    // СКО вектора скорости движения
  double latitudeSelf;     // широта места объекта в WGS-84 (градусы)
  double longitudeSelf;    // долгота места объекта в WGS-84 (градусы)
  double altitudeSelf;     // высота места объекта в метрах
  double ecefXself;        // местоположение объекта в формате ECEF - расчет от центра Земли в трех координатах (мало ли вам она нужна)
  double ecefYself;        // направлена от центра Земли к пересечению экватара и нулевого мередиана
  double ecefZself;        // направлена от центра Земли к северному полюсу
  float latitudeSelfDev;   // СКО широты места в градусах
  float longitudeSelfDev;  // СКО долготы места в градусах
  float altitudeSelfDev;   // СКО высоты места в метрах
  float ecefXselfDev;      // ско местоположения в формате ECEF
  float ecefYselfDev;
  float ecefZselfDev;
  double latitudeBase;        // широта места БАЗЫ в WGS-84 (градусы)
  double longitudeBase;       // долгота места БАЗЫ в WGS-84 (градусы)
  double altitudeBase;        // высота места БАЗЫ в WGS-84 (метры)
  double latitudeSelfSlave;   // широта места объекта в WGS-84 (градусы) по второй антенне
  double longitudeSelfSlave;  // долгота места объекта в WGS-84 (градусы) по второй антенне
  double altitudeSelfSlave;   // высота места объекта в WGS-84 (метры) по второй антенне
  float undulation;           // разница между геоидом и элипсоидом
} UserGnssData;



struct SystemData {
  SystemStatus status;     //статус текущего модуля
  SystemConfig cfg;        //настройки для текущего модуля
  UserGnssData gData;       //Актуальные данные текущего модуля
  SystemConfig remoteCfg;  //настройки для удаленных устройств (при работе в режиме БАЗЫ)
};
#pragma pack(pop) // возврат из побайтового выравнивания
#endif  // ETH_DATAGRAMM_H
