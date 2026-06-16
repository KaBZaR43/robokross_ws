#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "gkv2_motor_bridge__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__GKV2Status() -> *const std::ffi::c_void;
}

#[link(name = "gkv2_motor_bridge__rosidl_generator_c")]
extern "C" {
    fn gkv2_motor_bridge__msg__GKV2Status__init(msg: *mut GKV2Status) -> bool;
    fn gkv2_motor_bridge__msg__GKV2Status__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GKV2Status>, size: usize) -> bool;
    fn gkv2_motor_bridge__msg__GKV2Status__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GKV2Status>);
    fn gkv2_motor_bridge__msg__GKV2Status__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GKV2Status>, out_seq: *mut rosidl_runtime_rs::Sequence<GKV2Status>) -> bool;
}

// Corresponds to gkv2_motor_bridge__msg__GKV2Status
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Статус навигационного решения ГКВ2
/// Согласно ЛМАП.402131.009Д1 п. 7.7.8.3 (ZED-F9P) и п. 7.5 (alg_state_status)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GKV2Status {
    /// Слово состояния ГНСС приёмника (gps_state_status, ID 72)
    pub gps_state_status: u32,

    /// Бит 0: годность даты
    pub gnss_date_valid: bool,

    /// Бит 1: годность времени
    pub gnss_time_valid: bool,

    /// Бит 2: временная неоднозначность решена
    pub gnss_ambiguity_resolved: bool,

    /// Бит 16: годность координат, DOP и оценок точности
    pub gnss_coords_valid: bool,

    /// Бит 17: применяются дифференциальные поправки
    pub gnss_diff_corrections: bool,

    /// Биты 8-15: 0=нет, 2=2D, 3=3D, 5=time
    pub gnss_fix_type: u8,

    /// Биты 22-23: 0=нет, 1=float, 2=fixed
    pub rtk_status: u8,

    /// Слово состояния ровера (gps_rel_status, ID 29) — для двух антенн
    pub gps_rel_status: u32,

    /// Бит 0: годность навигационного решения
    pub rel_nav_valid: bool,

    /// Бит 1: диф. поправки применены
    pub rel_diff_applied: bool,

    /// Бит 2: годность точности относительных координат
    pub rel_coords_valid: bool,

    /// Биты 3-4: 0=не решена, 1=diff, 2=fixed
    pub rel_ambiguity_status: u8,

    /// Бит 5: режим вычисления курса по двум антеннам
    pub rel_heading_mode: bool,

    /// Бит 8: годность вычисления курса
    pub rel_heading_valid: bool,

    /// Состояние навигационного алгоритма (alg_state_status, ID 96)
    pub alg_state_status: u32,

    /// Биты 7-0: этап (0=сброс, 1-2=поиск, 10=ожидание курса, 30=преднавигация, 50=полная навигация)
    pub alg_stage: u8,

    /// Биты 15-8: тип коррекции (0=нет, 1=по скорости ГНСС, 3=по положению и скорости, 18=по курсу ГНСС)
    pub alg_correction: u8,

    /// Биты 31-16: ошибки алгоритма
    pub alg_fails: u16,

    /// stage == 50 && fails == 0
    pub alg_navigation_ready: bool,

    /// Количество спутников (ID 79)
    pub gps_num_satellites: u16,

    /// СКО координат от ГНСС (ID 85-87), метры
    /// СКО по оси X (север)
    pub gnss_sig_lat: f32,

    /// СКО по оси Y (восток)
    pub gnss_sig_lon: f32,

    /// СКО по оси Z (вниз)
    pub gnss_sig_alt: f32,

    /// Дисперсии ошибки навигационного алгоритма (ID 98-106)
    /// Дисперсия ошибки положения X, м²
    pub alg_var_x: f32,

    /// Дисперсия ошибки положения Y, м²
    pub alg_var_y: f32,

    /// Дисперсия ошибки положения Z, м²
    pub alg_var_z: f32,

    /// Дисперсия ошибки скорости X, (м/с)²
    pub alg_var_vx: f32,

    /// Дисперсия ошибки скорости Y, (м/с)²
    pub alg_var_vy: f32,

    /// Дисперсия ошибки скорости Z, (м/с)²
    pub alg_var_vz: f32,

    /// Дисперсия ошибки курса, рад²
    pub alg_var_psi: f32,

    /// Дисперсия ошибки тангажа, рад²
    pub alg_var_theta: f32,

    /// Дисперсия ошибки крена, рад²
    pub alg_var_phi: f32,

    /// Двухантенное решение (ID 13-14)
    /// Курс между антеннами, рад
    pub gps_rel_heading: f32,

    /// Расстояние между антеннами, м
    pub gps_rel_length: f32,

    /// rel_heading_valid && rel_heading_mode
    pub heading_from_dual_antenna: bool,

}



