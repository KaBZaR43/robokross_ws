#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to gkv2_motor_bridge__msg__GKV2Status
/// Статус навигационного решения ГКВ2
/// Согласно ЛМАП.402131.009Д1 п. 7.7.8.3 (ZED-F9P) и п. 7.5 (alg_state_status)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GKV2Status::default())
  }
}

impl rosidl_runtime_rs::Message for GKV2Status {
  type RmwMsg = super::msg::rmw::GKV2Status;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gps_state_status: msg.gps_state_status,
        gnss_date_valid: msg.gnss_date_valid,
        gnss_time_valid: msg.gnss_time_valid,
        gnss_ambiguity_resolved: msg.gnss_ambiguity_resolved,
        gnss_coords_valid: msg.gnss_coords_valid,
        gnss_diff_corrections: msg.gnss_diff_corrections,
        gnss_fix_type: msg.gnss_fix_type,
        rtk_status: msg.rtk_status,
        gps_rel_status: msg.gps_rel_status,
        rel_nav_valid: msg.rel_nav_valid,
        rel_diff_applied: msg.rel_diff_applied,
        rel_coords_valid: msg.rel_coords_valid,
        rel_ambiguity_status: msg.rel_ambiguity_status,
        rel_heading_mode: msg.rel_heading_mode,
        rel_heading_valid: msg.rel_heading_valid,
        alg_state_status: msg.alg_state_status,
        alg_stage: msg.alg_stage,
        alg_correction: msg.alg_correction,
        alg_fails: msg.alg_fails,
        alg_navigation_ready: msg.alg_navigation_ready,
        gps_num_satellites: msg.gps_num_satellites,
        gnss_sig_lat: msg.gnss_sig_lat,
        gnss_sig_lon: msg.gnss_sig_lon,
        gnss_sig_alt: msg.gnss_sig_alt,
        alg_var_x: msg.alg_var_x,
        alg_var_y: msg.alg_var_y,
        alg_var_z: msg.alg_var_z,
        alg_var_vx: msg.alg_var_vx,
        alg_var_vy: msg.alg_var_vy,
        alg_var_vz: msg.alg_var_vz,
        alg_var_psi: msg.alg_var_psi,
        alg_var_theta: msg.alg_var_theta,
        alg_var_phi: msg.alg_var_phi,
        gps_rel_heading: msg.gps_rel_heading,
        gps_rel_length: msg.gps_rel_length,
        heading_from_dual_antenna: msg.heading_from_dual_antenna,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      gps_state_status: msg.gps_state_status,
      gnss_date_valid: msg.gnss_date_valid,
      gnss_time_valid: msg.gnss_time_valid,
      gnss_ambiguity_resolved: msg.gnss_ambiguity_resolved,
      gnss_coords_valid: msg.gnss_coords_valid,
      gnss_diff_corrections: msg.gnss_diff_corrections,
      gnss_fix_type: msg.gnss_fix_type,
      rtk_status: msg.rtk_status,
      gps_rel_status: msg.gps_rel_status,
      rel_nav_valid: msg.rel_nav_valid,
      rel_diff_applied: msg.rel_diff_applied,
      rel_coords_valid: msg.rel_coords_valid,
      rel_ambiguity_status: msg.rel_ambiguity_status,
      rel_heading_mode: msg.rel_heading_mode,
      rel_heading_valid: msg.rel_heading_valid,
      alg_state_status: msg.alg_state_status,
      alg_stage: msg.alg_stage,
      alg_correction: msg.alg_correction,
      alg_fails: msg.alg_fails,
      alg_navigation_ready: msg.alg_navigation_ready,
      gps_num_satellites: msg.gps_num_satellites,
      gnss_sig_lat: msg.gnss_sig_lat,
      gnss_sig_lon: msg.gnss_sig_lon,
      gnss_sig_alt: msg.gnss_sig_alt,
      alg_var_x: msg.alg_var_x,
      alg_var_y: msg.alg_var_y,
      alg_var_z: msg.alg_var_z,
      alg_var_vx: msg.alg_var_vx,
      alg_var_vy: msg.alg_var_vy,
      alg_var_vz: msg.alg_var_vz,
      alg_var_psi: msg.alg_var_psi,
      alg_var_theta: msg.alg_var_theta,
      alg_var_phi: msg.alg_var_phi,
      gps_rel_heading: msg.gps_rel_heading,
      gps_rel_length: msg.gps_rel_length,
      heading_from_dual_antenna: msg.heading_from_dual_antenna,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gps_state_status: msg.gps_state_status,
      gnss_date_valid: msg.gnss_date_valid,
      gnss_time_valid: msg.gnss_time_valid,
      gnss_ambiguity_resolved: msg.gnss_ambiguity_resolved,
      gnss_coords_valid: msg.gnss_coords_valid,
      gnss_diff_corrections: msg.gnss_diff_corrections,
      gnss_fix_type: msg.gnss_fix_type,
      rtk_status: msg.rtk_status,
      gps_rel_status: msg.gps_rel_status,
      rel_nav_valid: msg.rel_nav_valid,
      rel_diff_applied: msg.rel_diff_applied,
      rel_coords_valid: msg.rel_coords_valid,
      rel_ambiguity_status: msg.rel_ambiguity_status,
      rel_heading_mode: msg.rel_heading_mode,
      rel_heading_valid: msg.rel_heading_valid,
      alg_state_status: msg.alg_state_status,
      alg_stage: msg.alg_stage,
      alg_correction: msg.alg_correction,
      alg_fails: msg.alg_fails,
      alg_navigation_ready: msg.alg_navigation_ready,
      gps_num_satellites: msg.gps_num_satellites,
      gnss_sig_lat: msg.gnss_sig_lat,
      gnss_sig_lon: msg.gnss_sig_lon,
      gnss_sig_alt: msg.gnss_sig_alt,
      alg_var_x: msg.alg_var_x,
      alg_var_y: msg.alg_var_y,
      alg_var_z: msg.alg_var_z,
      alg_var_vx: msg.alg_var_vx,
      alg_var_vy: msg.alg_var_vy,
      alg_var_vz: msg.alg_var_vz,
      alg_var_psi: msg.alg_var_psi,
      alg_var_theta: msg.alg_var_theta,
      alg_var_phi: msg.alg_var_phi,
      gps_rel_heading: msg.gps_rel_heading,
      gps_rel_length: msg.gps_rel_length,
      heading_from_dual_antenna: msg.heading_from_dual_antenna,
    }
  }
}


