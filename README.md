# 🌿 Sistema Adaptativo de Detección Temprana de Incendios Forestales – Loreto  
### *Taller 2 – Plataformas y Herramientas de Trabajo*  
**Autor:** Miguel Anderson Inocente Caro

**Email:** miguel.inocente.c@uni.pe

**Universidad Nacional de Ingeniería**  

---

## 🎯 Objetivo del Proyecto

Desarrollar un **sistema embebido integrado y adaptativo** que detecte incendios forestales en tiempo real, aplicando los principios de **eficiencia, confiabilidad y respuesta inmediata**, específicamente adaptado al contexto de **Loreto, Perú**.  

Entre 2020 y 2024, Loreto registró más de **15,000 incendios forestales** enero-septiembre, causados principalmente por quemas agrícolas y sequías extremas. Estos eventos devastan la biodiversidad amazónica, contaminan el aire con humo tóxico y amenazan la subsistencia de comunidades indígenas. Este sistema busca ser una solución económica, autónoma y escalable para zonas remotas sin infraestructura tecnológica.

---

## 🔧 Arquitectura del Sistema

El sistema se implementa mediante una **placa Arduino Uno** simulada en **Tinkercad**, integrando:

| Componente | Tipo | Función |
|----------|------|---------|
| **MQ-2** | Sensor analógico | Detecta humo y gases combustibles (valor bajo = alto riesgo). |
| **TMP36** | Sensor analógico | Mide temperatura ambiental en °C (sin librerías externas). |
| **Botón Digital (D13)** | Entrada digital | Simula la presencia de llama activa (alta confiabilidad en simulación). |
| **LED Rojo (D6)** | Actuador | Alarma visual. |
| **Buzzer (D12)** | Actuador | Alarma sonora. |

> ✅ **No se usan módulos GSM/LoRaWAN** — se simula la lógica de detección, como requiere el taller.  
> ✅ **Sin librerías externas** — optimización para bajo consumo y compatibilidad total con Tinkercad.

---

## 📈 Lógica de Decisión (Adaptativa)

El sistema responde de forma **inteligente y contextualizada**:

1. **Si se detecta llama (botón presionado):**  
   → Activación inmediata de **LED + Buzzer**.  
   → *“Incendio confirmado: alerta máxima.”*

2. **Si NO hay llama, pero sí:**  
   - `Humo > 400` (nivel crítico) **Y**  
   - `Temperatura > 30°C`  
   → Muestra un **aviso silencioso**:  
   *“HUMO + TEMPERATURA ALTA (SIN LLAMA)”*  
   → *“Riesgo potencial: monitoreo preventivo.”*

3. **Si no hay condiciones críticas:**  
   → LED y buzzer apagados.  
   → *“SIN ALERTAS”*

<img width="672" height="499" alt="image" src="https://github.com/user-attachments/assets/d8c91205-b4bd-47e9-98eb-7fcb39c03790" />

## 💻 Código Arduino (.ino)

El código está completamente comentado, organizado y optimizado:

- Uso de `#define` para pines.
- Lectura directa de sensores analógicos sin librerías.
- Respuesta en tiempo real (ciclo de 1 segundo).
- Mensajes claros en monitor serial para validación.

📌 **Archivo principal:** [`incendios_loreto.ino`](incendios_loreto.ino)

---

## 🖥️ Simulación en Tinkercad

✅ **Funcional al 100%** — Verifica el funcionamiento en vivo:  
🔗 [**Ver simulación en Tinkercad**](https://www.tinkercad.com/things/khUQ1Vb5O4Q-sistema-de-deteccion-temprana-de-incendios-forestales-?sharecode=6OHVXL1VrUTqqwaQsSHTYyKzoAQEqFgKJxRLniMT_Xc)

---

