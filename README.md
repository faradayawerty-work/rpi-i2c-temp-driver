# Raspberry Pi I2C Temperature Driver

## Сборка kernel module
cd kernel_module
make
sudo insmod temp_sensor.ko
sudo mknod /dev/temp_sensor c 240 0  # пример создания устройства
sudo chmod 666 /dev/temp_sensor

## User-space logger
cd user_space_service
python3 temp_logger.py

## API
cd api
python3 temp_api.py
