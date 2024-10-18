// @zn0th
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h> // Livraria

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE); // Iniciando a tela
// https://javl.github.io/image2cpp/ converte imagem para bitmap *ativar swap*

// 'FAZOL', 128x64px

const unsigned char epd_bitmap_FAZOL [] PROGMEM = {
	0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 
	0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
	0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 
	0x1f, 0x40, 0x00, 0x00, 0x00, 0x60, 0x78, 0x70, 0x1c, 0x30, 0x1e, 0x00, 0x00, 0x20, 0x00, 0x78, 
	0x1f, 0xc0, 0x00, 0x00, 0x00, 0x70, 0x0c, 0xd8, 0x36, 0x3c, 0x1b, 0x00, 0x00, 0x70, 0x00, 0x78, 
	0x1f, 0xe0, 0x01, 0x00, 0x00, 0x60, 0x04, 0xd8, 0x36, 0x30, 0x33, 0x00, 0x00, 0x70, 0x00, 0x78, 
	0x1f, 0xe0, 0x01, 0x00, 0x00, 0x60, 0x3e, 0xc8, 0x36, 0x30, 0x33, 0x00, 0x00, 0xf8, 0x00, 0x78, 
	0x1f, 0xf0, 0x03, 0x00, 0x00, 0x60, 0x66, 0xc8, 0x3e, 0x30, 0x3e, 0x00, 0x00, 0xf8, 0x00, 0x78, 
	0x1f, 0xf8, 0x07, 0x00, 0x00, 0x60, 0x66, 0xd8, 0x30, 0x30, 0x10, 0x00, 0x00, 0xfc, 0x01, 0x78, 
	0x1f, 0xf8, 0x07, 0x00, 0x00, 0x60, 0x6c, 0xdb, 0xb0, 0x31, 0x18, 0x00, 0x00, 0xfe, 0x03, 0x78, 
	0x1f, 0xfc, 0x0f, 0x00, 0x00, 0xf0, 0x3d, 0x73, 0x9e, 0xfd, 0x0f, 0x00, 0x00, 0xfe, 0x03, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x80, 0xf7, 0x61, 0x9c, 0xf1, 0xfb, 0xe0, 0x18, 0xce, 0x07, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x80, 0x31, 0xf3, 0x9c, 0xc1, 0x18, 0xe0, 0x3c, 0x6f, 0x0c, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x10, 0x80, 0x31, 0xf3, 0xbc, 0xc1, 0x18, 0xf0, 0x3c, 0x6f, 0x0c, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x10, 0x80, 0xf1, 0xd1, 0xac, 0xc1, 0x78, 0xb0, 0x6d, 0x6d, 0x0c, 0x18, 0x03, 0x78, 
	0x1f, 0x00, 0x38, 0x80, 0xb7, 0x99, 0xad, 0xc1, 0x18, 0x90, 0xed, 0x6d, 0x0c, 0xbc, 0x07, 0x78, 
	0x1f, 0x00, 0x38, 0x80, 0xb1, 0xf9, 0xed, 0xc1, 0x18, 0xf8, 0xed, 0x6d, 0x0c, 0xfe, 0x0f, 0x78, 
	0x1f, 0x00, 0xff, 0x81, 0x31, 0x8b, 0xcd, 0xc1, 0x18, 0x18, 0xcf, 0x6c, 0x0c, 0xfe, 0x0f, 0x78, 
	0x1f, 0x00, 0xfe, 0x81, 0x31, 0x0f, 0xcf, 0xc1, 0xf8, 0x18, 0xcf, 0xcc, 0x07, 0xfe, 0x0f, 0x78, 
	0x1f, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x07, 0x78, 
	0x1f, 0x00, 0x38, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xfc, 0x07, 0x78, 
	0x1f, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xf8, 0x03, 0x78, 
	0x1f, 0x00, 0x10, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xf0, 0x01, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x82, 0x0f, 0x7c, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, 0x3f, 0xff, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xff, 0xff, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf8, 0xff, 0xff, 0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xf8, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x0f, 0x00, 0x38, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x0f, 0x00, 0xfe, 0x00, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x0f, 0x00, 0xff, 0x01, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x0f, 0x80, 0x73, 0x02, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x40, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x07, 0x80, 0xa5, 0x04, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x07, 0x80, 0xa5, 0x04, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xf8, 0xff, 0xff, 0x07, 0x80, 0xad, 0x05, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xe0, 0x01, 0x00, 0x00, 0xf0, 0xff, 0xff, 0x03, 0x80, 0x73, 0x06, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xfe, 0x1f, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x01, 0x80, 0xff, 0x07, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xfc, 0x0f, 0x00, 0x00, 0xc0, 0xff, 0xff, 0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x80, 0xff, 0x7f, 0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x80, 0xff, 0x07, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x00, 0xfe, 0x1f, 0x00, 0x80, 0xe6, 0x06, 0x00, 0x00, 0x78, 
	0x1f, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00, 0xf8, 0x07, 0x00, 0x80, 0x64, 0x04, 0x00, 0x00, 0x78, 
	0xff, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 
	0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 
	0xfe, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 
	0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
	0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 
	0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 
	0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x03, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void setup(void) {
  u8g2.begin(); // puxar a livraria
}

void loop(void) {
  u8g2.clearBuffer();					// limpar a memoria
  u8g2.drawXBMP(0, 0, 128, 64, epd_bitmap_FAZOL); // desenhar na tela toda 128x64 
  u8g2.sendBuffer();					// transferir memória interna para o display
  delay(1000);  // 1 segundo de delay pra essa merda n explodir
}


