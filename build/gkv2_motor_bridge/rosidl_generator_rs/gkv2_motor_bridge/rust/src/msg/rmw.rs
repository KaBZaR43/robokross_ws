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

#[repr(C)]
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


