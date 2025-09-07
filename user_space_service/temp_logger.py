import time

def read_temp():
    with open("/dev/temp_sensor", "r") as f:
        return f.read().strip()

def main():
    while True:
        temp = read_temp()
        with open("temperature.log", "a") as log:
            log.write(f"{time.ctime()}: {temp} C\n")
        time.sleep(5)

if __name__ == "__main__":
    main()