impl Default for GKV2Status {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gkv2_motor_bridge__msg__GKV2Status__init(&mut msg as *mut _) {
        panic!("Call to gkv2_motor_bridge__msg__GKV2Status__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GKV2Status {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2Status__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2Status__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2Status__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GKV2Status {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GKV2Status where Self: Sized {
  const TYPE_NAME: &'static str = "gkv2_motor_bridge/msg/GKV2Status";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__GKV2Status() }
  }
}


#[link(name = "gkv2_motor_bridge__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__NavigationStatus() -> *const std::ffi::c_void;
}

#[link(name = "gkv2_motor_bridge__rosidl_generator_c")]
extern "C" {
    fn gkv2_motor_bridge__msg__NavigationStatus__init(msg: *mut NavigationStatus) -> bool;
    fn gkv2_motor_bridge__msg__NavigationStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavigationStatus>, size: usize) -> bool;
    fn gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavigationStatus>);
    fn gkv2_motor_bridge__msg__NavigationStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavigationStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<NavigationStatus>) -> bool;
}

// Corresponds to gkv2_motor_bridge__msg__NavigationStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Статус навигационной системы

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavigationStatus {
    /// Текущий режим навигации (0=ГНСС, 1=Одометрия, 2=Слияние)
    pub current_mode: u8,

    /// ГНСС доступен и имеет хорошее качество
    pub gnss_available: bool,

    /// RTK Fixed (сантиметровая точность)
    pub rtk_fixed: bool,

    /// Количество спутников ГНСС
    pub gnss_satellites: u16,

    /// Качество ГНСС (0.0-1.0)
    pub gnss_quality: f32,

    /// Накопленная ошибка одометрии (метры)
    pub odometry_drift: f32,

    /// Время с последней хорошей ГНСС позиции (секунды)
    pub time_since_gnss: f32,

    /// Текстовое описание статуса
    pub status_message: rosidl_runtime_rs::String,

}

impl NavigationStatus {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_GNSS: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_ODOMETRY: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_FUSION: u8 = 2;

}


impl Default for NavigationStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gkv2_motor_bridge__msg__NavigationStatus__init(&mut msg as *mut _) {
        panic!("Call to gkv2_motor_bridge__msg__NavigationStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavigationStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__NavigationStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__NavigationStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__NavigationStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavigationStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavigationStatus where Self: Sized {
  const TYPE_NAME: &'static str = "gkv2_motor_bridge/msg/NavigationStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__NavigationStatus() }
  }
}


#[link(name = "gkv2_motor_bridge__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__GKV2ConfigStatus() -> *const std::ffi::c_void;
}

#[link(name = "gkv2_motor_bridge__rosidl_generator_c")]
extern "C" {
    fn gkv2_motor_bridge__msg__GKV2ConfigStatus__init(msg: *mut GKV2ConfigStatus) -> bool;
    fn gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GKV2ConfigStatus>, size: usize) -> bool;
    fn gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GKV2ConfigStatus>);
    fn gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GKV2ConfigStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<GKV2ConfigStatus>) -> bool;
}

// Corresponds to gkv2_motor_bridge__msg__GKV2ConfigStatus
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Статус конфигурации ГКВ2

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GKV2ConfigStatus {
    /// Общая информация
    /// Название изделия
    pub device_name: rosidl_runtime_rs::String,

    /// Серийный номер
    pub serial_number: rosidl_runtime_rs::String,

    /// Версия прошивки
    pub firmware_version: u16,

    /// Текущий алгоритм (9 = навигация)
    pub algorithm_mode: u8,

    /// Статус соединения
    /// Соединение с ГКВ2 установлено
    pub connection_ok: bool,

    /// Данные готовы (бит 11 статуса)
    pub data_ready: bool,

    /// Переполнение очереди АЦП (бит 1)
    pub adc_overflow: bool,

    /// Пропуск данных АЦП (бит 2)
    pub adc_skip: bool,

    /// Отказ гироскопа (бит 4)
    pub gyroscope_fail: bool,

    /// Отказ акселерометра (бит 5)
    pub accelerometer_fail: bool,

    /// Конфигурация наборного пакета
    /// Количество параметров в наборном пакете
    pub packet_param_count: u8,

    /// ID параметров в наборном пакете
    pub packet_param_ids: rosidl_runtime_rs::Sequence<i32>,

    /// Структура пакета соответствует ожидаемой
    pub packet_structure_match: bool,

    /// Текстовое описание статуса
    pub status_message: rosidl_runtime_rs::String,

}



impl Default for GKV2ConfigStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gkv2_motor_bridge__msg__GKV2ConfigStatus__init(&mut msg as *mut _) {
        panic!("Call to gkv2_motor_bridge__msg__GKV2ConfigStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GKV2ConfigStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gkv2_motor_bridge__msg__GKV2ConfigStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GKV2ConfigStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GKV2ConfigStatus where Self: Sized {
  const TYPE_NAME: &'static str = "gkv2_motor_bridge/msg/GKV2ConfigStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gkv2_motor_bridge__msg__GKV2ConfigStatus() }
  }
}


