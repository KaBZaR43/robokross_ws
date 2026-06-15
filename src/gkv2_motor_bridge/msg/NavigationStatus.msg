# Статус навигационной системы
uint8 MODE_GNSS=0
uint8 MODE_ODOMETRY=1
uint8 MODE_FUSION=2

uint8 current_mode          # Текущий режим навигации (0=ГНСС, 1=Одометрия, 2=Слияние)
bool gnss_available         # ГНСС доступен и имеет хорошее качество
bool rtk_fixed              # RTK Fixed (сантиметровая точность)
uint16 gnss_satellites      # Количество спутников ГНСС
float32 gnss_quality        # Качество ГНСС (0.0-1.0)
float32 odometry_drift      # Накопленная ошибка одометрии (метры)
float32 time_since_gnss     # Время с последней хорошей ГНСС позиции (секунды)
string status_message       # Текстовое описание статуса