// Corresponds to gkv2_motor_bridge__msg__NavigationStatus
/// Статус навигационной системы

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub status_message: std::string::String,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NavigationStatus::default())
  }
}

impl rosidl_runtime_rs::Message for NavigationStatus {
  type RmwMsg = super::msg::rmw::NavigationStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        current_mode: msg.current_mode,
        gnss_available: msg.gnss_available,
        rtk_fixed: msg.rtk_fixed,
        gnss_satellites: msg.gnss_satellites,
        gnss_quality: msg.gnss_quality,
        odometry_drift: msg.odometry_drift,
        time_since_gnss: msg.time_since_gnss,
        status_message: msg.status_message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      current_mode: msg.current_mode,
      gnss_available: msg.gnss_available,
      rtk_fixed: msg.rtk_fixed,
      gnss_satellites: msg.gnss_satellites,
      gnss_quality: msg.gnss_quality,
      odometry_drift: msg.odometry_drift,
      time_since_gnss: msg.time_since_gnss,
        status_message: msg.status_message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      current_mode: msg.current_mode,
      gnss_available: msg.gnss_available,
      rtk_fixed: msg.rtk_fixed,
      gnss_satellites: msg.gnss_satellites,
      gnss_quality: msg.gnss_quality,
      odometry_drift: msg.odometry_drift,
      time_since_gnss: msg.time_since_gnss,
      status_message: msg.status_message.to_string(),
    }
  }
}


// Corresponds to gkv2_motor_bridge__msg__GKV2ConfigStatus
/// Статус конфигурации ГКВ2

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GKV2ConfigStatus {
    /// Общая информация
    /// Название изделия
    pub device_name: std::string::String,

    /// Серийный номер
    pub serial_number: std::string::String,

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
    pub packet_param_ids: Vec<i32>,

    /// Структура пакета соответствует ожидаемой
    pub packet_structure_match: bool,

    /// Текстовое описание статуса
    pub status_message: std::string::String,

}



impl Default for GKV2ConfigStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::GKV2ConfigStatus::default())
  }
}

impl rosidl_runtime_rs::Message for GKV2ConfigStatus {
  type RmwMsg = super::msg::rmw::GKV2ConfigStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        device_name: msg.device_name.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
        firmware_version: msg.firmware_version,
        algorithm_mode: msg.algorithm_mode,
        connection_ok: msg.connection_ok,
        data_ready: msg.data_ready,
        adc_overflow: msg.adc_overflow,
        adc_skip: msg.adc_skip,
        gyroscope_fail: msg.gyroscope_fail,
        accelerometer_fail: msg.accelerometer_fail,
        packet_param_count: msg.packet_param_count,
        packet_param_ids: msg.packet_param_ids.into(),
        packet_structure_match: msg.packet_structure_match,
        status_message: msg.status_message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        device_name: msg.device_name.as_str().into(),
        serial_number: msg.serial_number.as_str().into(),
      firmware_version: msg.firmware_version,
      algorithm_mode: msg.algorithm_mode,
      connection_ok: msg.connection_ok,
      data_ready: msg.data_ready,
      adc_overflow: msg.adc_overflow,
      adc_skip: msg.adc_skip,
      gyroscope_fail: msg.gyroscope_fail,
      accelerometer_fail: msg.accelerometer_fail,
      packet_param_count: msg.packet_param_count,
        packet_param_ids: msg.packet_param_ids.as_slice().into(),
      packet_structure_match: msg.packet_structure_match,
        status_message: msg.status_message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      device_name: msg.device_name.to_string(),
      serial_number: msg.serial_number.to_string(),
      firmware_version: msg.firmware_version,
      algorithm_mode: msg.algorithm_mode,
      connection_ok: msg.connection_ok,
      data_ready: msg.data_ready,
      adc_overflow: msg.adc_overflow,
      adc_skip: msg.adc_skip,
      gyroscope_fail: msg.gyroscope_fail,
      accelerometer_fail: msg.accelerometer_fail,
      packet_param_count: msg.packet_param_count,
      packet_param_ids: msg.packet_param_ids
          .into_iter()
          .collect(),
      packet_structure_match: msg.packet_structure_match,
      status_message: msg.status_message.to_string(),
    }
  }
}


