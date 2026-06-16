# Статус навигационного решения ГКВ2
# Согласно ЛМАП.402131.009Д1 п. 7.7.8.3 (ZED-F9P) и п. 7.5 (alg_state_status)

# Слово состояния ГНСС приёмника (gps_state_status, ID 72)
uint32 gps_state_status
bool gnss_date_valid           # Бит 0: годность даты
bool gnss_time_valid           # Бит 1: годность времени
bool gnss_ambiguity_resolved   # Бит 2: временная неоднозначность решена
bool gnss_coords_valid         # Бит 16: годность координат, DOP и оценок точности
bool gnss_diff_corrections     # Бит 17: применяются дифференциальные поправки
uint8  gnss_fix_type           # Биты 8-15: 0=нет, 2=2D, 3=3D, 5=time
uint8  rtk_status              # Биты 22-23: 0=нет, 1=float, 2=fixed

# Слово состояния ровера (gps_rel_status, ID 29) — для двух антенн
uint32 gps_rel_status
bool rel_nav_valid             # Бит 0: годность навигационного решения
bool rel_diff_applied          # Бит 1: диф. поправки применены
bool rel_coords_valid          # Бит 2: годность точности относительных координат
uint8  rel_ambiguity_status    # Биты 3-4: 0=не решена, 1=diff, 2=fixed
bool rel_heading_mode          # Бит 5: режим вычисления курса по двум антеннам
bool rel_heading_valid         # Бит 8: годность вычисления курса

# Состояние навигационного алгоритма (alg_state_status, ID 96)
uint32 alg_state_status
uint8  alg_stage               # Биты 7-0: этап (0=сброс, 1-2=поиск, 10=ожидание курса, 30=преднавигация, 50=полная навигация)
uint8  alg_correction          # Биты 15-8: тип коррекции (0=нет, 1=по скорости ГНСС, 3=по положению и скорости, 18=по курсу ГНСС)
uint16 alg_fails               # Биты 31-16: ошибки алгоритма
bool alg_navigation_ready      # stage == 50 && fails == 0

# Количество спутников (ID 79)
uint16 gps_num_satellites

# СКО координат от ГНСС (ID 85-87), метры
float32 gnss_sig_lat           # СКО по оси X (север)
float32 gnss_sig_lon           # СКО по оси Y (восток)
float32 gnss_sig_alt           # СКО по оси Z (вниз)

# Дисперсии ошибки навигационного алгоритма (ID 98-106)
float32 alg_var_x              # Дисперсия ошибки положения X, м²
float32 alg_var_y              # Дисперсия ошибки положения Y, м²
float32 alg_var_z              # Дисперсия ошибки положения Z, м²
float32 alg_var_vx             # Дисперсия ошибки скорости X, (м/с)²
float32 alg_var_vy             # Дисперсия ошибки скорости Y, (м/с)²
float32 alg_var_vz             # Дисперсия ошибки скорости Z, (м/с)²
float32 alg_var_psi            # Дисперсия ошибки курса, рад²
float32 alg_var_theta          # Дисперсия ошибки тангажа, рад²
float32 alg_var_phi            # Дисперсия ошибки крена, рад²

# Двухантенное решение (ID 13-14)
float32 gps_rel_heading        # Курс между антеннами, рад
float32 gps_rel_length         # Расстояние между антеннами, м
bool heading_from_dual_antenna # rel_heading_valid && rel_heading_mode