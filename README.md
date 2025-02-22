
**Security Band**

**🚀 Overview**

The **LoRa-Based Security Band** is a **wearable safety device** designed for **emergency situations** where cellular networks are unavailable. It uses **LoRa (Long Range) communication** to send **SOS alerts** with **GPS location** to nearby receivers, ensuring help can be dispatched quickly. It not only records the environment sounds , but also sends sos sms to all the nearby residents within the radius of our component.

**🌍 Problem Statement**

In remote or crime-prone areas, **cellular networks may not be available**, leaving individuals vulnerable in dangers/emergencies. The **Security Band** solves this by using **LoRa technology** to send **real-time distress signals** without needing the internet.

**🛠️ Tech Stack & Hardware Components ( key components used ) -**

**🔹 Hardware:**

-   **Microcontroller:** ESP32 / Arduino Mega 2560
-   **LoRa Module:** SX1278 / Ra-02
-   **GPS Module:** NEO-6M / u-blox M8N
-   **Push Button/ Pressure Sensor :** For SOS activation

**🔹 Software:**

-   Arduino IDE
-   LoRaWAN Protocol
-   Node js, Express Server
-   Android app

**How It Works**

**1. User presses the SOS button** on the band.  
2️. The **LoRa module** transmits an **SOS message** with location data.  
3️. Nearby **LoRa-enabled bands** within range receive the SOS signal.  
4️. These bands forward the event to the **receiver's phone** via **Bluetooth or Wi-Fi**.  
5️. The **companion app** on the receiver’s phone processes the event and sends it to a **central server**.  
6️. The **server relays the alert** to **nearby residents, emergency contacts, and the local police station**.  
7️. This **LoRa mesh network** ensures the SOS reaches the maximum possible range.

**🔗 System Architecture**

[Security Band] --LoRa--> [Receiver Node] – [Receiver’s mobile] --> [Server] --> [local residents/emergency contacts/ local police station]

**🚀 Features**

✅ **Works Without Internet** – Uses LoRa instead of cellular networks.  
✅ **Low Power Consumption** – Designed for long-lasting use.  
✅ **Real-Time GPS Location** – Sends accurate coordinates in emergencies.  
✅ **Long-Range Communication** – Can reach up to **10-15 km in rural areas**.  
✅ **Mesh Network Support** – Multiple LoRa nodes can extend the range.  
✅ **Compact & Wearable Design** – Lightweight for everyday use.

**🤝 Contributors & Contact**

Developed by **[Dextern]** & Team for **[Foss Hack]** 🚀

----------
