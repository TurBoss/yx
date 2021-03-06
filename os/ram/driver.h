/*
 *	driver.h
 *	device drivers 
 *
 *	tomaz stih sun may 12 2013
 */
#ifndef _DRIVER_H
#define _DRIVER_H

typedef struct driver_s {
	list_header_t hdr;
	handle_t *(*open)(struct driver_s *d, byte *hint, word attr);
	void (*close)(handle_t *h);				
	byte (*read_async)(handle_t *handle, byte *buffer, word count, event_t *done);
	byte (*write_async)(handle_t *handle, byte *buffer, word count, event_t *done);
	byte (*ioctl)(handle_t *handle, byte fn, word data);
	void (*timer_hook)();
} driver_t;

extern driver_t *drv_first;

extern driver_t *drv_register(
	string name,
	handle_t *(*open)(struct driver_s *d, byte *hint, word attr),
	void (*close)(handle_t *h),		
	byte (*read_async)(handle_t *handle, byte *buffer, word count, event_t *done),
	byte (*write_async)(handle_t *handle, byte *buffer, word count, event_t *done),
	byte (*ioctl)(handle_t *handle, byte fn, word data),
	void (*timer_hook)()
);		
	
#endif
