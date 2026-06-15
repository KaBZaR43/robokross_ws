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


