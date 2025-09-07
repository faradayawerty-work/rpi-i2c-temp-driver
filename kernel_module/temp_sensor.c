#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/init.h>
#include <linux/fs.h>

#define DEVICE_NAME "temp_sensor"
#define I2C_BUS_NUM 1
#define I2C_ADDR 0x48  // пример адреса датчика

static struct i2c_client *temp_client;

static int temp_open(struct inode *inode, struct file *file) {
    printk(KERN_INFO "temp_sensor: device opened\n");
    return 0;
}

static int temp_release(struct inode *inode, struct file *file) {
    printk(KERN_INFO "temp_sensor: device closed\n");
    return 0;
}

static ssize_t temp_read(struct file *file, char __user *buf, size_t len, loff_t *offset) {
    int temp_val;
    char buffer[16];
    
    // чтение регистра датчика (простой пример)
    i2c_smbus_read_byte_data(temp_client, 0); 
    temp_val = 25; // фиктивное значение, замените реальным считыванием
    
    int n = snprintf(buffer, sizeof(buffer), "%d\n", temp_val);
    copy_to_user(buf, buffer, n);
    
    return n;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = temp_open,
    .release = temp_release,
    .read = temp_read,
};

static int __init temp_init(void) {
    printk(KERN_INFO "temp_sensor: module loaded\n");
    return 0;
}

static void __exit temp_exit(void) {
    printk(KERN_INFO "temp_sensor: module unloaded\n");
}

module_init(temp_init);
module_exit(temp_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple I2C temperature sensor driver");
