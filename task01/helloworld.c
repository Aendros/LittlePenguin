/*
 * helloworld.c
 * This file is part of "The little penguin challange"
 *
 * Copyright (C) 2015 - BorjaIR aka PerisH
 *
 * "The little penguin challange" is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * "The little penguin challange" is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with "The little penguin challange". If not, see <http://www.gnu.org/licenses/>.
 */



#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>



MODULE_LICENSE("GPL");
/*
 * If you set the license to something non GPL-compatible, certain kernel functions
 * will not be available to your module
*/
MODULE_AUTHOR("Borja IR <borxinhaa@gmail.com");
MODULE_DESCRIPTION("First module ever");


/*
 * The modinfo command displays all parameters accepted by the module, and these
 * are also available under /sys/module//parameters as files.
 * Above, we define a variable to store the value, wrap it into  a parameter, and
 * make it readable by everyone via sysfs.
*/

static unsigned long buffer_size = 8192;
module_param(buffer_size, ulong, (S_IRUSR | S_IRGRP | S_IROTH));
MODULE_PARAM_DESC(buffer_size, "Internal buffer size");




static int __init helloworld_init(void) {
	printk(KERN_INFO"First module ever - Helloworld - Registered");
	return 0;
}

static void __exit helloworld_exit(void) {
	printk(KERN_INFO"First module ever- Helloworld - Unregistered");
}

module_init(helloworld_init);
module_init(helloworld_exit);
