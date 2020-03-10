#ifndef SSD1306_H
#define SSD1306_H

#include <esp_system.h>
#include <esp_log.h>
#include <driver/i2c.h>

// https://www.olimex.com/Products/Modules/LCD/MOD-OLED-128x64/resources/SSD1306.pdf

typedef enum {
    SSD1306_CONTRAST = 0x81,        // default: 0x7f
    
    SSD1306_DISPLAY_RAM = 0xa4,     // default
    SSD1306_DISPLAY_BLANK = 0xa5,

    SSD1306_DISPLAY_NORMAL = 0xa6,  // default
    SSD1306_DISPLAY_INVERSE = 0xa7,

    SSD1306_DISPLAY_OFF = 0xae,     // default
    SSD1306_DISPLAY_ON = 0xaf,

    SSD1306_SCROLL_RIGHT = 0x26,
    SSD1306_SCROLL_LEFT = 0x27,
    SSD1306_SCROLL_VERTICAL_AND_RIGHT = 0x29,
    SSD1306_SCROLL_VERTICAL_AND_LEFT = 0x2a,
    SSD1306_SCROLL_STOP = 0x2e,
    SSD1306_SCROLL_START = 0x2f,
    SSD1306_VERTICAL_SCROLL_AREA = 0xa3,

    SSD1306_COLUMN_START_LOW = 0x00, // default: 0
    SSD1306_COLUMN_START_HIGH = 0x10, // default: 0

    SSD1306_ADDRESSING_MODE = 0x20, // default: 2=page mode

    SSD1306_COLUMN_RANGE = 0x21,    // default: 0..0x7f
    SSD1306_PAGE_RANGE = 0x22,      // default: 0..7
    SSD1306_SELECT_PAGE = 0xb0,      // default: 0

    SSD1306_TOP_LINE = 0x40,        // default: 0

    SSD1306_NO_HORIZONTAL_FLIP = 0xa0,  // default
    SSD1306_HORIZONTAL_FLIP = 0xa1,

    SSD1306_LAST_ROW = 0xa8, // default: 0x3f

    SSD1306_VSCAN_INC = 0xc0,    // default
    SSD1306_VSCAN_DEC = 0xc8,

    SSD1306_OFFSET_ROWS = 0xd3, // default: 0

    SSD1306_COM_PINS = 0xda,  // default: 0x10

    SSD1306_FREQ_DIV = 0xd5,    // default: 0x80
    SSD1306_PRECHARGE = 0xd9,   // default: 2
    SSD1306_VCOM_DESELECT = 0xdb,   // default: 0x20

    SSD1306_NOP = 0xe3,

    SSD1306_FADE_BLINK = 0x23,  // default: 0
    SSD1306_CHARGEPUMP = 0x8d,  // default: 0
} ssd1306_cmd_t;

esp_err_t ssd1306_init(i2c_port_t port, int sda_io, int scl_io);
esp_err_t ssd1306_send_cmd(i2c_port_t port, uint8_t code);
esp_err_t ssd1306_send_data(i2c_port_t port, uint8_t value);

#endif // SSD1306_H
