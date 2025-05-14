#pragma once

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 1 初始化缓冲区
 * 2 初始化硬件接口
 * 3 调用 lv_init 初始化 LVGL
 * 4 初始化显示设备(已包含在 lvgl_port_init 中)
 * 5 初始化输入设备(已包含在 lvgl_port_init 中)
 * 6 调用 lv_disp_flush_ready 在刷新准备好时
 * 7 调用 lv_tick_inc 提供时钟
 */

typedef void (*lv_port_disp_flush_cb_t)(struct _lv_disp_drv_t *, const lv_area_t *, lv_color_t *);
typedef void (*lv_port_indev_read_cb_t)(struct _lv_indev_drv_t *, lv_indev_data_t *);

typedef struct
{
    lv_disp_draw_buf_t draw_buffer;
    lv_disp_drv_t disp_driver;
    lv_indev_drv_t indev_driver;
    lv_disp_t *display_device;
    lv_indev_t *input_device;
} lvgl_port_t;

typedef struct
{
    lv_coord_t hor_res;
    lv_coord_t ver_res;
    void *buffer1;
    void *buffer2;
    uint32_t size_in_px_cnt;
    lv_indev_type_t indev_type;
    lv_port_disp_flush_cb_t flush_cb;
    lv_port_indev_read_cb_t read_cb;
    void *disp_user_data;
    void *indev_user_data;
} lvgl_prot_init_t;

void lvgl_port_init(lvgl_port_t *port, lvgl_prot_init_t *init);

#ifdef __cplusplus
}
#endif