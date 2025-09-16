// --- DEFINICIÓN DE PINES ---
#define SMOKE_SENSOR A0     // MQ-2 → Pin ANALÓGICO A0
#define TMP36_PIN A1        // TMP36 → Pin ANALÓGICO A1
#define FLAME_SENSOR 13     // Push button → Pin DIGITAL D13
#define LED_PIN 6           // LED rojo → Pin DIGITAL D6
#define BUZZER_PIN 12       // Buzzer → Pin DIGITAL D12

const int SMOKE_THRESHOLD = 400;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(FLAME_SENSOR, INPUT); // 🔹 Botón con resistencia pull-down

  Serial.println("[SISTEMA] DETECCION DE INCENDIOS - LORETO");
  Serial.println("Iniciando monitoreo ambiental...");
  delay(2000);
}

void loop() {
  // Lectura MQ-2
  int smokeValue = analogRead(SMOKE_SENSOR);

  // Lectura TMP36
  int raw = analogRead(TMP36_PIN);
  float voltage = raw * (5.0 / 1023.0);
  float temperature = (voltage - 0.5) * 100.0;

  // Botón: HIGH = presionado = llama detectada
  bool hayLlama = (digitalRead(FLAME_SENSOR) == HIGH);

  // Mostrar valores
  Serial.print("Temp: "); Serial.print(temperature); Serial.print(" C | ");
  Serial.print("Humo: "); Serial.print(smokeValue); Serial.print(" | ");
  Serial.print("Llama: "); Serial.println(hayLlama ? "SI" : "NO");

  // --- Lógica de alarmas ---
  if (hayLlama) {
    // 🚨 SOLO llama activa LED + buzzer
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1000);
    Serial.println("[ALERTA] INCENDIO DETECTADO (LLAMA)");
  }
  else {
    // Si no hay llama → LED y buzzer apagados
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);

    // Mensaje de aviso por humo + temperatura
    if (smokeValue > SMOKE_THRESHOLD && temperature > 30) {
      Serial.println("[AVISO] HUMO + TEMPERATURA ALTA (SIN LLAMA)");
    } else {
      Serial.println("[OK] SIN ALERTAS");
    }
  }

  delay(1000);
}

