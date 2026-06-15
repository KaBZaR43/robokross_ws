#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to gkv2_motor_bridge__msg__GKV2Status
/// Статус навигационного решения ГКВ2

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GKV2Status {
    /// Слово состояния ГНСС приёмника (битовое поле)
    pub gps_state_status: u32,

    /// Количество спутников в решении
    pub gps_num_satellites: u16,

    /// Состояние навигационного алгоритма (0-50: сброс, поиск, навигация)
    pub alg_state_status: f32,

    /// RTK Fixed (сантиметровая точность)
    pub rtk_fixed: bool,

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
        gps_num_satellites: msg.gps_num_satellites,
        alg_state_status: msg.alg_state_status,
        rtk_fixed: msg.rtk_fixed,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      gps_state_status: msg.gps_state_status,
      gps_num_satellites: msg.gps_num_satellites,
      alg_state_status: msg.alg_state_status,
      rtk_fixed: msg.rtk_fixed,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gps_state_status: msg.gps_state_status,
      gps_num_satellites: msg.gps_num_satellites,
      alg_state_status: msg.alg_state_status,
      rtk_fixed: msg.rtk_fixed,
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


