import serial
import sqlite3
import time


WEIGHT_THRESHOLD = 0.5

def init_db():
    conn = sqlite3.connect("weights.db")
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS weight_log (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp TEXT,
            weight REAL
        )
    ''')
    conn.commit()
    conn.close()

def get_last_weight():
    conn = sqlite3.connect("weights.db")
    cursor = conn.cursor()
    cursor.execute("SELECT weight FROM weight_log ORDER BY timestamp DESC LIMIT 1")
    last_weight = cursor.fetchone()
    conn.close()
    return last_weight[0] if last_weight else None

def read_weight(serial_port):
    try:
        ser = serial.Serial(serial_port, 9600, timeout=1)
        time.sleep(2)  
        print("Connected to ESP32")
        
        last_weight = get_last_weight()
        
        while True:
            line = ser.readline().decode('utf-8').strip()
            if line:
                try:
                    weight = float(line)
                    print(f"Received weight: {weight} g")
                    

                    if last_weight is None or abs(weight - last_weight) >= WEIGHT_THRESHOLD:
                        store_weight(weight)
                        last_weight = weight
                    else:
                        print(f"Weight change ({abs(weight - last_weight)} g) is below threshold.")
                    
                except ValueError:
                    print("Invalid data received:", line)
    except serial.SerialException as e:
        print("Serial connection error:", e)

def store_weight(weight):
    conn = sqlite3.connect("weights.db")
    cursor = conn.cursor()
    timestamp = time.strftime("%Y-%m-%d %H:%M:%S")
    cursor.execute("INSERT INTO weight_log (timestamp, weight) VALUES (?, ?)", (timestamp, weight))
    conn.commit()
    conn.close()
    print("Weight stored in database.")

if __name__ == "__main__":
    init_db()
    serial_port = "COM3"  
    read_weight(serial_port)
