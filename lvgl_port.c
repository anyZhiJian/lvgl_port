#include "lvgl_port.h"

static lv_disp_t *lvgl_port_display_device_init(lvgl_port_t *port, lv_disp_draw_buf_t *draw_buffer, lv_coord_t hor_res, lv_coord_t ver_res, lv_port_disp_flush_cb_t flush_cb, void *user_data)
{
    lv_disp_drv_init(&port->disp_driver);
    port->disp_driver.draw_buf = draw_buffer;
    port->disp_driver.hor_res = hor_res;
    port->disp_driver.ver_res = ver_res;
    port->disp_driver.flush_cb = flush_cb;
    port->disp_driver.user_data = user_data;
    return lv_disp_drv_register(&port->disp_driver);
}

static lv_indev_t *lvgl_port_input_device_init(lvgl_port_t *port, lv_indev_type_t indev_type, lv_port_indev_read_cb_t read_cb, void *user_data)
{
    lv_indev_drv_init(&port->indev_driver);
    port->indev_driver.type = indev_type;
    port->indev_driver.read_cb = read_cb;
    port->indev_driver.user_data = user_data;
    return lv_indev_drv_register(&port->indev_driver);
}

void lvgl_port_init(lvgl_port_t *port, lvgl_prot_init_t *init)
{
    lv_disp_draw_buf_init(&port->draw_buffer, init->buffer1, init->buffer2, init->size_in_px_cnt);
    port->display_device = lvgl_port_display_device_init(port, &port->draw_buffer, init->hor_res, init->ver_res, init->flush_cb, init->disp_user_data);
    port->input_device = lvgl_port_input_device_init(port, init->indev_type, init->read_cb, init->indev_user_data);
}