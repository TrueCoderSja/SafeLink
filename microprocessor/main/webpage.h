#ifndef WEBPAGE_H
#define WEBPAGE_H

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>ESP32 LoRa API</title>
    <style>
        body { font-family: Arial, sans-serif; text-align: center; margin: 20px; }
        input, button { margin: 5px; padding: 8px; font-size: 16px; }
        #messageLog { margin-top: 20px; border: 1px solid #ccc; padding: 10px; height: 150px; overflow-y: auto; text-align: left; }
    </style>
</head>
<body>

    <h1>ESP32 LoRa API</h1>

    <h3>Set Username</h3>
    <input type="text" id="usernameInput" placeholder="Enter username">
    <button onclick="setUsername()">Save Username</button>
    <p id="usernameStatus"></p>

    <h3>Send LoRa Message</h3>
    <input type="text" id="messageInput" placeholder="Enter message">
    <button onclick="sendMessage()">Send</button>
    <p id="sendStatus"></p>

    <h3>Received Messages</h3>
    <div id="messageLog">Waiting for messages...</div>

    <script>
        const API_URL = "http://192.168.1.1";  // ESP32 AP IP

        function setUsername() {
            let username = document.getElementById("usernameInput").value;
            if (!username) {
                alert("Please enter a username!");
                return;
            }

            fetch(`${API_URL}/setuser`, {
                method: "POST",
                headers: { "Content-Type": "application/x-www-form-urlencoded" },
                body: `username=${username}`
            })
            .then(response => response.json())
            .then(data => document.getElementById("usernameStatus").innerText = data.status)
            .catch(error => console.error("Error:", error));
        }

        function sendMessage() {
            let message = document.getElementById("messageInput").value;
            if (!message) {
                alert("Please enter a message!");
                return;
            }

…        }

        setInterval(fetchLoRaMessages, 3000);  // Fetch messages every 3 seconds
    </script>

</body>
</html>
)rawliteral";

#endif
